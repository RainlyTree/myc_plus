#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//对于string类接口的学习使用！


// 第一种：构造函数
//default(1)
//string();
//copy(2)
//string(const string& str);
//substring(3)
//string(const string& str, size_t pos, size_t len = npos);
//from c - string(4)
//string(const char* s);
//from sequence(5)
//string(const char* s, size_t n);
//fill(6)
//string(size_t n, char c);
//range(7)
//template <class InputIterator>
//string(InputIterator first, InputIterator last);

//创建string类
void Makestring()
{
	//构造函数
	string s1;
	string s2("hello world");
	//拷贝构造
	string s3(s2);
	string s4(s2, 0, 5);	//hello
	string s5("hello world", 5); //hello
	string s7(10, 'a');		//aaaaaaaaaa
	string s6(s2, 1);	//ello world
	//赋值构造
	string s8 = "hello";
}

//迭代器:不会破坏内容	访问内容解引用 下一个位置就++
void TextIterators()
{
	string s("hello world");
	/*
		迭代器:一种容器内容的访问形式
		使用方式:类似于指针的使用方式
		begin():指向容器的第一个元素的位置
		end():指向容器的最后一个元素的下一个位置
		左闭右开
	*/
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	//for循环方式
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << "";
	}
	cout << endl;

	//范围for循环方式
	for (const auto& ch : s)
	{
		cout << ch << "";
	}
	cout << endl;

	//const 迭代器
	const string s1("hello world");
	string::const_iterator s1it = s1.begin();
	while (s1it != s1.end())
	{
		cout << *s1it ;
		s1it++;
	}
	cout << endl;


	/*
		反向迭代器
		rbegin()
		rend()
		向后移动还是 ++ 操作
	*/

	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit;
		rit++;
	}
	cout << endl;

	const string s3("hello world");
	string::const_reverse_iterator s3it = s3.rbegin();
	while (s3it != s3.rend())
	{
		cout << *s3it;
		s3it++;
	}
	cout << endl;

}

// 容器接口
void TextCapacity()
{
	string s1("hello world");
	//当前字符串大小 不算\0
	cout << s1.size() << endl;
	//最大的大小
	cout << s1.max_size() << endl;
	//可以存放字符的空间
	cout << s1.capacity() << endl;
	//改变字符串的大小 可以任意修改
	s1.resize(20);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << "end" << endl;
	//改变容量的大小 只能增加容量，不会减少容量
	s1.reserve(50);
	cout << s1.capacity() << endl;
	//判断当前字符串是否为空
	cout << s1.empty() << endl;
	//清空内容  不会改变容量的大小
	s1.clear();
	cout << s1.empty() << endl;
	cout << s1.capacity() << endl;
	//减小容量的接口	系统自动判断减小多少
	s1.shrink_to_fit();
	cout << s1.capacity() << endl;
}

//元素访问的接口 + 增删查改接口
void TextElement()
{
	string s1("hello world");
	cout << s1[2] << endl;
	cout << s1.at(2) << endl;
	//显示最后一个字符
	cout << s1.back() << endl;
	//显示第一个字符
	cout << s1.front() << endl;

	//尾插单个字符 + 尾删单个字符
	s1.push_back('a');
	s1.pop_back();
	cout << s1 << endl;

	/*
string (1)
	string& append (const string& str);
substring (2)
	string& append (const string& str, size_t subpos, size_t sublen);
c-string (3)
	string& append (const char* s);
buffer (4)
	string& append (const char* s, size_t n);
fill (5)
	string& append (size_t n, char c);
range (6)
	template <class InputIterator>
   string& append (InputIterator first, InputIterator last);
	*/
	string s2;

	s2.append("012");
	cout << s2 << endl;
	
	s2.append("345", 3);
	cout << s2 << endl;
	
	string s3("678");
	s2.append(s3);
	cout << s2 << endl;

	string s4("91011");
	s2.append(s4, 0, 5);
	cout << s2 << endl;
	//数组天然就是迭代器
	char str[] = { "121314" };
	s2.append(str, str + sizeof(str) / sizeof(str[0]));
	cout << s2 << endl;
}

void TextInsert()
{
	/*
string (1)
	string& insert (size_t pos, const string& str);
substring (2)
	string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
c-string (3)
	string& insert (size_t pos, const char* s);
buffer (4)
	string& insert (size_t pos, const char* s, size_t n);
fill (5)
	string& insert (size_t pos, size_t n, char c);
	void insert (iterator p, size_t n, char c);
single character (6)
	iterator insert (iterator p, char c);
range (7)
	template <class InputIterator>
   void insert (iterator p, InputIterator first, InputIterator last)
	*/
	string s("123");
	cout << s << endl;
	//在当前位置的前面插入
	s.insert(0, "0");
	cout << s << endl;
	s.insert(0, "-2-1");
	cout << s << endl;
	string s2("456");
	s.insert(8, s2);
	cout << s << endl;
	s.insert(s.begin() + 4, '-');
	cout << s << endl;
	char str[] = { "1112" };
	s.insert(s.end(),str, str + sizeof(str) / sizeof(str[0]));
	cout << s << endl;


}

//覆盖接口 (辣鸡借口  还不如用=)
void TextAssign()
{
	string s1("123");
	cout << s1 << endl;
	string s2("4");
	s1.assign(s2);
	cout << s1 << endl;
}

// += 接口 (特别常用)
// replace接口
//cin 与 getline()
void TextUsuall()
{
	string s1;
	s1 += '0';
	cout << s1 << endl;
	s1 += "123";
	cout << s1 << endl;

	string s("01234");
	cout << s << endl;
	string s2("56789");
	s.replace(3, 1, s2);	//将一个字符替换后面的整个字符串
	cout << s << endl;


	string s3;
	//cin 遇到 空格停止接收
	cin >> s3;
	cout << s3 << endl;
	//getline()默认遇到回车停止接收
	//可以通过第三个参数修改停止接收的符号
	getline(cin, s3);
	cout << s3 << endl;
}



int main()
{
	//Makestring();
	//TextIterators();
	//TextCapacity();
	//TextElement();
	//TextInsert();
	//TextAssign();
	TextUsuall();
	system("pause");
	return 0;
}