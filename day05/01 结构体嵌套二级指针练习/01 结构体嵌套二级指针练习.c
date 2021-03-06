// 01 结构体嵌套二级指针练习.c : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct Teacher
{
	char * name;
	char **student;
};
void allocateSpace(struct Teacher ***teachers)
{
	struct Teacher **p = calloc(3, sizeof(struct Teacher*));
	int i;
	for (i = 0; i < 3; i++)
	{
		//给每个老师分配空间
		p[i] = calloc(1, sizeof(struct Teacher));
		//给每个老师姓名分配空间
		p[i]->name = calloc(64, sizeof(char));
		sprintf(p[i]->name, "Teacher_%d", i + 1);

		//给老师带的学生的数组分配空间
		p[i]->student = calloc(4, sizeof(char*));
		int j;
		for (j = 0; j < 4; j++)
		{
			p[i]->student[j] = calloc(64, sizeof(char));
			sprintf(p[i]->student[j], "%s_Student_%d", p[i]->name, j + 1);
		}
	}
	*teachers = p;
}
void printTeacherS(struct Teacher **p, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("第%d个老师的姓名是:%s\n他的学生有:\n", i + 1, p[i]->name);
		int j;
		for (j = 0; j < 4; j++)
		{
			printf("\t第%d个学生的姓名是:%s\n", j + 1, p[i]->student[j]);
		}
		printf("\n");
	}
}
void freeSpace(struct Teacher ***p, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		//释放老师的姓名
		if ((*p)[i]->name)
		{
			free((*p)[i]->name);
			(*p)[i]->name = NULL;
		}
		int j;
		//释放学生
		for (j = 0; j < 4; j++)
		{
			if ((*p)[i]->student[j])
			{
				free((*p)[i]->student[j]);
				(*p)[i]->student[j] = NULL;
			}
		}
		//释放学生数组
		if ((*p)[i]->student)
		{
			free((*p)[i]->student);
			(*p)[i]->student = NULL;
		}
		//释放老师
		if ((*p)[i])
		{
			free((*p)[i]);
			(*p)[i] = NULL;
		}
	}
	//释放大数组
	if ((*p))
	{
		free(*p);
		*p = NULL;
	}
}
void test01(void)
{
	struct Teacher **pArray = NULL;
	//分配内存
	allocateSpace(&pArray);
	//打印数据
	printTeacherS(pArray, 3);
	//释放内存
	freeSpace(&pArray, 3);
	if (pArray)
	{
		printf("没有释放\n");
	}
	else
	{
		printf("释放完成\n");
	}
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}


