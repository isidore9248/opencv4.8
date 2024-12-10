#include <opencv2/opencv.hpp>
#include "Drawing.h"
#include <vector>
/*
----------->X
|
|
|
|
|
v
Y
*/

void Drawing::DrawRectangle(cv::Mat& image)
{
	//	左上角顶点坐标	_width  _height
	cv::Rect rect(10, 30, 600, 200);//创建一个矩形对象

	//		目标图片	矩形对象	颜色	     线宽（-1时为填充）
	cv::rectangle(image, rect, cv::Scalar(0, 0, 255), 3);//绘制函数1
	//			目标图片	左上角顶点		右下角顶点			颜色		线宽（-1时为填充）
	cv::rectangle(image, cv::Point(20, 50), cv::Point(400, 600), cv::Scalar(0, 0, 255), -1);//绘制函数2

	displayimage("rectangle", image);
}

void Drawing::DrawCircle(cv::Mat& image)
{
	cv::circle(image, cv::Point(100, 100), 46, cv::Scalar(255, 0, 255), 4);
	displayimage("circle", image);
}

void Drawing::DrawEllipse(cv::Mat& image)
{
	//			目标图片	中心点坐标		长轴和短轴长度	旋转角度 开始角度 结束角度	颜色	线宽
	cv::ellipse(image, cv::Point(600, 300), cv::Size(300, 150), 0, 0, 360, cv::Scalar(255, 35, 1), 3);
	//当起始角度和终止角度不到360时，可以画出弧线

	displayimage("Ellipse", image);
}

void Drawing::DrawPolygon(cv::Mat& image)
{
	//填充的多边形
	std::vector<cv::Point> fillpoint;
	fillpoint.push_back(cv::Point(100, 400));
	fillpoint.push_back(cv::Point(300, 400));
	fillpoint.push_back(cv::Point(700, 600));
	fillpoint.push_back(cv::Point(500, 600));
	cv::fillPoly(image, fillpoint, cv::Scalar(124, 25, 57));
	//displayimage("fillpoint", image);

	//非填充的多边形
	std::vector<cv::Point> linepoint;
	linepoint.push_back(cv::Point(400, 700));
	linepoint.push_back(cv::Point(700, 700));
	linepoint.push_back(cv::Point(600, 900));
	linepoint.push_back(cv::Point(300, 900));
	cv::polylines(image, linepoint, true, cv::Scalar(255, 0, 255), 2);
	displayimage("polylines", image);
}

void Drawing::DrawROI(cv::Mat& image)
{
	std::vector<cv::Point> linepoint;
	linepoint.push_back(cv::Point(400, 700));
	linepoint.push_back(cv::Point(600, 400));
	linepoint.push_back(cv::Point(600, 900));
	linepoint.push_back(cv::Point(100, 600));
	//cv::polylines(image, linepoint, true, cv::Scalar(255, 0, 255), 1);
	//displayimage("polylines", image);

	//创建掩饰图片对象
	cv::Mat mask;
	image.copyTo(mask);
	mask.setTo(cv::Scalar::all(0));	//将掩模设置为全黑
	cv::fillPoly(mask, linepoint, cv::Scalar(255, 255, 255));	//填充多边形，选中的部分非黑
	//cv::imshow("mask", mask);
	//displayimage("mask", mask);

	cv::Mat dst;
	image.copyTo(dst, mask);	//将image和mask相乘，得到ROI
	displayimage("ROI", dst);
}

void Drawing::DrawText(cv::Mat& image)
{
	std::string str("TEXT");

	//		目标图片 文本内容	文本位置左下角坐标		字体			字体大小	颜色			线宽
	cv::putText(image, str, cv::Point(200, 400), cv::FONT_HERSHEY_COMPLEX, 4.0, cv::Scalar(24, 236, 35), 3);
	displayimage("TEXT", image);
}

void Drawing::displayimage(std::string str, cv::Mat& image)
{
	cv::Size newSize(640, 480);
	resize(image, image, newSize);
	cv::imshow(str, image);
}