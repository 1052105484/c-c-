// 02 定义数组的指针.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//1、先定义数组的类型，再通过类型创建数组指针
void test01(void)
{
	int arr[5] = { 1,2,3,4,5 };
	typedef int(ARRAY_TYPE)[5];//ARRAY_TYPE是一个数据类型，代表有5个int类型元素的数组
	ARRAY_TYPE *arrp = &arr;
	printf("%d\n", arrp);
	printf("%d\n", arrp + 1);
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", (*arrp)[i]);
	}
}
//2、先定义数组指针的类型，再通过数组指针的类型创建出数组指针变量
void test02(void)
{
	int arr[5] = { 1,2,3,4,5 };
	typedef int(*ARRAY_TYPE)[5];
	ARRAY_TYPE arrp = arr;
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", (*arrp)[i]);
	}
}
//3、直接创建数组指针变量
void test03(void)
{
	int arr[5] = { 1,2,3,4,5 };
	int(*p)[5]=&arr;
	printf("%d\t%d\t%d\t%d\n", arr, &arr,arr+1,&arr+1);
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", (*p)[i]);
	}
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}