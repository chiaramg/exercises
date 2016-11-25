//
// Created by chiara on 22.11.16.
//

#include "ros/ros.h"
#include "std_msgs/Float32MultiArray.h"

#include <Eigen/Dense>


void chatterCallback(const std_msgs::Float32MultiArray::ConstPtr& my_array){


    std::cout << "Message received" << std::endl;
/*
    if(my_array == NULL){
        std::cout << "ooooups!! you're dealing with a null pointer!" << std::endl;
    }
    else{
        std::cout << "relax, it's not a null pointer" << std::endl;
    }
*/


    std::vector<float> temp = my_array->data;

/*
    std::cout << "my_array->data to vector temp worked" << std::endl;
*/

    Eigen::MatrixXf my_mat = Eigen::Map<Eigen::MatrixXf> (temp.data(), 6, 5);
/*
    std::cout << "EigenMatrix from vector temp worked" << std::endl;
*/

    std::cout << my_mat << std::endl;


/*
    int j;

    for(j=0; j<30; j++){


        std::cout << my_array->data[j] << "  ";
        if (j %6 ==0){
            std::cout << std::endl;
        }

    }
*/
/*
    std_msgs::Float32MultiArray new_array;
    new_array.data = my_array->data;

    ros::NodeHandle m;
    ros::Publisher React_pub = m.advertise<std_msgs::Float32MultiArray>("React", 100);
    ros::Rate loop_rate(10);

    while(ros::ok()) {

        React_pub.publish(new_array);

        ros::spinOnce();
        loop_rate.sleep();

    }
*/
}

int main(int argc, char **argv) {

    //Subscribe to talker:
    ros::init(argc, argv, "listen");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("chatter", 100, chatterCallback);

    ros::spin();

/*
    //Publish again to talker:

    std_msgs::Float32MultiArray new_array;
    new_array.data = my_array->data;

    ros::init(argc, argv, "ReactToMatrix");
    ros::Publisher React_pub = n.advertise<std_msgs::Float32MultiArray>("React", 100);
    ros::Rate loop_rate(10);

    while(ros::ok()) {

        React_pub.publish(new_array);

        ros::spinOnce();
        loop_rate.sleep();

    }
*/

    return 0;
}