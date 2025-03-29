#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import argparse
import time
import cv2
import torch
import numpy as np
import sys
import os
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from sklearn.cluster import DBSCAN
from sklearn.linear_model import RANSACRegressor
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline

from my_lane_msgs.msg import LanePoints

# YOLOPv2 모듈 경로 설정
sys.path.append(os.path.abspath('/home/wonsuk1025/jeju_ws/src/jeju'))
from utils.utils import select_device  # 모델 실행 시 사용할 장치 선택 함수

# --------------------- 상수 설정 --------------------- #
MIN_LANE_SEPARATION = 400       # 최소 차선 간격 (픽셀 단위)
LEFT_HIST_THRESHOLD = 1200      # 좌측 히스토그램 임계값
RIGHT_HIST_THRESHOLD = 1200     # 우측 히스토그램 임계값

# --------------------- RANSAC 기반 이상치 제거 함수 --------------------- #
def ransac_filter_points(points_x, points_y, degree=2):
    """
    RANSAC(Random Sample Consensus) 회귀 분석을 사용하여 이상치를 제거하고, 다항식 피팅을 적용
    차선이 깨지거나 노이즈가 있어도 이상치를 자동으로 제거 + 차선 곡선을 좀 더 부드럽게 피팅
    residual_threshold=25 값이 환경에 따라 다를 수 있음, 데이터가 너무 적으면(5개 미만) 작동하지 않음
    degree=2를 기본으로 하고 있는데, 곡선 차선이 많다면 degree=3 이상을 고려하는 것도 좋은 방법
    """

    # 데이터 포인트가 5개 미만이면, RANSAC 수행이 불가능하므로 입력값 그대로 반환
    if len(points_y) < 5:
        return points_x, points_y
    X = np.array(points_y).reshape(-1, 1) # points_y 값을 2D 배열 (n_samples, 1) 형태로 변환 (RANSAC 모델 학습을 위해 필요)
    y = np.array(points_x) # points_x는 1D 배열로 유지

    # RANSAC 기반 다항식 회귀 모델을 생성
    model = make_pipeline(PolynomialFeatures(degree), RANSACRegressor(residual_threshold=25, max_trials=500))    
    model.fit(X, y) # X (y 좌표)와 y (x 좌표)를 입력하여 학습, 이 과정에서 이상치(outlier)가 자동으로 감지 및 제거됨

    # 이상치 필터링
    inlier_mask = model.named_steps['ransacregressor'].inlier_mask_
    filtered_x = y[inlier_mask] # 이상치가 아닌 데이터만 추출
    filtered_y = X[inlier_mask].flatten()

    return filtered_x.tolist(), filtered_y.tolist()

# --------------------- 영상 전처리 함수들 --------------------- #
def letterbox(im, new_shape=(640, 640), color=(114, 114, 114)):
    """
    입력 이미지를 주어진 크기로 맞추되, 비율을 유지하면서 여백(padding)을 추가하는 역할
    주로 YOLO 모델에서 입력 이미지를 정해진 크기로 변환할 때 사용
    """
    shape = im.shape[:2] # 원본 이미지 크기 가져오기

    # 새로운 크기(new_shape)가 단일 정수이면 (640 → (640, 640))
    if isinstance(new_shape, int):
        new_shape = (new_shape, new_shape)

    # 원본 비율을 유지하면서 새로운 크기로 맞춤
    ratio = min(new_shape[0] / shape[0], new_shape[1] / shape[1])
    new_unpad = (int(round(shape[1] * ratio)), int(round(shape[0] * ratio)))

    # 여백(padding) 계산
    dw, dh = (new_shape[1] - new_unpad[0]) / 2, (new_shape[0] - new_unpad[1]) / 2
    top, bottom = int(np.floor(dh)), int(np.ceil(dh))
    left, right = int(np.floor(dw)), int(np.ceil(dw))

    im_resized = cv2.resize(im, new_unpad, interpolation=cv2.INTER_LINEAR) # 이미지 크기 조정 (비율 유지)
    im_padded = cv2.copyMakeBorder(im_resized, top, bottom, left, right, 
                                   cv2.BORDER_CONSTANT, value=color) # 패딩 추가 (회색 배경)
    return im_padded, top, left

