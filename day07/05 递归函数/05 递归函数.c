// 05 递归函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//递归函数 函数自己调用自身，必须有结束条件 跳出循环
void printCh(char *p, char *str, int len)
{
	if (*p == '\0')
	{
		*(str + len) = '\0';
		return;
	}
	printCh(p + 1, str, len);
	*(str + strlen(p + 1)) = *(p);
	printf("%c", *p);
}
void test01()
{
	char *p = "abcdef";
	char *str = malloc((strlen(p) + 1) * sizeof(char));
	printCh(p, str, strlen(p));
	printf("\n字符串:%s\n", str);
	if (str)
	{
		free(str);
		str = NULL;
	}
}
//2、斐波那契数列  1  1 2 3 5 8 13
int fibonacci(int pos)
{
	if (pos==1||pos==2)
	{
		return 1;
	}
	return  fibonacci(pos-2)+fibonacci(pos-1);
}

int test02(void)
{
	int ret = fibonacci(7);
	printf("%d\n", ret);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}