// 02 预处理指令.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//1、头文件包含 #include "" 自定义头文件 <>系统头文件
//#define  MAX 1024
//2、宏定义

//不重视作用域 可以利用#undef 卸载
//宏定义的常量 没有数据类型的

void test01(void)
{
#define MAX 1024

}
//3、条件编译
//#define DEBUG
#ifdef DEBUG
void func(void)
{
	printf("debug版本调用\n");
}
#else
//void func(void)
//{
//	printf("release版本调用\n");
//}

#if 0
void func(void)
{
	printf("release版本调用1\n");
}
#else
void func(void)
{
	printf("release版本调用2\n");
}
#endif

#endif // DEBUG


//4、特殊的宏
void doWork(char *p)
{
	if (!p)
	{
		printf("文件 :%s的%d行出错了!\n", __FILE__, __LINE__);
		printf("日期:%s\n", __DATE__);
		printf("时间:%s\n", __TIME__);
		return;
	}
}
void test02(void)
{
	doWork(NULL);
}
int main()
{
	func();
	test02();
	printf("%d\n", MAX);
	system("pause");
#undef MAX
	return EXIT_SUCCESS;
}