// 04 函数指针做函数参数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//提供一个函数，可以将任意的数据类型 打印出来
void prinText(void *a,void(*myPrint)(void*))
{
	myPrint(a);
}
void myPrintInt(int *a)
{
	int *p = a;
	printf("%d\n", *p);
}
void test01()
{
	int a=100;
	prinText(&a,myPrintInt);
}
struct Person
{
	char name[64];
	int age;
};
void printPerson(struct Person *p)
{
	struct Person * person = p;
	printf("姓名:%s   年龄：%\d\n", person->name, person->age);
}
void test02()
{
	struct Person p = {"aaa",10};
	prinText(&p,printPerson);
}
int main()
{
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}