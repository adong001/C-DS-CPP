#ifndef _SORT_H_
#define _SOTR_H_
#include<stdio.h>
#include<stdlib.h>

void Print(int *ar, int n);

void InsertSort(int *ar, int n);//²åÈëÅÅĞò

void ShellSort(int *ar, int n);//Ï£¶ûÅÅĞò(×îĞ¡ÔöÁ¿·¨)

void SelectioSort(int *ar, int n);//Ñ¡ÔñÅÅĞò

void BubbleSort(int *ar, int n);//Ã°ÅİÅÅĞò

void HeapSort(int *ar, int n);//¶ÑÅÅĞò

void QuickSort(int *ar, int n);//¿ìÅÅ

void MergeSort(int *ar,int n);//¹é²¢ÅÅĞò

void mergesort(int *arr, int *tmp, int start, int end);
#endif 