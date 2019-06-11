#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//1. 打印100~200之间的素数
int main()
{
	int i, j;
	for (i = 100; i <= 200; ++i)
	{
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}
//2. 输出乘法口诀表
//int main()
//{
//	for (int i = 1; i <= 9; ++i)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			printf("%d*%d=%2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//
////3. 判断1000年-- - 2000年之间的闰年
//
//int main()
//{
//	int year;
//	for (year = 1000; year <= 2000; ++year)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//		}
//	}
//	system("pause");
//	return 0;
//}

//1. 给定两个整形变量的值，将两个值的内容进行交换。

//void swap1(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
////int *tmp=x;  注意这个方法交换不了实参的内容，
//// x=y;        只是交换了形参x和y的指向
//// y=tmp;      对其中的值没有改变
//}
//void swap2(int &x, int &y)//形参引用实参，形参就是实参的别名
//{                         //实质是一样的，只在cpp文件中生效
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int x = 10;
//	int y = 20;
//	swap1(&x, &y);//给指针传的是实参的地址
//	printf("x=%d ,y=%d ", x, y);
//	swap2(x, y); //引用就直接赋实参的值
//	printf("\nx=%d ,y=%d ", x, y);
//	system("pause");
//	return 0;
//}
//2. 不允许创建临时变量，交换两个数的内容（附加题）
//int main()
//{  //思路：任何数异或自己为0
//	int x = 10;
//	int y = 20;
//	x = x^y;
//	y = x^y; //得到x的值；
//	x = x^y; //得到y的值；
//	printf("x=%d y=%d\n", x, y);
//	system("pause");
//	return 0;
//}
////3.求10 个整数中最大值。
//int Max(int ar[], int n)
//{
//	int max = ar[0];
//	for (int i=1; i < n; ++i)
//	{
//		max = max>ar[i] ? max : ar[i];
//	}
//	return max;
//}
//int main()
//{
//	int ar[] = { 10, 2, 3, 17, 4, 2, 8, 4, 1, 6 };
//	int n = SIZEOF(ar);
//	printf("max=%d\n", Max(ar, n));
//	system("pause");
//	return 0;
//}
////4.将三个数按从大到小输出。
//void swap(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 30;
//	int c = 20;
//	if (a < b)
//	{
//	  swap(&a, &b);
//	}
//	if (a < c)
//	{
//		swap(&a, &c);
//	}
//	if (b < c)
//	{
//		swap(&b, &c);
//	}
//	printf("%d %d %d\n", a, b, c);
//	system("pause");
//	return 0;
}
////5.求两个数的最大公约数。
//int main()
//{
//	while (1)
//	{
//		int x, y;
//		int max,min;
//		int tmp;
//		scanf("%d%d", &x, &y);
//		max = x > y ? x : y;
//		min = x < y ? x : y;
//		while (min)
//		{
//			tmp = min;
//			min = max%min;
//			max = tmp;
//		}
//		printf("最大公约数=%d\n",tmp);
//	}
//	system("pause");
//	return 0;
//}
////6.求两个数的最小公倍数。
//int main()
//{
//	while (1)
//	{
//		int x, y;
//		int max, min;
//		int tmp;
//		scanf("%d%d", &x, &y);
//		max = x > y ? x : y;
//		min = x < y ? x : y;
//		while (min)
//		{
//			tmp = min;
//			min = max%min;
//			max = tmp;
//		}
//		tmp *= (x / tmp)*(y / tmp);
//		printf("最小公倍数=%d\n", tmp);
//	}
//	system("pause");
//	return 0;
//}