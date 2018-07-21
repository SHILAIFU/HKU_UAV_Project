// Generated by gencpp from file octomap_msgs/GetOctomapRequest.msg
// DO NOT EDIT!


#ifndef OCTOMAP_MSGS_MESSAGE_GETOCTOMAPREQUEST_H
#define OCTOMAP_MSGS_MESSAGE_GETOCTOMAPREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace octomap_msgs
{
template <class ContainerAllocator>
struct GetOctomapRequest_
{
  typedef GetOctomapRequest_<ContainerAllocator> Type;

  GetOctomapRequest_()
    {
    }
  GetOctomapRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }






  typedef boost::shared_ptr< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetOctomapRequest_

typedef ::octomap_msgs::GetOctomapRequest_<std::allocator<void> > GetOctomapRequest;

typedef boost::shared_ptr< ::octomap_msgs::GetOctomapRequest > GetOctomapRequestPtr;
typedef boost::shared_ptr< ::octomap_msgs::GetOctomapRequest const> GetOctomapRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace octomap_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'octomap_msgs': ['/home/wsn/HKU_UAV_Project/guidancemap/src/octomap_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::octomap_msgs::GetOctomapRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "octomap_msgs/GetOctomapRequest";
  }

  static const char* value(const ::octomap_msgs::GetOctomapRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::octomap_msgs::GetOctomapRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetOctomapRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::octomap_msgs::GetOctomapRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::octomap_msgs::GetOctomapRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // OCTOMAP_MSGS_MESSAGE_GETOCTOMAPREQUEST_H
