#include <opencv2/opencv.hpp>
#include "Imagebasics.h"

void Imagebasics::displayimage(std::string str, cv::Mat& image)
{
	cv::Size newSize(640, 480);
	resize(image, image, newSize);
	cv::imshow(str, image);
	//cv::waitKey(0);
}

/// <summary></summary>
/// <param name="rows"></param>	图像的排
/// <param name="cols"></param>	图像的列
/// <param name="value"></param>初始化为1或0
/// <param name="dims"></param>	图像维度（1~3）
/// <returns></returns>			得到的图像引用
cv::Mat Imagebasics::GetExampleMat(int rows, int cols, int value, int dims)
{
	cv::Mat image;
	uchar type;
	if (dims == 1) { type = CV_8UC1; }
	else if (dims == 3) { type = CV_8UC3; }

	if (value)
	{
		image = cv::Mat::ones(rows, cols, type);
		return image;
	}
	image = cv::Mat::zeros(rows, cols, type);
	return image;
}

/// <summary></summary>			通过下标访问Mat矩阵像素值
/// <param name="image"></param>
void Imagebasics::PixelTraversal_subscript(cv::Mat& image)
{
	int wide = image.cols;		//列--x
	int height = image.rows;	//排--y
	int dims = image.channels();//通道数
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < wide; col++)
		{
			if (dims == 1)
			{
				int pv = image.at<uchar>(row, col);	//at方法访问第row行,第col列的像素值
				image.at<uchar>(row, col) = Imagebasics::Pixel_dosomething(pv);
			}
			if (dims == 3)
			{
				cv::Vec3b bgr = image.at<cv::Vec3b>(row, col);
				image.at<cv::Vec3b>(row, col)[0] = Imagebasics::Pixel_dosomething(bgr[0]);
				image.at<cv::Vec3b>(row, col)[1] = Imagebasics::Pixel_dosomething(bgr[1]);
				image.at<cv::Vec3b>(row, col)[2] = Imagebasics::Pixel_dosomething(bgr[2]);
			}
		}
	}
}

/// <summary> </summary>		对每个像素点的像素值进行操作
/// <param name="image"></param>
/// <param name="type"></param>	运算类型 1--4	分别对应 加、减、乘、除
void Imagebasics::Pixel_arithmetic(cv::Mat& image, int type)
{
	cv::Mat m = cv::Mat::zeros(image.size(), image.type());
	m = cv::Scalar(50, 50, 50);
	//	加数	加数	和
	if (type == 1) { cv::add(image, m, image); return; }
	if (type == 2) { cv::subtract(image, m, image); return; }
	if (type == 3) { cv::multiply(image, m, image); return; }
	if (type == 4) { cv::divide(image, m, image); return; }
}

cv::Mat src, dst, m;
int lightness = 50;
void Imagebasics::trackbar_demo(cv::Mat& image)
{
	//cv::WINDOW_AUTOSIZE:窗口的大小将根据图像的实际大小来决定
	//避免出现关闭或拉伸的效果，使得图像不会被变形。
	cv::namedWindow("trackbar_demo", cv::WINDOW_AUTOSIZE);		//创建一个窗口
	dst = cv::Mat::zeros(image.size(), image.type());
	m = cv::Mat::zeros(image.size(), image.type());
	src = image;
	int max_value = 100;

	/// @name  :cv::createTrackbar
	/// @brief :在名为 "trackbar_demo" 的窗口中创建一个滑动条（trackbar）
	/// @param :"lightness":		滑动条的名称
	/// @param :"trackbar_demo": 滑动条将被添加到的窗口的名称
	/// @param :&lightness:		这是指向要与滑动条关联的变量的指针。
	///							当用户操作滑动条时，lightness 的值会自动更新。
	/// @param :max_value		这是滑动条的最大值。用户可以通过滑动条
	///							将 lightness 的值调整在 0 到 100 之间。
	/// @param :trackbar_callback: 这是一个回调函数指针，当滑动条的值发生变化时
	/// 							这个回调函数会被调用，以执行相关操作。
	cv::createTrackbar("lightness", "trackbar_demo", &lightness, max_value, trackbar_callback);
	trackbar_callback(50, 0);	//在用户调用前做一些初始化工作
}

uchar Imagebasics::Pixel_dosomething(int value)
{
	return uchar(255 - value);
}

void Imagebasics::trackbar_callback(int, void*)
{
	m = cv::Scalar(lightness, lightness, lightness);
	add(src, m, dst);
	cv::imshow("trackbar_demo", dst);
}