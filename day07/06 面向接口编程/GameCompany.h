#pragma once
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//��ʼ����Ϸ
 void INIT_GAME_COMPANY(void **gameHandle, char * name);

//��Ϸս��,������Ϸս���Ľ���������1 ������Ϸʤ�� ����0������Ϸʧ��
 int FIGHT_GAME_COMPANY(struct Player  *gameHandle, int gameLevel);

//�鿴�����Ϣ
void PRINT_GAME_COMPANY(struct Player  *gameHandle);

//�뿪��Ϸ
 void CLOSE_GAME_COMPANY(struct Player  *gameHandle);

 //�ж���Ϸ�Ƿ�ʤ��,����1 ʤ�� ����2 �Ѷ� ����ֵ ʤ����ľ��飬������ص���0������ս��ʧ��
 int isWin(int winRate, int diff);
