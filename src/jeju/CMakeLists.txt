cmake_minimum_required(VERSION 3.8)
project(yolopv2)

# ROS 2의 필수 빌드 시스템 패키지들
find_package(ament_cmake REQUIRED)
find_package(ament_python REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)

# 커스텀 메시지 의존성 (my_lane_msgs)
find_package(my_lane_msgs REQUIRED)

# Python 패키지 빌드 설정
ament_python_install_package(${PROJECT_NAME})

install(FILES package.xml DESTINATION share/${PROJECT_NAME})

# 실행 가능한 Python 스크립트 설치 (lane_node.py)
install(
  PROGRAMS
    jeju/lane_node.py  # 실제 스크립트 경로를 확인
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

