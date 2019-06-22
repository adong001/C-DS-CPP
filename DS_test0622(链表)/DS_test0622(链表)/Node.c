#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Node.h"


void SListInit(SList* plist)
{
	plist->_head = NULL;
}

void SListDestory(SList* plist)
{
	assert(plist != NULL);
	SList *temp;
	while (plist->_head != NULL)
	{
		temp = plist->_head->_next;
		free(plist->_head);
		plist->_head = temp;
	}
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode *cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	return cur;
}

void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist != NULL);
	SListNode *cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}

void SListPopFront(SList* plist)
{
	assert(plist != NULL);
	SList *temp;
	if (plist->_head != NULL)
  {
	temp = plist->_head->_next;
	free(plist->_head);
	plist->_head = temp;
  }
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist != NULL);
	SListNode *cur;
	for (cur = plist->_head; cur != NULL; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}

void SListInsertBefore(SListNode* pos, SLTDataType x)//前插
{
	assert(pos);
	SList *cur = NULL;
	SListNode *tmp = cur->_head;
	for (; tmp->_next!= NULL; tmp = tmp->_next)
	{
		if (tmp->_next == pos)
		{
			SListInsertAfter(tmp, x);
		}
	}
}
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode *cur;
	cur = BuySListNode(x);
	cur->_next = pos->_next;
	pos->_next = cur;
}


void SListEraseAfter(SListNode* pos)
{
	assert(pos != NULL && pos->_next != NULL );
	SListNode *temp = pos->_next;
	pos->_next = pos->_next->_next;
	free(temp);
	temp = NULL;
}

void SListRemove(SList* plist, SLTDataType x)
{
	SListNode *cur = plist->_head, *temp = NULL;
	assert(plist != NULL);
	if (cur->_data == x)
	{
		SListDestory(plist);
	}
	for (; cur->_next != NULL; cur = cur->_next)
	{
		if (cur->_next->_data == x)
		{
			temp = cur->_next;
			cur->_next = cur->_next->_next;
			free(temp);
			temp = NULL;
		}
	}
}

void SListPrint(SList* plist)
{
	assert(plist);
	SListNode *cur;
	for (cur = plist->_head; cur != NULL; cur = cur->_next)
	{
		printf("%d ", cur->_data);
	}
	putchar('\n');
}

void TestSList();