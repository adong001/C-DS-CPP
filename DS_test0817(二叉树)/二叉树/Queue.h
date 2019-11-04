#ifndef _DEQUEUE_H_
#define _DEQUEUE_H_
#include"BTree.h"

typedef BTNode*  DataType;

typedef struct Queue
{ 
	DataType _data;
	struct Queue* _next;
}Queue;

typedef struct Dequeue
{
	Queue* _head; // ∂”Õ∑   
	Queue* _tail;  // ∂”Œ≤
}Dequeue;


void dequeueInit(Dequeue * qu);
void dequeueDestory(Dequeue * qu);
Queue* dequeueBuyNode(DataType x);
void dequeuePush(Dequeue * qu, DataType x);
void dequeuePop(Dequeue * qu);
int dequeueIsEmpty(Dequeue * qu);
int dequeueSize(Dequeue * qu);
void dequeueTest();
#endif _DEQUEUE_H_
