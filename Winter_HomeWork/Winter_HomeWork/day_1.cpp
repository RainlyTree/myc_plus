#include<iostream>
#include<vector>
using namespace std;

bool is(int* arr, int begin, int end, double res)
{
	if (begin == end - 1)
		return arr[begin] == res;
	else
	{
		bool flag = false;
		for (int i = begin; i < end; ++i)
		{
			swap(arr[i], arr[begin]);
			flag = flag ||
				is(arr, begin + 1, end, res + arr[begin]) ||
				is(arr, begin + 1, end, res - arr[begin]) ||
				is(arr, begin + 1, end, res * arr[begin]) ||
				is(arr, begin + 1, end, res / arr[begin]);
			swap(arr[i], arr[begin]);
		}
		return flag;
	}
}


int main()
{
	int num[4];
	for (int i = 0; i < 4; ++i)
	{
		cin >> num[i];
	}
	if (is(num, 0, 4, 24))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}