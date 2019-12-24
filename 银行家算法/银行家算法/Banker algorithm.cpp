#include <iostream>
using namespace std;

//全局变量定义
#define M 100				//进程的最大
#define N 50				//资源的最大
int Available[M];			//可利用资源数组

int Max[N][M];				//最大需求矩阵
int Allocation[N][M];       //分配矩阵
int Need[N][M];             //需求矩阵

int Request[N][M];			//M个进程还需要N类资源的资源量
bool Finish[N];				//表示是否完成
int p[50];					//记录完成的顺序
int m, n;   //M个进程,N类资源

//安全性算法
int Safe()
{
	// l 用于计算当前完成的个数
	int i, j, l = 0;

	//可利用资源数组
	int Work[100]; 

	//获取当前的可用资源数组
	for (i = 0; i < n; i++)
		Work[i] = Available[i];

	//初始化Finish
	for (i = 0; i < m; i++)
		Finish[i] = false;

	for (i = 0; i < m; i++)
	{
		if (Finish[i] == 1)
			continue;
		else
		{
			//如果其中任意一项不符合跳出
			for (j = 0; j < n; j++)
			{
				if (Need[i][j] > Work[j])
				{
					cout << "第" << i << "不符合";
					break;
				}
			}

			//都符合的情况
			if (j == n)
			{
				Finish[i] = true;
				for (int k = 0; k < n; k++)
					Work[k] += Allocation[i][k];
				p[l++] = i;
				i = -1;
			}
			else continue;
		}
		if (l == m)
		{
			cout << "系统是安全的" << '\n';
			cout << "系统安全序列是:\n";
			for (i = 0; i < l; i++)
			{
				cout << p[i];
				if (i != l - 1)
					cout << "-->";
			}
			cout << endl;

			cout << "进程名" << "     " << "Max" << "     " <<
				"Allocation" << "     " << "Need" << "     "<< 
				"Finish" << endl;
			for (i = 0; i < m; ++i)
			{
				cout << "  " << "P" << i;
				cout << "       ";
				for (j = 0; j < n; ++j)
				{
					cout << Max[i][j] << ' ';
				}
				cout << "     ";
				for (j = 0; j < n; ++j)
				{
					cout << Allocation[i][j] << ' ';
				}
				cout << "     ";
				for (j = 0; j < n; ++j)
				{
					cout << Need[i][j] << ' ';
				}
				cout << "     ";

				cout << Finish[i] << ' ';
				
				cout << endl;
			}
			cout << endl;
			return 1;
		}
	}
	return 0;
}


bool Init()
{
	int i, j;

	//获取当前进程  资源
	cout << "输入进程的数目:\n";
	cin >> m;
	cout << "输入资源的种类:\n";
	cin >> n;

	//初始化 Max   Allocation 并完成Need 的计算
	cout << "输入每个进程最多所需的各类资源数,按照" << m << "x" << n << "矩阵输入\n";
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			cin >> Max[i][j];
	cout << "输入每个进程已经分配的各类资源数,按照" << m << "x" << n << "矩阵输入\n";
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> Allocation[i][j];
			Need[i][j] = Max[i][j] - Allocation[i][j];
			if (Need[i][j] < 0)
			{
				cout << "你输入的第" << i + 1 << "个进程所拥有的第" << j + 1 << "个资源错误，请重新输入:\n";
				j--;
				continue;
			}
		}
	}

	//对当前现有的资源获取
	cout << "请输入各个资源总共的数目:\n";
	for (i = 0; i < n; i++)
		cin >> Available[i];

	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			Available[j] -= Max[i][j];
			if (Available[j] < 0)
			{
				cout << "输入的值有问题，无法进行计算" << endl;
				return false;
			}
		}
	}

	cout << "各个资源现有的数目:" << endl;
	for(i = 0; i < n; ++i)
		cout << Available[i] << ' ';
	cout << endl;
	return true;
}

void need_soursce(char* Flag)
{
	//mi 为进程号
	int i, mi = 0;
	while (1)
	{
		cout << "输入要申请的资源的进程号：（第一个进程号为0，第二个进程号为1，依此类推）" << endl;
		cin >> mi;

		cout << "输入进程所请求的各个资源的数量\n";
		for (i = 0; i < n; i++)
			cin >> Request[mi][i];

		for (i = 0; i < n; i++)
		{
			//应该先判断是否超过拥有数在判断是否超过需求量
			if (Request[mi][i] > Available[i])
			{
				cout << "所请求资源数超过系统所有的资源数！\n";
				return;
			}
			if (Request[mi][i] > Need[mi][i])
			{
				cout << "所请求资源数超过进程的需求量！\n";
				return ;
			}
			
		}

		for (i = 0; i < n; i++)
		{
			Available[i] -= Request[mi][i];
			Allocation[mi][i] += Request[mi][i];
			Need[mi][i] -= Request[mi][i];
		}

		//判断是否还安全
		if (Safe())
			cout << "同意分配请求\n";
		else
		{
			cout << "SORRY……你的请求被拒绝…\n";
			for (i = 0; i < n; i++)
			{
				Available[i] += Request[mi][i];
				Allocation[mi][i] -= Request[mi][i];
				Need[mi][i] += Request[mi][i];
			}
		}
		//返回状态
		for (i = 0; i < m; i++)
			Finish[i] = 0;


		cout << "是否再次请求分配？是请按Y/y，否请按N/n" << endl;
		while (1)
		{
			cin >> *Flag;
			cout << endl;
			if (*Flag == 'Y' || *Flag == 'y' || *Flag == 'N' || *Flag == 'n')
				break;
			else
			{
				cout << "请按要求重新输入:\n";
				continue;
			}
		}
		if (*Flag == 'Y' || *Flag == 'y')
			continue;
		else break;
	}
}

//银行家算法
int main()
{
	bool pa = Init();
	
	//初始化失败
	if (pa == false)
		return 0;
	//安全性判断
	Safe();
	char Flag = 'Y';       //标志位
	while(Flag != 'n' && (Flag != 'N'))
		need_soursce(&Flag);
	
	return 0;
}