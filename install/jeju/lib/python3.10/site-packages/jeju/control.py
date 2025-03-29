#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Int32

class ArduinoSerialNode(Node):
    def __init__(self):
        super().__init__('arduino_serial_node')

        # 개별 제어값을 구독하는 서브스크라이버 생성
        self.steering_subscription = self.create_subscription(
            Float32, '/steering_angle_topic', self.steering_callback, 10)

        self.throttle_subscription = self.create_subscription(
            Float32, '/throttle_topic', self.throttle_callback, 10)

        self.mode_subscription = self.create_subscription(
            Int32, '/mode_topic', self.mode_callback, 10)

    def steering_callback(self, msg):
        """ 스티어링 값 로그 출력 """
        self.get_logger().info(f"Received steering angle: {msg.data}")

    def throttle_callback(self, msg):
        """ 스로틀 값 로그 출력 """
        self.get_logger().info(f"Received throttle: {msg.data}")

    def mode_callback(self, msg):
        """ 모드 값 로그 출력 """
        self.get_logger().info(f"Received mode: {msg.data}")


def main(args=None):
    rclpy.init(args=args)
    node = ArduinoSerialNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()