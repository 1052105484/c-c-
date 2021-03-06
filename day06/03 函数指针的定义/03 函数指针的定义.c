// 03 函数指针的定义.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void func(void)
{
	printf("hello world\n");
}

//函数指针定义方式
void test01(void)
{
	//先定义出函数类型，再通过类型定义出函数指针
	typedef void (FUNC_TYPE)(void);
	FUNC_TYPE * Pfunc = func;
	Pfunc();
}
void test02(void)
{
	//先定义出函数指针的类型，再定义函数指针
	typedef void(*FUNC_TYPE)(void);
	FUNC_TYPE Pfunc = func;
	Pfunc();
}
void test03(void)
{
	//直接定义函数指针变量
	void(*pFunc)(void) = func;
	pFunc();
}
//函数指针的数组

void func1(void)
{
	printf("func1的调用\n");
}
void func2(void)
{
	printf("func2的调用\n");
}
void func3(void)
{
	printf("func3的调用\n");
}

void test04(void)
{
	//函数指针数组的定义
	void(*pFunc[3])();
	pFunc[0] = func1;
	pFunc[1] = func2;
	pFunc[2] = func3;
	int i;
	for (i=0;i<3;i++)
	{
		pFunc[i]();
	}
}
//函数指针 和指针函数的区别
//函数指针 是指向函数的指针
//指针函数 函数的返回值是一个指针的函数
int main()
{
	test01();
	test02();
	test03();
	test04();
	system("pause");
	return EXIT_SUCCESS;
}