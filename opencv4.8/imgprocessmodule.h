#pragma once
class imgprocessmodule
{
public:
	static void ColourSwitch(cv::Mat& image);

private:
	static void displayimage(std::string str, cv::Mat& image);
};
