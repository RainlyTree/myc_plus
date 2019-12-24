#define _CRT_SECURE_NO_WARNINGS 1

#define MAX_length 640 //最大内存空间为640KB

#include<iostream>
using namespace std;
const int MinSize = 5; //允许最小的碎片空间为5

//定义一个空闲分区表结构
typedef struct Node
{
	int ID;   //分区号
	long size;   //分区大小
	long address; //分区地址
	bool state;   //状态
}Node;

//空闲链结构
typedef struct Link //double linked list
{
	Node data;
	struct Link *prior; //前趋指针
	struct Link *next;  //后继指针
}Link;

Link* block_first; //头结点
Link* block_follow = block_first;	//跟随节点
Link* block_last;  //尾结点

bool Initblock()//开创带头结点的内存空间链表
{
	block_first = (Link* )malloc(sizeof(Link));
	block_last = (Link*)malloc(sizeof(Link));
	//头节点设置
	block_first->prior = NULL;
	block_first->data.ID = -1;
	block_first->next = block_last;
	block_first->data.state = true;
	//尾节点设置(尾节点为当前的第一个节点)
	block_last->prior = block_first;
	block_last->next = NULL;
	block_last->data.address = 0;
	block_last->data.size = MAX_length;
	block_last->data.ID = 0;
	block_last->data.state = false;
	return true;
}

//------------------ 首次适应算法 -----------------------
bool First_fit(int ID, int request)//传入作业名及申请量
{
	//为申请作业开辟新空间且初始化
	Link* temp = (Link*)malloc(sizeof(Link));
	temp->data.ID = ID;
	temp->data.size = request;
	temp->data.state = true;

	Link* p = block_first->next;
	while (p)
	{
		if (p->data.state == false && p->data.size == request)
		{//有大小恰好合适的空闲块
			p->data.state = true;
			p->data.ID = ID;
			return true;
		}
		if (p->data.state == false && p->data.size > request)
		{//有空闲块能满足需求且有剩余"
			temp->prior = p->prior;
			temp->next = p;
			temp->data.address = p->data.address;
			p->prior->next = temp;
			p->prior = temp;
			p->data.address = temp->data.address + temp->data.size;
			p->data.size -= request;
			return true;
		}
		p = p->next;
	}
	return false;
}

//--------------------  最佳适应算法  ------------------------
bool Best_fit(int ID, int request)
{
	int ch; //记录最小剩余空间
	Link* temp = (Link*)malloc(sizeof(Link));
	temp->data.ID = ID;
	temp->data.size = request;
	temp->data.state = true;
	Link *p = block_first->next;
	Link *q = NULL; //记录最佳插入位置
	while (p) //初始化最小空间和最佳位置
	{
		if (p->data.state == false && (p->data.size > request || p->data.size == request))
		{
			q = p;
			ch = p->data.size - request;
			break;
		}
		p = p->next;
	}
	//从头进行一次便利
	p = block_first->next;
	while (p)
	{
		if (p->data.state == false && p->data.size == request)
		{//空闲块大小恰好合适
			p->data.ID = ID;
			p->data.state = true;
			return true;
		}
		if (p->data.state == false && p->data.size > request)
		{//空闲块大于分配需求
			if (p->data.size - request < ch)//剩余空间比初值还小
			{
				ch = p->data.size - request;//更新剩余最小值
				q = p;//更新最佳位置指向
			}
		}
		p = p->next;
	}
	if (q == NULL) 
		return false;//没有找到空闲块
	else
	{
		//找到了最佳位置并实现分配
		temp->prior = q->prior;
		temp->next = q;
		temp->data.address = q->data.address;
		q->prior->next = temp;
		q->prior = temp;
		q->data.address += request;
		q->data.size = ch;
		return true;
	}
}

//--------------------最坏适应算法 -------------------------
bool Worse_fit(int ID, int request)
{
	int ch; //记录最大剩余空间
	Link* temp = (Link*)malloc(sizeof(Link));
	temp->data.ID = ID;
	temp->data.size = request;
	temp->data.state = true;
	Link *p = block_first->next;
	Link *q = NULL; //记录最佳插入位置
	while (p) //初始化最大空间和最佳位置
	{
		if (p->data.state == false && (p->data.size > request || p->data.size == request))
		{
			q = p;
			ch = p->data.size - request;
			break;
		}
		p = p->next;
	}
	//从头进行一次便利
	p = block_first->next;
	while (p)
	{
		if (p->data.state == false && p->data.size > request)
		{//空闲块大于分配需求
			if (p->data.size - request > ch)//剩余空间比初值还小
			{
				ch = p->data.size - request;//更新剩余最大值
				q = p;//更新最佳位置指向
			}
		}
		p = p->next;
	}
	if (q == NULL)
		return false;//没有找到空闲块
	else
	{
		//找到了最佳位置并实现分配
		temp->prior = q->prior;
		temp->next = q;
		temp->data.address = q->data.address;
		q->prior->next = temp;
		q->prior = temp;
		q->data.address += request;
		q->data.size = ch;
		return true;
	}
}

