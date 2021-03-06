// 01 动态数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "dynamicArray.h"
struct Person
{
	char name[64];
	int age;
};
void printPerson(struct Person *p)
{
	printf("姓名:%s   年龄:%d\n", p->name, p->age);
}

int comParePerson(struct Person *p1, struct Person *p2)
{
	if ((p1->age == p2->age)&&(strcmp(p1->name,p2->name)==0))
	{
		return 1;
	}
	return 0;
}

void test01(void)
{
	struct  dynamicArray*arr= init_DynamicArray(5);
	//准备五个数据
	struct Person p1 = {"亚瑟",18};
	struct Person p2 = {"王昭君",28};
	struct Person p3 = {"赵云", 38};
	struct Person p4 = {"张飞",19};
	struct Person p5= {"关羽",20};
	struct Person p6 = { "宫本",17 };
	printf("当前容量为:%d  元素个数:%d\n", arr->m_capacity,arr->m_size);
	insert_dynamicArray(arr,0,&p1);
	insert_dynamicArray(arr,0, &p2);
	insert_dynamicArray(arr,0, &p3);
	insert_dynamicArray(arr, 2, &p4);
	insert_dynamicArray(arr, 10, &p5);
	insert_dynamicArray(arr, 1, &p6);
	foreach_DynamicArray(arr, printPerson);
	printf("当前容量为:%d  元素个数:%d\n", arr->m_capacity, arr->m_size);
	remove_dynamicArray(arr,1);
	printf("删除第一个元素后，数组中数据为:\n");
	foreach_DynamicArray(arr, printPerson);
	struct Person p = {"张飞",19};
	removeByValue(arr,&p, comParePerson);
	printf("------------------------------------------------------\n");
	foreach_DynamicArray(arr, printPerson);
	//销毁数组
	destroy(arr);
	arr = NULL;
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}