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


//��������
void insert_linkList(struct LinkNode *pHeader, int oldVal, int newVal)
{
	if (!pHeader)
	{
		return;
	}
	//������������ָ�����
	struct LinkNode * pPrev = pHeader;
	struct LinkNode *pCurrent = pHeader->next;
	while (pCurrent)
	{
		if (pCurrent->num == oldVal)//�ҵ�����λ��
		{
			break;
		}
		//û���ҵ�λ�ã��ø���ָ�����
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	//�����½ڵ�
	struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	newNode->num = newVal;
	newNode->next = NULL;

	//������ϵ,����ָ���ָ��
	newNode->next = pCurrent;
	pPrev->next = newNode;
}

//ɾ������
void delete_linkList(struct LinkNode *pHeader, int val)
{
	if (!pHeader)
	{
		return;
	}
	struct LinkNode *pPrev = pHeader;
	struct LinkNode * pCurrent = pHeader->next;
	while (pCurrent)
	{
		if (pCurrent->num == val)
		{
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
	if (!pCurrent)
	{
		return;
	}
	pPrev->next = pCurrent->next;
	free(pCurrent);
	pCurrent = NULL;
}

//�������
void clear_linkList(struct LinkNode *pHeader)
{
	if (!pHeader)
	{
		return;
	}
	//������ʱָ�����
	struct LinkNode * pCurrent = pHeader->next;
	while (pCurrent)
	{
		//�ȱ���ס��ɾ���ڵ����Ľڵ�
		struct LinkNode *nextNode = pCurrent->next;
		free(pCurrent);
		pCurrent = NULL;
		pCurrent = nextNode;
	}
	//ͷ�ڵ��next�ÿ�
	pHeader->next = NULL;

}

//����
void destroty_linkList(struct LinkNode *pHeader)
{
	if (!pHeader)
	{
		return;
	}
	//���������
	clear_linkList(pHeader);
	//���ͷ�ͷ�ڵ�
	free(pHeader);
	pHeader = NULL;
}

