#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <iostream>
#include <cstdio>
#include  <bits/stdc++.h>
#include <string>
using namespace std;

int main(int argc, char **argv){
    
    ros::init(argc,argv,"input");
    ros::NodeHandle nh;
    ROS_INFO_STREAM("Hello");
    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("input", 1000);
    ros::Rate loop_rate(10);
    cout<<"Input has been initiated"<<endl;
    int count = 0;
        while (ros::ok()){
            std_msgs::String counts;
            /*std::stringstream ss;
            ss << "hello world " << count;
            msg.data = ss.str();
            ROS_INFO("%s", msg.data.c_str());*/

            std::string vote;
            std::cout<<"Cast your vote\nEnter \"R\" for Raj \nEnter \"V\" for Vijay\nEnter \"G\" Gordon"<<endl;
            
            std::getline (std::cin,vote);
            cout<<endl;
            
            counts.data = vote;
            chatter_pub.publish(counts);
            if (vote == "password123")
            {
            cout<<"Voting has closed"<<endl;
            exit(0);
            }
		
        cout<<"Your Vote has been cast"<<endl;

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}
    return 0;
}