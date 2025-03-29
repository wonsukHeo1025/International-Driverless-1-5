from setuptools import find_packages
from setuptools import setup

setup(
    name='my_lane_msgs',
    version='0.0.1',
    packages=find_packages(
        include=('my_lane_msgs', 'my_lane_msgs.*')),
)
