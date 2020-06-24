#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
int main(int argc, char** argv)
{
    ros::init(argc, argv,"node_publisher");
    ros::NodeHandle nd;
    
    /*publish string msg, 100 is the catch queue*/
    ros::Publisher pub = nd.advertise<std_msgs::String>("mytest_msg", 100);
    /*10 Hz*/
    ros::Rate loop_rate(10);
    int cnt = 0; 
    while(ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "current:" << cnt;
        cnt++;
        
        msg.data = ss.str();
        pub.publish(msg);
        /*if some topics is subscribed,this is necessary*/
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}

