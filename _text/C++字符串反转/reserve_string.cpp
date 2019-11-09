#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

void reserveString(string& s1)
{
	//将整个字符串翻转
	string::iterator s1itstr = s1.begin();
	string::iterator s1itend = s1.end() - 1;
	while (s1itstr < s1itend)
	{
		char tmp = *s1itstr;
		*s1itstr = *s1itend;
		*s1itend = tmp;
		s1itstr++;
		s1itend--;
	}
	//将每个单词进行翻转
	int i = 0;
	//记录单词头
	int begin = 0;
	//记录单词尾
	int end = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != ' ')
		{
			begin = i;
			while (s1[i] != ' ' && s1[i] != '\0')
				i++;
			i = i - 1;
			end = i;
		}
		while (begin < end)
		{
			char tmp = s1[begin];
			s1[begin] = s1[end];
			s1[end] = tmp;
			begin++;
			end--;
		}
		i++;
	}
}

int main()
{
	string s1;
	getline(cin, s1);
	reserveString(s1);
	cout << s1;
	system("pause");
	return 0;
}