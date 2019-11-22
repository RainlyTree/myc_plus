#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"contact.h"

void InitContact(Contact *pCon)
{
	assert(pCon != NULL);
	memset(pCon->per, 0, sizeof(pCon->per));
	pCon->usedSize = 0;
}

void AddContact(Contact *pCon)
{
	//1 往哪里放 数组 下标
	//2 性别 年龄。。。。
	assert(pCon != NULL);
	if (pCon->usedSize == MAX_NUMPERSON)
	{
		printf("通讯录满了");
		return;
	}
	int n = pCon->usedSize;
	printf("name :");
	scanf("%s", pCon->per[n].name);
	printf("age  :");
	scanf("%d", &(pCon->per[n].age));
	printf("tele :");
	scanf("%s", pCon->per[n].tele);
	printf("addr :");
	scanf("%s", pCon->per[n].addr);
	printf("sex  :");
	scanf("%s", pCon->per[n].sex);
	pCon->usedSize++;
	printf("添加成功");
}


int SearchContact(Contact *pCon)
{
	assert(pCon != NULL);
	char InName[MAX_NAME];
	if (pCon->usedSize == 0)
	{
		printf("通讯录为空");
		return -1;
	}
	printf("input the name:");
	scanf("%s", InName);
	for(int i = 0;pCon->usedSize < MAX_NUMPERSON;i++)
	{
		if (strcmp(pCon->per[i].name,InName))
			return i;
	}
	return -1;
}


void DelContact(Contact *pCon)
{
	assert(pCon != NULL);
	int i = SearchContact(pCon);
	if (i == -1)
	{
		printf("查无此人");
		return;
	}
	for (; i < pCon->usedSize - 1; i++)
	{
		pCon->per[i] = pCon->per[i + 1];
	}
	pCon->usedSize--;
	printf("删除成功\n");
}

void ShowContact(Contact *pCon)
{
	assert(pCon != NULL);
	printf("%-20s %-3s %-3s %-11s %-15s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < pCon->usedSize; i++)
	{
		printf("%-20s %-3s %-3d %-11s %-15s\n", pCon->per[i].name, pCon->per[i].sex, pCon->per[i].age, pCon->per[i].tele, pCon->per[i].addr);
	}
}

void ClearContact(Contact *pCon)
{
	InitContact(pCon);
}
