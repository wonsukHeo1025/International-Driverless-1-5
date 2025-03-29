// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_lane_msgs:msg/LanePoints.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_lane_msgs/msg/detail/lane_points__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace my_lane_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void LanePoints_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_lane_msgs::msg::LanePoints(_init);
}

void LanePoints_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_lane_msgs::msg::LanePoints *>(message_memory);
  typed_message->~LanePoints();
}

size_t size_function__LanePoints__left_x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LanePoints__left_x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__LanePoints__left_x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__LanePoints__left_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__LanePoints__left_x(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__LanePoints__left_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__LanePoints__left_x(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__LanePoints__left_x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__LanePoints__left_y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LanePoints__left_y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__LanePoints__left_y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__LanePoints__left_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__LanePoints__left_y(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__LanePoints__left_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__LanePoints__left_y(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__LanePoints__left_y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__LanePoints__right_x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LanePoints__right_x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__LanePoints__right_x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__LanePoints__right_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__LanePoints__right_x(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__LanePoints__right_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__LanePoints__right_x(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__LanePoints__right_x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__LanePoints__right_y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__LanePoints__right_y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__LanePoints__right_y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__LanePoints__right_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__LanePoints__right_y(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__LanePoints__right_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__LanePoints__right_y(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__LanePoints__right_y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LanePoints_message_member_array[4] = {
  {
    "left_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_lane_msgs::msg::LanePoints, left_x),  // bytes offset in struct
    nullptr,  // default value
    size_function__LanePoints__left_x,  // size() function pointer
    get_const_function__LanePoints__left_x,  // get_const(index) function pointer
    get_function__LanePoints__left_x,  // get(index) function pointer
    fetch_function__LanePoints__left_x,  // fetch(index, &value) function pointer
    assign_function__LanePoints__left_x,  // assign(index, value) function pointer
    resize_function__LanePoints__left_x  // resize(index) function pointer
  },
  {
    "left_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_lane_msgs::msg::LanePoints, left_y),  // bytes offset in struct
    nullptr,  // default value
    size_function__LanePoints__left_y,  // size() function pointer
    get_const_function__LanePoints__left_y,  // get_const(index) function pointer
    get_function__LanePoints__left_y,  // get(index) function pointer
    fetch_function__LanePoints__left_y,  // fetch(index, &value) function pointer
    assign_function__LanePoints__left_y,  // assign(index, value) function pointer
    resize_function__LanePoints__left_y  // resize(index) function pointer
  },
  {
    "right_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_lane_msgs::msg::LanePoints, right_x),  // bytes offset in struct
    nullptr,  // default value
    size_function__LanePoints__right_x,  // size() function pointer
    get_const_function__LanePoints__right_x,  // get_const(index) function pointer
    get_function__LanePoints__right_x,  // get(index) function pointer
    fetch_function__LanePoints__right_x,  // fetch(index, &value) function pointer
    assign_function__LanePoints__right_x,  // assign(index, value) function pointer
    resize_function__LanePoints__right_x  // resize(index) function pointer
  },
  {
    "right_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_lane_msgs::msg::LanePoints, right_y),  // bytes offset in struct
    nullptr,  // default value
    size_function__LanePoints__right_y,  // size() function pointer
    get_const_function__LanePoints__right_y,  // get_const(index) function pointer
    get_function__LanePoints__right_y,  // get(index) function pointer
    fetch_function__LanePoints__right_y,  // fetch(index, &value) function pointer
    assign_function__LanePoints__right_y,  // assign(index, value) function pointer
    resize_function__LanePoints__right_y  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LanePoints_message_members = {
  "my_lane_msgs::msg",  // message namespace
  "LanePoints",  // message name
  4,  // number of fields
  sizeof(my_lane_msgs::msg::LanePoints),
  LanePoints_message_member_array,  // message members
  LanePoints_init_function,  // function to initialize message memory (memory has to be allocated)
  LanePoints_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LanePoints_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LanePoints_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace my_lane_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_lane_msgs::msg::LanePoints>()
{
  return &::my_lane_msgs::msg::rosidl_typesupport_introspection_cpp::LanePoints_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_lane_msgs, msg, LanePoints)() {
  return &::my_lane_msgs::msg::rosidl_typesupport_introspection_cpp::LanePoints_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
