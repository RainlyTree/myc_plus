#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
using namespace std;

bool Gethuiwen(string::iterator& A, string::iterator& B)
{
	while (A < B)
	{
		if (*A != *B)
			return false;
		A++;
		B++;
	}
	return true;
}

int GetNum(string& A, string& B)
{
	int sum = 0;
	int num = A.size();
	while (num >= 0)
	{
		string tmp(A);
		tmp.insert(num, B);
		if (Gethuiwen(tmp.begin(), tmp.end() - 1))
			sum++;
	}
}

int main()
{
	string A;
	string B;
	getline(cin, A);
	getline(cin, B);
	int num = GetNum(A, B);
	cout << num;
	return 0;
}