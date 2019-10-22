#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	/*
		this 指针:类类型 * const
				指向当前对象的指针
				做诶成员函数的第一个参数
				只存在成员函数中
	*/
	
	//底层 ：void SetDate(Date* const this ,int year, int month, int day)

	//构造函数 整个生命周期只调用一次
	//若自己构造后 编译器不会在构造
	//默认构造 ：
	//			1.无参构造
	//			2.编译期默认生成
	//			3.全缺省的构造函数
	Date()
	{
		cout << "Date()" << endl;
	}

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}




	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Display()
	{
		cout << _year << " " << _month  << " " << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};