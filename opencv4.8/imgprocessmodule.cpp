#include <opencv2/opencv.hpp>
#include "imgprocessmodule.h"

/// <summary> </summary>	对图像进行颜色转换，并使用得到的HSV图像进行颜色过滤
/// <param name="image"></param>
void imgprocessmodule::ColourSwitch(cv::Mat& image)
{
	cv::namedWindow("old", cv::WINDOW_AUTOSIZE);
	displayimage("old", image);

	//灰度
	cv::Mat gray_image;
	cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
	cv::namedWindow("gray", cv::WINDOW_AUTOSIZE);
	displayimage("gray", gray_image);

	//HSV
	cv::Mat hsv_image;
	cv::cvtColor(image, hsv_image, cv::COLOR_BGR2HSV);
	cv::namedWindow("hsv", cv::WINDOW_AUTOSIZE);
	displayimage("hsv", hsv_image);

	//对HSV图像过滤
	cv::Scalar red_lower(156, 43, 46);
	cv::Scalar red_upper(180, 255, 255);
	cv::Mat mask_red;
	cv::inRange(hsv_image, red_lower, red_upper, mask_red);
	cv::namedWindow("mask_red", cv::WINDOW_AUTOSIZE);
	cv::imshow("mask_red", mask_red);
}

void imgprocessmodule::displayimage(std::string str, cv::Mat& image)
{
	cv::Size newSize(640, 480);
	resize(image, image, newSize);
	cv::imshow(str, image);
}