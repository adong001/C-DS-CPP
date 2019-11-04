#define _CRT_SECURE_NO_WARNINGS 1
#define BUFSIZE 10000
#include<time.h>
#include"Sort.h"



int main()
{
#if 0
	int ar[] = { 1, 5, 9, 4, 2, 8, 6, 10, 3, 7 };
	InsertSort(ar,sizeof(ar)/sizeof(ar[0]));
	Print(ar, sizeof(ar) / sizeof(ar[0]));
#else 
	srand(time(NULL));
	int ar[BUFSIZE];
	int i;
	for (i = 0; i < BUFSIZE; i++)
	{
		ar[i] = rand() % 5000 + 1;
	}
	//InsertSort(ar, sizeof(ar) / sizeof(ar[0]));
	//ShellSort(ar, sizeof(ar) / sizeof(ar[0
	MergeSort(ar, sizeof(ar) / sizeof(ar[0]));
	Print(ar, sizeof(ar) / sizeof(ar[0]));
#endif
	system("pause");
    return 0;
}
