//#include <vector>
//#include <iostream>
//#include "FaceRec.h"
#include "MobileDevice.h"
#include "StaffMember.h"




int main()
{
	//MobileDevice::sendMyRequest();
	//LBPHFaceTrainer();
	//FaceRecognition();
	//fisherFaceTrainer();
	//sendRequest();

	/*string classifier = "C:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
	cout << "classifier" << classifier << endl;

	CascadeClassifier face_cascade;

	face_cascade.load(classifier);
	VideoCapture captureDevice;
	captureDevice.open(0);

	if (!captureDevice.isOpened()) {
	cout << "failed to open camera" << endl;
	}


	namedWindow("grayScaleimage", WINDOW_AUTOSIZE);
	namedWindow("outputCapture", WINDOW_AUTOSIZE);
	Mat captureFrame;
	Mat grayScaleFrame;
	while (1)
	{
	captureDevice >> captureFrame;
	//imshow("outputCapture", *captureFrame);
	//waitKey(33);
	//cout << captureFrame.empty() << endl;
	std::cerr << "image chans : " << captureFrame.channels() << std::endl;
	cvtColor(captureFrame, grayScaleFrame, CV_BGR2GRAY);

	equalizeHist(grayScaleFrame, grayScaleFrame);

	vector<Rect> faces;
	face_cascade.detectMultiScale(grayScaleFrame, faces, 1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	cout << "Number of faces detected is : " << faces.size() << endl;
	for (int i = 0; i < faces.size(); i++) {
	Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
	Point pt2(faces[i].x, faces[i].y);
	rectangle(captureFrame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
	}

	imshow("outputCapture", captureFrame);
	//imshow("grayScaleimage", grayScaleFrame);
	waitKey(33);
	}*/
	
	return 0;
}