#include<vector>
#include<iostream>
using namespace std;

void  _GetSum(vector<vector<int>>& fin, vector<vector<int>>& tmp, int row, int col, int i, int j)
{
	if (fin[i][j] == 1 && tmp[i][j] == 0)
	{
		tmp[i][j] = 1;
		if (i - 1 >= 0)
			_GetSum(fin, tmp, row, col, i - 1, j);
		if (i + 1 < row)
			_GetSum(fin, tmp, row, col, i + 1, j);
		if (j - 1 >= 0)
			_GetSum(fin, tmp, row, col, i, j - 1);
		if (j + 1 < col)
			_GetSum(fin, tmp, row, col, i, j + 1);
	}
	return;
}

int GetSum(vector<vector<int>>& fin, int row, int col, int count)
{
	int Sum = 0;
	vector<vector<int>> tmp(row, vector<int>(col, 0));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (fin[i][j] == 1 && tmp[i][j] == 0)
			{
				_GetSum(fin, tmp, row, col, i, j);
				++Sum;
			}
		}
	}
	return Sum;
}

int main()
{
	int row, col;
	cin >> row >> col;
	vector<vector<int>> fin(row, vector<int>(col, 0));
	int count = 0;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> fin[i][j];
			if (fin[i][j] == 1)
				++count;
		}
	}
	int sum = GetSum(fin, row, col, count);
	return 0;
}