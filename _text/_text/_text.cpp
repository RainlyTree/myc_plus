#define _CRT_SECURE_NO_WARNINGS 1
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//long order_count()
//{
//	long n;
//	cin >> n;
//	vector<int> arr;
//	arr.resize(n);
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	int ret = 1;
//	for (int i = 1; i < n - 1; i++)
//	{
//		if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) ||
//			(arr[i - 1] > arr[i] && arr[i] < arr[i + 1]))
//		{
//			ret++;
//			if (i != n - 3)
//				++i;
//			else
//				break;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	long num;
//	num = order_count();
//	cout << num;
//	return 0;
//}


//¿¼À­ÓÐn ¸ö×Ö·û´®
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//bool Get(vector<string> str)
//{
//	int length = str.size() - 1;
//	for (int i = 0; i < length; ++i)
//	{
//		string::iterator begin1 = str[i].begin();
//		string::iterator begin2 = str[i + 1].begin();
//		while (begin1 != str[i].end() && begin2 != str[i + 1].end())
//		{
//			if (*begin1 > *begin2)
//				return false;
//			begin1++;
//			begin2++;
//		}
//	}
//	return true;
//}
//
//bool len(vector<string> str)
//{
//	int length = str.size() - 1;
//	for (int i = 0; i < length; ++i)
//	{
//		if (str[i].size() > str[i + 1].size())
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int num = 0;
//	cin >> num;
//	vector<string> str;
//	str.reserve(num + 1);
//	str.resize(num);
//	for (int i = 0; i < num; ++i)
//	{
//		cin >> str[i];
//	}
//	bool lex = Get(str);
//	bool leng = len(str);
//	if (lex && leng)
//		cout << "both";
//	else if (!lex && leng)
//		cout << "lengths";
//	else if (lex && !leng)
//		cout << "lexicographically";
//	else
//		cout << "none";
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int num;
	
	while (cin >> num)
	{
		int n = 0;
		if (num == 0)
			break;
		while (num / 2)
		{
			++n;
			num /= 2;
		}
		cout << n << endl;
	}
	return 0;
}