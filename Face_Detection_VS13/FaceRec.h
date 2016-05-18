//using namespace std;
//using namespace cv;

#pragma once
#ifndef FACEREC_H
#define FACEREC_H

#include "common.h"
#include <ctime>
//#include "MobileDevice.h"

bool running = false;
time_t current = time(0);
std::vector<int> detected_list;
std::vector<time_t> time_list;


void dbread(const std::string& filename, std::vector<cv::Mat>& images, std::vector<int>& labels, char separator = ';') {
	std::ifstream file(filename.c_str(), std::ifstream::in);

	if (!file) {
		std::string error = "no valid input file";
		CV_Error(CV_StsBadArg, error);
	}

	std::string line, path, label;
	while (std::getline(file, line))
	{
		std::stringstream liness(line);
		std::getline(liness, path, separator);
		std::getline(liness, label);
		if (!path.empty() && !label.empty()) {
			images.push_back(cv::imread(path, 0));
			labels.push_back(atoi(label.c_str()));
		}
	}
}


void LBPHFaceTrainer() {

	std::vector<cv::Mat> images;
	std::vector<int> labels;

	try {
		std::string filename = "C:/Users/Vikum/Documents/Visual Studio 2013/Pictures/at.txt";
		dbread(filename, images, labels);

		std::cout << "size of the images is " << images.size() << std::endl;
		std::cout << "size of the labes is " << labels.size() << std::endl;
		std::cout << "Training begins...." << std::endl;
	}
	catch (cv::Exception& e) {
		std::cerr << " Error opening the file " << e.msg << std::endl;
		exit(1);
	}

	//lbph face recognier modelfgh
	cv::Ptr<cv::FaceRecognizer> model = cv::createLBPHFaceRecognizer();

	//training images with relevant labels 
	model->train(images, labels);

	//save the data in yaml file
	model->save("C:/Users/Vikum/Documents/Visual Studio 2013/Pictures/LBPHface.yml");

	std::cout << "training finished...." << std::endl;

	cv::waitKey(10000);
}

int  FaceRecognition() {

	std::cout << "start recognizing..." << std::endl;

	//load pre-trained data sets
	//Ptr<FaceRecognizer>  model = createFisherFaceRecognizer();
	cv::Ptr<cv::FaceRecognizer> model = cv::createLBPHFaceRecognizer();

	model->load("C:/Users/Vikum/Documents/Visual Studio 2013/Pictures/LBPHface.yml");
	/*
	Mat testSample = imread("E:/db/s41/5.pgm", 0);

	int img_width = testSample.cols;
	int img_height = testSample.rows;
	*/

	//lbpcascades/lbpcascade_frontalface.xml
	std::string classifier = "C:/opencv1/sources/data/haarcascades/haarcascade_frontalface_default.xml";

	cv::CascadeClassifier face_cascade;
	std::string window = "Capture - face detection";

	if (!face_cascade.load(classifier)) {
		std::cout << " Error loading file" << std::endl;
		return -1;
	}

	cv::VideoCapture cap(1);
	//VideoCapture cap("C:/Users/lsf-admin/Pictures/Camera Roll/video000.mp4");

	if (!cap.isOpened())
	{
		std::cout << "exit" << std::endl;
		return -1;
	}

	double fps = cap.get(CV_CAP_PROP_FPS);
	std::cout << " Frames per seconds " << fps << std::endl;
	cv::namedWindow(window, 1);
	long count = 0;

	while (running)
	{
		std::vector<cv::Rect> faces;
		cv::Mat frame;
		cv::Mat graySacleFrame;
		cv::Mat original;
		
		cap >> frame;
		//cap.read(frame);
		count = count + 1;//count frames;

		if (!frame.empty()) {

			//clone from original frame
			original = frame.clone();

			//convert image to gray scale and equalize
			cvtColor(original, graySacleFrame, CV_BGR2GRAY);
			//equalizeHist(graySacleFrame, graySacleFrame);

			//detect face in gray image
			face_cascade.detectMultiScale(graySacleFrame, faces, 1.1, 3, 0, cv::Size(90, 90));

			//number of faces detected
			std::cout << faces.size() << " faces detected" << std::endl;
			std::string frameset = std::to_string(count);
			std::string faceset = std::to_string(faces.size());

			int width = 0, height = 0;

			//region of interest
			//cv::Rect roi;
		
			//person name
			std::string Pname = "";

			for (int i = 0; i < faces.size(); i++)
			{
				//region of interest
				cv::Rect face_i = faces[i];

				//crop the roi from grya image
				cv::Mat face = graySacleFrame(face_i);

				//resizing the cropped image to suit to database image sizes
				cv::Mat face_resized;
				cv::resize(face, face_resized, cv::Size(50, 50), 1.0, 1.0, cv::INTER_CUBIC);

				//recognizing what faces detected
				int label = -1; double confidence = 0;
				model->predict(face_resized, label, confidence);

				//std::cout << " confidencde " << confidence << std::endl;
				//std::cout << " label " << label << std::endl;
				//drawing green rectagle in recognize face
				cv::rectangle(original, face_i, CV_RGB(0, 255, 0), 1);
				std::string text = "Detected";
				
				time_t rawtime;
				struct tm * timeinfo;
				time(&rawtime);
				timeinfo = localtime(&rawtime);
				timeinfo->tm_sec = 15;
				
				if (std::find(detected_list.begin(), detected_list.end(), label) != detected_list.end()){
					if (difftime(time(0), time_list.at(0)) < 15) {
						//std::cout << "good good good" << std::endl;
						continue;
					}
					else{
						detected_list.erase(detected_list.begin());
						time_list.erase(time_list.begin());
						//std::cout << "no no no" << std::endl;
						//running = false;
					}
				}
				else if(label<100){
					detected_list.push_back(label);
					time_list.push_back(time(0));
					std::cout << "label ********************** "<<label<<std::endl;

					String^ constring = L"datasource=localhost;port=3306;username=root;password=1234";
					MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
					MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT CustomerType FROM face_detection.CustomerInfo where id = C" + label, conDataBase);
					MySqlDataReader^ myReader;
					conDataBase->Open();

					String^ content;
					std::string inKey;
					try{
						myReader = cmdDataBase->ExecuteReader();
						while (myReader->Read())
						{
							content = myReader->GetString(0);
							inKey = msclr::interop::marshal_as<std::string>(content);
						}
						int num = std::stoi(inKey);
						if (num = 1)
							MobileDevice::sendMyRequest("C" + label);
						else if (num = 0)
							MobileDevice::sendMyRequest("T" + label);
					}
					catch (Exception^ e){
						inKey = "0";
					}
					
				}
				

				int pos_x = std::max(face_i.tl().x - 10, 0);
				int pos_y = std::max(face_i.tl().y - 10, 0);

				//name the person who is in the image
				putText(original, text, cv::Point(pos_x, pos_y), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);

			}


			putText(original, "Frames: " + frameset, cv::Point(30, 60), CV_FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
			putText(original, "Person: " + Pname, cv::Point(30, 90), CV_FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
			//display to the winodw
			imshow(window, original);

			//cout << "model infor " << model->getDouble("threshold") << endl;

		}
		if (cv::waitKey(30) >= 0) break;
	}
}
#endif