#define _CRT_SECURE_NO_WARNINGS
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	//获取图片
	Mat image = imread("D:/My_file/myc_plus/AI_Face/image/test3.png");
	if (image.empty())
	{
		cout << "not load image..." << endl;
		return -1;
	}
	imshow("input image", image);

	//均值      标准差差
	Mat means, stddev;
	meanStdDev(image, means, stddev);
	cout << "means rows:" << means.rows << " "
		<< "means cols:" << means.cols << endl;
	cout << "stddev rows:" << stddev.rows << " "
		<< "stddev cols:" << stddev.cols << endl;
	for (int row = 0; row < means.rows; row++)
	{
		printf("mean %d = %.3f\n", row, means.at<double>(row));
		printf("stddev %d = %.3f\n", row, stddev.at<double>(row));
	}

	Mat samples = (Mat_<double>(5, 3) 
		<< 90, 60, 90, 90, 90, 30, 60, 60, 60, 60, 60, 90, 30, 30, 30);
	Mat cov, mu;
	calcCovarMatrix(samples, cov, mu, CV_COVAR_NORMAL | CV_COVAR_ROWS);

	cout << "==================================" << endl;
	cout << "cov: " << endl;
	cout << cov / 5 << endl;

	cout << "means: " << endl;
	cout << mu << endl;

	waitKey(0);
	return 0;
}