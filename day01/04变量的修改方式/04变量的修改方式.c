#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Person {
	char a;
	int b;
	char c;
	int d;
}MPerson;
void test1(void) {
	int a = 10;
	//直接修改
	a = 20;
	//间接修改
	int * p = &a;
	*p = 100;
	int c = 20;
	p = &c;
	printf("%d\t%d", a, *p);
}
int  test2(void)
{
	MPerson p1 = {'a',10,'b',20};
	printf("%c\t%d\t%c\t%d\n", p1.a, p1.b, p1.c, p1.d);
	p1.d = 1000;
	printf("%c\t%d\t%c\t%d\n", p1.a, p1.b, p1.c, p1.d);
	MPerson *p;
	p = &p1;
	p->d = 2000;
	printf("%c\t%d\t%c\t%d\n", p1.a, p1.b, p1.c, p1.d);
	return 0;
}
int main()
{
	//test1();
	test2();
	return 0;
}