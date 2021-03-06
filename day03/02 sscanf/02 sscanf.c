// 02 sscanf.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
//1.   %*s或者%*d跳过数据
void test01(void)
{
	char *str = "12345abcde";
	char buf[1024] = {0};
	sscanf(str,"%*d%s",buf);
	printf("%s\n",buf);
}
void test02(void)
{
	char *str = "abcde12345";//在中间加空格或者\t都可以实现效果
	char buf[1024] = { 0 };
	//sscanf(str, "%*s%s", buf);
	sscanf(str,"%*[a-z]%s",buf);
	printf("%s\n", buf);
}
//2. %[width]s读取指定宽度的数据
void test03(void) 
{
	char *str = "abcde12345";
	char buf[1024] = { 0 };
	sscanf(str, "%5s", buf);
	printf("%s\n", buf);
}
//3. %[a-z]匹配a到z中任意字符（尽可能多的匹配）
void test04(void)
{
	char *str = "12345abcde";
	char buf[1024] = { 0 };
	sscanf(str,"%*d%[a-z]",buf);
	printf("%s\n", buf);
}
//4. %[aBc] 匹配a 、B、c中的一员，贪婪性
void test05(void) 
{
	char *str = "aabcde12345";
	char buf[1024] = { 0 };
	sscanf(str,"%[abc]",buf);//在匹配的过程中，只要有有一个匹配失败，后续就不再匹配
	printf("%s\n", buf);
}
//5 .%[^a] 匹配非a得任意字符，贪婪性
void test06(void) 
{
	char *str = "abcde12345";
	char buf[1024] = { 0 };
	sscanf(str, "%[^c]", buf);
	printf("%s\n", buf);
}
//6 .%[^a-z] 表示读取除a-z以外的所有字符
void test07(void)
{
	char *str = "abcde12345";
	char buf[1024] = { 0 };
	sscanf(str, "%[^0-9]", buf);
	printf("%s\n", buf);
}
//7、案列
void test08(void)
{
	char *ip = "127.0.0.1";
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	sscanf(ip,"%d.%d.%d.%d", &num1, &num2, &num3,&num4);
	printf("%d\n",num1);
	printf("%d\n", num2);
	printf("%d\n", num3);
	printf("%d\n", num4);
}
void test09(void) 
{
	char *str = "abcde#zhangtao@12345";
	char buf[1024] = { 0 };
	sscanf(str,"%*[^#]#%[^@]",buf);
	printf("%s\n", buf);
}
void test10(void)
{
	char *str = "helloworld@itcast.cn";
	char buf1[1024] = { 0 };
	char buf2[1024] = { 0 };
	sscanf(str,"%[a-z]%*[@]%s", buf1,buf2);
	printf("%s\t%s\n", buf1,buf2);
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	test10();
	return 0;
}

