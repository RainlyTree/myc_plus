#define _CRT_SECURE_NO_WARNINGS 1

//删除公共字符

//将第二个字符串的字符都映射到一个数组中
//判断一个字符在第二个字符串中，添加到一个新的字符串
//最后返回新的字符串

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2;
	//这里不能使用cin 因为cin遇到空格就结束了
	getline(cin, str1);
	getline(cin, str2);

	//将第二个字符串出现的字符统计到hashtable中
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

	//遍历str1,将hashtable中为0的写入新的表中
	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret << endl;
	return 0;
}