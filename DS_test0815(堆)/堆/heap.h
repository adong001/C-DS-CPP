#ifndef HEAP_H
#define HEAP_H
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType *data;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);//初始化堆
void HeapDestory(Heap* hp);//销毁堆
void HeapPush(Heap* hp, HPDataType x);//插入元素x,保证产生新堆
void HeapPop(Heap* hp);//删除堆顶元素,保证产生新堆
HPDataType HeapTop(Heap* hp);//判断堆是否为空，为空返回0，否则返回第一个元素
int HeapSize(Heap* hp);//堆内数据的数量
int HeapEmpty(Heap* hp);//清空堆
void HeapPrint(Heap* hp);//打印堆
void AdjustDown(Heap* hp, int n);//从n节点处向下调整函数
void AdjustUp(Heap* hp);//(从最后一个节点)向上调整函数
void HeapSort(int* a, int n);// 堆排序 
void TestHeap();

#endif 
