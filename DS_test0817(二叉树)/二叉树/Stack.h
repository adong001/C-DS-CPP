#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>
#include<stdlib.h>
#include"BTree.h"

typedef BTNode* STDataType;

typedef struct Stack
{
	STDataType* _data;
	int _size; //³¤¶È 
	int _capacity;  // ÈÝÁ¿ 
}Stack;

void StackInit(Stack* st,size_t capacity);
void StackDestory(Stack* st);
void StackPush(Stack* st, STDataType x);
void StackPop(Stack* st);
STDataType StackTop(Stack* st);
int StackIsEmpty(Stack* st);
int StackSize(Stack* st);
void StackTest();


#endif _STACK_H_
