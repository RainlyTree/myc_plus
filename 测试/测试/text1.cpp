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


//测试模板
template<class T>
T Add(const T& A, const T& B)
{
	return A + B;
}

int main()
{
	int a = 10, b = 20;
	double a1 = 10, b1 = 1;
	cout << Add(a, b) << endl;
	cout << Add(a1, b1) << endl;
	return 0;
}