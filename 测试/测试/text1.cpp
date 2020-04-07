#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class A
{
public:
	virtual void show()
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	virtual void show() override
	{
		cout << "B" << endl;
	}
};

int main(int argc, char* argv[])
{
	A a;
	B b;
	A& pa = b;
	a.show();
	b.show();
	pa.show();
	return 0;
}