#include "pch.h"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
//1.静态变量
static int a = 10;//特点：只初始化一次，在编译阶段就已经分配内存，属于内部链接属性，只能在当前文件中使用

void test01() 
{
	static int b = 20;//局部静态变量,作用域只能在当前test01()中
	//a和b的生命周期是一样的
}
//2.全局变量
int g_a = 100;//在C语言下，全局变量前都隐藏加了关键字extren,属于外部链接属性

void test02()
{
	extern int g_b;
	printf("%d\n",g_b);
	g_b = 20000;
	printf("%d\n", g_b);
}
int main()
{
	test02();
	return 0;
}
