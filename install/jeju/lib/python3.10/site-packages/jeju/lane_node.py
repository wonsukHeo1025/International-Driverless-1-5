import rclpy
from rclpy.node import Node
from std_msgs.msg import String  # 메시지 타입

class LaneSubscriber(Node):
    def __init__(self):
        super().__init__('lane_subscriber')  # 노드 이름 설정
        self.subscription = self.create_subscription(
            String,  # 메시지 타입
            'lane_data',  # 구독할 토픽 이름
            self.listener_callback,  # 메시지를 받았을 때 호출할 콜백 함수
            10  # 큐 사이즈
        )
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        # 메시지가 들어오면 출력
        self.get_logger().info(f'Received message: {msg.data}')

def main(args=None):
    rclpy.init(args=args)  # ROS 2 노드 초기화
    node = LaneSubscriber()  # 노드 생성
    rclpy.spin(node)  # 노드가 종료될 때까지 실행

if __name__ == '__main__':
    main()

