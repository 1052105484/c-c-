// 03 查找子串.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//优化思路 memcmp(str,substr,3)==0
int myStrstr(char * str, char * substr)
{
	int ret = -1;
	int num = 0;
	while (str!='\0')
	{
		if (*str != *substr) 
		{
			str++;
			num++;
			continue;
		}
		//创建临时指针
		char *tempStr = str;
		char * tempSubStr = substr;
		while (*tempSubStr != '\0') 
		{
			if (*tempStr != *tempSubStr)
			{
				//匹配失败
				str++;
				num++;
				break;
			}
			tempStr++;
			tempSubStr++;
			if (*tempSubStr == '\0')
			{
				return num;
			}
		}
	}
	return ret;
}
void test01(void)
{
	char *str = "abcdefgdnf";
	int ret=myStrstr(str,"dnf");
	if (ret==-1)
	{
		printf("%s\n","没有找到字符");
	}
	else 
	{
		printf("找到了子串，位置为%d\n", ret);
	}
}
int main()
{
	test01();
	return 0;
}
