// 01 静态链表和动态链表.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//1、静态链表
//节点的声明
struct LinkNode
{
	int num;//数据域
	struct LinkNode *next;
};
void test01(void)
{
	//创建节点
	struct LinkNode node1 = { 10,NULL };
	struct LinkNode node2 = { 20,NULL };
	struct LinkNode node3 = { 30,NULL };
	struct LinkNode node4 = { 40,NULL };
	struct LinkNode node5 = { 50,NULL };
	//建立关系
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	//如何遍历这个链表
	struct LinkNode *pCurrent = &node1;
	do
	{
		printf("%d\n", pCurrent->num);
	} while (pCurrent = pCurrent->next);
}
//2、动态链表
void test02(void)
{
	struct LinkNode * node1 = malloc(sizeof(struct LinkNode));
	struct LinkNode * node2 = malloc(sizeof(struct LinkNode));
	struct LinkNode * node3 = malloc(sizeof(struct LinkNode));
	struct LinkNode * node4 = malloc(sizeof(struct LinkNode));
	struct LinkNode * node5 = malloc(sizeof(struct LinkNode));

	node1->num = 10;
	node2->num = 20;
	node3->num = 30;
	node4->num = 40;
	node5->num = 50;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	struct LinkNode *pCurrent = node1;
	do
	{
		printf("%d\n", pCurrent->num);
	} while (pCurrent = pCurrent->next);
	//释放节点
	free(node1);
	node1 = NULL;

	free(node2);
	node2 = NULL;

	free(node3);
	node3 = NULL;

	free(node4);
	node5 = NULL;

	free(node5);
	node5 = NULL;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}