
#include <ros/ros.h>                       
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>    //非常有用的功能包，实现ROS与OPENCV图像的转换

 







int main(int argc, char** argv)
{
  ros::init(argc, argv, "RGBD_image_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub_RGB = it.advertise("/camera/rgb/image_raw", 1);  //这里我们发布的主题要与ORB_SLAM节点订阅的话题一致
  image_transport::Publisher pub_D = it.advertise("/camera/depth_registered/image_raw", 1); 
  ros::Rate loop_rate(5);
  for(int i = 0; i<1000; i++)  
  {
    if(!nh.ok())
        break;
    std::ostringstream stringStream_RGB;
    std::ostringstream stringStream_D;
    stringStream_RGB << "/home/jinjing/Datasets/rgbd_dataset_freiburg1_xyz/rgb/" << i << ".png";//require the img name are ordered numbers,you can rename these batch imges in ubuntu.
    stringStream_D << "/home/jinjing/Datasets/rgbd_dataset_freiburg1_xyz/depth/" << i << ".png";
    cv::Mat image_RGB = cv::imread(stringStream_RGB.str(), CV_LOAD_IMAGE_COLOR);
    sensor_msgs::ImagePtr msg_RGB = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image_RGB).toImageMsg();
    pub_RGB.publish(msg_RGB);

    cv::Mat image_D = cv::imread(stringStream_D.str(), CV_LOAD_IMAGE_COLOR);
    sensor_msgs::ImagePtr msg_D = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image_D).toImageMsg();
    pub_D.publish(msg_D);

    ros::spinOnce();
    loop_rate.sleep();
  }
 
 
}