def apply_birds_eye_view(binary_mask):
    """
     Bird’s Eye View(탑뷰) 변환을 적용하여 원근 보정을 수행
    """
    # src_points: 원본 좌표, dst_points: 목표 좌표
    src_points = np.float32([[130, 360], [510, 360], [205, 240], [435, 240]])
    dst_points = np.float32([[130, 360], [510, 360], [130, 0], [510, 0]])

    M = cv2.getPerspectiveTransform(src_points, dst_points) # 원근 변환 행렬(M)을 생성. 입력 이미지의 특정 좌표를 원하는 좌표로 변환하는 역할
    bird_eye = cv2.warpPerspective(binary_mask, M, (640, 360)) # 이진 마스크를 새로운 시점으로 변환
    return bird_eye

def apply_sobel_filter(binary_img):
    """
    Sobel 필터를 사용하여 차선의 경계를 강조하는 역할
    이미지에서 수평 방향의 경계를 감지하여 차선 엣지를 추출
    """
    sobelx = cv2.Sobel(binary_img, cv2.CV_64F, 1, 0, ksize=3) # 수평 방향 경계 검출 (Sobel 필터 적용)
    abs_sobelx = np.absolute(sobelx) # 절댓값 변환 (음수 제거)
    
    # 예외 처리 (엣지가 없는 경우). 이미지 전체가 0(엣지 없음)이면, 계산할 필요 없이 0으로 된 빈 이미지를 반환
    if np.max(abs_sobelx) == 0:
        return np.zeros_like(abs_sobelx, dtype=np.uint8)
    
    scaled_sobel = np.uint8(255 * abs_sobelx / np.max(abs_sobelx)) # 정규화 (0~255로 변환)
    return scaled_sobel

def apply_morphology_filter(scaled_sobel):
    """
    차선의 엣지를 보정하고 잡음을 제거하는 역할
    차선이 끊어져 있거나 노이즈가 많은 경우 연결을 강화하고 불필요한 작은 객체를 제거
    """
    kernel = np.ones((9, 9), np.uint8) # 커널 생성. 클수록 연산량 증가
    morph_close = cv2.morphologyEx(scaled_sobel, cv2.MORPH_CLOSE, kernel, iterations=4) # 닫힘 연산: 작은 구멍(검은 부분)을 메우고 차선을 연결
    dilated = cv2.dilate(morph_close, kernel, iterations=2) # 열림 연산: 픽셀을 확장하여 차선을 더 두껍게 만듦
    return dilated

