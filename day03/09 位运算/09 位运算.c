// 09 位运算.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//1、按位取反
void test01(void)
{
	int num = 2;
	printf("%d\n",~num);
	//010 按位取反 101(源码)（计算机存储的时候存的是补码）
	//101 （负数的补码，符号位不动，有效位取反后+1） 110+1=111
}
//2、按位与(&)-->全真为真，有假为假
void test02(void) 
{
	int num = 123;
	if ((num&1) == 0)
	{
		printf("num为偶数\n");
	} 
	else
	{
		printf("num为奇数\n");
	}
}
//3、按位或 | 全假为假，有真为真
void test03(void)
{
	int num1 = 5;
	int num2 = 3;
	printf("num1|num2=%d\n", num1 | num2);
}
//4、按位异或 相同为0，不同为1
void test04(void)
{
	int num1 = 10;
	int num2 = 20;
	printf("num1=%d,num2=%d\n", num1, num2);
	//int temp = num1;
	//num1 = num2;
	//num2 = temp;

	//利用按位异或实现两个数的交换
	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;

	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;

	printf("num1=%d,num2=%d\n", num1, num2);
}
//5、左移
void test05(void)
{
	int num = 10;
	printf("%d\n", num <<= 2);
}
//6、右移
void test06(void)
{
	int num = 10;
	printf("%d\n", num >>= 1);
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return EXIT_SUCCESS;
}