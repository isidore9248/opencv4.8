#include <opencv2/opencv.hpp>
#include "myScalar.h"

void myScalar::MyScalar_test(void)
{
	cv::Scalar Scalar_ch1(128);
	cv::Mat img_ch1(120, 240, CV_8UC1, Scalar_ch1);
	cv::imshow("pic1", img_ch1);

	cv::Scalar Scalar_ch2(128, 255, 255);
	//在图像进行转换时，会丢失精度，所以32位浮点类型一般用于处理深度图
	cv::Mat img_ch2(120, 240, CV_32FC3, Scalar_ch2);	//32位浮点类型
	cv::imshow("pic2", img_ch2);
}