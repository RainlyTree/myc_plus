#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{
	}

	SmartPtr(SmartPtr<T>& ptr)
		:_ptr(ptr._ptr)
	{
		ptr._ptr = NULL;
	}

	~SmartPtr()
	{
		if (_ptr)
		{
			delete(_ptr);
			_ptr = nullptr;
		}
	}

	SmartPtr<T>& operator=(SmartPtr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
				delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}

	//实现指针的功能:解引用 
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};


int main()
{
	SmartPtr<int> sp(new int(10));
	*sp = 20;
	cout << *sp << endl;
	return 0;
}