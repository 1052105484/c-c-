// 06 面向接口编程.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <time.h>
#include "GameCompany.h"
//初始化游戏
typedef void(*INIT_GAME)(void **gameHandle, char * name);

//游戏战斗,返回游戏战斗的结果，如果是1 代表游戏胜利 返回0代表游戏失败
typedef int(*FIGHT_GAME)(void *gameHandle, int gameLevel);

//查看玩家信息
typedef void(*PRINT_GAME)(void *gameHandle);

//离开游戏
typedef void(*CLOSE_GAME)(void *gameHandle);

void playGame(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME printGame, CLOSE_GAME closeGame)
{
	//初始化游戏
	void *gameHadle = NULL;
	printf("请输入玩家的姓名:\n");
	char name[64];
	scanf("%s", name);
	init(&gameHadle, name);
	//游戏战斗
	int level=-1;
	while (1)
	{
		getchar();
		system("cls");
		printf("请选择游戏难度:\n");
		printf("1、普通\n");
		printf("2、中等\n");
		printf("3、困难\n");
		scanf("%d", &level);
		getchar();
		int ret = fight(gameHadle, level);
		if (!ret)
		{
			printf("挑战失败!\n");
			break;
		}
		else
		{
			printf("挑战成功!\n");
		}
		printGame(gameHadle);
	}
	closeGame(gameHadle);
}

void test01()
{
	playGame(INIT_GAME_COMPANY, FIGHT_GAME_COMPANY, PRINT_GAME_COMPANY, CLOSE_GAME_COMPANY);
}
int main()
{
	srand((unsigned int)time(NULL)) ;
	test01();
	system("pause");
	return EXIT_SUCCESS;
}