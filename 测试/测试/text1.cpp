#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include"text1.h"
using namespace std;

//实现一个类 计算程序中穿件出了多少个类对象
/*class A
{
public:
	A(int x = 0)
	{
		++_count;
		cout << " A " << endl;
	}
	A(const A& t)
	{
		++_count;
		cout << " A + " << endl;
	}
	static int GetACount()
	{
		return _count;
	}
private:
	static int _count;
};

int A::_count = 0;

void Text()
{
	cout << A::GetACount() << endl;
	A a1, a2;

	A a3(A(1));
	cout << a1.GetACount() << endl;
}

int main()
{
	Text();
	system("pause");
	return 0;
}*/


//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	private:
//	int _year;
//	int _month;
//	int _day;
//};
//static bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//void Test()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}
//
//int main()
//{
//	Test();
//	return 0;
//
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d(2017, 12, 24);
//	//ate::operator<<(d, cout);
//	d << cout;
//	return 0;
//}

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, const Date& d);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, const Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}


//class HeapOnly
//{
//public:
//	static HeapOnly* Creat()
//	{
//		return new HeapOnly;
//	}
//private:
//	HeapOnly()
//	{}
//	//只声明 不实现
//	HeapOnly(const HeapOnly&);
//
//	bool operator=(const HeapOnly& d);
//};
//
//
//void Text()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	
//	int* p2 = (int*)calloc(1, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 1);
//
//}

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//private:
//	Singleton()
//	{};
//	//防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	static Singleton m_instance;
//};
//Singleton Singleton:: m_instance;
//
//int main()
//{
//	Singleton::GetInstance();
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	system("pause");
//	return 0;
//}