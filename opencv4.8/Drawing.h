#pragma once
class Drawing
{
public:
	static void DrawRectangle(cv::Mat& image);
	static void DrawCircle(cv::Mat& image);
	static void DrawEllipse(cv::Mat& image);
	static void DrawPolygon(cv::Mat& image);
	static void DrawROI(cv::Mat& image);
	static void DrawText(cv::Mat& image);

private:
	static void displayimage(std::string str, cv::Mat& image);
};
