// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_lane_msgs:msg/LanePoints.idl
// generated code does not contain a copyright notice
#include "my_lane_msgs/msg/detail/lane_points__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_lane_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_lane_msgs/msg/detail/lane_points__struct.h"
#include "my_lane_msgs/msg/detail/lane_points__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // left_x, left_y, right_x, right_y
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // left_x, left_y, right_x, right_y

// forward declare type support functions


using _LanePoints__ros_msg_type = my_lane_msgs__msg__LanePoints;

static bool _LanePoints__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LanePoints__ros_msg_type * ros_message = static_cast<const _LanePoints__ros_msg_type *>(untyped_ros_message);
  // Field name: left_x
  {
    size_t size = ros_message->left_x.size;
    auto array_ptr = ros_message->left_x.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: left_y
  {
    size_t size = ros_message->left_y.size;
    auto array_ptr = ros_message->left_y.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_x
  {
    size_t size = ros_message->right_x.size;
    auto array_ptr = ros_message->right_x.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: right_y
  {
    size_t size = ros_message->right_y.size;
    auto array_ptr = ros_message->right_y.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _LanePoints__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LanePoints__ros_msg_type * ros_message = static_cast<_LanePoints__ros_msg_type *>(untyped_ros_message);
  // Field name: left_x
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_x.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_x);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_x, size)) {
      fprintf(stderr, "failed to create array for field 'left_x'");
      return false;
    }
    auto array_ptr = ros_message->left_x.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: left_y
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->left_y.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->left_y);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->left_y, size)) {
      fprintf(stderr, "failed to create array for field 'left_y'");
      return false;
    }
    auto array_ptr = ros_message->left_y.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_x
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_x.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_x);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_x, size)) {
      fprintf(stderr, "failed to create array for field 'right_x'");
      return false;
    }
    auto array_ptr = ros_message->right_x.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: right_y
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->right_y.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->right_y);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->right_y, size)) {
      fprintf(stderr, "failed to create array for field 'right_y'");
      return false;
    }
    auto array_ptr = ros_message->right_y.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_lane_msgs
size_t get_serialized_size_my_lane_msgs__msg__LanePoints(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LanePoints__ros_msg_type * ros_message = static_cast<const _LanePoints__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name left_x
  {
    size_t array_size = ros_message->left_x.size;
    auto array_ptr = ros_message->left_x.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_y
  {
    size_t array_size = ros_message->left_y.size;
    auto array_ptr = ros_message->left_y.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_x
  {
    size_t array_size = ros_message->right_x.size;
    auto array_ptr = ros_message->right_x.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name right_y
  {
    size_t array_size = ros_message->right_y.size;
    auto array_ptr = ros_message->right_y.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LanePoints__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_lane_msgs__msg__LanePoints(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_lane_msgs
size_t max_serialized_size_my_lane_msgs__msg__LanePoints(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: left_x
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_y
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_x
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: right_y
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_lane_msgs__msg__LanePoints;
    is_plain =
      (
      offsetof(DataType, right_y) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _LanePoints__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_lane_msgs__msg__LanePoints(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LanePoints = {
  "my_lane_msgs::msg",
  "LanePoints",
  _LanePoints__cdr_serialize,
  _LanePoints__cdr_deserialize,
  _LanePoints__get_serialized_size,
  _LanePoints__max_serialized_size
};

static rosidl_message_type_support_t _LanePoints__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LanePoints,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_lane_msgs, msg, LanePoints)() {
  return &_LanePoints__type_support;
}

#if defined(__cplusplus)
}
#endif
