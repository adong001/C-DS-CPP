#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
//void bibble_sort(int arr[], int n)
//{
//	int tmp = 0;
//	//int flag = 1;
//	for (int i = 0; i < n-1; i++)
//	{
//		for (int j = 0; j <= n-i-1; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//			/*	flag = 0;*/
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//		//if (flag == 1)
//		//{
//		//	break;
//		//}
//	}
//}

//void  print(int arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//
//	int ar[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	print(ar, 10);
//	bibble_sort(ar, 10);
//	print(ar, 10);
//	system("pause");
//	return 0;
//}

//
//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
//
//
//void mult_print(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%3d  ", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入要打印的乘法表行数：");
//	scanf("%d", &n);
//	mult_print(n);
//	system("pause");
//	return 0;
//}
//
//
//
//2.使用函数实现两个数的交换。
//
//void Swap(int *px, int *py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//int main()
//{
//	int x = 10;
//	int y = 20;
//	printf("x=%d y=%d\n", x, y);
//	Swap(&x, &y);
//	printf("x=%d y=%d\n", x, y);
//	system("pause");
//	return 0;
//}
//
//3.实现一个函数判断year是不是润年。
//
//int Is_prime(int year)
//{
//	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
//}
//
//int main()
//{
//	int year = 0;
//	while (1)
//	{
//	 printf("请输入要判断的年份：");
//	 scanf("%d", &year);
//	 if (Is_prime(year) == 1)
//	 {
//		 printf("是闰年\n\n");
//	 }
//	 else
//	 {
//		 printf("不是闰年\n\n");
//	 }
//	
//	}
//	system("pause");
//	return 0;
//}
//
//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//
//
//void init(int ar[],int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		ar[i] = 0;
//	}
//}
//
//void empty(int ar[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		ar[i] = 0;
//	}
//}
//void reverse(int ar[], int n)
//{
//	for (int i = 0; i <= n / 2; i++)
//	{
//		int tmp = 0;
//		tmp = ar[i];
//		ar[i] = ar[n - i - 1];
//		ar[n - i - 1] = tmp;
//	}
//}
//
//void print(int ar[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", ar[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int ar[10]= { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	print(ar, n);
//	reverse(ar, n);
//	print(ar, n);
//	empty(ar, n);
//	print(ar, n);
//	system("pause");
//	return 0;
//}
//
//
//5.实现一个函数，判断一个数是不是素数。
//
//int Is_prime(int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		printf("请输入想要判断的数：");
//		scanf("%d", &n);
//		if (Is_prime(n) == 1)
//		{
//			printf("是素数\n\n");
//		}
//		else
//		{
//			printf("不是素数\n\n");
//		}
//
//	}
//	system("pause");
//	return 0;
//}



//1.递归和非递归分别实现求第n个斐波那契数。

//int fib(int n)             //递归，从后往前计算，每次计算都要把前面的数算出来
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//	  return fib(n - 1) + fib(n - 2);
//	}
//}

//int fib(int n)               //非递归，从前往后算，在此题中比递归快
//{
//	int ret = 0;
//	int num1 = 1;
//	int num2 = 2;
//	if (n <= 2)
//	{
//		return num1;
//	}
//	else
//	{
//		while (n > 2)
//		{
//			ret = num1 + num2;
//			num1 = num2;
//			num2 = ret;
//			n--;
//		}
//		return ret;
//	}
//}
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		printf("%d\n\n",fib(n));
//	}
//	system("pause");
//	return 0;
//}
//
//2.编写一个函数实现n^k，使用递归实现
//

//int fuc(int n,int k)
//{
//	if (k < -1)
//	{
//		return (1 / (fuc(n, -k)));
//	}
//	else if (k == 0)
//	{
//		return 1;
//	}
//	else if (k == 1)
//	{
//		return n;
//	}
//	else
//	{
//		
//			return  n*fuc(n, k - 1);
//		
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	while (1)
//	{
//		scanf("%d%d", &n, &k);
//		printf("sum=%d", fuc(n, k));
//	}
//	system("pause");
//	return 0;
//}

//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//
//int DigitSum(unsigned int n)
//{
//	if (n > 9)
//	{
//		return ((n % 10) + DigitSum(n / 10));
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		printf("请输入:");
//		scanf("%d", &n);
//		printf("Sum=%d\n\n",DigitSum(n));
//		system("pause");
//		return 0;
//	}
//}

//4. 编写一个函数 reverse_string(char * string)（递归实现）   **********
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。


//void reverse_string(char * string)  //递归
//{
//
//	if (*(++string)!= '\0')
//	{
//		reverse_string(string);
//	}
//	printf("%c",*(string-1));
//}
//char * reverse_string(char * string)   //非递归
//{
//	char * ptr = string;
//	char str = NULL;
//	int count = 0;
//	while ((*ptr++)!='\0')
//	{
//		count++;
//	}
//	for (int i = 0; i <= count / 2; i++)
//	{
//		str = string[i];
//		string[i] = string[count - i - 1];
//		string[count - i - 1] = str;
//	}
//	return string;
//}

//int main()
//{
//	char string[] = "abcdef";
//    reverse_string(string);
//	system("pause");
//	return 0;
//}


//5.递归和非递归分别实现strlen

//int my_strlen(char * string)          //递归
//{
//	while (*string != '\0')
//	{
//		return (1 + my_strlen(string + 1));
//	}
//	return 0;
//}

//int my_strlen(char * string)             //非递归
//{
//	int count = 0;
//	while (*string++!= '\0')
//	{
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char * str = "abcdef";
//	printf("%d\n", my_strlen(str));
//	system("pause");
//	return 0;
//}


//6.递归和非递归分别实现求n的阶乘

 
//int fuc (int n)                      递归
//{
//	if (n == 0)
//	{
//		return 1;
//	}
//	else if (n < 0)
//	{
//	  return n*fuc(n + 1);
//	}
//	else
//	{
//	return n*fuc(n - 1);
//	}
//}
 
//int fuc(int n)           // 非递归
//{
//	int sum = 1;
//	if (n == 0)
//	{
//		return 1;
//	}
//	else if (n < 0)
//	{
//		while ( n < 0)
//		{
//			sum *= n;
//			n++;
//		}
//		return sum;
//		}
//	else
//	{
//	while (n>0)
//	   {
//		sum *= n;
//		n--;
//		}
//		return sum;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		printf("sum=%d\n", fuc(n));
//	}
//}

//7.递归方式实现打印一个整数的每一位

//int  fuc_print(int n)
//{
//	while (n > 9)
//	{
//	 printf("%d ",fuc_print(n / 10));
//	 return n % 10;
//    }   
//	return n;
//}
//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		printf("%d\n", fuc_print(n));
//	}
//	system("pause");
//	return 0;
//}