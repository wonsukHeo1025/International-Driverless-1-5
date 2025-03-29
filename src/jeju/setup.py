from setuptools import setup

package_name = 'jeju'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/' + package_name, ['package.xml']),  # package.xml 명시적으로 설치
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='your_name',
    maintainer_email='your_email@example.com',
    description='YOLOPv2 ROS 2 integration package',
    license='License',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'lane_node = jeju.lane:main',  
            'path_node = jeju.path:main',  
            'highcontrol_node = jeju.highcontrol:main',  
            'control_node = jeju.control:main',  
        ],
    },
)

