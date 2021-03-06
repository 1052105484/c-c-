// 06 配置文件读写.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "code.h"
#include "config.h"
#include <time.h>
void test03(char * filePath);
void test01(void)
{
	char * filePath = "config.txt";
	test03(filePath);
	int line = getFileLine(filePath);
	printf("文件中的有效行数为:%d\n", line);
	struct ConfigInfo *pArray = NULL;
	parserFile(filePath,line, &pArray);
	if (!pArray)
	{
		return;
	}
	int i;
	for (i = 0; i < line; i++)
	{
		printf("key=%s--value=%s\n", (pArray + i)->key, (pArray + i)->value);
	}
	printf("heroId=%s\n", getInfoByKey("heroId", pArray, line));
	freeSpace(pArray);
	pArray = NULL;
}
void test03(char * filePath)
{
	char *p[] = 
	{
		"#英雄的ID\n",
		"heroId:1\n",
		"#英雄的姓名\n",
		"heroName:孙悟空\n",
		"#英雄的攻击力\n",
		"heroAtk:1000\n",
		"#英雄的防御力\n",
		"heroDef:999\n",
		"#英雄简介\n",
		"heroInfo:无敌\n"
	};
	FILE * destFile = fopen(filePath,"w+");
	if (!destFile)
	{
		return;
	}
	int len = sizeof(p) / sizeof(char*);
	int i;
	for (i=0;i<len;i++)
	{
		fputs(*(p + i), destFile);
	}
	fclose(destFile);
}
void test02(void)
{
	char * sourceFilePath = "config.txt";
	char * destFilePath = "加密文件.txt";
	char * path = "解密文件.txt";
	test03(sourceFilePath);
	codeFile(sourceFilePath,destFilePath);
	decodeFile(destFilePath, path);
}
int main()
{
	srand((unsigned int)time(NULL));
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}