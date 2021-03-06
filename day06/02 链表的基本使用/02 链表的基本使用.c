// 02 链表的基本使用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "linkList.h"
void test01(void)
{
	struct LinkNode *pHeader = init_linkList();
	printf("初始化后遍历的结果为:\n");
	foreach_linkList(pHeader);
	//插入数据
	//10 20 30 
	//100 10 200 20 30 300
	insert_linkList(pHeader, 10, 100);
	insert_linkList(pHeader, 20, 200);
	insert_linkList(pHeader, -1, 300);
	printf("插入数据后遍历的结果为:\n");
	foreach_linkList(pHeader);
	//测试 删除
	delete_linkList(pHeader, 300);
	delete_linkList(pHeader, 100);
	delete_linkList(pHeader, 1000);
	printf("删除数据后遍历的结果为:\n");
	foreach_linkList(pHeader);
	//测试 清空链表
	clear_linkList(pHeader);
	printf("清空数据后遍历的结果为:\n");
	foreach_linkList(pHeader);

	insert_linkList(pHeader, 111, 111);
	insert_linkList(pHeader, 222, 222);
	insert_linkList(pHeader, 333, 333);
	printf("清空后再次使用遍历的结果为:\n");
	foreach_linkList(pHeader);
	//销毁链表
	destroty_linkList(pHeader);
	pHeader = NULL;
}
void test02(void)
{
	struct LinkNode * pHeader = init_linkList();
	printf("反转之前:\n");
	foreach_linkList(pHeader);
	reverse_linkList(pHeader);
	printf("反转之后:\n");
	foreach_linkList(pHeader);
	printf("链表的长度为:%d\n", size_linkList(pHeader));
}
void test03(void)
{
	struct LinkNode * pHeader = init_linkList();
	foreach_linkList(pHeader);
	printf("逆序遍历:\n");
	printLinkList(pHeader->next);
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
