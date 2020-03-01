#include<iostream>
using namespace std;

//测试函数重载 (个数 类型 顺序)
int Add(int left, double right)
{
	return left + right;
}

int Add(double right, int left)
{
	return left + right;
}

int main()
{
	int left = 1;
	double right = 1;
	cout << Add(left, right) << endl;
	cout << Add(right, left) << endl;
	return 0;
}