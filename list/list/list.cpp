#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

void TestList1()
{
	List<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	List<int> lst1;
	lst1 = lst;
	List<int>::iterator lit = lst.begin();
	while (lit != lst.end())
	{
		cout << *lit << " ";
		++lit;
	}
}

int main()
{
	TestList1();
	return 0;
}