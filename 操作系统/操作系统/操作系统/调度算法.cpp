#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
	string name = "1111111111";	//进程标识符
	float Tarrive = 0;	//进入时间
	float Tservice = 0;	//服务时间
	float Tsurplus = 0;	//剩余时间
	float Tstart = 0;		//开始时间
	float Taccomplish = 0;//完成时间
	float TZz = 0;		//周转时间
	float TDqZz = 0;		//带权周转时间
	int prio = 0;		//优先级-->数字越大优先级越高
	bool flag = false;	//是否进入时间片的队列
	//int num;		//进程个数
};
//将剩余时间设置成服务时间
void SetTime(int num, vector<Node*>& job)
{
	for (int i = 0; i < num; ++i)
	{
		job[i]->Tsurplus = job[i]->Tservice;
	}
}

//按到达时间排序
void Arrive_sort(int num, vector<Node*>& job)
{
	int tmp = job.size();
	for (int i = tmp - num; i < tmp; i++)
	{
		for (int j = i + 1; j < tmp; j++)
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
	int tmp = job.size();
	for (int i = tmp - num; i < tmp; i++)
	{
		for (int j = i + 1; j < tmp; j++)
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
	int tmp = job.size();
	for (int i = tmp - num; i < tmp; i++)
	{
		for (int j = i + 1; j < tmp; j++)
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
	//按到达时间排序
	Arrive_sort(num, job);
	//第一个要进行的任务
	for (int i = 1; i < num; ++i)
	{
		//如果找到时间与第一个相同的时间但服务时间比他小 交换
		if (job[0]->Tarrive == job[i]->Tarrive && job[0]->Tservice > job[i]->Tservice)
		{
			swap(job[0], job[1]);
		}
	}
	job[0]->Tstart = job[0]->Tarrive;
	//完成时间 = 开始 + 服务时间
	job[0]->Taccomplish = job[0]->Tstart + job[0]->Tservice;
	//周转时间 == 完成时间-到达时间
	job[0]->TZz = job[0]->Taccomplish - job[0]->Tarrive;
	//带权周转时间 == 周转时间/服务时间
	job[0]->TDqZz = job[0]->TZz / job[0]->Tservice;

	for (int i = 1; i < num; i++)
	{
		//寻找第i个进入的进程
		//对剩下的进行服务排序
		Service_sort(num - i, job);
		//记录当前进行的位置
		int tmp = i;
		//判断当前的最小服务时间是否在已经进入
		for (int j = i; j < num; ++j)
		{
			//如果服务时间最小的到达时间 < 前一个完成的完成时间
			if (job[j]->Tarrive < job[i - 1]->Taccomplish)
			{
				swap(job[j], job[tmp]);
				break;
			}
		}
		if (job[i]->Tarrive < job[i - 1]->Taccomplish)
			job[i]->Tstart = job[i - 1]->Taccomplish;//上一个作业结束时间
		else
		{
			//所有的都比他完成之后都要晚  再次进行时间排序
			Arrive_sort(num, job);
			for (int k = tmp + 1; k < num; ++k)
			{
				//如果找到时间与第一个相同的时间但服务时间比他小 交换
				if (job[tmp]->Tarrive == job[k]->Tarrive && job[tmp]->Tservice > job[k]->Tservice)
				{
					swap(job[tmp], job[k]);
				}
			}
			job[i]->Tstart = job[i]->Tarrive;

		}

		job[i]->Taccomplish = job[i]->Tstart + job[i]->Tservice;
		job[i]->TZz = job[i]->Taccomplish - job[i]->Tarrive;
		job[i]->TDqZz = job[i]->TZz / job[i]->Tservice;
	}
}

//高优先级优先
void High_level(int num, vector<Node*> job)
{
	//按到达时间排序
	Arrive_sort(num, job);
	//第一个要进行的任务
	for (int i = 1; i < num; ++i)
	{
		//如果找到时间与第一个相同的时间但权限比它大的 交换
		if (job[0]->Tarrive == job[i]->Tarrive && job[0]->prio < job[i]->prio)
		{
			swap(job[0], job[1]);
		}
	}
	job[0]->Tstart = job[0]->Tarrive;
	//完成时间 = 开始 + 服务时间
	job[0]->Taccomplish = job[0]->Tstart + job[0]->Tservice;
	//周转时间 == 完成时间-到达时间
	job[0]->TZz = job[0]->Taccomplish - job[0]->Tarrive;
	//带权周转时间 == 周转时间/服务时间
	job[0]->TDqZz = job[0]->TZz / job[0]->Tservice;

	for (int i = 1; i < num; i++)
	{
		//寻找第i个进入的进程
		//对剩下的进行优先级排序
		Priority_sort(num - i, job);
		//记录当前进行的位置
		int tmp = i;
		//判断当前的最大权限是否在已经进入
		for (int j = i; j < num; ++j)
		{
			//如果权限最大的到达时间 < 前一个完成的完成时间
			if (job[j]->Tarrive <= job[i - 1]->Taccomplish)
			{
				swap(job[j], job[tmp]);
				break;
			}
		}
		if (job[i]->Tarrive <= job[i - 1]->Taccomplish)
			job[i]->Tstart = job[i - 1]->Taccomplish;//上一个作业结束时间
		else
		{
			//所有的都比他完成之后都要晚  再次进行时间排序
			Arrive_sort(num, job);
			for (int k = tmp + 1; k < num; ++k)
			{
				//如果找到时间与第一个相同的时间但权限比它大的 交换
				if (job[tmp]->Tarrive == job[k]->Tarrive && job[tmp]->Tservice < job[k]->Tservice)
				{
					swap(job[tmp], job[k]);
				}
			}
			job[i]->Tstart = job[i]->Tarrive;

		}

		job[i]->Taccomplish = job[i]->Tstart + job[i]->Tservice;
		job[i]->TZz = job[i]->Taccomplish - job[i]->Tarrive;
		job[i]->TDqZz = job[i]->TZz / job[i]->Tservice;
	}

}

//时间片轮转算法
void RR(int num, vector<Node*> job)//RR算法
{
	//设置剩余时间
	SetTime(num, job);
	//获取时间片
	int q;
	cout << "请输入时间片长度：" << endl;
	cin >> q;
	//将等待序列放入队列中
	queue<Node*> job_que;
	//当前的时间
	int time = 0;
	//进行时间排序
	Arrive_sort(num, job);
	//开始时间为第一个作业的到达时间
	time = job[0]->Tarrive;
	//设置第一个开始时间
	job[0]->Tstart = time;
	//将第一个任务入队
	job_que.push(job[0]);
	job[0]->flag = true;
	while (!job_que.empty())
	{
		//获取当前需要进行的作业
		Node* tmp_job = job_que.front();
		job_que.pop();
		//如果开始时间没有设定，将当前时间设为开始时间
		if ((tmp_job->Tstart == 0 && (tmp_job != job[0])))
		{
			tmp_job->Tstart = time;
		}
		//判断当前所需要的时间是否比当前的时间片小
		if (tmp_job->Tsurplus <= q)
		{
			//时间加上当前剩余时间
			time += tmp_job->Tsurplus;
			tmp_job->Tsurplus = 0;
			//设置完成时间
			tmp_job->Taccomplish = time;
		}
		//还需要不止一个时间片
		else
		{
			//时间 直接加上时间片
			tmp_job->Tsurplus -= q;
			time += q;
		}
		for (int i = 0; i < num; ++i)
		{
			//不是当前进程   未完成	 已经到达   没有进入队列
			if (job[i] != tmp_job && job[i]->Taccomplish == 0 && job[i]->Tarrive <= time && job[i]->flag == false)
			{
				job_que.push(job[i]);
				job[i]->flag = true;
			}
		}
		//没有完成时间
		if(tmp_job->Taccomplish == 0)
			job_que.push(tmp_job);
	}
	for (int i = 0; i < num; ++i)
	{
		//job[i]->Taccomplish = job[i]->Tstart + job[i]->Tservice;
		job[i]->TZz = job[i]->Taccomplish - job[i]->Tarrive;
		job[i]->TDqZz = job[i]->TZz / job[i]->Tservice;
	}
}

void ave_time(int num, vector<Node*>& job)
{
	int ave_t1 = 0;
	int ave_t2 = 0;
	for (int i = 0; i < num; ++i)
	{
		ave_t1 += job[i]->TZz;
		ave_t2 += job[i]->TDqZz;
	}
	ave_t1 /= num;
	ave_t2 /= num;
	cout << "平均周转周期" << "\t\t" << "平均带权周转周期" << endl;
	cout << "\t" << ave_t1 << "\t\t" << ave_t2 << endl;
}

//输出函数
void print(int num, vector<Node*>& job)
{
	cout << "进程名" << "\t" << "到达时间" << "\t" << "服务时间" << "\t" << "开始时间" <<
		"\t" << "完成时间" << "\t" << "周转时间" << "\t" << "带权周转" << endl;

	for (int i = 0; i < num; i++)
	{
		cout << job[i]->name << "\t" << job[i]->Tarrive << "\t\t" << job[i]->Tservice 
			<< "\t\t"  << job[i]->Tstart << "\t\t" << job[i]->Taccomplish
			<< "\t\t" << job[i]->TZz << "\t\t"  << job[i]->TDqZz << endl;
	}
	ave_time(num, job);
}

//清理函数
void clear(int num, vector<Node*>& job)
{
	for (int i = 0; i < num; ++i)
	{
		job[i]->Tstart = 0;
		job[i]->Taccomplish = 0;
		job[i]->TZz = 0;
		job[i]->TDqZz = 0;
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
		clear(num, job);
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
			print(num, job);
			break;
		case 4:
			High_level(num, job);
			print(num, job);
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