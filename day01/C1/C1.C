#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
void test01();
void test02();
void test03();
#define print(...) printf(__VA_ARGS__)
int main()
{
	//test01();
	test03();
	return 0;
}
void test01()
{
	printf("sizeof int =%d\n", sizeof(int));
	double d = 3.14;
	printf("sizeof double d=%d\n",sizeof d);
}
void test02()
{
void * a;
	a = '3';
	char *p2;
	p2 = a;
}
void test03()
{
	unsigned int a = 10;
	a = a - 20;
	if (a>0) {
		printf("a大于0\n");
		print("%u", a);
	}
	else {
		printf("a小于0");
	}
}