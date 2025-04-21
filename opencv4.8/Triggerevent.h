#pragma once
class Triggerevent
{
public:
	static void mouseevent(cv::Mat& image);
	static void keyboardevents(cv::VideoCapture& VideoCapture);

private:
	static void mouse_callback(int event, int x, int y, int flags, void* userdata);
};
