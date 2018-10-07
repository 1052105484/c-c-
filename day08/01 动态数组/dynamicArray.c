#include "pch.h"
#include "dynamicArray.h"

//��ʼ������
struct dynamicArray * init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	struct dynamicArray *array = malloc(sizeof(struct dynamicArray));
	if (!array)
	{
		return NULL;
	}
	array->m_capacity = capacity;
	array->m_size = 0;
	array->pAddr = malloc(sizeof(void*)*array->m_capacity);
	return array;
}

//���빦��
void insert_dynamicArray(struct dynamicArray*array, int pos, void *data)
{
	if (!array)
	{
		return;
	}
	if (!data)
	{
		return;
	}
	if (pos<0 || pos>array->m_size)
	{
		//��Ч��λ�ã�����β��
		pos = array->m_size;
	}
	//���ж��Ƿ����أ�������ˣ���̬���п���
	if (array->m_size >= array->m_capacity)
	{
		//1������һ��������ڴ�ռ�
		int newCapacity = array->m_capacity * 2;
		//2�������¿ռ�
		void **newSpacec = malloc(sizeof(void*)*newCapacity);
		//3����ԭ�е����ݣ��������¿ռ���
		memcpy(newSpacec, array->pAddr, sizeof(void*)*array->m_capacity);
		//4���ͷ�ԭ�пռ�
		free(array->pAddr);
		//6��������������С
		array->pAddr = newSpacec;
		array->m_capacity = newCapacity;
	}
	//����������Ԫ��
	//�����һ��λ�ÿ�ʼ�����ƶ����� ����
	int i;
	for (i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}
	//����Ԫ�ز��뵽ָ��λ��
	array->pAddr[pos] = data;
	//���´�С
	array->m_size++;
}

//��������
void foreach_DynamicArray(struct dynamicArray *array, void(*mForeach)(void *))
{
	if (!array)
	{
		return;
	}
	if (!mForeach)
	{
		return;
	}
	int i;
	for (i = 0; i < array->m_size; i++)
	{
		mForeach(array->pAddr[i]);
	}
}

//ɾ������--����ָ��λ�ý���ɾ��
void remove_dynamicArray(struct dynamicArray * array, int pos)
{
	if (!array)
	{
		return;
	}
	if (pos<0 || pos>array->m_size - 1)
	{
		return;
	}
	int i;
	for (i = pos; i < array->m_size - 1; i++)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}
	array->m_size--;
}

//ɾ��������Ԫ�أ�����Ԫ����ɾ��
void removeByValue(struct dynamicArray *array, void * data, int(*compare)(void *, void *))
{
	if (!array)
	{
		return;
	}
	if (!data)
	{
		return;
	}
	if (!compare)
	{
		return;
	}
	int i;
	for (i = 0; i < array->m_size; i++)
	{
		if (compare(array->pAddr[i], data))
		{
			remove_dynamicArray(array, i);
			break;
		}
	}
}

//��������
void destroy(struct dynamicArray *array)
{
	if (!array)
	{
		return;
	}
	if (array->pAddr)
	{
		free(array->pAddr);
		array->pAddr = NULL;
	}
	if (array)
	{
		free(array);
		array = NULL;
	}
}

