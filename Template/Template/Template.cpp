#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


//对方法进行模板

//template <typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
////另外一种类型的定义
////template <class T>
////void swap(T& a, T& b)
////{
////	T tmp = a;
////	a = b;
////	b = tmp;
////}
//
//template <typename T>
//T add(const T& a, const T& b)
//{
//	return a + b;
//}
//
//int add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	float c = 3.1, d = 4.1;
//	//隐式实例化
//	Swap(c, d);
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//	//显示实例化
//	//Swap(a, (int)d);	//做强转  保存为临时变量，临时变量具有常性 与 &类型有冲突
//	add(a, (int)d);		//改为const & 类型就可以了
//
//	//非模板函数与模板函数共存，优先使用非模板函数
//	//如果不能完全匹配，实例化可以生成更加匹配的函数，则走实例化
//	add(a, b);
//	add(a, c);
//	//如果声明显示实例化，一定会进行实例化
//	add<int>(a, c);
//	system("pause");
//	return 0;
//}


//对类进行模板

template<class DateType>
class SeqList
{
public:
	SeqList(int num = 10)
	{
		:_date(new DateType[num])
			, _size(num)
			, _capacity(num)
		{
		}
	}

	SeqList<DateType>& operator=(const SeqList<DateType>& sq)
	{
		//进行了浅拷贝  在同一片内存
		if (this != &sq)
		{
			_date = sq._date;
			_size = sq._size;
			_capacity = sq._capacity;
		}
	}

	int Size()
	{
		return _size;
	}

	DateType& operator[] (size_t pos)
	{
		return _date[pos];
	}

	~SeqList()
	{
		if (_date)
		{
			delete[] _date;
			_date = nullptr;
			_size = _capacity = 0;
		}
	}
private:
	DateType* _date;
	size_t _size;
	size_t _capacity;
};

int main()
{
	// 类只有显示实例化
	//在模型中  SeqList<int> 为类型  SeqList为类名
  	SeqList<int> s1;
	for (int i = 0; i < s1.Size(); ++i)
	{
		s1[i] = i;
		cout << s1[i] << endl;
	}
	system("pause");
	return 0;
}