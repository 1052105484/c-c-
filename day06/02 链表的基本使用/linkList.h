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

//��������
void insert_linkList(struct LinkNode *pHeader,int oldVal,int newVal);

//ɾ������
void delete_linkList(struct LinkNode *pHeader,int val);

//�������
void clear_linkList(struct LinkNode *pHeader);

//����
void destroty_linkList(struct LinkNode *pHeader);
