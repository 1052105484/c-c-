#pragma once
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "GameCompany.h"
struct Player
{
	char name[64];//�������
	int level;//��������ҵĵȼ�
	int exp;//��Ҿ���
};
//��ʼ����Ϸ
void INIT_GAME_COMPANY(void **gameHandle, char * name)
{
	struct Player *player=malloc(sizeof(struct Player));
	if (!player)
	{
		return;
	}
	strcpy(player->name,name);
	player->level = 0;
	player->exp = 0;
	*gameHandle = player;
}

//��Ϸս��,������Ϸս���Ľ���������1 ������Ϸʤ�� ����0������Ϸʧ��
int FIGHT_GAME_COMPANY(struct Player *gameHandle, int gameLevel)
{
	int addExp = 0;//�ۼӵľ���ֵ
	switch (gameLevel)
	{
	case 1:
		addExp = isWin(90, 1);
		break;
	case 2:
		addExp = isWin(50, 2);
		break;
	case 3:
		addExp = isWin(30, 3);
		break;
	default:
		break;
	}
	gameHandle->exp += addExp;
	gameHandle->level = gameHandle->exp / 10;
	if (addExp==0)
	{
		return 0;
	}
	return 1;
}

//�鿴�����Ϣ
void PRINT_GAME_COMPANY(struct Player  *gameHandle)
{
	printf("����:%s �ȼ�:%d  ����:%d\n", gameHandle->name, gameHandle->level, gameHandle->exp);
}

//�뿪��Ϸ
void CLOSE_GAME_COMPANY(void *gameHandle)
{
	if (!gameHandle)
	{
		return;
	}
	if (gameHandle)
	{
		free(gameHandle);
		gameHandle = NULL;
	}
}

//�ж���Ϸ�Ƿ�ʤ��,����1 ʤ�� ����2 �Ѷ� ����ֵ ʤ����ľ��飬������ص���0������ս��ʧ��
int isWin(int winRate, int diff)
{
	int random = rand()%100+1;//1~100
	if (random<=winRate)//����ʤ��
	{
		return 10 * diff;
	}
	return 0;
}