// 05 回调函数案例.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//提供一个函数，可以打印任意类型的数组
void printArray(void * arr, int len, int STEP_SIZE, void(*print)(void *))
{
	char *ch = arr;
	int i;
	for (i = 0; i < len; i++)
	{
		void * temp = ch + i * STEP_SIZE;
		print(temp);
	}
}
void print01(int *p)
{
	printf("%d\n", *p);
}
void test01(void)
{
	int arr[6] = { 1,2,3,4,5,6 };
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len, sizeof(int), print01);
}

struct Person
{
	char name[64];
	int age;
};
void printPerson(struct Person *person)
{
	printf("姓名:%s  年龄:%d\n", person->name, person->age);
}
void test02()
{
	struct Person persons[5] =
	{
		{"aaa",10},
		{"bbb",20},
		{"ccc",30},
		{"ddd",40},
		{"eee",50}
	};
	int len = sizeof(persons) / sizeof(struct Person);
	printArray(persons, len, sizeof(struct Person), printPerson);
}

//参数1 ：数组首地址 参数2 数组中元素个数 参数3 每个元素占多大空间 参数4 查找元素的地址
int findPerson(void *array, int len, int eleSize, void *data,int (*myCompare)(void *,void *))
{
	int i;
	char * ch=array;
	for (i=0;i<len;i++)
	{
		void *temp=ch + i * eleSize;
		if (myCompare(temp,data))
		{
			return 1;
		}
	}
	return 0;
}
int check(struct Person* p1, struct Person *p2)
{
	if ((p1->age == p2->age)&&strcmp(p1->name,p2->name)==0)
	{
		return 1;
	}
	return 0;
}
void test03(void)
{
	struct Person persons[5] =
	{
		{"aaa",10},
		{"bbb",20},
		{"ccc",30},
		{"ddd",40},
		{"eee",50}
	};
	struct Person p = {"ccc",30};
	//查找数组中的元素
	int len = sizeof(persons) / sizeof(struct Person);
	int ret=findPerson(persons, len, sizeof(struct Person), &p, check);
	if (ret)
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
}
int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}