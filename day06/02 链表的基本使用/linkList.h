#pragma once
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//�ڵ�����
struct LinkNode
{
	int num;
	struct LinkNode *next;
};
//��ʼ������
struct LinkNode * init_linkList();
//��������
void foreach_linkList(struct LinkNode *pHeader);
