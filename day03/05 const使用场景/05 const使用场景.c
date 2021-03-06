// 05 const使用场景.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct P
{
	char name[64];
	int age;
	int Id;
	double score;
}Person;
//const使用场景，修饰函数中的形参，防止误操作
void printPerson(const Person * p)
{
	//p->age = 500;加入const之后，编译器会检测误操作
	//printf("姓名:%s\t年龄:%d\t学号:%d\t分数:%f\n",p.name,p.age,p.Id,p.score);
	printf("姓名:%s\t年龄:%d\t学号:%d\t分数:%f\n", p->name, p->age, p->Id, p->score);
}
void test01(void)
{
	Person person = {"张三",18,1,60};
	printPerson(&person);
	printf("%d\n",person.age);
}
int main()
{
	test01();
	return 0;
}
