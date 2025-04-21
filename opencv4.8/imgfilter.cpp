#include <opencv2/opencv.hpp>
#include "imgfilter.h"

void imgfilter::my_GaussianBlur(cv::Mat& image)
{
	cv::GaussianBlur(image, image, cv::Size(11, 11), 1.5);
	displayimage("Gauss", image);
}

void imgfilter::my_boxFilter(cv::Mat& image)
{
	cv::boxFilter(image, image, -1, cv::Size(5, 5));
	displayimage("box", image);
}

void imgfilter::my_blur(cv::Mat& image)
{
	blur(image, image, cv::Size(5, 5));
	displayimage("blur", image);
}

void imgfilter::my_bilarter(cv::Mat& image)
{
	//cv::bilateralFilter(image, image, 9, 75, 75);
	//displayimage("bilarter", image);
}

void imgfilter::displayimage(std::string str, cv::Mat& image)
{
	cv::Size newSize(640, 480);
	resize(image, image, newSize);
	cv::imshow(str, image);
}