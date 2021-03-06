// 07 二级指针做函数的输出特性.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
void allocateSpace(int **p)
{
	int *temp = calloc(4,sizeof(int));
	int i;
	for (i = 0; i < 4; i++)
	{
		*(temp + i) = i + 10;
	}
	*p = temp;
}
void printArray(int **p,int len)
{
	int i ;
	for ( i = 0; i < len; i++)
	{
		printf("%d\n",(*p)[i]);
	}
}
void freeSpace(int **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}
void test01()
{
	int *p= NULL;
	allocateSpace(&p);
	printArray(&p,4);
	freeSpace(&p);
	if (!p)
	{ 
		printf("空指针\n");
	}
	else 
	{
		printf("野指针\n");
	}
}
int main()
{
	test01();
	return 0;
}

