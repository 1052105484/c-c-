#include "pch.h"
#include "code.h"
// ����
void codeFile(char * sourceFile, char * destFile)
{
	FILE *fp1 = fopen(sourceFile, "r");
	if (!fp1)
	{
		return;
	}
	FILE *fp2 = fopen(destFile, "w");
	if (!fp2)
	{
		return;
	}
	char ch;
	while ((ch = fgetc(fp1)) != EOF)
	{
		//# 35
		short temp = (short)ch;
		temp = temp << 4;
		temp = temp | 0x8000;
		temp = temp + rand() % 16;
		//printf("%d\n", temp);
		//���ܺ�����д�뵽�ļ���
		fprintf(fp2, "%hd", temp);
	}
	fclose(fp2);
	fclose(fp1);
}

//����
void decodeFile(char * sourceFile, char * destFile)
{
	FILE *fp1 = fopen(sourceFile, "r");
	if (!fp1)
	{
		return;
	}
	FILE *fp2 = fopen(destFile, "w");
	if (!fp2)
	{
		return;
	}
	short temp;
	while (!feof(fp1))
	{
		fscanf(fp1,"%hd", &temp);
		temp <<= 1;
		temp >>= 5;
		char ch = (char)temp;
		fputc(ch,fp2);
	};
	fclose(fp1);
	fclose(fp2);
}