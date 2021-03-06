// 06 结构体赋值问题已经解决.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct Person
{
	char name[64];
	int age;
};
void test01(void)
{
	struct Person p1 = { "Tom",18 };
	struct Person p2 = { "Jerry",20 };
	p1 = p2;
	printf("p1的姓名:%s\t年龄:%d\n", p1.name, p1.age);
	printf("p2的姓名:%s\t年龄:%d\n", p2.name, p2.age);
}
struct Person2
{
	char * name;
	int age;
};
void test02(void)
{
	struct Person2 p1;

	p1.age = 18;
	p1.name = malloc(sizeof(char) * 64);
	strcpy(p1.name, "Tom");

	struct Person2 p2;
	p2.age = 20;
	p2.name = malloc(sizeof(char) * 128);
	strcpy(p2.name, "Jerry");


	//p1 = p2;//涉及到堆区，浅拷贝内存管理会有问题

	//自己提供一个赋值操作  深拷贝
	//先释放原有的内容
	/*
	if (p1.name)
	{
		free(p1.name);
		p1.name = NULL;
	}
	p1.name = calloc((strlen(p2.name) + 1),(sizeof(char)));

	*/

	p1.name = realloc(p1.name, (strlen(p2.name) + 1)*(sizeof(char)));
	strcpy(p1.name, p2.name);

	p1.age = p2.age;

	printf("p1的姓名:%s\t年龄:%d\n", p1.name, p1.age);
	printf("p2的姓名:%s\t年龄:%d\n", p2.name, p2.age);

	if (p1.name)
	{
		free(p1.name);
		p1.name = NULL;
	}
	if (p2.name)
	{
		free(p2.name);
		p2.name = NULL;
	}
}
int main()
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}