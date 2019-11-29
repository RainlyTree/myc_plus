#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node {
	char name;
	int Tarrive;//到达时间
	int Tservice;//服务时间
	int Tsurplus;//剩余时间
	int Tstart;//开始时间
	int Taccomplish;//完成时间
	int prio;//优先级---数字越大优先级越高
	int if_finish;//进程是否完成
	int num;//进程个数
}job[10];
//按到达时间排序
void Arrive_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive > job[j].Tarrive)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}
}
//按服务时间排序
void Service_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tservice > job[j].Tservice)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}
}
//按优先级排序
void Priority_sort(int num)//按优先级减小排序
{
	int temp1, temp2, temp3, temp4;
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].prio < job[j].prio)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
				temp4 = job[j].prio;
				job[j].prio = job[i].prio;
				job[i].prio = temp3;
			}
		}
	}
}
//如果到达时间相等，服务时间按从小到大排序
void Arrive_Short_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive >= job[j].Tarrive)
			{
				if (job[i].Tarrive > job[j].Tarrive)
				{
					temp1 = job[j].name;
					job[j].name = job[i].name;
					job[i].name = temp1;
					temp2 = job[j].Tarrive;
					job[j].Tarrive = job[i].Tarrive;
					job[i].Tarrive = temp2;
					temp3 = job[j].Tservice;
					job[j].Tservice = job[i].Tservice;
					job[i].Tservice = temp3;
				}
				else
				{
					if (job[i].Tservice > job[j].Tservice)
					{
						temp1 = job[j].name;
						job[j].name = job[i].name;
						job[i].name = temp1;
						temp2 = job[j].Tarrive;
						job[j].Tarrive = job[i].Tarrive;
						job[i].Tarrive = temp2;
						temp3 = job[j].Tservice;
						job[j].Tservice = job[i].Tservice;
						job[i].Tservice = temp3;
					}
				}
			}
		}
	}
}
void fcfs(int num)//先来先服务
{
	for (int i = 0; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;//上一个作业结束时间
		if (job[i].Tstart < job[i].Tarrive)
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
	}
}
void sjf(int num)//短作业优先
{
	Service_sort(num);
	for (int i = 0; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;//上一个作业结束时间
		if (job[i].Tstart < job[i].Tarrive)//该作业的开始时间小于到达时间
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
	}
}
void RR(int num)//RR算法
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
			Arrive_sort(num);
			job[i].Tsurplus = job[i].Tservice;
			job[i].Tstart = job[i - 1].Taccomplish;//上一个作业结束时间
			if (job[i].Tstart < job[i].Tarrive)//该作业的开始时间小于到达时间
			{
				job[i].Tstart = job[i].Tarrive;
			}
			else
			{
				job[i].Tstart = job[i - 1].Taccomplish;
			}
			time = job[i].Tstart;
			if (job[i].if_finish == 1) continue;//该进程已完成
			else
			{
				if (job[i].Tsurplus <= q && time >= job[i].Tarrive)//未完成且少于一个时间片
				{
					flag = 1;
					time = time + job[i].Tsurplus;
					job[i].if_finish = 1;//该进程完成
					job[i].Taccomplish = time;
					cout << job[i].name << "\t\t" << job[i].Taccomplish - job[i].Tsurplus << "\t\t" << job[i].Tsurplus << "\t\t" << 0 << "\t\t" << job[i].Taccomplish << endl;
					job[i].Tsurplus = 0;
				}
				else if (job[i].Tsurplus > q && time >= job[i].Tarrive)
				{
					flag = 1;
					time = time + q;
					job[i].Tsurplus -= q;
					job[i].Taccomplish = time;
					cout << job[i].name << "\t\t" << time - q << "\t\t" << q << "\t\t" << job[i].Tsurplus << "\t\t" << job[i].Taccomplish << endl;
					job[num].name = job[i].name;
					job[num].Tarrive = time;
					job[num].Tservice = job[i].Tsurplus;
					num++;
				}
				if (job[i].if_finish == 1) finish_pro++;//一个进程完成加一
			}
			c++;
		}break;
		if (flag == 0 && finish_pro < num)//没执行完且没进入就绪队列
		{
			for (int i = 0; i < num; i++)
			{
				if (job[i].if_finish == 0)
				{
					time = job[i].Tarrive;
					break;
				}
			}
		}
	}
}
//输出
//void print(int num)
//{
//	cout << "进程名" << "\t" << "到达时间" << "\t" << "服务时间" << "\t" << "完成时间" << endl;
//
//	for (int i = 0; i < num; i++)
//	{
//		cout << job[i].name << "\t" << job[i].Tarrive << "\t\t" << job[i].Tservice << "\t\t" << job[i].Taccomplish << endl;
//	}
//}
//void display(int num)
//{
//	int ch = 0;
//	cout << "—————————————————————————" << endl;
//	cout << "——————————1、先来先服务算法 —————————" << endl;
//	cout << "——————————2、短作业优先算法——————————" << endl;
//	cout << "——————————3、时间片轮转算法 ——————————" << endl;
//	cout << "——————————4、优先级算法 ————————" << endl;
//	cout << "——————————5、退出 ———————————" << endl;
//	cout << "—————————————————————————" << endl;
//	do {
//		cout << "请选择你想要的算法：" << endl;
//		cin >> ch;
//		switch (ch) {
//		case 1:
//			Arrive_sort(num);
//			fcfs(num);
//			print(num);
//			break;
//		case 2:
//			sjf(num);
//			print(num);
//			break;
//		case 3:
//			RR(num);
//			break;
//		case 4:
//			Priority_sort(num);
//			break;
//		case 5:
//			exit;
//		default:
//			cout << "输入错误，请重新输入！" << endl;
//			break;
//		}
//	} while (ch != 5);
//}
//int main()
//{
//	int num;
//	cout << "请输入进程个数：" << endl;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//	{
//		cout << "请输入进程名、到达时间、服务时间" << endl;
//		//获取进程名
//		cin >> job[i].name;
//		//获取到达时间
//		cin >> job[i].Tarrive;
//		//获取服务时间
//		cin >> job[i].Tservice;
//	}
//	display(num);
//	system("pasue");
//	return 0;
//}