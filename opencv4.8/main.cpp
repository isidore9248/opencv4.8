#include <opencv2/opencv.hpp>
#include "Imagebasics.h"
#include "Triggerevent.h"
#include "imgprocessmodule.h"
#include "myScalar.h"
#include "Drawing.h"
#include "imgfilter.h"
#include "Camera.h"
#include "morphology.h"

//cv::Mat img_track1 = cv::imread("C:/Users/isidore/Desktop/yello.jpg");
//cv::Mat img_track2 = cv::imread("C:/Users/isidore/Desktop/Track2.jpg");
//
//cv::Mat img1 = cv::imread("C:/Users/isidore/Desktop/line.jpg");
//cv::Mat img2 = cv::imread("C:/Users/isidore/Desktop/1.jpg");
//cv::VideoCapture cap1("C:/Users/isidore/Desktop/QQ202432-215515.mp4");

void Camera_test(void);

int main()
{
	//morphology::my_Sobel(img_track2);
	Camera_test();
	cv::waitKey(0);
	return 0;
}

void Camera_test(void)
{
	cv::VideoCapture cap(0);
	Camera mycamera;
	mycamera.ShowCamera_picture(cap);
}