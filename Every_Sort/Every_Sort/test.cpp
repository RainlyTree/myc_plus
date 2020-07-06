#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

//√∞≈›≈≈–Ú Œ»∂®
void bubbleSort(int* arr, int len)
{
	int reducej = len, reducepos;
	for (int i = 0; i < len - 1; ++i)
	{
		reducepos = reducej - 1;
		reducej = 0;
		for (int j = 0; j < reducepos; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				reducej = j + 1;
			}
		}
	}
}

//—°‘Ò≈≈–Ú  ≤ªŒ»∂®
void SelectionSort(int* arr, int len)
{
	int begin = 0, end = len - 1;
	while (begin <= end)
	{
		int min = begin, max = end;
		for (int i = begin; i < end; ++i)
		{
			if (arr[i] > arr[max])
				max = i;
			if (arr[i] < arr[min])
				min = i;
		}
		swap(arr[begin], arr[min]);
		if (max == begin)
			max = min;
		swap(arr[end], arr[max]);
		++begin;
		--end;
	}
}

//≤Â»Î≈≈–Ú Œ»∂®
void InsertSort(int* arr, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int tmp = arr[i + 1];
		int j = i;
		while(j >= 0)
		{
			if (arr[j] > tmp)
				arr[j + 1] = arr[j];
			else
				break;
			--j;
		}
		arr[j + 1] = tmp;
	}
}

//øÏ≈≈ ≤ªŒ»∂®(µ›πÈ)
void QuitSort(int* arr, int begin, int end)
{
	if (begin > end)
		return;
	int i = begin;
	int j = end;
	int tmp = arr[begin];
	while (i < j)
	{
		while (arr[j] >= tmp && j > i)
			--j;
		while (arr[i] <= tmp && j > i)
			++i;
		if (j > i)
		{
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i], arr[begin]);
	QuitSort(arr, begin, i - 1);
	QuitSort(arr, i + 1, end);
}

//πÈ≤¢≈≈–Ú 
void merge(int* arr, int left1, int left2,int right1, int right2)
{
	int start = left1;
	int len = left2 - left1 + right2 - right1 + 2;
	int* tmp = new int[len];
	int i = 0;
	while (left1 <= left2 && right1 <= right2)
	{
		if (arr[left1] <= arr[right1])
		{
			tmp[i] = arr[left1];
			++left1;
		}
		else
		{
			tmp[i] = arr[right1];
			++right1;
		}
		++i;
	}
	while (left1 <= left2)
	{
		tmp[i] = arr[left1];
		++left1;
		++i;
	}
	while (right1 <= right2)
	{
		tmp[i] = arr[right1];
		++right1;
		++i;
	}
	for (int i = 0; i < len; ++i)
	{
		arr[start] = tmp[i];
		++start;
	}
	delete tmp;
	tmp = nullptr;
}

void mergesort(int* arr, int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergesort(arr, begin, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, begin, mid, mid + 1, end);
	}	
}

void merge1(int* arr, int left1, int right1, int left2, int right2)
{
	int start = left1;
	int len = right2 - left1 + 1;
	int* tmp = new int[len];
	int i = 0;
	while (left1 <= right1 && left2 <= right2)
	{
		if (arr[left1] < arr[left2])
		{
			tmp[i] = arr[left1];
			++left1;
		}
		else
		{
			tmp[i] = arr[left2];
			++left2;
		}
		++i;
	}
	while (left1 <= right1)
	{
		tmp[i] = arr[left1];
		++left1;
		++i;
	}
	while (left2 <= right2)
	{
		tmp[i] = arr[left2];
		++left2;
		++i;
	}
	for (int i = 0; i < len; ++i)
	{
		arr[start] = tmp[i];
		++start;
	}
	delete tmp;
	tmp = nullptr;
}

void mergeSort1(int* arr, int left, int right)
{
	if (left < right)
	{
		int mid = (right + left) / 2;
		mergeSort1(arr, left, mid);
		mergeSort1(arr, mid + 1, right);
		merge(arr, left, mid, mid + 1, right);
	}
}


void test()
{
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	mergeSort1(arr, 0, 5);
}

int main()
{
	test();
	return 0;
}

