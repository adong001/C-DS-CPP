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

#if 0
void SListReverse(SList *plist)
{
	assert(plist != NULL);
	SListNode *tmp = plist->_head->_next;
	SListNode *cur = plist->_head;
	while (tmp != NULL)
	{
		cur->_next = tmp->_next;
		tmp->_next = plist->_head;
		plist->_head = tmp;
		tmp = cur->_next;
	}
}
#else

void SListReverse(SList *plist)
{
	assert(plist != NULL);
	SListNode *tmp = plist->_head->_next;
	SListNode *cur = plist->_head;
	//SListNode *newhead = cur;
	cur->_next = NULL;
	while (tmp != NULL)
	{
		plist->_head = tmp;
		tmp = tmp->_next;
		plist->_head->_next = cur;
		cur = plist->_head;
	}
	/*while(tmp != NULL)
	{
		newhead = tmp;
		tmp = tmp->_next;
		newhead->_next = cur;
		cur = cur->_next;
	}
	plist->_head->_next = NULL;
	plist->_head = newhead;*/
}
#endif
int SListSize(SList *plist) //求链表节点个数
{
	int count = 0;
	SListNode *tmp = plist->_head;
	assert(plist != NULL);
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->_next;
	}
	return count;
}

SListNode* SListIntersect(SList *plistA, SList *plistB)//找到两个链表相交的第一个节点返回(链表无环)
{
	int lenA = 0;
	int lenB = 0;
	int i;
	int gap;
	SListNode* headlong = plistA->_head;
	SListNode* headshort = plistB->_head;
	lenA = SListSize(&plistA);//分别求两个链表节点长度
	lenB = SListSize(&plistB);
	gap = lenA - lenB;
	if (gap < 0)
	{
		gap *= -1;
		headlong = plistB->_head;
		headshort = plistA->_head;
	}
	for (i = 0; i < gap; i++)
	{
		headlong = headlong->_next;
	}
	for (; headlong != NULL; headlong = headlong->_next, headshort = headshort->_next)
	{
		if (headlong == headshort)
		{
			return headlong;
		}
	}
	return NULL;
}

int SListHasCycle(SList *plist)
{
	SListNode* fast = plist->_head;
	SListNode* slow = plist->_head;
	while (slow && fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast)
		{
			return 1;
		}
	}
	return 0;
}
SList* SListGetHasCycle(SList *plist)
{
	SListNode* fast = plist->_head;
	SListNode* slow = plist->_head;
	while (slow && fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast)
		{
			return slow;
		}
	}
	return NULL;
}
SListNode *SListDelectCycle(SList* plist)
{
	SListNode * cur = plist->_head;
	SListNode *tmp = SListGetHasCycle(&plist);
	if (tmp == NULL)
	{
		return NULL;
	}
	for (; cur != NULL; cur = cur->_next ,tmp =tmp->_next)
	{
		if (cur == tmp)
		{
			return cur;
		}
	}

}
void TestSList();