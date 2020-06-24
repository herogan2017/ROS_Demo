#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
/*msg callback function*/
void msgCallBack(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("info: [%s]", msg->data.c_str());
}
int main(int argc, char** argv)
{
    ros::init(argc, argv,"node_subscriber");
    ros::NodeHandle nd;
    
    /*publish string msg, 100 is the catch queue*/
    ros::Subscriber sub = nd.subscribe("mytest_msg", 100, msgCallBack);
    ros::spin();
    return 0;
}

