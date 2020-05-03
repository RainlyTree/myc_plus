//#define _CRT_SECURE_NO_WARNINGS
//#include <opencv2/opencv.hpp>
//#include <opencv2/face.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace cv::face;
//using namespace std;
//
//int main(int argc, char** argv) {
//	string filename = string("D:/My_file/myc_plus/AI_Face/image/¿Î³ÌÅäÌ×Ô´´úÂë/orl_faces/image.csv");
//	ifstream file(filename.c_str(), ifstream::in);
//	if (!file) {
//		printf("could not load file correctly...\n");
//		return -1;
//	}
//
//	string line, path, classlabel;
//	vector<Mat> images;
//	vector<int> labels;
//	char separator = ';';
//	while (getline(file, line)) {
//		stringstream liness(line);
//		getline(liness, path, separator);
//		getline(liness, classlabel);
//		if (!path.empty() && !classlabel.empty()) {
//			//printf("path : %s\n", path.c_str());
//			images.push_back(imread(path, 0));
//			labels.push_back(atoi(classlabel.c_str()));
//		}
//	}
//
//	if (images.size() < 1 || labels.size() < 1) {
//		printf("invalid image path...\n");
//		return -1;
//	}
//
//	int height = images[0].rows;
//	int width = images[0].cols;
//	printf("height : %d, width : %d\n", height, width);
//
//	Mat testSample = images[images.size() - 1];
//	int testLabel = labels[labels.size() - 1];
//	images.pop_back();
//	labels.pop_back();
//
//	// train it
//	Ptr<LBPHFaceRecognizer> model = LBPHFaceRecognizer::create();
//	model->train(images, labels);
//
//	// recognition face
//	int predictedLabel = model->predict(testSample);
//	printf("actual label : %d, predict label :  %d\n", testLabel, predictedLabel);
//
//	// print parameters
//	int radius = model->getRadius();
//	int neibs = model->getNeighbors();
//	int grad_x = model->getGridX();
//	int grad_y = model->getGridY();
//	double t = model->getThreshold();
//
//	printf("radius : %d\n", radius);
//	printf("neibs : %d\n", neibs);
//	printf("grad_x : %d\n", grad_x);
//	printf("grad_y : %d\n", grad_y);
//	printf("threshold : %.2f\n", t);
//
//	waitKey(0);
//	return 0;
//}