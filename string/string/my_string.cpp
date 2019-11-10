#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<assert.h>
#include<string>
#include<iostream>
using namespace std;
class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	//构造
	String(const char* str = "")
	{
		_size = strlen(str);
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	String(const String& str)
		:_str(nullptr)
		,_size(0)
		,_capacity(0)
	{
		String tmp(str._str);
		Swap(tmp);
	}

	void Swap(String& str)
	{
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_size =	_capacity = 0;
		}
	}

	//容量
	size_t Size() const
	{
		return _size;
	}

	size_t Capacity();

	void resize(size_t sz, char c = '\0')
	{
		// sz > _capacity :增容
		if (sz > _capacity)
			reserve(sz);

		// _size < sz <= _capacity :内容赋值
		if (sz > _size)
		{
			memset(_str + _size, c , sz - _size);
		}


		//sz < _size
		_size = sz;
		_str[_size] = '\0';
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	//访问
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}

	//可读可写接口
	//返回第一个元素的位置
	iterator begin()
	{
		return _str;
	}

	//返回最后一个元素的位置
	iterator end()
	{
		return _str + _size;
	}

	const iterator begin() const
	{
		return _str;
	}

	//返回最后一个元素的位置
	const iterator end() const
	{
		return _str + _size;
	}

	//只读接口
	const_iterator cbegin() const
	{
		return _str;
	}

	const_iterator cend() const
	{
		return _str + _size;
	}

	const char* c_str() const
	{
		return _str;
	}


	//修改
	void push_back(char c)
	{
		//检查容量
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		_str[_size] = c;
		++_size;
		_str[_size] = '\0';
	}

	void Append(const char* str)
	{
		int sz = strlen(str);
		if ((_size + sz) > _capacity)
		{
			reserve(_size + sz);
		}
		strcpy(_str + _size, str);
		_size += sz;
	}

	String& operator+=(char c)
	{
		push_back(c);
		return *this;
	}

	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	String& operator+=(const String& str)
	{
		Append(str._str);
		return *this;
	}

	void insert(size_t pos, char c)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//移动元素
		size_t end = _size + 1;
		while(end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}

		_str[pos] = c;
		++_size;
	}

	void insert(size_t pos, const char* str)
	{
		int sz = strlen(str);
		if (_size + sz > _capacity)
		{
			reserve(_size + sz);
		}
		size_t end = _size + sz;
		while (end > pos + sz - 1)
		{
			_str[end] = _str[end - sz];
			--end;
		}
		int i = 0;
		while (*str)
		{
			_str[pos + i] = *str++;
			++i;
		}

		_size += sz;
	}

	void erase(size_t pos, int len);

	friend ostream& operator<<(ostream& _cout, const String& str)
	{
		for (const auto& ch : str)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

void text()
{
	String s1 = "hello";
	String s2 = "world";
	String copy(s2);
}

int main()
{
	text();
	system("pasue");
	return 0;
}