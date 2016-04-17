// Face_Detection.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include "Customer.h"
#include "StaffMember.h"

#include<math.h>
#include<opencv\cv.h>
#include<opencv\highgui.h>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<vector>

using namespace cv;
using namespace std;

int main()
{	
	Customer vikum = Customer("Vikum", "Bandara", 001);
	StaffMember wedda = StaffMember();

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
			rectangle(cap_img, pt1, pt2, cvScalar(100, 200, 100), 3, 8, 0);
			string box_text = format("Customer: %d",vikum.getIdNumber());
			int pos_x = max(faces[i].tl().x - 10, 0);
			int pos_y = max(faces[i].tl().y - 10, 0);
			putText(cap_img, box_text, Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0, 255, 0), 2.0);
		
		}
		imshow("Video_Feed", cap_img);
		waitKey(3);
		char c = waitKey(3);
		if (c == 27)
			break;
	}
	return 0;
}