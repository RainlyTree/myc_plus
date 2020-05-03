#define _CRT_SECURE_NO_WARNINGS
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <iostream>

using namespace cv;
using namespace cv::face;
using namespace std;

string haar_face_datapath = "D:/My_file/myc_plus/AI_Face/image/课程配套源代码/orl_faces/image.xml";
int main(int argc, char** argv) {
	string filename = string("D:/My_file/myc_plus/AI_Face/image/课程配套源代码/orl_faces/image.csv");
	ifstream file(filename.c_str(), ifstream::in);
	if (!file) {
		printf("could not load file correctly...\n");
		return -1;
	}

	string line, path, classlabel;
	vector<Mat> images;
	vector<int> labels;
	char separator = ';';
	while (getline(file, line)) {
		stringstream liness(line);
		getline(liness, path, separator);
		getline(liness, classlabel);
		if (!path.empty() && !classlabel.empty()) {
			//printf("path : %s\n", path.c_str());
			images.push_back(imread(path, 0));
			labels.push_back(atoi(classlabel.c_str()));
		}
	}

	if (images.size() < 1 || labels.size() < 1) {
		printf("invalid image path...\n");
		return -1;
	}

	int height = images[0].rows;
	int width = images[0].cols;
	printf("height : %d, width : %d\n", height, width);

	Mat testSample = images[images.size() - 1];
	int testLabel = labels[labels.size() - 1];
	images.pop_back();
	labels.pop_back();

	// train it
	Ptr<BasicFaceRecognizer> model = EigenFaceRecognizer::create();
	model->train(images, labels);

	// recognition face
	int predictedLabel = model->predict(testSample);
	printf("actual label : %d, predict label :  %d\n", testLabel, predictedLabel);

	CascadeClassifier faceDetector;
	faceDetector.load(haar_face_datapath);

	VideoCapture capture(0);
	if (!capture.isOpened()) {
		printf("could not open camera...\n");
		return -1;
	}
	Mat frame;
	namedWindow("face-recognition", CV_WINDOW_AUTOSIZE);
	vector<Rect> faces;
	Mat dst;
	while (capture.read(frame)) {
		flip(frame, frame, 1);
		faceDetector.detectMultiScale(frame, faces, 1.1, 1, 0, Size(80, 100), Size(380, 400));
		for (int i = 0; i < faces.size(); i++) {
			Mat roi = frame(faces[i]);
			cvtColor(roi, dst, COLOR_BGR2GRAY);
			resize(dst, testSample, testSample.size());
			int label = model->predict(testSample);
			rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
			putText(frame, format("i'm %s", (label == 19 ? "zhigang" : "Unknow")), faces[i].tl(), FONT_HERSHEY_PLAIN, 1.0, Scalar(0, 0, 255), 2, 8);
		}

		imshow("face-recognition", frame);
		char c = waitKey(10);
		if (c == 27) {
			break;
		}
	}

	waitKey(0);
	return 0;
}