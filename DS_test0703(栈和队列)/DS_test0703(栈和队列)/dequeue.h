#ifndef _DEQUEUE_H_
#define _DEQUEUE_H_
#define _CRT_SECURE_NO_WARNINGS 1
#define QUEUENUM 5
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct{
	DataType _data[QUEUENUM];
	DataType *_head;
	DataType *_tail;
	size_t _size;
}Dequeue;

void dequeueInit(Dequeue * qu);
void dequeueDestory(Dequeue * qu);
void dequeueEmpty(Dequeue * qu);
int dequeuePush(Dequeue * qu, DataType x);
int dequeuePop(Dequeue * qu);
Dequeue *dequeueFront(Dequeue * qu);
Dequeue *dequeueBack(Dequeue * qu);
int dequeueIsEmpty(Dequeue * qu);
int dequeueSize(Dequeue * qu);

#endif _DEQUEUE_H_