# ------------------------ DBSCAN 클러스터링 함수 ------------------------ 
def filter_lane_points_dbscan(points_x, points_y, eps=15, base_min_samples=4):
    """
    차선 포인트를 클러스터링하고, 가장 큰 클러스터만 반환
    노이즈가 포함된 차선 포인트 데이터에서 주요 차선 포인트만 필터링
    """
    # 예외처리
    if len(points_x) == 0:
        return points_x, points_y
    
    # min_samples 동적 조정
    dynamic_min_samples = base_min_samples
    if len(points_x) < 50:
        dynamic_min_samples = max(2, len(points_x) // 10) # 최솟값은 2로 보장

    data = np.column_stack((points_x, points_y)) # x, y 좌표를 2D 배열로 변환

    # DBSCAN 클러스터링 적용
    clustering = DBSCAN(eps=eps, min_samples=dynamic_min_samples).fit(data)
    labels = clustering.labels_

    # 노이즈 제거 (유효한 클러스터만 선택)
    valid_labels = labels[labels != -1]
    if len(valid_labels) == 0:
        return points_x, points_y
    
    # 가장 큰 클러스터 선택
    unique, counts = np.unique(valid_labels, return_counts=True)
    largest_cluster = unique[np.argmax(counts)]

    filtered_data = data[labels == largest_cluster] # 선택된 클러스터의 포인트만 반환
    return filtered_data[:, 0].tolist(), filtered_data[:, 1].tolist()

# ------------------------ Sliding Window 함수 ------------------------
def sliding_window_demo(mask, right_nwindows=20, left_nwindows=20,
                        right_margin=80, left_margin=80, minpix=20):
    """
    히스토그램 기반 Sliding Window 기법을 사용하여 차선을 탐지
    차선 픽셀을 검출하고 DBSCAN과 RANSAC을 적용해 노이즈를 제거, 다항식 피팅을 통해 차선 보정
    """
    # 히스토그램을 이용한 차선 기초 탐색
    base_limit_height = mask.shape[0] * 4 // 5
    histogram = np.sum(mask[base_limit_height:, :], axis=0)
    midpoint = histogram.shape[0] // 2
    meas_left = np.argmax(histogram[:midpoint])
    meas_right = np.argmax(histogram[midpoint:]) + midpoint

    left_hist_sum = np.sum(histogram[:midpoint])
    right_hist_sum = np.sum(histogram[midpoint:])

    left_lane_missing = False
    right_lane_missing = False

    # 차선이 감지되지 않는 경우 예외 처리
    if left_hist_sum < LEFT_HIST_THRESHOLD:
        left_lane_missing = True
        meas_left = meas_right - MIN_LANE_SEPARATION
    if right_hist_sum < RIGHT_HIST_THRESHOLD:
        right_lane_missing = True
        meas_right = meas_left + MIN_LANE_SEPARATION

    if meas_right <= meas_left + MIN_LANE_SEPARATION:
        meas_right = meas_left + MIN_LANE_SEPARATION

    # 슬라이딩 윈도우를 이용한 차선 포인트 탐색
    leftx_base = meas_left
    rightx_base = meas_right

    left_window_height = int(mask.shape[0] // left_nwindows)
    right_window_height = int(mask.shape[0] // right_nwindows)
    leftx_current = leftx_base
    rightx_current = rightx_base

    nonzero = mask.nonzero()
    nonzeroy = np.array(nonzero[0])
    nonzerox = np.array(nonzero[1])

    left_lane_points_x = []
    left_lane_points_y = []
    right_lane_points_x = []
    right_lane_points_y = []

    # 각 윈도우의 박스 좌표를 저장할 리스트
    left_window_rects = []
    right_window_rects = []

    # 슬라이딩 윈도우
    for window in range(max(right_nwindows, left_nwindows)):
        # 왼쪽 윈도우
        if not left_lane_missing and window < left_nwindows:
            win_y_low_left = mask.shape[0] - (window + 1) * left_window_height
            win_y_high_left = mask.shape[0] - window * left_window_height
            win_xleft_low = leftx_current - left_margin
            win_xleft_high = leftx_current + left_margin
            left_window_rects.append((int(win_xleft_low), int(win_y_low_left), int(win_xleft_high), int(win_y_high_left)))
            good_left_inds = ((nonzeroy >= win_y_low_left) & (nonzeroy < win_y_high_left) &
                              (nonzerox >= win_xleft_low) & (nonzerox < win_xleft_high)).nonzero()[0]
            if len(good_left_inds) > minpix:
                leftx_mean = int(np.mean(nonzerox[good_left_inds]))
                lefty_mean = int(np.mean(nonzeroy[good_left_inds]))
                leftx_current = leftx_mean
                left_lane_points_x.append(leftx_mean)
                left_lane_points_y.append(lefty_mean)

        # 오른쪽 윈도우
        if not right_lane_missing and window < right_nwindows:
            win_y_low_right = mask.shape[0] - (window + 1) * right_window_height
            win_y_high_right = mask.shape[0] - window * right_window_height
            win_xright_low = rightx_current - right_margin
            win_xright_high = rightx_current + right_margin
            right_window_rects.append((int(win_xright_low), int(win_y_low_right), int(win_xright_high), int(win_y_high_right)))
            good_right_inds = ((nonzeroy >= win_y_low_right) & (nonzeroy < win_y_high_right) &
                               (nonzerox >= win_xright_low) & (nonzerox < win_xright_high)).nonzero()[0]
            if len(good_right_inds) > minpix:
                rightx_mean = int(np.mean(nonzerox[good_right_inds]))
                righty_mean = int(np.mean(nonzeroy[good_right_inds]))
                rightx_current = rightx_mean
                right_lane_points_x.append(rightx_mean)
                right_lane_points_y.append(righty_mean)

    # DBSCAN -> RANSAC 순서로 후처리
    left_lane_points_x, left_lane_points_y = filter_lane_points_dbscan(left_lane_points_x, left_lane_points_y)
    right_lane_points_x, right_lane_points_y = filter_lane_points_dbscan(right_lane_points_x, right_lane_points_y)

    left_lane_points_x, left_lane_points_y = ransac_filter_points(left_lane_points_x, left_lane_points_y)
    right_lane_points_x, right_lane_points_y = ransac_filter_points(right_lane_points_x, right_lane_points_y)

    # 다항식 보정 (곡선에 맞게 재배열)
    if len(left_lane_points_y) >= 3:
        poly_left = np.polyfit(left_lane_points_y, left_lane_points_x, 2)
        p_left = np.poly1d(poly_left)
        y_left_new = np.linspace(min(left_lane_points_y), max(left_lane_points_y), num=len(left_lane_points_y))
        left_lane_points_x = p_left(y_left_new).tolist()
        left_lane_points_y = y_left_new.tolist()
        
    if len(right_lane_points_y) >= 3:
        poly_right = np.polyfit(right_lane_points_y, right_lane_points_x, 2)
        p_right = np.poly1d(poly_right)
        y_right_new = np.linspace(min(right_lane_points_y), max(right_lane_points_y), num=len(right_lane_points_y))
        right_lane_points_x = p_right(y_right_new).tolist()
        right_lane_points_y = y_right_new.tolist()
    
    # 기울기 기반 차선 무시 로직
    def calculate_slope(x_points, y_points):
        if len(x_points) >= 2:
            fit = np.polyfit(y_points, x_points, 1)
            return fit[0]
        return None

    slope_threshold = 3
    left_slope = calculate_slope(left_lane_points_x, left_lane_points_y)
    right_slope = calculate_slope(right_lane_points_x, right_lane_points_y)
    
    if len(left_lane_points_x) > len(right_lane_points_x):
        if left_slope is not None and abs(left_slope) < slope_threshold:
            right_lane_points_x, right_lane_points_y = [], []
    elif len(right_lane_points_x) > len(left_lane_points_x):
        if right_slope is not None and abs(right_slope) < slope_threshold:
            left_lane_points_x, left_lane_points_y = [], []
    
    # 시각화용 이미지 (마스크 3채널)
    vis_img = np.dstack((mask, mask, mask))

    # 슬라이딩 윈도우 박스 시각화 (차선 픽셀이 검출된 경우만)
    for (x_low, y_low, x_high, y_high), (lane_x, lane_y) in zip(left_window_rects, zip(left_lane_points_x, left_lane_points_y)):
        if lane_x and lane_y:  # 차선 픽셀 존재 여부 확인
            cv2.rectangle(vis_img, (x_low, y_low), (x_high, y_high), (255, 0, 0), 2)  # 왼쪽: 파란색
    for (x_low, y_low, x_high, y_high), (lane_x, lane_y) in zip(right_window_rects, zip(right_lane_points_x, right_lane_points_y)):
        if lane_x and lane_y:  # 차선 픽셀 존재 여부 확인
            cv2.rectangle(vis_img, (x_low, y_low), (x_high, y_high), (0, 0, 255), 2)  # 오른쪽: 빨간색

    # 검출된 차선 포인트 시각화
    for x, y in zip(left_lane_points_x, left_lane_points_y):
        cv2.circle(vis_img, (int(x), int(y)), 5, (255, 0, 0), -1)
    for x, y in zip(right_lane_points_x, right_lane_points_y):
        cv2.circle(vis_img, (int(x), int(y)), 5, (0, 0, 255), -1)

    return vis_img, left_lane_points_x, left_lane_points_y, right_lane_points_x, right_lane_points_y

# --------------------- 인자 파싱 함수 --------------------- #
def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--weights', type=str,
                        default='/home/wonsuk1025/jeju_ws/src/jeju/data/weights/yolopv2.pt',
                        help='모델 가중치 파일 경로')
    parser.add_argument('--source', type=str,
                        default='/home/wonsuk1025/jeju_ws/src/jeju/data/28_1.mp4',
                        help='비디오 소스 (파일 경로 또는 웹캠이면 0)')
    parser.add_argument('--img-size', type=int, default=640, help='추론 이미지 크기 (정사각형)')
    parser.add_argument('--device', default='0', help='cuda device (예: 0) 또는 cpu')
    return parser.parse_args()

# --------------------- 메인 함수 --------------------- #
def main():
    rclpy.init()
    node = Node("lane_detection_node")
    publisher = node.create_publisher(LanePoints, "lane_points", 10)
    gps_mode_publisher = node.create_publisher(Float32MultiArray, "gps_mode", 10)

    args = parse_args()
    device = select_device(args.device)
    half = (device.type != 'cpu')

    try:
        model = torch.jit.load(args.weights, map_location=device)
        model.to(device).eval()
        if half:
            model.half()
    except Exception as e:
        print(f"모델 로드 실패: {e}")
        return

    cap = cv2.VideoCapture(args.source)
    if not cap.isOpened():
        print(f"Error: 비디오 소스를 열 수 없습니다. 경로 확인: {args.source}")
        return

    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 360)
    cap.set(cv2.CAP_PROP_FPS, 30)
    cap.set(cv2.CAP_PROP_BUFFERSIZE, 1)

    skip_frames = 1
    frame_count = 0
    prev_time = time.time()

    lane_missing_counter = 0
    LANE_MISSING_LIMIT = 20  # 차선 감지 안 될 때 카운트 기준

    while rclpy.ok():
        time.sleep(0.01)
        ret, frame = cap.read()
        if not ret:
            print("프레임을 읽을 수 없습니다. 스트림 종료")
            break

        frame_count += 1
        if frame_count % skip_frames != 0:
            continue

        current_time = time.time()
        dt = current_time - prev_time
        prev_time = current_time

        orig_h, orig_w = frame.shape[:2]
        frame_letterbox, top_pad, left_pad = letterbox(frame, (args.img_size, args.img_size))
        img_rgb = cv2.cvtColor(frame_letterbox, cv2.COLOR_BGR2RGB)
        img_rgb = img_rgb.transpose(2, 0, 1)
        img_rgb = np.expand_dims(img_rgb, axis=0)
        img_tensor = torch.from_numpy(img_rgb).to(device)
        img_tensor = img_tensor.half() if half else img_tensor.float()
        img_tensor /= 255.0

        with torch.no_grad():
            outputs = model(img_tensor)

        try:
            ll = outputs[2]  # YOLOPv2에서 세 번째 출력(차선 세그멘테이션)
            ll = ll.cpu().numpy()
            lane_line_output = np.squeeze(ll)
            if lane_line_output.ndim > 2:
                lane_line_output = lane_line_output[..., 0]
        except Exception as e:
            print(f"모델 출력 오류: {e}")
            continue

        # 이진 마스크 생성
        yolo_mask = (lane_line_output > 0.0001).astype(np.uint8) * 255

        # 패딩 제거 (또는 리사이즈)
        if yolo_mask.shape[0] >= top_pad + orig_h and yolo_mask.shape[1] >= left_pad + orig_w:
            yolo_mask_cropped = yolo_mask[top_pad: top_pad + orig_h, left_pad: left_pad + orig_w]
        else:
            yolo_mask_cropped = cv2.resize(yolo_mask, (orig_w, orig_h), interpolation=cv2.INTER_LINEAR)

        # 시각화용
        yolo_mask_color = cv2.applyColorMap(yolo_mask_cropped, cv2.COLORMAP_JET)
        overlay = cv2.addWeighted(frame, 0.8, yolo_mask_color, 0.4, 0)

        # Bird's Eye View
        binary_mask = np.zeros_like(frame[:, :, 0])
        binary_mask[yolo_mask_cropped > 0] = 255

        bird_eye = apply_birds_eye_view(binary_mask)
        scaled_sobel = apply_sobel_filter(bird_eye)
        corrected_mask = apply_morphology_filter(scaled_sobel)

        sw_img, left_pts_x, left_pts_y, right_pts_x, right_pts_y = sliding_window_demo(corrected_mask)

        # ROS 메시지 퍼블리시
        lane_msg = LanePoints()
        lane_msg.left_x = [float(x) for x in left_pts_x]
        lane_msg.left_y = [float(y) for y in left_pts_y]
        lane_msg.right_x = [float(x) for x in right_pts_x]
        lane_msg.right_y = [float(y) for y in right_pts_y]
        publisher.publish(lane_msg)

        # 차선 감지 여부 확인
        lane_detected = (len(left_pts_x) > 0 or len(right_pts_x) > 0)
        if lane_detected:
            lane_missing_counter = 0
        else:
            lane_missing_counter += 1
        
        # 일정 프레임 이상 차선 미검출 시 GPS 모드 전환
        if lane_missing_counter >= LANE_MISSING_LIMIT:
            print("차선이 일정 프레임 이상 감지되지 않음 → GPS 모드로 전환")
            gps_mode_msg = Float32MultiArray()
            gps_mode_msg.data = [1.0]  # GPS 모드 활성화 예시
            gps_mode_publisher.publish(gps_mode_msg)
            lane_missing_counter = 0

        cv2.imshow("lane overlay", overlay)
        cv2.imshow("Sliding Window", sw_img)
        if cv2.waitKey(1) & 0xFF == 27:
            break

    cap.release()
    cv2.destroyAllWindows()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
