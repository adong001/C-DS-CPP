#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"seqList.h"

void SeqListInit(SeqList* psl, size_t capacity)//初始化
{
	assert(psl != NULL);
	psl->array = (SeqList*)malloc(sizeof(SeqList)*capacity);
	assert(psl->array != NULL);
	psl->capacity = capacity;
	psl->size = 0;	
}

void SeqListDestory(SeqList* psl)
{
	assert(psl != NULL);
	if (psl->array != NULL)
	{
		free(psl->array);
		psl->array = NULL;
		psl->capacity = 0;
		psl->size = 0;
	}
}

void CheckCapacity(SeqList* psl)
{
	assert(psl!=NULL);
	if (psl->size == psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SeqList*)realloc(psl->array, psl->capacity*sizeof(SeqList)); 
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl != NULL);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl)
{
	assert(psl != NULL || psl->size == 0);
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	int i;
	assert(psl != NULL);
	CheckCapacity(psl);
	for (i = psl->size; i > 0; i--)
	{
		psl->array[i] = psl->array[i-1];
	}
	psl->array[0] = x;
	psl->size++;
}

void SeqListPopFront(SeqList* psl)
{
	int i;
	assert(psl != NULL || psl->size == 0);
	for (i = 0; i < psl->size-1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//找到返回坐标
{
	int i;
	assert(psl != NULL);
	for (i = 0; i < psl->size; i++)
	{
		if (x == psl->array[i])
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	int i;
	assert(psl != NULL||pos < psl->size);
	CheckCapacity(psl);
	for (i = psl->size; i > pos; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos)//按位置删除
{
	int i;
	assert(psl != NULL||pos < psl->size);
	for (i = pos; i <psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListRemove(SeqList* psl, SLDataType x)
{
	int pos;
	assert(psl != NULL);
	pos = SeqListFind(&psl, x);
	if (pos >= 0)
	{
		SeqListErase(&psl, pos);
	}
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl != NULL|| psl->size >= pos);
	psl->array[pos] = x;
}

void SeqListPrint(SeqList* psl)
{
	int i;
	assert(psl != NULL);
	for (i = 0; i < psl->size ; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

void SeqListBubbleSort(SeqList* psl)
{
	int i, j;
	SLDataType	temp;
	assert(psl != NULL);
	for (i = 0; i < psl->size;i++)
	{
		for (j = 0; j<psl->size - i - 1;j++)
		{
			if (psl->array[j] > psl->array[j+1])
			{
				temp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = temp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl != NULL);
	SLDataType left, right, mid;
	left = 0;
	right = psl->size - 1;
	mid = (left + right) / 2;
	while (left <= right)
	{
		if (psl->array[mid] == x)
		{
			return mid;
		}
		else if (psl->array[mid] < x)
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList* psl, SLDataType x)//删除重复的X
{
	int pos;
	int i;
	assert(psl != NULL);
	pos = SeqListFind(&psl, x);
	for (i = pos + 1; i < psl->size; i++)
	{
		pos = SeqListFind(&psl,x);
		if (pos >= 0)
		{
			SeqListErase(&psl, pos);
		}
	}
}