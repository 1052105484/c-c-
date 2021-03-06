// 06 二级指针做函数参数的输入特性.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>


void printArray(int **Array, int len)
{
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		printf("%d\n",*Array[i]);
	}
}

//二级指针做函数参数的输入特性
//主调函数分配内存，被调函数使用
void test01(void) 
{
	//在堆区分配内存
	int **p = calloc(5,sizeof(int*));
	//在栈上创建数据
	int a1 = 10;
	int a2 = 20;
	int a3 = 30;
	int a4 = 40;
	int a5 = 50;

	p[0] = &a1;
	p[1] = &a2;
	p[2] = &a3;
	p[3] = &a4;
	p[4] = &a5;
	printArray(p,5);
	if (p)
	{
		free(p);
		p = NULL;
	}
}

void test02(void)
{
	//在栈上创建
	int *pArray[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		pArray[i] = calloc(1, 4);
		*(pArray[i]) = 100 + i;
	}
	printArray(pArray,sizeof(pArray)/sizeof(int*));
	for (size_t i = 0; i < 5; i++)
	{
		if (!pArray[i])
		{
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}
}
int main()
{
	//test01();
	test02();
	return 0;
}
