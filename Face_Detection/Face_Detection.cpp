// Face_Detection.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

/*#include<stdio.h>
#include<math.h>
#include<opencv\cv.h>
#include<opencv\highgui.h>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<vector>
#include<opencv2\core\core.hpp>
#include<opencv2\opencv.hpp>
#include "Face_rec.h"

using namespace cv;
using namespace std;

int main()
{
	CascadeClassifier face_cascade, eye_cascade, profileface_cascade;
	if (!face_cascade.load("c:\\haar\\haarcascade_frontalface_alt2.xml")) {
		printf("Error loading cascade file for face");
		return 1;
	}
	if (!eye_cascade.load("c:\\haar\\haarcascade_eye.xml")) {
		printf("Error loading cascade file for eye");
		return 1;
	}
	if (!profileface_cascade.load("c:\\haar\\haarcascade_profileface.xml")) {
		printf("Error loading cascade file for profile face");
		return 1;
	}
	VideoCapture capture(0);
	if (!capture.isOpened()) {
		printf("Error in initializing camera");
		return 1;
	}
	Mat cap_img, gray_img;
	vector<Rect> faces, eyes, profile;
	while (1) {
		capture >> cap_img;
		waitKey(10);
		cvtColor(cap_img, gray_img, CV_BGR2GRAY);
		equalizeHist(gray_img, gray_img);
		face_cascade.detectMultiScale(gray_img, faces, 1.1, 10, CV_HAAR_SCALE_IMAGE | CV_HAAR_DO_CANNY_PRUNING, CvSize(0.0), cvSize(500, 500));
		for (int i = 0; i < faces.size(); i++) {
			Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
			Point pt2(faces[i].x, faces[i].y);
			Mat faceROI = gray_img(faces[i]);
			eye_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
			for (size_t j = 0; j < eyes.size(); j++) {
				Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
				int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
				circle(cap_img, center, radius, Scalar(255, 200, 100), 1, 8, 0);
			}
			rectangle(cap_img, pt1, pt2, cvScalar(100, 200, 100), 1, 8, 0);
		}
		imshow("Video_Feed", cap_img);
		waitKey(3);
		char c = waitKey(3);
		if (c == 27)
			break;
	}
	
	return 0;
}*/
/*
#include "VideoCap.h"

#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include "opencv2\objdetect\objdetect.hpp"
#include <opencv2\opencv.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;


int FaceDetector(string &classifier) {

	//haarcascade_frontalface_alt2
	//string face = "C:/opencv/sources/data/lbpcascades/lbpcascade_frontalface.xml";

	CascadeClassifier face_cascade;
	string window = "Capture - face detection";

	if (!face_cascade.load(classifier)) {
		cout << " Error loading file" << endl;
		return -1;
	}

	VideoCapture cap(0);
	//VideoCapture cap("C:/Users/lsf-admin/Pictures/Camera Roll/video000.mp4");

	if (!cap.isOpened())
	{
		cout << "exit" << endl;
		return -1;
	}

	//double fps = cap.get(CV_CAP_PROP_FPS);
	//cout << " Frames per seconds " << fps << endl;
	namedWindow(window, 1);
	long count = 0;

	string name = "vikum";
	while (true)
	{
		vector<Rect> faces;
		Mat frame;
		Mat graySacleFrame;
		Mat cropImg;

		cap >> frame;
		//cap.read(frame);
		count = count + 1;//count frames;

		if (!frame.empty()) {

			//convert image to gray scale and equalize
			//cvtColor(frame, graySacleFrame, CV_BGR2GRAY);
			//equalizeHist(graySacleFrame, graySacleFrame);

			face_cascade.detectMultiScale(frame, faces, 1.1, 3, 0, cv::Size(190, 190), cv::Size(200, 200));

			cout << faces.size() << " faces detected" << endl;
			std::string frameset = std::to_string(count);
			std::string faceset = std::to_string(faces.size());

			int width = 0, height = 0;

			//region of interest
			cv::Rect roi;

			for (int i = 0; i < faces.size(); i++)
			{
				rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(255, 0, 255), 1, 8, 0);
				cout << faces[i].width << faces[i].height << endl;
				width = faces[i].width; height = faces[i].height;

				//select the roi
				roi.x = faces[i].x; roi.width = faces[i].width;
				roi.y = faces[i].y; roi.height = faces[i].height;

				//get the roi from orginal frame
				cropImg = frame(roi);
				//cv::imshow("ROI", cropImg);

				//cv::imwrite("E:/FDB/"+frameset+".jpg", cropImg);
			}

			std::string wi = std::to_string(width);
			std::string he = std::to_string(height);

			cv::putText(frame, "Frames: " + frameset, cvPoint(30, 30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 255, 0), 1, CV_AA);
			cv::putText(frame, "Faces Detected: " + faceset, cvPoint(30, 60), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 255, 0), 1, CV_AA);
			cv::putText(frame, "Resolution " + wi + " x " + he, cvPoint(30, 90), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 255, 0), 1, CV_AA);
			//cv::putText(frame, "size : " +)

			cv::imshow(window, frame);
		}
		if (waitKey(30) >= 0) break;
	}
}

int videoCapturing()
{
	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		cout << "camera opened" << endl;
		return -1;
	}

	Mat edges;
	namedWindow("edges", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		if (!frame.empty()) {
			cvtColor(frame, edges, CV_HLS2BGR);
			GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
			Canny(edges, edges, 0, 30, 3);
			imshow("edges", edges);
		}
		if (waitKey(30) == 10) break;
	}

	return 0;
}

int videoCapOriginal()
{
	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		cout << "exit" << endl;
		return -1;
	}

	namedWindow("window", 1);

	while (true)
	{
		Mat frame;
		cap.read(frame);

		if (!frame.empty()) {
			imshow("window", frame);
		}
		if (waitKey(30) >= 0) break;
	}
	return 0;
}*/








