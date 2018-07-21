#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/PointCloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>  
#include <pcl/filters/voxel_grid.h>

#include <pcl/sample_consensus/model_types.h>  //分割模型的头文件
#include <pcl/sample_consensus/method_types.h> //采样一致性的方法
#include <pcl/segmentation/sac_segmentation.h> //ransac分割法
ros::Publisher pub;
ros::Publisher pub2;
int frame_id = 0;
sensor_msgs::PointCloud2ConstPtr msg_last;
pcl::PCLPointCloud2 *cloud_last = new pcl::PCLPointCloud2;
pcl::PCLPointCloud2 *cloud_null = new pcl::PCLPointCloud2;
void cloud_cb(const sensor_msgs::PointCloud2ConstPtr &cloud_msg)
{
    // Container for original & filtered data
    pcl::PCLPointCloud2 *cloud = new pcl::PCLPointCloud2;
    // // pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
    // // pcl::PCLPointCloud2 cloud_filtered;

    // // Convert to PCL data type
    pcl_conversions::toPCL(*cloud_msg, *cloud);
    // // Perform the actual filtering
    // // pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
    // // sor.setInputCloud(cloudPtr);
    // // sor.setLeafSize(0.1, 0.1, 0.1);
    // // sor.filter(cloud_filtered);
    // // Convert to ROS data type
    // sensor_msgs::PointCloud2 thismsg,output,last;
    sensor_msgs::PointCloud2 saved;
    pcl_conversions::moveFromPCL(*cloud, saved);
    // pcl_conversions::moveFromPCL(*cloud_last, last);
    // // Publish the data
    // // pub.publish(output);
    // // pcl::PointCloud<pcl::PointXYZ> pointcloud;
    // // sensor_msgs::PointCloud output;
    // pcl::concatenatePointCloud(thismsg,last,output);
    // pcl::PCLPointCloud2 cloud_temp;
    // // pcl::toROSMsg(pointcloud, output);
    frame_id ++;
    frame_id %= 5;
    // // ROS_INFO("get frame # %d",frame_id);
    // pcl_conversions::toPCL(output,cloud_temp);
    // pub2.publish(output);    
    // if(frame_id!=4)
        // *cloud_last = cloud_temp;
    // else
        // *cloud_last = *cloud_null;

    pcl::io::savePCDFile("../pcd_output/guidance_"+std::to_string(frame_id)+".pcd",saved);
    pub2.publish(saved);
}

int main(int argc, char **argv)
{
    // Initialize ROS
    ros::init(argc, argv, "pcl_saved");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2>("points", 1, cloud_cb);

    pub = nh.advertise<sensor_msgs::PointCloud>("output_PointCloud", 1);
    pub2 = nh.advertise<sensor_msgs::PointCloud2>("output_PointCloud2", 1);
    ros::spin();
}
