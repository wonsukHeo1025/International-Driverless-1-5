// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_lane_msgs:msg/LanePoints.idl
// generated code does not contain a copyright notice

#ifndef MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__STRUCT_H_
#define MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'left_x'
// Member 'left_y'
// Member 'right_x'
// Member 'right_y'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/LanePoints in the package my_lane_msgs.
typedef struct my_lane_msgs__msg__LanePoints
{
  rosidl_runtime_c__float__Sequence left_x;
  rosidl_runtime_c__float__Sequence left_y;
  rosidl_runtime_c__float__Sequence right_x;
  rosidl_runtime_c__float__Sequence right_y;
} my_lane_msgs__msg__LanePoints;

// Struct for a sequence of my_lane_msgs__msg__LanePoints.
typedef struct my_lane_msgs__msg__LanePoints__Sequence
{
  my_lane_msgs__msg__LanePoints * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_lane_msgs__msg__LanePoints__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_LANE_MSGS__MSG__DETAIL__LANE_POINTS__STRUCT_H_
