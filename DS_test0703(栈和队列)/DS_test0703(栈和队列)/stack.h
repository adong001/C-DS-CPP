#ifdef _STACK_H_
#define _STACK_H_
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N 10 

typedef int STDataType; 
typedef struct Stack {
	STDataType _a[N];    
	int _top; // 栈顶 
}Stack;// 支持动态增长的栈

typedef int STDataType; 

typedef struct Stack 
	{   
	STDataType* _a;   
	int _top;       // 栈顶   
	int _capacity;  // 容量 
    }Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x); 
void StackPop(Stack* ps); 
STDataType StackTop(Stack* ps); 
int StackEmpty(Stack* ps); 
int StackSize(Stack* ps);
void TestStack();


#endif _STACK_H_
