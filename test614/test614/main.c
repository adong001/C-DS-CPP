#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fpr,*fp;
	char ar[10];
	printf("\n");
	fpr = fopen("C:\\Users\\杨冬\\Desktop\\t1.txt", "r");//"\\"第一个'\'为转意符.
	fp = fpr;
	fgets(ar, 5, fpr);
	fputs(ar, fp);
	fclose(fp);
	fp = NULL;
    system("pause");
    return 0;
}