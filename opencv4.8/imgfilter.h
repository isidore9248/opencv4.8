#pragma once
class imgfilter
{
public:
	static void my_GaussianBlur(cv::Mat& image);
	static void my_boxFilter(cv::Mat& image);
	static void my_blur(cv::Mat& image);	//均值滤波，size越大越模糊
	static void my_bilarter(cv::Mat& image);
private:
	static void displayimage(std::string str, cv::Mat& image);
};
