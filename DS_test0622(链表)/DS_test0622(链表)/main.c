#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include"Node.h"
#include<assert.h>
void TestSList()
{
	SList test;
	SListNode *n;
	SListInit(&test);
	SListPushFront(&test, 4);
	SListPushFront(&test, 1);
	SListPushFront(&test, 5);
	SListPushFront(&test, 3);
	SListPushFront(&test, 9);
   /* n=SListFind(&test, 5);
	printf("%d\n", n->_data);*/
	//SListInsertAfter(test._head, 100);
	/*SListInsertAfter(test._head->_next, 111);
	SListInsertAfter(test._head->_next, 112);*/
	SListRemove(&test, 1);
	// 在pos的前面进行插入
	// SListEraseAfter(test._head ->_next);
	SListPrint(&test);
}
int main()
{
	TestSList();
    system("pause");
    return 0;
}