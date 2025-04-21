#include <opencv2/opencv.hpp>
#include <vector>
#include "Camera.h"

void Camera::ShowCamera_picture(cv::VideoCapture& cap)
{
	cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
	if (!cap.isOpened())
	{
		std::cerr << "open error" << std::endl;
		return;
	}
	// 设置窗口名称
	const std::string windowName = "Camera Feed";
	cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);

	while (true)
	{
		cap >> frame;  // 从摄像头读取一帧画面

		// 检查是否成功捕获画面
		if (frame.empty())
		{
			std::cerr << "捕获画面失败" << std::endl;
			break;
		}

		//cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
		//Camera_pictureprocessing(frame);
		FaceDetect(frame);

		imshow(windowName, frame);  // 在窗口中显示画面
		if (cv::waitKey(30) >= 0) return;  // 每 30ms 检查一次按键，任意键退出
	}
}

void Camera::FaceDetect(cv::Mat& image)
{
	cv::CascadeClassifier face_model;
	std::string face_model_path = "E:/opencv/install4.8/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
	if (!face_model.load(face_model_path)) { return; }
	std::vector<cv::Rect> faces;
	face_model.detectMultiScale(image, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

	for (const auto& face : faces) {
		cv::rectangle(image, face, cv::Scalar(255, 0, 0), 2); // 蓝色矩形框
	}
}

void Camera::Camera_pictureprocessing(cv::Mat& image)
{
	Camera_GetHSV();

	cv::imshow("HSV", mask_yellow);  // 显示掩码
}

void Camera::Camera_GetHSV(void)
{
	cv::Mat hsv_image;

	cv::cvtColor(frame, hsv_image, cv::COLOR_BGR2HSV);  // 转换为HSV

	cv::Scalar yellow_lower(29, 23, 157);
	cv::Scalar yellow_upper(53, 255, 255);
	cv::inRange(hsv_image, yellow_lower, yellow_upper, mask_yellow);  // 创建掩码
}