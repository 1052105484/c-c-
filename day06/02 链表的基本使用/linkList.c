#include "pch.h"
#include "linkList.h"
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//��ʼ������
struct LinkNode * init_linkList()
{
	struct LinkNode * p = malloc(sizeof(struct LinkNode));
	if (!p)
	{
		return NULL;
	}
	p->num = -1;//ͷ�ڵ㲻ά��������
	p->next = NULL;//ͷ�ڵ��ʼ��ָ����ΪNULL
	int value = -1;

	//����һ��β�ڵ㣬���ں�������µ�����
	struct LinkNode *pTail = p;
	while (1)
	{
		printf("���������:(-1�����������:)\n");
		scanf("%d", &value);
		if (value == -1)
		{
			break;
		}
		//�����½ڵ�
		struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
		newNode->num = value;
		newNode->next = NULL;

		//������ϵ
		pTail->next = newNode;
		//�������µ�β�ڵ�
		pTail = newNode;
		


	}
	return p;
}


//��������
void foreach_linkList(struct LinkNode *pHeader)
{
	if (!pHeader)
	{
		return;
	}
	//pCurrent ��ʼָ����ǵ�һ����ʵ��Ч�Ľڵ�
	struct LinkNode *pCurrent = pHeader->next;
	while (pCurrent)
	{
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}
}

