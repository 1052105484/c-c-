#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void changeValue(int * p)
{
	int *temp = NULL;
	temp = p;
	*temp = 1000;
}



//1.一个普通变量和一个指针变量
//2.建立关系
//3.通过*进行赋值
void test01(void)
{
	int a = 10;
	int *p = NULL;
	p = &a;
	*p = 100;
	printf("%d\n", a);
	int a2 = 10;
	changeValue(&a2);
	printf("%d\n", a2);
}

int main()
{
	test01();
	return 0;
}

