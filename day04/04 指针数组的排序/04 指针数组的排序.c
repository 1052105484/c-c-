// 04 指针数组的排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//从小到大 选择排序
void selectSore01(int *p, int len)
{


}
void test01(void)
{
	int arr[] = {3,2,5,1,4};
	int len = sizeof(arr) / sizeof(arr[0]);
	selectSore01(&arr,len);
}


//通过选择排序算法计算后，实现对指针数据的降序排列,从大到小
void selectSore02(char **pArr,int len)
{

}
void test02(void)
{
	char *pArr[] = {"aaa","bbb","fff","ddd","eee","ccc"};
	int len = sizeof(pArr) / sizeof(char*);
	selectSort(&pArr, len);
}
int main()
{
	system("pause");
	return EXIT_SUCCESS;
}