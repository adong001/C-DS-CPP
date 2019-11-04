#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>


//1.理解数组指针
//2.理解函数指针和定义
//3.理解函数指针数组和定义，转移表
//4.理解指向函数指针数组的指针和定义
//5.理解回调函数的使用
//6.完成课堂代码和练习。
//7.练习使用qsort函数排序各种类型的数据。
//8.模仿qsort的功能实现一个通用的冒泡排序。
#include <stdio.h> 

//qosrt函数的使用者得实现一个比较函数 int int_cmp(const void * p1, const void * p2) {    return (*( int *)p1 > *(int *) p2); } 
int int_cmp(const void * p1, const void * p2) 
{
	return (*(int *)p1 > *(int *)p2); 
}
int main()
{ 
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };   
	int i = 0;        
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);  
	for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++)    
	{ 
		printf("%d ", arr[i]);
	}  
	printf("\n");    
	return 0; }

int main1()
{
    system("pause");
    return 0;
}