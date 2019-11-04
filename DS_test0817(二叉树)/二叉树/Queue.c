#include"Queue.h"

void dequeueInit(Dequeue * qu)
{
	assert(qu != NULL);
	qu->_head = qu->_tail = NULL;
}

void dequeueDestory(Dequeue * qu)
{
	Queue *cur;
	while (qu->_head != NULL)
	{
		cur = qu->_head;
		qu->_head = qu->_head->_next;
		free(cur);
	}
}

void dequeuePush(Dequeue * qu, DataType x)
{
	assert(qu != NULL);
	Queue *cur = (Queue*)malloc(sizeof(Queue));
	cur->_data = x;
	cur->_next = NULL;

	if (dequeueIsEmpty(qu) == 0)
	{
		qu->_head = qu->_tail = cur;
		return;
	}
	qu->_tail->_next = cur;
	qu->_tail = cur;
}

void dequeuePop(Dequeue * qu)
{
	assert(qu != NULL);
	Queue *cur = qu->_head;
	if (dequeueIsEmpty(qu) == 0)
	{
		return ;
	}
	qu->_head=qu->_head->_next;
	free(cur);
}



int dequeueIsEmpty(Dequeue * qu)
{
	return !(qu->_head == NULL);
}

int dequeueSize(Dequeue * qu)
{
	return (qu->_tail - qu->_head)/sizeof(Queue)+1;
}

DataType dequeueTop(Dequeue *qu)
{
	if (dequeueIsEmpty(qu) == 0)
	{
		return (DataType)0;
	}
	return qu->_head->_data;
}

void dequeueTest()
{
	Dequeue qu;
	dequeueInit(&qu);
	dequeuePush(&qu, 1);
	dequeuePush(&qu, 2);
	dequeuePush(&qu, 3);
	dequeuePush(&qu, 4);
	dequeuePush(&qu, 5);
	printf("%d\n", dequeueSize(&qu));
	printf("%d\n", dequeueTop(&qu));
	dequeuePop(&qu);
	printf("%d\n", dequeueTop(&qu));
	dequeuePop(&qu);
	printf("%d\n", dequeueTop(&qu));
	dequeuePop(&qu);
	printf("%d\n", dequeueTop(&qu));
	dequeuePop(&qu);
	printf("%d\n", dequeueTop(&qu));
	dequeuePop(&qu);
	dequeueDestory(&qu);
}