#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Class_Date.h"

ostream& operator << (ostream& _cout, const Date&d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

istream& operator >>(istream& _cin, const Date& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}

void text()
{
	Date my = Date(2019,12,23);
	Date my1 = Date(2088,12,24);
	Date my2;
	int num = my1 - my;
	my--;
	--my1;
	my.show();
	my1.show();
	my = my1;
	my += 30;
	my.show();
}



//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	static int GetACount() { return _scount; }
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}

int main()
{
	text();
	//TestA();
	system("pause");
	return 0;
}