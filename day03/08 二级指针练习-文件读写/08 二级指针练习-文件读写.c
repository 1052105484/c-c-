// 08 二级指针练习-文件读写.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
//获取文件的函数
int getFileLines(int *p, FILE *file)
{
	int ret = 0;
	*p = 0;
	if (!file)
	{
		return -1;
	}
	char buf[1024] = { 0 };
	while (fgets(buf, 1024, file) != NULL)
	{
		(*p)++;
		printf("%s", buf);
	}
	//将文件光标置位文件首
	fseek(file, 0, SEEK_SET);
	printf("\n");
	return 0;
}

void readFileData(FILE *file, int len, char **pArray)
{
	if (!file)
	{
		return;
	}
	if (len <= 0)
	{
		return;
	}
	if (!pArray)
	{
		return;
	}
	char buf[1024] = { 0 };
	while (fgets(buf, 1024, file) != NULL)
	{
		//buf中就是存放的每行的数据
		int currentLen = strlen(buf) + 1;
		char * currentP = malloc(sizeof(char)*currentLen);
		//将数据拷贝到堆区内存中
		strcpy(currentP, buf);
		*pArray++ = currentP;
		//清空缓冲区
		memset(buf, 0, 1024);
	}
}
void showFileData(char **pArray, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("第%d行中的数据为:%s", i + 1, pArray[i]);
	}
	printf("\n");
}
void freeSpace(char **pArray, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (pArray[i])
		{
			free(pArray[i]);
		}
	}
	free(pArray);
	pArray = NULL;
}
void test01(void)
{
	FILE *file = fopen("./test.txt", "r");
	if (!file)
	{
		printf("文件打开失败!\n");
		return;
	}
	int ret = 0;
	int len = 0;
	ret = getFileLines(&len, file);
	if (ret)
	{
		printf("文件打开失败!\n");
	}
	printf("文件的有效行数为:%d\n", len);
	char **pArray = malloc(sizeof(char*)*len);
	//将文件中的数据读取后放入到pArray中
	readFileData(file, len, pArray);
	//打印数据
	showFileData(pArray, len);
	pArray = NULL;
	if (file)
	{
		fclose(file);
	}
}
int main()
{
	test01();
	return 0;
}

