// 08 字符串强化训练.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

void test01(void)
{
	//注意字符串需要有结束标志
	char str1[] = { 'h','e','l','l','o','\0' };
	printf("%s\n", str1);

	//字符串数组部分初始化，剩余填0
	char str2[100] = { 'h','e','l','l','o' };
	printf("%s\n", str2);

	//如果以字符串初始化，那么编译器会默认在字符串尾部添加'\0'
	char str3[] = "hello";
	printf("%s\n", str3);
	printf("%d\n", sizeof(str3));
	printf("%d\n", strlen(str3));


	char str5[] = "hello\0world";
	printf("%s\n", str5);
	printf("%d\n", sizeof(str5));
	printf("%d\n", strlen(str5));

	char str6[] = "hello\012world";
	printf("%s\n", str6);
	printf("%d\n", sizeof(str6));
	printf("%d\n", strlen(str6));
}
//将原字符中的内容拷贝到目标字符串中
void copyString(char * dest/*目标字符串*/, char *source/*原字符串*/)
{
	int i;
	int len;
	for (i = 0, len = strlen(source); i < len; i++) {
		dest[i] = source[i];
	}
	dest[len] = '\0';
}

//2.第二种，字符串指针进行操作
void copyString02(char * dest/*目标字符串*/, char *source/*原字符串*/)
{
	int len = strlen(source);
	while (*source != NULL)
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}
//第三种
void copyString03(char * dest/*目标字符串*/, char *source/*原字符串*/)
{
	while (*dest++ = *source++);
}
//字符串拷贝
void test02(void)
{
	char *str = "hello world";
	char buf[1024];
	//copyString(buf, str);
	//copyString02(buf,str);
	copyString03(buf, str);
	printf("%s\n", buf);

}

void reverseString01(char *str)
{
	int len = strlen(str);
	//起始位置下标
	int start = 0;
	//结束位置下标
	int end = len - 1;
	while (start < end)
	{
		char temp = NULL;
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void reverseString02(char *str)
{
	int len = strlen(str);
	char * start = str;
	char * end = str + len - 1;
	while (start < end)
	{
		char	temp = *start;
		*start =*end;
		*end = temp;
		start++;
		end--;
	}
}
//字符串反转
void  test03(void)
{
	char buf[] = "abcdefg";
	//reverseString01(buf);
	reverseString02(buf);
	printf("%s\n", buf);
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}