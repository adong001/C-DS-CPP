#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include"seqList.h"

void test()
{
	SeqList List;
	SeqListInit(&List, CAPACITY);
	SeqListPushBack(&List, 1);
	SeqListPushBack(&List, 2);
	SeqListPushBack(&List, 3); 
	SeqListPushBack(&List, 4);
	SeqListPushBack(&List, 4);
	SeqListPushBack(&List, 6);
	SeqListPushBack(&List, 4);
    SeqListBubbleSort(&List);
   printf("%d\n", SeqListBinaryFind(&List, 3));
	SeqListRemoveAll(&List, 4);
	SeqListPrint(&List);
	SeqListDestory(&List);
}

int main()
{
	test();
	system("pause");
    return 0;
}