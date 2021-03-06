// 04 指针的易错点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
#include<string.h>

void test01(void)
{
	char *p = malloc(sizeof(char) * 10);
	int len = 64;
	//利用临时指针，操作里面的内存
	char * temp = p;
	for (int i = 0; i < 10; ++i)
	{
		*temp = i + 97;
		printf("%c\n", *temp);
		temp++;//申请的首地址指针偏移后，就可以利用这个指针释放堆区内存了
	}
	if (p)
	{
		free(p);
		p = NULL;
	}
}
int main()
{
	test01();
	return 0;
}
