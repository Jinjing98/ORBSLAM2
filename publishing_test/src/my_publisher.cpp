
#include <ros/ros.h>                       
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>    //非常有用的功能包，实现ROS与OPENCV图像的转换

 







int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("/usb_cam/image_raw", 1);  //这里我们发布的主题要与ORB_SLAM节点订阅的话题一致
 
  ros::Rate loop_rate(18);
  for(int i = 0; i<1000; i++)  
  {
    if(!nh.ok())
        break;
    std::ostringstream stringStream;
    //stringStream << "/home/jinjing/Datasets/rgbd_dataset_freiburg1_xyz/rgb/" << i << ".png";//require the img name are ordered numbers,you can rename these batch imges in ubuntu.
    stringStream << argv[1]<<"/" << i << ".png";
    cv::Mat image = cv::imread(stringStream.str(), CV_LOAD_IMAGE_COLOR);
    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
 
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
 
 
}
