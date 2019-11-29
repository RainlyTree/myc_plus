#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	string name = "1111111111";	//进程标识符
	int Tarrive = 0;	//进入时间
	float Tservice = 0;	//服务时间
	int Tsurplus = 0;	//剩余时间
	int Tstart = 0;		//开始时间
	int Taccomplish = 0;//完成时间
	float TZz = 0;		//周转时间
	float TDqZz = 0;		//带权周转时间
	int prio = 0;		//优先级-->数字越大优先级越高
	int if_finish = 0;	//进程是否完成
	//int num;		//进程个数
};

//按到达时间排序
void Arrive_sort(int num, vector<Node*>& job)
{
	for (int i = job.size() - num; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i]->Tarrive > job[j]->Tarrive)
			{
				swap(job[i], job[j]);
			}
		}
	}
}

//按服务时间排序
void Service_sort(int num, vector<Node*>& job)
{
	for (int i = job.size() - num; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i]->Tservice > job[j]->Tservice)
			{
				swap(job[i], job[j]);
			}
		}
	}
}

//按优先级排序
void Priority_sort(int num, vector<Node*>& job)//按优先级减小排序
{
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i]->prio < job[j]->prio)
			{
				swap(job[i], job[j]);
			}
		}
	}
}

//如果到达时间相等，服务时间按从小到大排序
void Arrive_Short_sort(int num, vector<Node*>& job)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i]->Tarrive >= job[j]->Tarrive)
			{
				if (job[i]->Tarrive > job[j]->Tarrive)
				{
					swap(job[i], job[j]);
				}
				else
				{
					if (job[i]->Tservice > job[j]->Tservice)
					{
						swap(job[i], job[j]);
					}
				}
			}
		}
	}
}

//FCFS算法
void fcfs(int num, vector<Node*>& job)//先来先服务
{
	//第一个开始时间 是它的到达时间
	job[0]->Tstart = job[0]->Tarrive;
	//第一个完成时间 是它的开始+服务时间
	job[0]->Taccomplish = job[0]->Tstart + job[0]->Tservice;
	//第一个周转时间 == 它的服务时间
	job[0]->TZz = job[0]->Tservice;
	//第一个带权周转时间 == 周转时间/服务时间
	job[0]->TDqZz = job[0]->TZz / job[0]->Tservice;
	for (int i = 1; i < num; i++)
	{
		job[i]->Tstart = job[i - 1]->Taccomplish;//上一个作业结束时间
		//判断上一个进程结束之后是否下一个进程已经进入
		if (job[i]->Tstart < job[i]->Tarrive)
		{
			job[i]->Tstart = job[i]->Tarrive;
		}
		else
		{
			job[i]->Tstart = job[i - 1]->Taccomplish;
		}
		//完成时间 = 开始 + 服务时间
		job[i]->Taccomplish = job[i]->Tstart + job[i]->Tservice;
		//周转时间 == 完成时间-到达时间
		job[i]->TZz = job[i]->Taccomplish - job[i]->Tarrive;
		//带权周转时间 == 周转时间/服务时间
		job[i]->TDqZz = job[i]->TZz / job[i]->Tservice;
	}
}

//短作业优先
void sjf(int num, vector<Node*> job)
{
	//当前的结束时间
	float tmpnum = num;
	//按到达时间排序
	Arrive_sort(tmpnum, job);
	//第一个要进行的任务
	for (int i = 1; i < num; ++i)
	{
		//如果找到时间与第一个相同的时间但服务时间比他小 交换
		if (job[0]->Tarrive == job[i]->Tarrive && job[0]->Tservice > job[i]->Tservice)
		{
			swap(job[0], job[1]);
		}
	}
	--tmpnum;
	//完成时间 = 开始 + 服务时间
	job[0]->Taccomplish = job[0]->Tstart + job[0]->Tservice;
	//周转时间 == 完成时间-到达时间
	job[0]->TZz = job[0]->Taccomplish - job[0]->Tarrive;
	//带权周转时间 == 周转时间/服务时间
	job[0]->TDqZz = job[0]->TZz / job[0]->Tservice;

	for (int i = 1; i < num; i++)
	{
		//对剩下的进行服务排序
		Service_sort(tmpnum, job);
		//记录当前进行的位置
		int tmp = i;
		//判断当前的最小服务时间是否在已经进入
		for (int j = i; j < num; ++j)
		{
			//如果在已经进入
			if (job[j]->Tstart < job[i - 1]->Taccomplish)
			{
				break;
			}
			//还没有进入
			else
			{

			}
		}
		job[i]->Tstart = job[i - 1]->Taccomplish;//上一个作业结束时间
		if (job[i]->Tstart < job[i]->Tarrive)//该作业的开始时间小于到达时间
		{
			job[i]->Tstart = job[i]->Tarrive;
		}
		else
		{
			job[i]->Tstart = job[i - 1]->Taccomplish;
		}
		job[i]->Taccomplish = job[i]->Tstart + job[i]->Tservice;
		job[i]->TZz = job[i]->Taccomplish - job[i]->Tarrive;
		job[i]->TDqZz = job[i]->TZz / job[i]->Tservice;
	}
}

