//
// Created by chiara on 22.11.16.
//


#include "ros/ros.h"

//#include "std_msgs/String.h"

#include "std_msgs/Float32MultiArray.h"
#include <Eigen/Dense>

//#include <sstream>


void reactionCallback(const std_msgs::Float32MultiArray::ConstPtr& new_array){


    std::cout << "I got a reaction from the listener" << std::endl;


    std::vector<float> temp = new_array->data;


    Eigen::MatrixXf new_mat = Eigen::Map<Eigen::MatrixXf> (temp.data(), 6, 5);


    std::cout << "the new matrix is: " << std::endl << new_mat << std::endl;

}


int main(int argc, char **argv){

    ros::init(argc, argv, "publishMatrix");

    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::Float32MultiArray>("chatter", 100);

    ros::Rate loop_rate(10);


    // create eigen::matrix

    Eigen::MatrixXf eig_matrix(6,5);

    for(int i=0; i<6; i++){
        for(int j=0; j<5; j++){
            eig_matrix(i, j) = i*5+j;
        }
    }


    //std::cout << eig_matrix;

    std_msgs::Float32MultiArray my_array;


    //std::cout << my_array.data << std::endl;

    //std::cout << my_array.data;


    my_array.data.clear();

    for (int i = 0; i < 6; i++) {
       for(int j = 0; j<5; j++) {
            my_array.data.push_back(eig_matrix(i, j));
        }
    }

/*//WORKING:
    my_array.data.clear();
    //for loop, pushing data in the size of the array
    for (int i = 0; i < 30; i++) {
        my_array.data.push_back(i);
    }
*/


/*
    ros::NodeHandle m;
*/


    while(ros::ok()) {

        chatter_pub.publish(my_array);



        ros::spinOnce();
        loop_rate.sleep();

    }
/*
    ros::Subscriber sub = m.subscribe("React", 100, reactionCallback);
*/


    //ros::spin();



    return 0;

}