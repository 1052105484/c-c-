// 07 结构体嵌套一级指针练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct Person
{
	char * name;
	int age;
};
struct Person ** allocateSpace()
{
	struct Person **p=malloc(sizeof(struct Person*) * 3);
	int i;
	for (i=0;i<3;i++)
	{
		//给每个结构体开辟内存
		p[i]=malloc(sizeof(struct Person));
		p[i]->name=malloc(sizeof(char*) * 64);
		sprintf(p[i]->name, "name_%d", i+1);
		p[i]->age = i + 20;
	}
	return p;
}
void printArray(struct Person **p,int len)
{
	int i;
	for (i=0;i<len;i++)
	{
		printf("%d\t姓名：%s\t年龄:%d\n", i, (*(*(p + i))).name, p[i]->age);
	}
}
void freeSpace(struct Person **p, int len)
{
	int i;
	for (i=0;i<len;i++)
	{
		if (p[i]->name)
		{
			free(p[i]->name);
			p[i]->name = NULL;
		}
		if (p[i])
		{
			free(p[i]);
			p[i] = NULL;
		}
	}
}
void test01(void)
{
	struct Person **p1 = NULL;
	p1 = allocateSpace();
	printArray(p1, 3);
	//释放内存
	freeSpace(p1,3);
	if (p1)
	{
		free(p1);
		p1 = NULL;
	}
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}