#pragma once
class Imagebasics
{
public:
	static void displayimage(std::string str, cv::Mat& image);
	static cv::Mat GetExampleMat(int rows, int cols, int value, int dims);
	static void PixelTraversal_subscript(cv::Mat& image);
	static void Pixel_arithmetic(cv::Mat& image, int type);
	static void trackbar_demo(cv::Mat& image);

private:
	static uchar Pixel_dosomething(int value);
	static void trackbar_callback(int, void*);
};
