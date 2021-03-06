// 05 结构体基本概念.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct  Person1
{
	char name[64];
	int age;//不要在定义结构体的时候赋初值
}mPerson1;//Person是一个结构体别名

void test01(void)
{
	mPerson1 p = { "张三",2 };
	printf("%s\t%d\n", p.name, p.age);
}
struct Person2
{
	char name[64];
	int age;
}mPerson2 = { "bbb",200 };//Person是一个结构体变量
void test02(void)
{
	printf("%s\t%d\n", mPerson2.name, mPerson2.age);
	mPerson2.age = 20;
	strcpy(mPerson2.name, "aaa");
	printf("%s\t%d\n", mPerson2.name, mPerson2.age);
}

struct
{
	char name[64];
	int age;
}mPerson3 = { "ccc",90 };
void test03(void)
{
	printf("%s\t%d\n", mPerson3.name, mPerson3.age);
	mPerson3.age = 20;
	strcpy(mPerson3.name, "aaa");
	printf("%s\t%d\n", mPerson3.name, mPerson3.age);
}
void test04(void)
{
	//在栈上创建结构体
	struct Person1 p1 = { "aaa",10 };
	printf("%s\t%d\n", p1.name, p1.age);
	//在堆区创建结构体变量
	struct Person1 *p2=calloc(1,sizeof(struct Person1));
	p2->age = 30;
	strcpy(p2->name, "fff");
	printf("%s\t%d\n", p2->name, p2->age);
	free(p2);
	p2 = NULL;
}
void printPersons(struct Person1 * persons, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d:name=%s\t age=%d\n", i, (persons + i)->name, (persons + i)->age);
	}
}
void test05(void)
{
	//结构体变量数组
	//在栈上创建
	struct Person1  persons[]=
	{
		{"aaa",10},
		{"bbb",20},
		{"ccc",30}
	};
	int len = sizeof(persons) / sizeof(persons[0]);
	printPersons(persons,len);
	//在堆区创建
	struct Person1 * persons1 = calloc(4, sizeof(struct Person1));
	int i;
	for (i=0;i<4;i++)
	{
		sprintf((persons1 + i)->name, "name_%d", i);
		(persons1 + i)->age = i * 10;
	}
	printPersons(persons1,4);
	free(persons1);
	persons1 = NULL;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	system("pause");
	return EXIT_SUCCESS;
}