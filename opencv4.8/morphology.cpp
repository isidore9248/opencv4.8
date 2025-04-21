#include <opencv2/opencv.hpp>
#include "morphology.h"

void morphology::my_binaryzation(cv::Mat& image)
{
	//hresh：阈值（threshold value）。
	//像素值大于这一值会被转换为最大值（maxval），如下即为
	//而小于或等于这一值的像素值会被设置为 0（取决于阈值类型）。
	double thresh = 20.0;
	double maxval = 255.0;
	cv::threshold(image, image, thresh, maxval, cv::THRESH_BINARY);
}

/// <summary> </summary>		用于灰度图像的二值化，自适应阈值 适合光线不一致的情况，可自适应设置阈值。
/// <param name="image"></param>
void morphology::my_adaptivebinaryzation(cv::Mat& image)
{
	cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

	//maxValue - 转换成的最大值
	double maxValue = 255;
	//C - 常量，应从计算出的平均值或加权平均值中减去。
	double C = 11.0;
	//blockSize用于指定用于计算每个像素阈值的像素邻域的大小
	int blockSize = 11;
	cv::adaptiveThreshold(image, image, maxValue, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, blockSize, C);
}

void morphology::my_swell(cv::Mat& image)	//膨胀
{
	cv::Mat kernel = get_neighbour_pixel(image);
	cv::dilate(image, image, kernel);
}

void morphology::my_corrosion(cv::Mat& image)//腐蚀
{
	cv::Mat kernel = get_neighbour_pixel(image);
	cv::erode(image, image, kernel);
}

/// <summary></summary>			先腐蚀再膨胀，可去除非核心区域的噪点，如黑底白点
/// <param name="image"></param>
void morphology::my_open(cv::Mat& image)
{
	cv::Mat kernel = get_neighbour_pixel(image);
	cv::morphologyEx(image, image, cv::MORPH_OPEN, kernel);
}

void morphology::my_close(cv::Mat& image)
{
	cv::Mat kernel = get_neighbour_pixel(image);
	cv::morphologyEx(image, image, cv::MORPH_CLOSE, kernel);
}

void morphology::my_ExtractLine(cv::Mat& image)
{
	cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

	cv::adaptiveThreshold(image, image, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 15, -2);

	cv::imshow("sd", image);

	//int xsize = image.cols / 30.0;
	//int ysize = image.rows / 30.0;

	//cv::Mat horlines = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(xsize, 1));
	//cv::Mat veclines = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, ysize));

	//cv::Mat hbin;
	//cv::erode(image, hbin, horlines);
	//cv::dilate(hbin, hbin, horlines);
	//cv::imshow("hbin", hbin);
}

void morphology::my_Sobel(cv::Mat& image)
{
	cv::Sobel(image, image, CV_8U, 1, 1);
	cv::imshow("Original Image", image);
}

cv::Mat& morphology::get_neighbour_pixel(cv::Mat& image)
{
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5)); // 矩形结构元素
	// 圆形结构元素		cv::MORPH_ELLIPSE
	// 十字形结构元素	cv::MORPH_CROSS
	return kernel;
}