//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<opencv2/face.hpp>
//#include <opencv2/highgui/highgui_c.h>
//#include<opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//double calcPCAOrientation(vector<Point>& pts, Mat& image);
//
//int main(int argc, char** argv)
//{
//	//获取图片
//	Mat image = imread("D:\\My_file\\myc_plus\\AI_Face\\image\\课程配套源代码\\orl_faces\\s1\\1.pgm");
//	if (image.empty())
//	{
//		cout << "not load image..." << endl;
//		return -1;
//	}
//	namedWindow("input image:", CV_WINDOW_AUTOSIZE);
//	imshow("input image", image);
//
//	Mat gray, binary;
//	cvtColor(image, gray, COLOR_BGR2GRAY);
//	threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
//	imshow("binary image", binary);
//
//	vector<Vec4i> hireadchy;
//	vector<vector<Point>> contours;
//	findContours(binary, contours, hireadchy, RETR_LIST, CHAIN_APPROX_NONE);
//	Mat result = image.clone();
//	for (int i = 0; i < contours.size(); ++i)
//	{
//		double area = contourArea(contours[i]);
//		if (area > 1e5 || area < 1e2)
//			continue;
//		drawContours(result, contours, i, Scalar(0,0,255), 2, 8);
//		double theta = calcPCAOrientation(contours[i], result);
//	}
//	imshow("contours result", result);
//
//	waitKey(0);
//	return 0;
//}
//
//double calcPCAOrientation(vector<Point>& pts, Mat& image)
//{
//	int size = static_cast<int>(pts.size());
//	Mat data_pts = Mat(size, 2, CV_64FC1);
//	for (int i = 0; i < size; ++i)
//	{
//		data_pts.at<double>(i, 0) = pts[i].x;
//		data_pts.at<double>(i, 1) = pts[i].y;
//	}
//
//	PCA pac_analysis(data_pts, Mat(), CV_PCA_DATA_AS_ROW);
//	Point cnt = Point(static_cast<int>(pac_analysis.mean.at<double>(0, 0))
//		, static_cast<int>(pac_analysis.mean.at<double>(0, 1)));
//	circle(image, cnt, 2, Scalar(0, 255, 0), 2, 8, 0);
//
//	vector<Point2d> vecs(2);
//	vector<double> vals(2);
//	for (int i = 0; i < 2; ++i)
//	{
//		vals[i] = pac_analysis.eigenvalues.at<double>(i, 0);
//		vecs[i] = Point2d(pac_analysis.eigenvectors.at<double>(i, 0)
//			, pac_analysis.eigenvectors.at<double>(i, 1));
//	}
//
//	Point p1 = cnt + 0.02 * Point(static_cast<int>(vecs[0].x * vals[0]), static_cast<int>(vecs[0].y * vals[0]));
//	Point p2 = cnt - 0.05 * Point(static_cast<int>(vecs[1].x * vals[1]), static_cast<int>(vecs[1].y * vals[1]));
//
//	line(image, cnt, p1, Scalar(255, 0, 0), 2, 8, 0);
//	//line(image, cnt, p2, Scalar(255, 255, 0), 2, 8, 0);
//
//	double angle = atan2(vecs[0].y, vecs[0].x);
//	printf("angle : %.2f\n", 180 * (angle / CV_PI));
//
//	return angle;
//}