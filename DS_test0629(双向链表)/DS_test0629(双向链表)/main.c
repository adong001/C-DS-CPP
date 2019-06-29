#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include"List.h"
int main()
{
	ListNode test;
	ListInit(&test);
	ListPushFront(&test, 1);
	ListPushFront(&test, 2);
	ListPushFront(&test, 3);
	ListPushFront(&test, 4);
	ListPushBack(&test, 1);
	ListPushBack(&test, 2);
	ListPushBack(&test, 3);
	ListPushBack(&test, 4);
	ListPrint(&test);
	system("pause");
	return 0;
}

