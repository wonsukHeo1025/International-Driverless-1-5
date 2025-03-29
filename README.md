# 1/5 of the International College Student EV Self-Driving Competition
2025 국제 대학생 EV wkdbfwngod rudwlseoghl 1/5 부문 Lane Detection + Control의 모든 것

본 프로젝트는 ROS 2 환경에서 자율주행 차량의 차선 인식 및 경로 계획, 차량 제어를 목적으로 개발되었습니다. 딥러닝 기반의 YOLOPv2 모델과 이미지 처리 기법을 결합하여 정확한 차선 탐지 및 안정적인 주행 제어를 구현했습니다.

프로젝트 개요

이 프로젝트는 다음의 핵심 기능을 포함하고 있습니다.

Lane Detection: YOLOPv2와 이미지 처리 기법으로 차선 검출

Path Planning: 차선을 기반으로 안정적인 주행 경로 생성

Vehicle Control: Pure Pursuit 알고리즘을 사용한 차량 제어 (스티어링 각도 및 속도)

기술 스택

Python, ROS 2

OpenCV, NumPy

PyTorch (YOLOPv2)

CUDA (GPU 가속)

Pure Pursuit 알고리즘

프로젝트 디렉터리 구조

jeju_ws
├── src
│   └── jeju
│       ├── config
│       │   ├── camera_config.json
│       │   └── hsv_ranges.json
│       ├── data
│       │   └── test_video.mp4
│       ├── models
│       │   └── yolopv2_weights.pt
│       ├── output
│       │   └── (출력 결과 저장 폴더)
│       ├── scripts
│       │   ├── lane.py
│       │   ├── path.py
│       │   ├── highcontrol.py
│       │   └── control.py
│       ├── launch
│       │   └── lane_detection.launch.py
│       ├── package.xml
│       ├── setup.py
│       └── README.md
└── my_lane_msgs
    ├── package.xml
    ├── CMakeLists.txt
    └── msg
        └── LanePoints.msg

핵심 기능 설명

1. 차선 탐지 (lane.py)

YOLOPv2를 이용한 lane mask 생성

Bird’s Eye View 변환, Sobel 필터, Morphology 필터 적용

Sliding Window 알고리즘을 통한 차선 픽셀 추출

DBSCAN 클러스터링 및 RANSAC 알고리즘을 이용한 이상치 제거

결과를 ROS 토픽으로 발행 (LanePoints)

2. 경로 계획 (path.py)

수신한 차선 포인트를 기반으로 경로 좌표 계산

좌우 차선 여부에 따라 유연한 경로 생성

Cubic Spline 보간을 사용한 부드러운 경로 생성

최종 경로를 ROS 토픽으로 발행 (Float32MultiArray)

3. 차량 제어 (highcontrol.py)

Pure Pursuit 알고리즘을 사용한 스티어링 각도 및 속도 계산

차량 상태 및 목표점에 따라 실시간 제어값 결정

스티어링 각도와 속도를 ROS 토픽으로 발행 (Float32)

4. 제어 명령 처리 (control.py)

ROS 토픽에서 차량 제어 명령을 수신하고 로그 출력

향후 Arduino와의 시리얼 통신 연계 가능
