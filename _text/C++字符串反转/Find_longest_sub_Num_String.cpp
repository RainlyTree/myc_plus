#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
using namespace std;

//方法一
//bool Gethuiwen(string::iterator& A, string::iterator& B)
//{
//	while (A < B)
//	{
//		if (*A != *B)
//			return false;
//		A++;
//		B++;
//	}
//	return true;
//}
//
//int GetNum(string& A, string& B)
//{
//	int sum = 0;
//	int num = A.size();
//	while (num >= 0)
//	{
//		string tmp(A);
//		tmp.insert(num, B);
//		string::iterator beg = tmp.begin();
//		string::iterator end = tmp.end() - 1;
//		if (Gethuiwen(beg, end))
//			sum++;
//	}
//}
//
//int main()
//{
//	string A;
//	string B;
//	getline(cin, A);
//	getline(cin, B);
//	int num = GetNum(A, B);
//	cout << num;
//	return 0;
//}

//方法二
int main()
{
	string str, res, cur;
	cin >> str;
	for (int i = 0; i <= str.length(); ++i)
	{
		//数字+=到cur
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			//找出更长的字符串,则更新
			if (res.size() < cur.size())
				res = cur;
			else
				cur.clear();
		}
	}
	cout << res;
	return 0;
}