#include<stdio.h>
#include<math.h>
//#include<opencv\cv.h>
#include<opencv\highgui.h>
#include<opencv2\core\core.hpp>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
//#include<opencv2\contrib\contrib.hpp>
//#include <opencv2\opencv.hpp>
#include<vector>
#include <iostream>
//#include"FaceRec.h"

using namespace cv;
using namespace std;

int main()
{
	//fisherFaceTrainer();
	//FaceRecognition();
	//system("pause");
	string classifier = "C:/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml";
	cout << "classifier" << classifier << endl;

	CascadeClassifier face_cascade;

	face_cascade.load(classifier);
	VideoCapture captureDevice;
	captureDevice.open(0);

	Mat captureFrame;
	Mat grayScaleFrame;

	namedWindow("outputCapture", WINDOW_AUTOSIZE);
	namedWindow("grayScale", WINDOW_AUTOSIZE);
	while (1)
	{
		captureDevice >> captureFrame;
		//waitKey(303);
		cvtColor(captureFrame, grayScaleFrame, CV_BGR2GRAY);
		equalizeHist(grayScaleFrame, grayScaleFrame);
		imshow("grayScale", grayScaleFrame);
		vector<Rect> faces;
		face_cascade.detectMultiScale(grayScaleFrame, faces, 1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE, Size(30, 30));
		//face_cascade.detectMultiScale(captureFrame, faces, 1.1, 3, 0, cv::Size(300, 300));
		cout << faces.size() << endl;
		for (int i = 0; i < faces.size(); i++) {
			Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
			Point pt2(faces[i].x, faces[i].y);
			rectangle(captureFrame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);

		}
		imshow("outputCapture", captureFrame);

		waitKey(1);
	}
	return 0;
}











/*#include<stdio.h>
//#include<math.h>
//#include<opencv\cv.h>
//#include<opencv\highgui.h>
#include<opencv2\core\core.hpp>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
//#include<opencv2\contrib\contrib.hpp>
#include<opencv2\opencv.hpp>
#include<math.h>
#include<vector>
#include <iostream>

//#include "FaceRec.h"
using namespace cv;
using namespace std;

int main()
{
	//eigenFaceTrainer();
	//FaceRecognition();
	//system("pause");
	string classifier = "C:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
	cout << "classifier" << classifier << endl;

	CascadeClassifier face_cascade;

	face_cascade.load(classifier);
	VideoCapture captureDevice;
	captureDevice.open(0);

	Mat captureFrame;
	Mat grayScaleFrame;

	namedWindow("outputCapture", WINDOW_AUTOSIZE);

	while(1)
	{
	captureDevice >> captureFrame;
	//waitKey(303);

	cvtColor(captureFrame, grayScaleFrame, CV_BGR2GRAY);
	equalizeHist(grayScaleFrame, grayScaleFrame);

	vector<Rect> faces;
	face_cascade.detectMultiScale(grayScaleFrame, faces, 1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	for (int i = 0; i < faces.size(); i++) {
	Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
	Point pt2(faces[i].x, faces[i].y);
	rectangle(captureFrame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);

	}
	imshow("outputCapture", captureFrame);

	waitKey(33);
	} 
	return 0;
}*/