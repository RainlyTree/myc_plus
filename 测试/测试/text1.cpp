#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//
//using namespace std;
//
//enum color {
//	NONE, WHITE, BLACK,         //棋子颜色，NONE表示未落子
//};
//struct weiqi {
//	enum color board[19][19];   //棋盘上每个位置的落子
//};
//
//int _calc(struct weiqi* wq, int x, int y, int need, int* sum)
//{
//	if (x < 0 || y < 0 || x > 18 || y > 18)
//		return 0;
//	if (wq->board[y][x] == NONE)
//		return 0;
//	if (wq->board[y][x] == need)
//	{
//		wq->board[y][x] = NONE;
//		++(*sum);
//	}
//	else
//		return 0;
//	return _calc(wq, x + 1, y, need, sum) + _calc(wq, x - 1, y, need, sum) +
//		_calc(wq, x, y + 1, need, sum) + _calc(wq, x, y - 1, need, sum);
//}
//
//int calc(struct weiqi *wq, int x, int y)
//{
//	TODO:
//	int sum = 0;
//	_calc(wq, x, y, wq->board[y][x], &sum);
//	return sum;
//}
//
//
//
//int input(struct weiqi *wq, int *x, int *y)
//{
//	int row, col;
//	int ret;
//	char buf[80];
//
//	for (row = 0; row < 19; ++row) {
//		if (fgets(buf, sizeof(buf), stdin) == NULL)
//			return -1;
//		if (strlen(buf) < 19)
//			return -1;
//		for (col = 0; col < 19; ++col) {
//			switch (buf[col]) {
//			case '0':
//				wq->board[row][col] = NONE;
//				break;
//			case '1':
//				wq->board[row][col] = WHITE;
//				break;
//			case '2':
//				wq->board[row][col] = BLACK;
//				break;
//			default:
//				return -1;
//			}
//		}
//	}
//	ret = fscanf(stdin, "%d,%d\n", x, y);
//	if (ret != 2)
//		return -1;
//	for (row = 0; row < 19; ++row) {
//		for (col = 0; col < 19; ++col) {
//			fprintf(stderr, "%d ", wq->board[row][col]);
//		}
//		fprintf(stderr, "\n");
//	}
//	fprintf(stderr, "x = %d, y = %d\n", *x, *y);
//	return 0;
//}
//
//int main()
//{
//	struct weiqi wq;
//	int x = 0, y = 0;
//	int cnt;
//
//	memset(&wq, 0, sizeof(wq));
//	if (input(&wq, &x, &y) < 0) {
//		fprintf(stderr, "error!\n");
//		return 1;
//	}
//	cnt = calc(&wq, x, y);
//
//	printf("%d\n", cnt);
//	return 0;
//}


//#include <stdio.h>
//#include <malloc.h>
//#include <iostream>
//using namespace std;
//
//struct node {
//	int val;
//	struct node *next;
//};
//
//static void list_sort(struct node *head);
//
//
//struct node *list_create(int arr[], int size)
//{
//	struct node *head = NULL;
//	int i;
//	for (i = size - 1; i >= 0; --i) {
//		struct node *p = (struct node *)malloc(sizeof(struct node));
//
//		p->val = arr[i];
//		p->next = head;
//		head = p;
//	}
//	return head;
//}
//static void list_print(struct node *head)
//{
//	for (; head; head = head->next) {
//		printf("%d", head->val);
//		if (head->next)
//			printf(" ");
//	}
//	printf("\n");
//}
//static void list_free(struct node *head)
//{
//	struct node *next;
//	while (head) {
//		next = head->next;
//		free(head);
//		head = next;
//	}
//}
//static int input(int **arr, int *size)
//{
//	int i;
//	int ret;
//
//	ret = fscanf(stdin, "%d\n", size);
//	if (ret != 1)
//		return -1;
//	*arr = (int *)malloc(sizeof(int) * (*size));
//	for (i = 0; i < *size; ++i) {
//		fscanf(stdin, "%d ", &(*arr)[i]);
//	}
//	return 0;
//}
//
//int main(int argc, char *argv[])
//{
//	struct node *head;
//	int *arr = NULL;
//	int size = 0;
//
//	if (input(&arr, &size) < 0) {
//		fprintf(stderr, "input error\n");
//		return 0;
//	}
//	head = list_create(arr, size);
//	list_sort(head);
//	list_print(head);
//	list_free(head);
//	free(arr);
//	return 0;
//}
//
//static void list_sort(struct node *head)
//{
//	TODO:
//	struct node* head1 = head;
//	struct node* head2 = head->next;
//	int len = 0;
//	while (head1 != NULL)
//	{
//		++len;
//		head1 = head1->next;
//	}
//	if (len <= 1)
//		return;
//	head1 = head;
//
//	for (int i = 0; i < len - 1; ++i)
//	{
//		head1 = head;
//		head2 = head->next;
//		for (int j = 0; j < len - i - 2; ++j)
//		{
//			if (head1->val > head2->val)
//			{
//				swap(head1->val, head2->val);
//			}
//			head1 = head1->next;
//			head2 = head2->next;
//		}
//	}
//}


//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int num = 0;
//	while (cin >> num)
//	{
//		int sum = 0;
//		vector<int> fin(num, 0);
//		for (int i = 0; i < num; ++i)
//		{
//			int tmp;
//			cin >> tmp;
//			sum += tmp;
//			fin[i] = tmp;
//		}
//		int avg = sum / num;
//		int number = 0;
//		bool flag = true;
//		for (int i = 0; i < num; ++i)
//		{
//			if (abs(fin[i] - avg) % 2 != 0)
//			{
//				cout << -1 << endl;
//				flag = false;
//				break;
//			}
//			else
//			{
//				number = abs(fin[i] - avg) / 2;
//			}
//		}
//		if (flag)
//			cout << number / 2 << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<map>
//using namespace std;
//int main()
//{
//	int num = 0;
//	while (cin >> num)
//	{
//		int sum = num;
//		map<int, int> fin;
//		for (int i = 0; i < num; ++i)
//		{
//			int tmp;
//			cin >> tmp;
//			++fin[tmp];
//		}
//		int avg = num / 2;
//		auto it = fin.begin();
//		while (it != fin.end())
//		{
//			num -= it->second;
//			if (num == avg)
//			{
//				cout << it->first << endl;
//				break;
//			}
//			++it;
//		}
//
//		cin >> num;
//		sum += num;
//		for (int i = 0; i < num; ++i)
//		{
//			int tmp;
//			cin >> tmp;
//			++fin[tmp];
//		}
//		avg = sum / 2;
//		it = fin.begin();
//		while (it != fin.end())
//		{
//			sum -= it->second;
//			if (sum == avg)
//			{
//				cout << it->first << endl;
//				break;
//			}
//			++it;
//		}
//	}
//	return 0;
//}

//#include<iostream>
//#include<mutex>
//#include<thread>
//using namespace std;
//
//int main()
//{
//	const int ci = 20;
//	const int* pci = &ci;
//	int* pci2 = const_cast<int*> (&ci);
//	*pci2 = 30;
//
//	cout << ci << endl;
//	cout << *pci << endl;
//	cout << *pci2 << endl;
//	return 0;
//}

//
//#include<iostream>
//#include<string>
//using namespace std;
//int main() {
//	string str;
//	while (cin >> str);
//	cout << str.size() << endl;
//	return 0;
//}

#include<stdio.h>
#include<string.h>
unsigned char i = 0;
int main()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");
	}
	return 0;
}