//------------------ 循环首次适应算法 -----------------------
bool Re_First_fit(int ID, int request)
{
	//为申请作业开辟新空间且初始化
	Link* temp = (Link*)malloc(sizeof(Link));
 	temp->data.ID = ID;
	temp->data.size = request;
	temp->data.state = true;

	Link* p = block_follow;
	while (p)
	{
		if (p->data.state == false && p->data.size == request)
		{//有大小恰好合适的空闲块
			p->data.state = true;
			p->data.ID = ID;
			block_follow = p->next;
			return true;
		}
		if (p->data.state == false && p->data.size > request)
		{//有空闲块能满足需求且有剩余"
			temp->prior = p->prior;
			temp->next = p;
			temp->data.address = p->data.address;
			p->prior->next = temp;
			p->prior = temp;
			p->data.address = temp->data.address + temp->data.size;
			p->data.size -= request;
			block_follow = p;
			return true;
		}
		p = p->next;
		if (p == NULL)
		{
			p = block_first->next;
		}
		if (block_follow == p)
			return false;
	}
	return false;
}


//-----------------------   内 存 回 收   --------------------
bool free(int ID)
{
	Link *p = block_first;
	while (p)
	{
		if (p->data.ID == ID)
		{
			p->data.state = false;
			p->data.ID = false;
			Link *_head = p->prior;
			Link *_next = p->next;
			if (_head != block_first && _next != NULL)
			{
				if (p->prior->data.state == false && p->next->data.state == false)//前后都是空的
				{
					_head->next = _next->next;
					_next->prior = p->prior;
					_head->data.size += p->data.size + _next->data.size;
					free(p->next);
					free(p);
				}
				else if (p->prior->data.state == false)//与前面的空闲块相连
				{
					_head->data.size += p->data.size;
					_head->next = _next;
					_next->prior = p->prior;
					free(p);
				}
				else if (p->next->data.state == false)//与后面的空闲块相连
				{
					p->data.size += _next->data.size;
					_next->prior = p;
					p->next = _next->next;
					free(_next);
				}
				return true;
			}
			else if (_head == block_first && _next != NULL)
			{
				if (p->next->data.state == false)//与后面的空闲块相连
				{
					p->data.size += _next->data.size;
					_next->next->prior = p;
					p->next = _next->next;
					free(_next);
				}
				return true;
			}
			else if (_head != block_first && _next == NULL)
			{
				if (p->prior->data.state == false)//与前面的空闲块相连
				{
					_head->data.size += p->data.size;
					_head->next = _next;
					_next->prior = p->prior;
					free(p);
				}
				return true;
			}
			else
			{
				p->data.state = false;
				return true;
			}
		}
		p = p->next;
	}
	return false;
}

//----------------------- 分 配 内 存 -------------------------
bool alloc()
{
	
	int ch;//算法选择标记
	cout << "       内存动态分区分配与回收       \n";
	cout << "************************************\n";
	cout << "** 1)首次适应算法 \n";
	cout << "** 2)最佳适应算法 \n";
	cout << "** 3)最坏适应算法 \n";
	cout << "** 4)循环首次适应适应算法\n";
	cout << "************************************\n";
	cout << "请选择分配算法：";
	cin >> ch;

	int ID, request;
	cout << "请输入作业(分区号)：";
	cin >> ID;
	cout << "请输入需要分配的主存大小(单位:KB)：";
	cin >> request;

	if (request < 0 || request == 0)
	{
		cout << "分配大小不合适，请重试！" << endl;
		return false;
	}
		switch (ch)
		{
		case 2:
			if (Best_fit(ID, request) == true)
				cout << "分配成功！" << endl;
			else
				cout << "内存不足，分配失败！" << endl;
			break;
		case 1:
			if (First_fit(ID, request) == true)
				cout << "分配成功！" << endl;
			else
				cout << "内存不足，分配失败！" << endl;
			break;
		case 3:
			if (Worse_fit(ID, request) == true)
				cout << "分配成功！" << endl;
			else
				cout << "内存不足，分配失败！" << endl;
			break;
		case 4:
			if (Re_First_fit(ID, request) == true)
				cout << "分配成功！" << endl;
			else
				cout << "内存不足，分配失败！" << endl;
			break;
		default:
			break;
		}
}


//---------------  显示主存分配情况 ------------------
void show()
{
	cout << "+++++++++++++++++++++++++++++++++++++++\n";
	cout << "+++        主 存 分 配 情 况        +++\n";
	cout << "+++++++++++++++++++++++++++++++++++++++\n";
	Link *p = block_first->next;
	while (p)
	{
		cout << "分 区 号：";
		if (p->data.ID == false) 
			cout << "Free" << endl;
		else 
			cout << p->data.ID << endl;
		cout << "起始地址：" << p->data.address << endl;
		cout << "分区大小：" << p->data.size << " KB" << endl;
		cout << "状    态：";
		if (p->data.state == false) 
			cout << "空  闲" << endl;
		else 
			cout << "已分配" << endl;
		cout << "——————————————" << endl;
		p = p->next;
	}
}

int main()
{
	Initblock(); //开创空间表
	block_follow = block_first;
	int choice;  //操作选择标记
		cout << "********************************************\n";
		cout << "**    1: 分配内存        2: 回收内存      **\n";
		cout << "**    3: 查看分配        0: 退    出      **\n";
		cout << "********************************************\n";
		do {
			cout << "请输入您的操作 ：";
			cin >> choice;
			switch (choice) {
			case 0:
				break;
			case 1:
				 //分配内存
				alloc();
				break;
			case 2:
				int ID;
				cout << "请输入您要释放的分区号：";
				cin >> ID;
				free(ID);
				break;
			case 3:
				show();
				break;
			default:
				cout << "输入错误，请重新输入！" << endl;
				break;
			}
		} while (choice != 0);
}
