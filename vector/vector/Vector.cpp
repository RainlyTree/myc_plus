#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void testVec1()
{
	vector<char> v;
	vector<int> v2(10, 1);
	vector<int> copy(v2);
	string s("123456");
	vector<int> v3(v2.begin(), v2.end());
	vector<char> v4(s.begin(), s.end());
  }