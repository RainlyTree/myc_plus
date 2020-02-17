#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<iomanip>	//调用setw,setfill
//setw函数  设置数字表示一共多少个字符 不够用空格补足
//setfill(x)函数   前面用x补满
using namespace std;


int main()
{
	//设置当前时间
	int hour = 0, min = 0, sec = 0;
	while (1)
	{
		sec++;
		if (sec == 60)
		{
			sec = 0;
			++min;
		}
		if (60 == min)
		{
			min = 0;
			++hour;
		}
		if (60 == hour)
		{
			hour = 0;
		}
		//一秒清一次屏幕
		Sleep(1000);
		system("cls");

		//显示函数
		cout << "---------------" << endl;
		cout << "   " << setfill('0') << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << sec << endl;
		cout << "---------------" << endl;
	}
	return 0;
}