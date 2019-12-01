#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//一个排过序的数组，包含n个证书，数组向左进行一定的位移   时间复杂度为log级别
//原数组 [1,2,3,4,5,6]     ----->  向左5位     [6,1,2,3,4,5]
#include<vector>
#include<iostream>
using namespace std;
class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		// write code here
		int left = 0;
		int right = n - 1;
		int mid = (left + right) / 2;
		while (A[mid] != x)
		{
			if (A[mid] < A[right])
			{
				if (A[mid] < x && x < A[right])
				{
					left = mid + 1;
					mid = (left + right) / 2;
				}
				else
				{
					right = mid - 1;
					mid = (left + right) / 2;
				}
			}
			else if (A[left] < x && A[mid] > x)
			{
				right = mid - 1;
				mid = (left + right) / 2;
			}
			else
			{
				mid = mid + 1;
			}
		}
		return mid;
	}
};