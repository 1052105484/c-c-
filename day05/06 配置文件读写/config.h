#pragma once
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct ConfigInfo
{
	char key[64];//����ֵ
	char value[64];//ʵֵ
};
//��ȡ��Ч����
int getFileLine(char * filename);

//�жϵ�ǰ���Ƿ���Ч
int isValidLine(char * str);

//�����ļ�
void parserFile(char * filePath, int lines, struct ConfigInfo **configInfo);
//��������ֵ��ȡʵֵ 
char * getInfoByKey(char * key, struct ConfigInfo *configInfo, int line);
//�ͷ���Ϣ
void freeSpace(struct ConfigInfo * configInfo);