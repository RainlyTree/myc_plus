#define _CRT_SECURE_NO_WARNINGS 1

//牛客网链接
//https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	//处理越界的情况
	vector<int> a;
	a.reserve(n + 1);
	a[n] = 0;

	//读入数组
	for (int i = 0; i < n; ++n)
	{
		cin >> a[i];
	}

	int i = 0;
	int count = 0;
	while (i < n)
	{
		//非递减子序列
		if (a[i] < a[i + 1])
		{
			while (i < n && a[i] <= a[i + 1])
				i++;
			count++;
			i++;
		}
		else if (a[i] == a[i + 1])
		{
			i++;
		}
		else
		{
			while (i < n && a[i] >= a[i + 1])
				i++;
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}