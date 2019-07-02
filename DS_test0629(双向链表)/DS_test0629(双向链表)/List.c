#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include"List.h"

void ListInit(List* plist)
{
	assert(plist != NULL);
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	memset(&plist->_head->_data, 0, sizeof(LTDataType));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListDestory(List* plist)
{
	assert(plist->_head != NULL && plist != NULL);
	ListNode* cur = plist->_head->_next;
	for (; cur != plist->_head; cur = cur->_next)
	{
		plist->_head->_next = cur->_next;
		cur->_next->_prev = plist->_head;
		free(cur);
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPushBack(List* plist, LTDataType x)
{
	assert(plist != NULL && plist->_head != NULL);
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev->_next = cur;
	cur->_next = plist->_head;
	plist->_head->_prev = cur;
}

void ListPopBack(List* plist)
{
	assert(plist != NULL && plist->_head != NULL);
	ListNode *cur = plist->_head->_prev;
	if (cur != plist->_head)
	{
		cur->_next->_prev = cur->_prev;
		cur->_prev->_next = cur->_next;
		free(cur);
	}
}

void ListPushFront(List* plist, LTDataType x)
{
	assert(plist != NULL && plist->_head != NULL);
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	cur->_next = plist->_head->_next;
	plist->_head->_next->_prev = cur;
	cur->_prev = plist->_head;
	plist->_head->_next = cur;
}

void ListPopFront(List* plist)
{
	assert(plist != NULL && plist->_head!=NULL);
	ListNode *cur = plist->_head->_next;
	if (cur != plist->_head)
	{
		cur->_next->_prev = cur->_prev;
		cur->_prev->_next = cur->_next;
		free(cur);
	}
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist->_head != NULL && plist != NULL);
	ListNode *cur = plist->_head->_next;
	for (; cur != plist->_head; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}


void ListInsert(ListNode* pos, LTDataType x)// 在pos的前面进行插入 
{
	assert(pos != NULL);
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	cur->_prev = pos;
	pos->_next->_prev = cur;
	pos->_next = cur;
}

void ListErase(ListNode* pos)// 删除pos位置的节点 
{
	assert(pos != NULL);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
	pos = NULL;
}

void ListRemove(List* plist, LTDataType x)
{
	assert(plist->_head != NULL && plist != NULL);
	ListNode* cur = plist->_head->_next;
	for (; cur != plist->_head; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			cur->_prev->_next = cur->_next;
			cur->_next->_prev = cur->_prev;
			free(cur);
			return;
		}
	}
}

void ListPrint(List* plist)
{
	assert(plist != NULL); 
	ListNode *cur= plist->_head->_next;
	printf("head<->");
	for (; cur!= plist->_head; cur = cur->_next)
	{
		printf("%d<->", cur->_data);
	}
	printf("head");
}