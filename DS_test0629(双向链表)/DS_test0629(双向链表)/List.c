#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include"List.h"

void ListInit(List* plist)
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	memset(&plist->_head->_data, 0, sizeof(LTDataType));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListDestory(List* plist)
{
	assert(plist != NULL);
	ListNode* cur = plist->_head;
	ListNode* tmp = plist->_head->_next;
	for (;;)
	{
	}
}

void ListPushBack(List* plist, LTDataType x)
{
	assert(plist != NULL);
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev->_next = cur;
	cur->_next = plist->_head;
	plist->_head->_prev = cur;
}

void ListPushBack1(List* plist)
{

}

void ListPushFront(List* plist, LTDataType x)
{
	assert(plist != NULL);
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;
	cur->_next = plist->_head->_next;
	plist->_head->_next->_prev = cur;
	cur->_prev = plist->_head;
	plist->_head->_next = cur;
	//cur->_next = plist->_head->_next;
	//plist->_head->_next = cur;
	//cur->_prev = plist->_head;
	//if (plist->_head->_prev == plist->_head)//防止链表中只有一个头结点
	//{
	//	plist->_head->_prev = cur;
	//}
}

void ListPopFront(List* plist);

ListNode* ListFind(List* plist, LTDataType x); // 在pos的前面进行插入

void ListInsert(ListNode* pos, LTDataType x); // 删除pos位置的节点 

void ListErase(ListNode* pos);

void ListRemove(List* plist, LTDataType x);

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