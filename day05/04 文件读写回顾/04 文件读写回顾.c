// 04 文件读写回顾.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//1、字符的读写回顾，fgetc() fputc()
void test01(void)
{
	//写文件
	FILE * f_write = fopen("test1.txt", "w");
	if (!f_write)
	{
		return;
	}
	char buf[] = "helloworld";
	for (int i = 0; i < strlen(buf); i++)
	{
		fputc(*(buf + i), f_write);
	}
	fclose(f_write);
	FILE *f_read = fopen("test1.txt", "r");
	if (!f_read)
	{
		return;
	}
	char ch;
	while ((ch = fgetc(f_read)) != EOF)
	{
		printf("%c", ch);
	}
	fclose(f_read);
}
//2、按行进行读写
void test02(void)
{
#if 0
	//写文件
	FILE *f_write = fopen("test02.txt", "w+");
	if (!f_write)
	{
		return;
	}
	char * buf[] =
	{
			"锄禾日当午\n",
			"汗滴禾下土\n",
			"谁知盘中餐\n",
			"粒粒皆辛苦\n"
	};
	int i;
	for (i = 0; i < 4; i++)
	{
		fputs(buf[i], f_write);
	}
	fclose(f_write);
#endif
	FILE * f_read = fopen("test02.txt", "r");
	if (!f_read)
	{
		return;
	}
	while (!feof(f_read))
	{
		char temp[1024] = {0};
		fgets(temp, 1024,f_read);
		printf("%s", temp);
	}
	fclose(f_read);
}
//3、按块进行读写
struct Hero
{
	char name[64];//0~63
	int age;//64~68
};
void test03(void)
{
	//写文件
	FILE *f_write = fopen("test03.txt", "wb");
	if (!f_write)
	{
		return;
	}
	struct Hero heros[] = 
	{
		{"孙悟空",999},
		{"亚瑟",20},
		{"曹操",80},
		{"鲁班",5}
	};
	printf("%d\n", *(int*)(((char*)(heros + 2)) + 64));
	for (int i=0;i<4;i++)
	{
		//参数1    数据地址    参数2 块大小 参数3 块个数  参数4 文件指针
		fwrite(heros + i, sizeof(struct Hero), 1, f_write);
	}
	fclose(f_write);

	struct Hero temp[4];
	FILE *f_read = fopen("test03.txt", "rb");
	if (!f_read)
	{
		return;
	}
	fread(&temp,sizeof(struct Hero),4,f_read); 
	fclose(f_read);
	int i;
	for (i=0;i<4;i++)
	{
		printf("姓名:%s \t年龄:%d\n", (temp + i)->name, (temp + i)->age);
	}
}
//4、格式化读写回顾
void test04(void)
{
	//写文件
	FILE * f_write=fopen("test04.txt", "w+");
	if (!f_write)
	{
		return;
	}
	fprintf(f_write, "hello world %s", "abc");
	fclose(f_write);

	FILE *f_read = fopen("test04.txt", "r");
	if (!f_read)
	{
		return;
	}
	char temp[1024] = { 0 };
	while (!feof(f_read))
	{
		fscanf(f_read,"%s",temp);
		printf("%s\n", temp);
	}
	fclose(f_read);
}
//5、随机位置进行读写
void test05(void)
{
	//写文件
	FILE *f_write = fopen("test05.txt", "wb");
	if (!f_write)
	{
		return;
	}
	struct Hero heros[] =
	{
		{"孙悟空",999},
		{"亚瑟",20},
		{"曹操",80},
		{"鲁班",5}
	};
	for (int i = 0; i < 4; i++)
	{
		//参数1    数据地址    参数2 块大小 参数3 块个数  参数4 文件指针
		fwrite(heros + i, sizeof(struct Hero), 1, f_write);
	}
	fclose(f_write);
	FILE *f_read = fopen("test051.txt", "rb");
	if (!f_read)
	{
		//error 宏
		perror("文件加载失败");//用户的提示信息加上系统的提示信息
		return;
	}
	struct  Hero tempHero;
	//参数1 文件指针 参数2偏移大小 参数3 起始位置
	//SEEK_SET 从开始 SEEK_END 从结尾 SEEK_CUR 从当前位置
	//fseek(f_read, sizeof(struct Hero) * 2, SEEK_SET);
	//fseek(f_read, -(long)sizeof(struct Hero) * 2, SEEK_END);
	rewind(f_read);//将文件的光标置首
	fread(&tempHero, sizeof(struct Hero), 1, f_read);
	printf("%s\n", tempHero.name);
}
int main()
{
	//test01();
	test02();
	//test03();
	//test04();
	//test05();
	system("pause");
	return EXIT_SUCCESS;
}