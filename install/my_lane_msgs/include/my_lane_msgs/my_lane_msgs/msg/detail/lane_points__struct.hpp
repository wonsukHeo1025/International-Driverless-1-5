// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_lane_msgs:msg/LanePoints.idl
// generated code does not contain a copyright notice

#ifndef MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__STRUCT_HPP_
#define MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_lane_msgs__msg__LanePoints __attribute__((deprecated))
#else
# define DEPRECATED__my_lane_msgs__msg__LanePoints __declspec(deprecated)
#endif

namespace my_lane_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LanePoints_
{
  using Type = LanePoints_<ContainerAllocator>;

  explicit LanePoints_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit LanePoints_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _left_x_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _left_x_type left_x;
  using _left_y_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _left_y_type left_y;
  using _right_x_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _right_x_type right_x;
  using _right_y_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _right_y_type right_y;

  // setters for named parameter idiom
  Type & set__left_x(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->left_x = _arg;
    return *this;
  }
  Type & set__left_y(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->left_y = _arg;
    return *this;
  }
  Type & set__right_x(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->right_x = _arg;
    return *this;
  }
  Type & set__right_y(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->right_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_lane_msgs::msg::LanePoints_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_lane_msgs::msg::LanePoints_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_lane_msgs::msg::LanePoints_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_lane_msgs::msg::LanePoints_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_lane_msgs::msg::LanePoints_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_lane_msgs::msg::LanePoints_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_lane_msgs::msg::LanePoints_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_lane_msgs::msg::LanePoints_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_lane_msgs::msg::LanePoints_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_lane_msgs::msg::LanePoints_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_lane_msgs__msg__LanePoints
    std::shared_ptr<my_lane_msgs::msg::LanePoints_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_lane_msgs__msg__LanePoints
    std::shared_ptr<my_lane_msgs::msg::LanePoints_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LanePoints_ & other) const
  {
    if (this->left_x != other.left_x) {
      return false;
    }
    if (this->left_y != other.left_y) {
      return false;
    }
    if (this->right_x != other.right_x) {
      return false;
    }
    if (this->right_y != other.right_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const LanePoints_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LanePoints_

// alias to use template instance with default allocator
using LanePoints =
  my_lane_msgs::msg::LanePoints_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_lane_msgs

#endif  // MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__STRUCT_HPP_
