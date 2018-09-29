#include "pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int * getSpace(void)
{
	int *p =malloc(sizeof(int) * 5);
	if (!p) {
		return NULL;
	}
	int i;
	for (i = 0; i < 5; ++i) {
		p[i] = i + 100;
	}
	return p;
}
void test01(void) {
	int *p = getSpace();
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d\n",*p+i);
	}
	free(p);
	p = NULL;
}
int main()
{
	test01();
	return 0;
}
