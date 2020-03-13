#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//测试函数重载 (个数 类型 顺序)
int Add(int left, double right)
{
	return left + right;
}

int Add(double right, int left)
{
	return left + right;
}


//测试模板
template<class T>
T Add(const T& A, const T& B)
{
	return A + B;
}

typedef void(*test)(int);

void print(int)
{
	cout << "123" << endl;
}



int orangesRotting(vector<vector<int>>& grid) {
	int num = 0;
	queue<pair<int, int>> tmp;
	int len = grid.size();
	int lon = grid[0].size();
	int arr[1 + 2][9 + 2] = { 0 };
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < lon; ++j)
		{
			arr[i + 1][j + 1] = grid[i][j];
		}
	}
	for (int i = 1; i < len + 1; ++i)
	{
		for (int j = 1; j < lon + 1; ++j)
		{
			if (arr[i][j] == 2)
			{
				tmp.push(make_pair(i, j));
			}
		}
	}
	while (tmp.empty() != 1)
	{
		bool flag = false;
		int time = tmp.size();
		while (time > 0)
		{
			int i = tmp.front().first;
			int j = tmp.front().second;
			tmp.pop();
			if (i <= 0 || j <= 0)
				return 0;
			if (arr[i - 1][j] == 1)
			{
				tmp.push(make_pair(i - 1, j));
				arr[i - 1][j] = 2;
				flag = true;
			}
			if (arr[i + 1][j] == 1)
			{
				tmp.push(make_pair(i + 1, j));
				arr[i + 1][j] = 2;
				flag = true;
			}
			if (arr[i][j - 1] == 1)
			{
				tmp.push(make_pair(i, j - 1));
				arr[i][j - 1] = 2;
				flag = true;
			}
			if (1 == arr[i][j + 1])
			{
				tmp.push(make_pair(i, j + 1));
				arr[i][j + 1] = 2;
				flag = true;
			}
			--time;
		}
		if (flag == true)
			++num;
	}

	for (int i = 1; i < len + 1; ++i)
	{
		for (int j = 1; j < lon + 1; ++j)
		{
			if (arr[i][j] == 1)
			{
				num = -1;
				break;
			}
		}
	}
	return num;
}

bool canThreePartsEqualSum(vector<int>& A) {
	int sum = 0;
	int size = A.size();
	for (int i = 0; i < size; ++i)
	{
		sum += A[i];
	}
	if (sum % 3 != 0)
		return false;
	sum /= 3;
	int i = 0;
	int j = size - 1;
	int sumi = 0, sumj = 0;
	while (i < j)
	{
		if (sumi != sum)
		{
			sumi += A[i];
			++i;
		}
		if (sumj != sum)
		{
			sumj += A[j];
			--j;
		}
		if (sumi == sumj)
			break;
	}
	if (i < j)
	{
		int sum_ = 0;
		for (; i <= j; ++i)
		{
			sum_ += A[i];
		}
		if (sum_ == sumi)
			return true;
	}
	return false;
}

int add(int a, int b) {
	while (b != 0)
	{
		int sum = a ^ b;
		unsigned int go_ = (a & b) << 1;
		a = sum;
		b = go_;
	}
	return a;
}



int main()
{
	//vector<int> arr = { 1,-1,1,-1 };
	//canThreePartsEqualSum(arr);
	//orangesRotting(arr);
	//add(-1, 2);
	//f();
	
	return 0;
}