// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_lane_msgs:msg/LanePoints.idl
// generated code does not contain a copyright notice

#ifndef MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__BUILDER_HPP_
#define MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_lane_msgs/msg/detail/lane_points__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_lane_msgs
{

namespace msg
{

namespace builder
{

class Init_LanePoints_right_y
{
public:
  explicit Init_LanePoints_right_y(::my_lane_msgs::msg::LanePoints & msg)
  : msg_(msg)
  {}
  ::my_lane_msgs::msg::LanePoints right_y(::my_lane_msgs::msg::LanePoints::_right_y_type arg)
  {
    msg_.right_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_lane_msgs::msg::LanePoints msg_;
};

class Init_LanePoints_right_x
{
public:
  explicit Init_LanePoints_right_x(::my_lane_msgs::msg::LanePoints & msg)
  : msg_(msg)
  {}
  Init_LanePoints_right_y right_x(::my_lane_msgs::msg::LanePoints::_right_x_type arg)
  {
    msg_.right_x = std::move(arg);
    return Init_LanePoints_right_y(msg_);
  }

private:
  ::my_lane_msgs::msg::LanePoints msg_;
};

class Init_LanePoints_left_y
{
public:
  explicit Init_LanePoints_left_y(::my_lane_msgs::msg::LanePoints & msg)
  : msg_(msg)
  {}
  Init_LanePoints_right_x left_y(::my_lane_msgs::msg::LanePoints::_left_y_type arg)
  {
    msg_.left_y = std::move(arg);
    return Init_LanePoints_right_x(msg_);
  }

private:
  ::my_lane_msgs::msg::LanePoints msg_;
};

class Init_LanePoints_left_x
{
public:
  Init_LanePoints_left_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LanePoints_left_y left_x(::my_lane_msgs::msg::LanePoints::_left_x_type arg)
  {
    msg_.left_x = std::move(arg);
    return Init_LanePoints_left_y(msg_);
  }

private:
  ::my_lane_msgs::msg::LanePoints msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_lane_msgs::msg::LanePoints>()
{
  return my_lane_msgs::msg::builder::Init_LanePoints_left_x();
}

}  // namespace my_lane_msgs

#endif  // MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__BUILDER_HPP_