//时间片轮转算法
void RR(int num, vector<Node*> job)//RR算法
{
	int q;
	cout << "请输入时间片长度：" << endl;
	cin >> q;
	int flag = 1;//标志队列中是否还有进程
	int finish_pro = 0;//完成的进程数
	cout << "进程名称\t" << "开始时间\t" << "运行时间\t" << "剩余服务时间\t" << "结束时间\t" << endl;
	int time;//记录当前时刻时间
	int c = 0;
	while (finish_pro < num)
	{
		flag = 0;//就绪队列里没进程
		for (int i = c; i < num; i++)
		{
			//到达排序
			Arrive_sort(num, job);
			//把服务时间给剩余时间
			job[i]->Tsurplus = job[i]->Tservice;
			//当前的开始时间 = 上一个作业结束时间
			job[i]->Tstart = job[i - 1]->Taccomplish;
			//该作业的开始时间小于到达时间
			if (job[i]->Tstart < job[i]->Tarrive)
			{
				job[i]->Tstart = job[i]->Tarrive;
			}
			else
			{
				job[i]->Tstart = job[i - 1]->Taccomplish;
			}
			time = job[i]->Tstart;
			if (job[i]->if_finish == 1) 
				continue;//该进程已完成
			else
			{
				if (job[i]->Tsurplus <= q && time >= job[i]->Tarrive)//未完成且少于一个时间片
				{
					flag = 1;
					time = time + job[i]->Tsurplus;
					job[i]->if_finish = 1;//该进程完成
					job[i]->Taccomplish = time;
					cout << job[i]->name << "\t\t" << job[i]->Taccomplish - job[i]->Tsurplus << "\t\t" << job[i]->Tsurplus << "\t\t" << 0 << "\t\t" << job[i]->Taccomplish << endl;
					job[i]->Tsurplus = 0;
				}
				else if (job[i]->Tsurplus > q && time >= job[i]->Tarrive)
				{
					flag = 1;
					time = time + q;
					job[i]->Tsurplus -= q;
					job[i]->Taccomplish = time;
					cout << job[i]->name << "\t\t" << time - q << "\t\t" << q << "\t\t" << job[i]->Tsurplus << "\t\t" << job[i]->Taccomplish << endl;
					job[num]->name = job[i]->name;
					job[num]->Tarrive = time;
					job[num]->Tservice = job[i]->Tsurplus;
					num++;
				}
				if (job[i]->if_finish == 1) finish_pro++;//一个进程完成加一
			}
			c++;
		}break;
		if (flag == 0 && finish_pro < num)//没执行完且没进入就绪队列
		{
			for (int i = 0; i < num; i++)
			{
				if (job[i]->if_finish == 0)
				{
					time = job[i]->Tarrive;
					break;
				}
			}
		}
	}
}

//输出函数
void print(int num, vector<Node*>& job)
{
	cout << "进程名" << "\t" << "到达时间" << "\t" << "服务时间" << "\t" << "完成时间" 
		<< "\t" << "周转时间" << "\t" << "带权周转" << endl;

	for (int i = 0; i < num; i++)
	{
		cout << job[i]->name << "\t" << job[i]->Tarrive << "\t\t" << job[i]->Tservice << "\t\t" << job[i]->Taccomplish 
			<< "\t\t" << job[i]->TZz << "\t\t"  << job[i]->TDqZz << endl;
	}
}



void display(int num,vector<Node*> job)
{
	int ch = 0;
	cout << "—————————————————————————" << endl;
	cout << "——————————1、FCFS算法 —————————" << endl;
	cout << "——————————2、SJF算法——————————" << endl;
	cout << "——————————3、时间片轮转算法 ——————" << endl;
	cout << "——————————4、优先级算法 ————————" << endl;
	cout << "——————————5、退出 ———————————" << endl;
	cout << "—————————————————————————" << endl;
	do {
		cout << "请选择你想要的算法：" << endl;
		cin >> ch;
		switch (ch) {
		case 1:
			Arrive_sort(num, job);
			fcfs(num, job);
			print(num, job);
			break;
		case 2:
			sjf(num, job);
			print(num, job);
			break;
		case 3:
			RR(num, job);
			break;
		case 4:
			/*Priority_sort(num);*/
			break;
		case 5:
			exit;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
	} while (ch != 5);
}

int main()
{
	int num;
	cout << "请输入进程个数：" << endl;
	cin >> num;
	//开num个存放Node指针的数组
	vector<Node*> job;
	job.resize(num);
	for (int i = 0; i < num; i++)
	{
		job[i] = new Node;
		cout << "请输入进程名、到达时间、服务时间、优先级" << endl;
		//获取进程名
		cin >> job[i]->name;
		//获取到达时间
		cin >> job[i]->Tarrive;
		//获取服务时间
		cin >> job[i]->Tservice;
		//获取优先级
		cin >> job[i]->prio;
	}
	display(num, job);
	system("pasue");
	return 0;
}