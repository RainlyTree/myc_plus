#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string inStr;
	while (cin >> inStr)
	{
		string ret;
		int num[128] = { 0 };
		//vector<int> num;
		//num.resize(128);
		for (const auto& ch : inStr)
		{
			if (num[ch] == 0)
			{
				ret += ch;
				num[ch] = 1;
			}
		}
		cout << ret << endl;
	}
	return 0;
}