#pragma once
class morphology
{
public:
	static void my_binaryzation(cv::Mat& image);
	static void my_adaptivebinaryzation(cv::Mat& image);//自适应阈值 适合光线不一致的情况，可自适应设置阈值
	static void my_swell(cv::Mat& image);		//膨胀
	static void my_corrosion(cv::Mat& image);	//腐蚀
	static void my_open(cv::Mat& image);	//开运算：可去除非核心区域的噪点，如黑底白点
	static void my_close(cv::Mat& image);	//闭运算：可去除核心区域的噪点，如白底黑点
	static void my_gradient(cv::Mat& image);
	static void my_ExtractLine(cv::Mat& image);
	static void my_Sobel(cv::Mat& image);
private:
	static cv::Mat& get_neighbour_pixel(cv::Mat& image);
};
