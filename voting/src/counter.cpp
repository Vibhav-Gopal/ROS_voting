#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <iostream>
#include <cstdio>
#include  <bits/stdc++.h>
#include <string>
int r=0,g=0,v=0;
void chatterCallback(const std_msgs::String::ConstPtr& msg){
	
  /*  std::cout<<"A says: "<<(msg->data.c_str());
    std::cout<<"\n";*/

    if ((msg->data) == "R")
    r++;
    else if((msg->data) == "G")
    g++;
    else if ((msg->data) == "V")
    v++;
    else if((msg->data) == "password123")
    {
        std::cout<<"Voting has been terminated, the final results are as follows\nR : "<<r<< "\nG : "<<g<<"\nV : "<< v << std::endl;
        exit(0);
    }
    else{
    std::cout <<"Illegal input received, voting terminated\n";
    exit(0);
    }
    std::cout <<"R : "<<r<<" G : "<<g<<" V : "<<v<<std::endl;
    
}
int main(int argc, char **argv){

	ros::init(argc, argv, "counter");


	ros::NodeHandle nr;

	ros::Subscriber sub = nr.subscribe("input", 1000, chatterCallback);

	ros::spin();

	return 0;
}