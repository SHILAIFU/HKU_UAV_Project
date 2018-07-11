// Generated by gencpp from file dji_sdk/MissionWpGetSpeedResponse.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_MISSIONWPGETSPEEDRESPONSE_H
#define DJI_SDK_MESSAGE_MISSIONWPGETSPEEDRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dji_sdk
{
template <class ContainerAllocator>
struct MissionWpGetSpeedResponse_
{
  typedef MissionWpGetSpeedResponse_<ContainerAllocator> Type;

  MissionWpGetSpeedResponse_()
    : speed(0.0)
    , cmd_set(0)
    , cmd_id(0)
    , ack_data(0)  {
    }
  MissionWpGetSpeedResponse_(const ContainerAllocator& _alloc)
    : speed(0.0)
    , cmd_set(0)
    , cmd_id(0)
    , ack_data(0)  {
  (void)_alloc;
    }



   typedef float _speed_type;
  _speed_type speed;

   typedef uint8_t _cmd_set_type;
  _cmd_set_type cmd_set;

   typedef uint8_t _cmd_id_type;
  _cmd_id_type cmd_id;

   typedef uint32_t _ack_data_type;
  _ack_data_type ack_data;




  typedef boost::shared_ptr< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> const> ConstPtr;

}; // struct MissionWpGetSpeedResponse_

typedef ::dji_sdk::MissionWpGetSpeedResponse_<std::allocator<void> > MissionWpGetSpeedResponse;

typedef boost::shared_ptr< ::dji_sdk::MissionWpGetSpeedResponse > MissionWpGetSpeedResponsePtr;
typedef boost::shared_ptr< ::dji_sdk::MissionWpGetSpeedResponse const> MissionWpGetSpeedResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dji_sdk

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'dji_sdk': ['/home/wsn/HKU_UAV_Project/catkin_ws/src/Onboard-SDK-ROS/dji_sdk/msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "24b8cc8834f9763e3d1c641b02dfffb4";
  }

  static const char* value(const ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x24b8cc8834f9763eULL;
  static const uint64_t static_value2 = 0x3d1c641b02dfffb4ULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_sdk/MissionWpGetSpeedResponse";
  }

  static const char* value(const ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 speed\n\
\n\
uint8 cmd_set\n\
uint8 cmd_id\n\
uint32 ack_data\n\
";
  }

  static const char* value(const ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.speed);
      stream.next(m.cmd_set);
      stream.next(m.cmd_id);
      stream.next(m.ack_data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MissionWpGetSpeedResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_sdk::MissionWpGetSpeedResponse_<ContainerAllocator>& v)
  {
    s << indent << "speed: ";
    Printer<float>::stream(s, indent + "  ", v.speed);
    s << indent << "cmd_set: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cmd_set);
    s << indent << "cmd_id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cmd_id);
    s << indent << "ack_data: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.ack_data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_SDK_MESSAGE_MISSIONWPGETSPEEDRESPONSE_H
