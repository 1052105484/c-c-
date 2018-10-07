#pragma once
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//��̬����Ľṹ��
struct dynamicArray
{
	void **pAddr;//ά���ڶ�����ʵ����ָ��
	int m_capacity;//���������
	int m_size;//�����С
};
//��ʼ������
struct dynamicArray * init_DynamicArray(int capacity);

//���빦��
void insert_dynamicArray(struct dynamicArray*array, int pos, void *data);

//��������
void foreach_DynamicArray(struct dynamicArray *array, void(*mForeach)(void *));

//ɾ������--����ָ��λ�ý���ɾ��
void remove_dynamicArray(struct dynamicArray * array, int pos);

//ɾ��������Ԫ�أ�����Ԫ����ɾ��
void removeByValue(struct dynamicArray *array, void * data, int(*compare)(void *, void *));

//��������
void destroy(struct dynamicArray *array);