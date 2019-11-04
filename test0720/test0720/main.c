#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#define INT_PTR int*
typedef int* int_ptr;
INT_PTR a, b;
int_ptr c, d;

//有1000瓶毒药，
//只有一瓶有毒，小白鼠吃了一星期就会死掉，
//请问，在一星期内找出有毒的药瓶，至少需要多少只老鼠

//int 
//
//int FindPoison(int *DiedMouse)//DiedMouse-死亡老鼠的编号，验证函数
//{
//
//}

int FindValue(int ar[4][4], int row, int col, int value)
{
	int i = 0;
	int j = row - 1;
	while (i < row&&j >= 0)
	{
		if (ar[i][j] == value)
		{
			return 1;
		}
		else if (ar[i][j]>value)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	return 0;
}
typedef struct {
		int a;  //0
		char b; //4
		short c;//6
		short d;//8
		        //10
		        //12
	}AA_t;
typedef struct {
	char b;
	int a;
	short c;
	short d;
}BB_t;
typedef struct {
	char b;
	short c;
	int a;
	short d;
}CC_t;
typedef struct {
	
	char b;
	short c;
	short d;
	int a;
}DD_t;
struct unknown {
	int a;
	char b;
	int c;
	long d;
	char e;
};

int main()
{
	printf("%d\n", sizeof(long));
	printf("%lu\n", sizeof(struct unknown));
	printf("%d\n", sizeof(AA_t));
	printf("%d\n", sizeof(BB_t));
	printf("%d\n", sizeof(CC_t));
	printf("%d\n", sizeof(DD_t));
	/*const char * p = "hello";
	printf("%c\n", *p);*/
	/*int ar[4][4]={
	    1,2,8,9,
		2,4,9,12,
		4,7,10,13,
		6,8,11,15
	};

	printf("%d", FindValue(ar, 4, 4, 11));*/
	/*int a[]={2,4,6,8,10,12,14,16,18,20,22,24},*q[4],k;
	for (k = 0; k < 4; k++)
	{
		q[k] = &a[k * 3];
	}
	printf("%d\n", q[3][1]);*/

	//int i, j, a = 0;
	//for (i = 0; i < 2; i++)
	//{
	//	for (j = 0; j < 4; j++)
	//	{
	//		if (j % 2)
	//		{
	//			break;
	//		}
	//		a++;
	//	}
	//	a++;
	//}
	//printf("%d\n", a);


    system("pause");
    return 0;
}
