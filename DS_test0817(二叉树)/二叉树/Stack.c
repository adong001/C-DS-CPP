#include"stack.h"

void StackInit(Stack* st,size_t capacity)
{
	assert(st != NULL);
	st->_size = 0;
	st->_capacity = capacity;
	st->_data = (STDataType*)malloc(sizeof(STDataType));
	//assert(st->_data != NULL);
}
void StackDestory(Stack* st)
{
	assert(st!= NULL);
	if (st->_data != NULL)
	{
	st->_capacity = 0;
    st->_size = 0; 
	// memset(st->_data, 0, st->_size * sizeof(STDataType));
	 free(st->_data);
	 st->_data = NULL;
	}	
}


void StackPush(Stack* st, STDataType x)
{
	assert(st != NULL);
	if (st->_size == st->_capacity)
	{
		st->_capacity *= 2;
		st->_data = (STDataType *)realloc(st->_data, st->_capacity * sizeof(STDataType));
	}
	st->_size++;
	st->_data = (STDataType *)realloc(st->_data, st->_size * sizeof(STDataType));
	st->_data[st->_size - 1] = x;
}

void StackPop(Stack* st)
{
	assert(st != NULL);
	st->_size--;
}

STDataType StackTop(Stack* st)
{
	if (StackIsEmpty(st) == 0)
	{
		return (STDataType)0;
	}
	return st->_data[st->_size - 1];
}

int StackIsEmpty(Stack* st)
{
	return !(st->_capacity == 0);
}
int StackSize(Stack* st)
{
	return st->_size ;
}

void StackTest()
{
	Stack st;
	int capacity = 3;
	StackInit(&st,capacity);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	printf("%d\n", StackTop(&st));
	StackPop(&st);
	printf("%d\n", StackTop(&st));
	StackPop(&st);
	printf("%d\n", StackTop(&st));
	StackPop(&st);
	printf("%d\n", StackTop(&st));
	StackPop(&st);
	
	StackDestory(&st);
}