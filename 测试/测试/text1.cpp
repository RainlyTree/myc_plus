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

void print(int)
{
	cout << "123" << endl;
}

//虚表

class Base
{
public:
	virtual void fun1()
	{
		cout << "base::func1" << endl;
	}
	virtual void fun2()
	{
		cout << "base::func2" << endl;
	}
private:
	int a;
};
class Derive : public Base
{
public:
	virtual void fun1()override
	{
		cout << "Derve::func1" << endl;
	}
	virtual void func3()
	{
		cout << "derve::func3" << endl;
	}
	virtual void func4()
	{
		cout << "derve::func4" << endl;
	}
private:
	int b;
};
typedef void(*VFpter) ();
void PrintVT(VFpter table[])
{
	cout << "虚表地址 : " << table << endl;
	for (int i = 0; table[i] != nullptr; ++i)
	{
		printf("第 %d 个虚函数地址 : %x", i, table[i]);
		VFpter f = table[i];
		f();
	}
	cout << endl;
}




//菱形继承与虚机表
//class A
//{
//public:
//	int a;
//};
//class B : virtual public A
//{
//public:
//	int b;
//};
//class C : virtual public A
//{
//public:
//	int c;
//};
//class D : public B, public C
//{
//public:
//	int d;
//};
//void test()
//{
//	D d;
//	d.B::a = 1;
//	d.C::a = 2;
//	d.b = 3;
//	d.c = 4;
//	d.d = 5;
//}

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



int lengthOfLIS(vector<int>& nums) {
	if (nums.empty() == 1)
		return 0;
	vector<int> fin;
	fin.push_back(nums[0]);
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] > fin[fin.size() - 1])
		{
			fin.push_back(nums[i]);
		}
		else
		{
			int fir = 0, sec = fin.size() - 1, len = 0;
			while (fir <= sec)
			{
				int in_ = (fir + sec) >> 1;
				if (fin[in_] > nums[i])
				{
					sec = in_ - 1;
				}
				else
				{
					len = in_;
					fir = in_ + 1;
				}
			}
			if (fin[len] == nums[i])
				;
			else
				fin[len + 1] = nums[i];
		}
	}
	return fin.size();

}

int dfs(vector<vector<int>>& grid, int cur_i, int cur_j)
{
	if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size()
		|| grid[cur_i][cur_j] == 0)
		return 0;
	grid[cur_i][cur_j] == 0;
	int di[4] = { 0, 0, 1, -1 };
	int dj[4] = { 1, -1, 0, 0 };
	int ans = 1;
	for (int k = 0; k < 4; k++)
	{
		int n_i = cur_i + di[k];
		int n_j = cur_j + dj[k];
		ans += dfs(grid, n_i, n_j);
	}
	return ans;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
		int row = grid[0].size();
		int col = grid.size();
		int len = 0;
		for (int i = 0; i < col; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				len = max(len, dfs(grid, i, j));
			}
		}
		return len;
	}

//class A
//{
//public:
//	void f1() { cout << "A::f1()" << endl; }
//	virtual void f2() { cout << "A::f2()" << endl; }
//	virtual void f3() { cout << "A::f3()" << endl; }
//};
//
//class B : public A
//{
//public:
//	virtual void f1() { cout << "B::f1()" << endl; }
//	virtual void f2() { cout << "B::f2()" << endl; }
//	void f3() { cout << "B::f3()" << endl; }
//};




vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> fin;
	if (matrix.empty() == 1)
		return fin;
	int row = matrix[0].size();
	int col = matrix.size();
	//mini 限制 i , minj 限制 j
	int mini = 0, minj = 0;
	int i = 0, j = 0;
	while (1)
	{
		if (row - 1 < minj && col - 1 < mini)
		{
			fin.push_back(matrix[i][j]);
			break;
		}
		//如果只有一行
		if (col - mini == 1)
		{
			for (int k = minj; k < row; ++k)
			{
				fin.push_back(matrix[mini][k]);
			}
			break;
		}
		if (row - minj == 1)
		{
			for (int k = mini; j < col; ++k)
			{
				fin.push_back(matrix[k][minj]);
			}
			break;
		}
		while (j < row)
		{
			fin.push_back(matrix[i][j]);
			++j;
		}
		--j;
		++i;
		while (i < col)
		{
			fin.push_back(matrix[i][j]);
			++i;
		}
		--i;
		--j;
		while (j >= minj)
		{
			fin.push_back(matrix[i][j]);
			--j;
		}
		++j;
		while (i > mini + 1)
		{
			--i;
			fin.push_back(matrix[i][j]);
		}
		row--;
		col--;
		i = ++mini;
		j = ++minj;
	}
	return fin;
}

//多态测试
class base
{
public:
	virtual void show()
	{
		cout << "base" << endl;
	}
};

class base1
{
public:
	virtual void show1()
	{
		cout << "base1" << endl;
	}
};

class A : public base ,public base1
{
public:
	virtual void show () override
	{
		cout << "A" << endl;
	}
	virtual void show1()
	{
		cout << "a1" << endl;
	}
	virtual void show2()
	{
		cout << "a2" << endl;
	}
};

void fun(base& A)
{
	A.show();
}

int main(int argc, char* argv[])
{
	A a;
	base& pt = a;
	return 0;
}