#include <opencv2/opencv.hpp>
#include "Triggerevent.h"

/// <summary> </summary>		设置鼠标事件回调函数
/// <param name="image"></param>
void Triggerevent::mouseevent(cv::Mat& image)
{
	cv::imshow("mouseevent", image);	//有图片才能进行获取事件
	//传递句柄的时候只需要传递与其关联的Mat对象
	cv::setMouseCallback("mouseevent", mouse_callback, &image);	//设置鼠标事件的回调函数
}

/// <summary> </summary>	使用显示视频，并且可以进行键盘操作
/// <param name="VideoCapture"></param>
void Triggerevent::keyboardevents(cv::VideoCapture& VideoCapture)
{
	cv::Mat frame;
	while (true)
	{
		VideoCapture >> frame;			//将视频帧保存到frame中
		if (frame.empty()) { break; }	//判断是否为空,即是否播放完成
		cv::imshow("Show Video", frame);//显示视频
		if (cv::waitKey(30) >= 0)		//等待30ms
			break;
	}
}

/// <summary></summary>				鼠标事件回调函数
/// <param name="event"></param>	鼠标事件，用于函数内使用，不需要传参时传递
/// <param name="flags"></param>	标志位，用于函数内使用，不需要传参时传递
/// <param name="userdata"></param>	与之关联的数据指针
void Triggerevent::mouse_callback(int event, int x, int y, int flags, void* userdata)
{
	static cv::Point pre_point, cur_point;
	static cv::Mat img = *(cv::Mat*)userdata;
	//鼠标左键按下
	//从当前点开始记录，如果没有，则显示为连接上次与当前所处坐标点
	if (event == cv::EVENT_LBUTTONDOWN)
	{
		pre_point = cv::Point(x, y);
		return;
	}
	if (event == cv::EVENT_MOUSEMOVE && flags == cv::EVENT_FLAG_LBUTTON)
	{
		cur_point = cv::Point(x, y);
		//cv::Mat目标对象	起始点		终止点		线的颜色
		cv::line(img, pre_point, cur_point, cv::Scalar(0, 0, 255), 4);
		cv::imshow("mouseevent", img);
		pre_point = cur_point;
	}
}