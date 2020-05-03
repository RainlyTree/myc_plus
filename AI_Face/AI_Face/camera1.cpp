//#define _CRT_SECURE_NO_WARNINGS
//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui_c.h>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//string haar_face_datapath = "D:/opencv3.2/opencv/build/etc/haarcascades/haarcascade_frontalface_alt_tree.xml";
//int main(int argc, char** argv) {
//	VideoCapture capture(0); // open camera
//	if (!capture.isOpened()) {
//		printf("could not open camera...\n");
//		return -1;
//	}
//	Size S = Size((int)capture.get(CAP_PROP_FRAME_COUNT), (int)capture.get(CAP_PROP_FRAME_HEIGHT));
//	int fps = capture.get(CAP_PROP_FPS);
//
//	CascadeClassifier faceDetector;
//	faceDetector.load(haar_face_datapath);
//
//	Mat frame;
//	namedWindow("camera-demo", CV_WINDOW_AUTOSIZE);
//	vector<Rect> faces;
//	int count = 0;
//	while (capture.read(frame)) {
//		flip(frame, frame, 1);
//		faceDetector.detectMultiScale(frame, faces, 1.1, 1, 0, Size(100, 120), Size(380, 400));
//		for (int i = 0; i < faces.size(); i++) {
//			if (count % 10 == 0) {
//				Mat dst;
//				resize(frame(faces[i]), dst, Size(100, 100));
//				imwrite(format("D:/gloomyfish/outimage/face_%d.jpg", count), dst);
//			}
//			rectangle(frame, faces[i], Scalar(0, 0, 255), 2, 8, 0);
//		}
//		imshow("camera-demo", frame);
//		char c = waitKey(10);
//		if (c == 27) {
//			break;
//		}
//		count++;
//	}
//
//	capture.release();
//
//	waitKey(0);
//	return 0;
//}