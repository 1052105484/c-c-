// 07 指针做函数参数的输入输出特性.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define     _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


void func(char * p) {
	char * temp = NULL;
	temp = p;
	strcpy(temp, "hello world");
}

//1.输入特性：主调函数中分配内存，被调函数中使用内存
void test01(void)
{
	//分配到栈上
	char buffer[1024] = { 0 };
	func(buffer);
	printf("%s\n", buffer);
}
void print(char * p) {
	printf("%s\n", p);
}
void test02(void)
{
	//分配到堆区
	char *p = malloc(sizeof(char) * 64);
	memset(p, 0, 64);
	strcpy(p, "hello world");
	print(p);
	free(p);
	p = NULL;
}
void allocateSpace(char ** pt)
{
	char *temp = malloc(sizeof(char) * 64);
	memset(temp, 0, 64);
	strcpy(temp, "hello world");
	*pt = temp;
}
void test03(void)
{
	char *p = NULL;
	allocateSpace(&p);
	printf("%s\n",p);
	free(p);
	p = NULL;
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}
