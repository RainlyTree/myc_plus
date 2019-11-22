#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<assert.h>
//void ReplaceBlank(char *str, int len)
//{
//	int NumBlank = 0;
//	int i = 0;
//	int mlen = 0;
//	int newLen = 0;
//	int indexofMyLen = 0;
//	int indexofNewLen = 0;
//	assert(str != NULL);
//	while (str[i] != '\0')
//	{
//		++mlen;//strlen();
//		if (str[i] == ' ')
//		{
//			++NumBlank;//空格的个数
//		}
//		i++;
//	}
//	//新的数组的长度
//	newLen = mlen + NumBlank * 2 + 1;
//	if (newLen > len)
//	{
//		return;
//	}
//	indexofMyLen = mlen;
//	indexofNewLen = newLen - 1;
//
//	while (indexofMyLen >= 0
//		&& indexofNewLen > indexofMyLen)
//	{
//		if (str[indexofMyLen] == ' ')
//		{
//			str[indexofNewLen--] = '0';
//			str[indexofNewLen--] = '2';
//			str[indexofNewLen--] = '%';
//		}
//		else
//		{
//			str[indexofNewLen] = str[indexofMyLen];
//
//			indexofNewLen--;
//		}
//		indexofMyLen--;
//	}
//}
//
//int main()
//{
//	char str[25] = "bd de f";
//	int len = sizeof(str) / sizeof(str[0]);
//	ReplaceBlank(str, len);
//	printf("%s\n", str);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int a = 2;
//	int b = 7;
//	int ret = (a&b) + ((a^b) >> 1);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//
//
//int fun(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else if (n = 2)
//	{
//		return 2;
//	}
//	else
//	{
//
//	}
//}
//
//int main()
//{
//	printf("%d\n", fun(4);
//	system("pause");
//	return 0;
//}


//int mergeStones(int* stones, int stonesSize, int K) {
//	int num = (stonesSize / K) + (stonesSize % K);
//	while (num > K)
//		num = (stonesSize / K) + (stonesSize % K);
//	if (num == K || stonesSize == K)
//	{
//		int x1 = 0;
//		int min = 0x8000000;
//		int tmp;
//		for (int i = 0; i < (stonesSize - K + 1); i++)
//		{
//			tmp = stones[i];
//			for (int j = i + 1; j < i + K; j++)
//			{
//				tmp += stones[j];
//			}
//			if (min > tmp)
//			{
//				x1 = i;
//				min = tmp;
//			}
//		}
//		stones[x1] = min;
//		int i;
//		for (i = x1 + 1; i < stonesSize - K + 1; i++)
//		{
//			stones[i] = stones[i + K - 1];
//		}
//		stones[stonesSize - 1] = stones[x1];
//		stonesSize = stonesSize - K + 1;
//		if (stonesSize != 1)
//		{
//			mergeStones(stones, stonesSize, K);
//		}
//		int sum = 0;
//		for (i = 0; i < stonesSize + K - 1; i = i + K - 1)
//		{
//			sum += stones[i];
//		}
//		sum = sum - stones[K - 1];
//		return sum;
//	}
//	return -1;
//}
//
//
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//};
//
//struct TreeNode;
//typedef struct TreeNode TreeNode;
//
//void _treestr(TreeNode* t, char* str)
//{
//	//如果是空，直接返回
//	if (t == NULL)
//		return;
//	//将节点转化为字符
//	char buff[10];
//	sprintf(buff, "%d", t->val);
//	strcat(str, buff);
//
//	//处理左侧
//	if (t->left == NULL)
//	{
//		if (t->right == NULL)
//			return;
//		else
//		{
//			strcat(str, "()");
//		}
//	}
//	else
//	{
//		strcat(str, "(");
//		_treestr(t->left, str);
//		strcat(str, ")");
//	}
//
//	//处理右子树
//	if (t->right == NULL)
//	{
//		return;
//	}
//	else
//	{
//		strcat(str, "(");
//		_treestr(t->right, str);
//		strcat(str, ")");
//	}
//
//}
//
//char *tree2str(struct TreeNode* t) {
//	char *str = (char*)malloc(sizeof(char)*1000000);
//	str[0] = '\0';
//	_treestr(t, str);
//	return str;
//}
//int main()
//{
//	TreeNode *text = (TreeNode*)malloc(sizeof(TreeNode));
//	TreeNode *text1 = (TreeNode*)malloc(sizeof(TreeNode));
//	TreeNode *text2 = (TreeNode*)malloc(sizeof(TreeNode));
//	TreeNode *text3 = (TreeNode*)malloc(sizeof(TreeNode));
//	text->val = 1;
//	text->left = text1;
//	text->right = text2;
//
//	text1->val = 2;
//	text1->left = text3;
//	text1->right = NULL;
//	
//	text2->val = 3;
//	text2->left = NULL;
//	text2->right = NULL;
//
//	text3->val = 4;
//	text3->left = NULL;
//	text3->right = NULL;
//
//	char* textchar = tree2str(text);
//	printf("%s", textchar);
//	system("pause");
//	return 0;
//}

int main()
{
	int a = 10;
	int *p = &a;
	printf("%d\n", a);
	printf("%d\n", *p);
	printf("%d", p);
	system("pause");
	return 0;
}