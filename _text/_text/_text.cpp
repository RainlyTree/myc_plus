#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#include<iostream>
#include<vector>
using namespace std;

long order_count()
{
	long n;
	cin >> n;
	vector<int> arr;
	arr.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int ret = 1;
	for (int i = 1; i < n - 1; i++)
	{
		if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) ||
			(arr[i - 1] > arr[i] && arr[i] < arr[i + 1]))
		{
			ret++;
			if (i != n - 3)
				++i;
			else
				break;
		}
	}
	return ret;
}

int main()
{
	long num;
	num = order_count();
	cout << num;
	return 0;
}