// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_lane_msgs:msg/LanePoints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_lane_msgs/msg/detail/lane_points__rosidl_typesupport_introspection_c.h"
#include "my_lane_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_lane_msgs/msg/detail/lane_points__functions.h"
#include "my_lane_msgs/msg/detail/lane_points__struct.h"


// Include directives for member types
// Member `left_x`
// Member `left_y`
// Member `right_x`
// Member `right_y`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_lane_msgs__msg__LanePoints__init(message_memory);
}

void my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_fini_function(void * message_memory)
{
  my_lane_msgs__msg__LanePoints__fini(message_memory);
}

size_t my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__size_function__LanePoints__left_x(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__left_x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__left_x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__fetch_function__LanePoints__left_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__left_x(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__assign_function__LanePoints__left_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__left_x(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__resize_function__LanePoints__left_x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__size_function__LanePoints__left_y(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__left_y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__left_y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__fetch_function__LanePoints__left_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__left_y(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__assign_function__LanePoints__left_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__left_y(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__resize_function__LanePoints__left_y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__size_function__LanePoints__right_x(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__right_x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__right_x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__fetch_function__LanePoints__right_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__right_x(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__assign_function__LanePoints__right_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__right_x(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__resize_function__LanePoints__right_x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__size_function__LanePoints__right_y(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__right_y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__right_y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__fetch_function__LanePoints__right_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__right_y(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__assign_function__LanePoints__right_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__right_y(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__resize_function__LanePoints__right_y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_message_member_array[4] = {
  {
    "left_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_lane_msgs__msg__LanePoints, left_x),  // bytes offset in struct
    NULL,  // default value
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__size_function__LanePoints__left_x,  // size() function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__left_x,  // get_const(index) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__left_x,  // get(index) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__fetch_function__LanePoints__left_x,  // fetch(index, &value) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__assign_function__LanePoints__left_x,  // assign(index, value) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__resize_function__LanePoints__left_x  // resize(index) function pointer
  },
  {
    "left_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_lane_msgs__msg__LanePoints, left_y),  // bytes offset in struct
    NULL,  // default value
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__size_function__LanePoints__left_y,  // size() function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__left_y,  // get_const(index) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__left_y,  // get(index) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__fetch_function__LanePoints__left_y,  // fetch(index, &value) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__assign_function__LanePoints__left_y,  // assign(index, value) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__resize_function__LanePoints__left_y  // resize(index) function pointer
  },
  {
    "right_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_lane_msgs__msg__LanePoints, right_x),  // bytes offset in struct
    NULL,  // default value
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__size_function__LanePoints__right_x,  // size() function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__right_x,  // get_const(index) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__right_x,  // get(index) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__fetch_function__LanePoints__right_x,  // fetch(index, &value) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__assign_function__LanePoints__right_x,  // assign(index, value) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__resize_function__LanePoints__right_x  // resize(index) function pointer
  },
  {
    "right_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_lane_msgs__msg__LanePoints, right_y),  // bytes offset in struct
    NULL,  // default value
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__size_function__LanePoints__right_y,  // size() function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_const_function__LanePoints__right_y,  // get_const(index) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__get_function__LanePoints__right_y,  // get(index) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__fetch_function__LanePoints__right_y,  // fetch(index, &value) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__assign_function__LanePoints__right_y,  // assign(index, value) function pointer
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__resize_function__LanePoints__right_y  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_message_members = {
  "my_lane_msgs__msg",  // message namespace
  "LanePoints",  // message name
  4,  // number of fields
  sizeof(my_lane_msgs__msg__LanePoints),
  my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_message_member_array,  // message members
  my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_init_function,  // function to initialize message memory (memory has to be allocated)
  my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_message_type_support_handle = {
  0,
  &my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_lane_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_lane_msgs, msg, LanePoints)() {
  if (!my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_message_type_support_handle.typesupport_identifier) {
    my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_lane_msgs__msg__LanePoints__rosidl_typesupport_introspection_c__LanePoints_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
