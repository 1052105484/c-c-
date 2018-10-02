// 03 二维数组名称.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//void printArray(int arr[][3], int row, int col)
void printArray(int arr[3][3], int row, int col)
//void printArray(int(*arr)[3], int row, int col)
{
	int i, j;
	for (i=0;i< row;i++)
	{
		for (j=0;j< col;j++)
		{
			//printf("%d\t", arr[i][j]);//给人看
			printf("%d\t", *(*(arr + i) + j));//给机器看

		}
		printf("\n");
	}
}
void test01(void)
{
	int arr[3][3] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	//int arr2[3][3] = {1,2,3,4,5,6,7,8,9};
	
	//int arr3[][3] = { 1,2,3,4,5,6,7,8,9 };

	int(*p)[3] = arr;//二维数组名称 指向第一个一维数组的指针
	//特殊情况
	printf("sizeof arr=%d\n", sizeof arr);//统计整个二维数组的长度
	int (*p2)[3][3]=&arr;//对数组名取地址  二维数组指针变量

	//访问二维数组中的6
	printf("%d\n", arr[1][2]);//给人看
	printf("%d\n", *(*(arr + 1) + 2));//给机器看
	
}
void test02(void)
{
	int arr[3][3] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	printArray(arr, 3, 3);
}
int main()
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}