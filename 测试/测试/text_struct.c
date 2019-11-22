#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#if 0
union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
int main()
{
	//下面输出的结果是什么？
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
	system("pause");
	return 0;
}

struct MyStruct
{
	int i;
	char c1;
	char c2;
};
int main()
{
	struct MyStruct p = { 1,3,4 };
	printf("%d", sizeof(struct MyStruct));
	system("pause");
	return 0;
}
#endif