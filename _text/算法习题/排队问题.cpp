#define _CRT_SECURE_NO_WARNINGS 1
/*队伍的水平值等于该队伍队员中第二高水平值，
为了所有队伍的水平值总和最大的解法，
也就是说每个队伍的第二个值是尽可能大的值。
所以实际值把最大值放到最右边，最小是放到最左边*/

//主要思路	贪心算法
//排序---->  一共 3n个数字 将[0, n-1]的数党组每组最左边的数
//右边一次取两个最大的数字

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	//可能会出现多组测试用例
	while (cin >> n)
	{
		long sum = 0;
		vector<int> a;

		//保证vector的大小可以存入
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		//排序  取下标为3n-2 -4  ...

		std::sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
}

