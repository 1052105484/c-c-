#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//1.空指针
void test01(void) 
{
	char *p = NULL;
	strcpy(p, "1111");//error
	char *q = 0x1122;
	//给q指向的内存区域拷贝内容
	strcpy(q,"2222");//error
}
//2、野指针
void test02(void)
{
	int *p;//2.1、未初始化指针
	printf("%d\n",*p);
	//2.2、malloc后也free了，但是指针没有置空
	int *p = malloc(sizeof(int));
	*p = 100;
	free(p);//将free后的指针要进行置空,防止野指针的出现
	printf("%d\n",*p);
}
//3、指针操作超越变量的作用域
int * doWork(void)
{
	int a = 10;
	int *p = &a;
	return p;
}
void test03(void)
{
	int *p2 = doWork();
	printf("%d\n",*p2);
	printf("%d\n", *p2);
}
int main()
{
	test01();
	test02();
	test03();
	return 0;
}
