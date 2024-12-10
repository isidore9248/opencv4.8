#pragma once
class Camera
{
public:
	void ShowCamera_picture(cv::VideoCapture& cap);
	void FaceDetect(cv::Mat& image);
private:
	void Camera_pictureprocessing(cv::Mat& image);
	void Camera_GetHSV(void);

	cv::Mat frame;
	cv::Mat mask_yellow;
};
