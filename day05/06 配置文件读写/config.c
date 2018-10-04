#include "pch.h"
#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//��ȡ��Ч����
int getFileLine(char * filename)
{
	FILE *f_read = fopen(filename, "r");
	if (!f_read)
	{
		return -1;
	}
	char buf[1024] = { 0 };
	int lines = 0;
	while (fgets(buf, 1024, f_read))
	{
		//�������Ч��һ���У���ȥͳ��
		if (isValidLine(buf))
		{
			lines++;
		}
	}
	fclose(f_read);
	return lines;
}


//�жϵ�ǰ���Ƿ���Ч
int isValidLine(char * str)
{
	if (str[0] == ' ' || str[0] == '\0' || !strchr(str, ':'))
	{
		return 0;//��Ч���� �����ؼ٣���Ч���ݷ�����
	}
	return 1;
}

//�����ļ�
void parserFile(char * filePath, int lines, struct ConfigInfo **configInfo)
{
	struct ConfigInfo  *info = malloc(sizeof(struct ConfigInfo)*lines);
	if (!info)
	{
		return;
	}
	FILE * f_read = fopen(filePath, "r");
	if (!f_read)
	{
		return;
	}
	int index = 0;
	char buf[1024] = { 0 };
	while (fgets(buf, 1024, f_read))
	{
		if (isValidLine(buf))
		{
			memset((info + index)->key, 0, 64);
			memset((info + index)->value, 0, 64);
#if 0
			sscanf(buf, "%[^:]:%s", (info + index)->key, (info + index)->value);
#else
			char *pos = strchr(buf, ':');
			strncpy((info + index)->key,buf,pos-buf);//��key��ȡ���ṹ����
			strncpy((info + index)->value, pos+1,strlen(pos+1)-1);//����1��ԭ���ǲ���Ҫ��ȡ���з�
#endif
			index++;
		}
		memset(buf, 0,1024);
	}
	fclose(f_read);
	*configInfo = info;
}

//��������ֵ��ȡʵֵ 
char * getInfoByKey(char * key, struct ConfigInfo *configInfo, int line)
{
	int i;
	for (i=0;i<line;i++)
	{
		if (!strcmp((configInfo + i)->key,key))
		{
			return (configInfo + i)->value;
		}
	}
	return NULL;
}
//�ͷ���Ϣ
void freeSpace(struct ConfigInfo * configInfo)
{
	if (configInfo)
	{
		free(configInfo);
		configInfo = NULL;
	}
}