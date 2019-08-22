#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct test1
//{
//	short a;
//	char b;
//	long c;
//	long d;
//};
//
//struct test2
//{
//	long a;
//	short b;
//	char c;
//	long d;
//};
//
//struct test3
//{
//	short a;
//	long c;
//	char b;
//	long d;
//	
//};
//int fun(int x)
//	{
//		int count = 0;
//		while (x)
//		{
//			count++;
//
//
//			x = x&(x - 1);
//		}
//		return count;
//	}
//unsigned long g_ul = 0;
//void globa(unsigned long ula)
//{
//	ula = 0x01;
//	return;
//}
//int f(int a)
//{
//	int b = 0;
//	static int c = 3;
//	a = c++, b++;
//	return (a);
//}

//


//int JudgeKey()
//{
//	union Un
//   {
//	  int a;
//	  char b;
//   }un;
//
//   un.a = 1;
//   return un.b;
//}
//int JudgeKey()
//{
//	int a = 1;
//	return *(char *)&a;
//}
//union x
//{
//	int x;
//	char y[4];
//}a;

//char *mystring()
//{
//	char buff[6] = { 0 };
//	char *s = "hello world";
//	for (int i = 0; i < 6; i++)
//	{
//		buff[i] = *(s + i);
//	}
//	return buff;
//}
int main()
{
	/*int i = 1;
	printf("%d %d", sizeof(i++), i);*/
	/*char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-i - 1);
	}
	printf("%d\n", strlen(a));*/
	/*printf("%s\n", mystring());
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p1 = (int *)(&a + 1);
	int *p2 = (int *)((int)a + 1);
	int *p3 = (int *)(a + 1);
	printf("%d %x %d", p1[-1], p2[0], p3[1]);*/
	/*a.x = 0x11223344;
	
	printf("%x %x %x %x\n", a.y[0], a.y[1], a.y[2], a.y[3]);*/
	/*int a=1<<3+2;
	printf("%d\n", a);*/

	//int ret = JudgeKey();
	//if (ret == 1)
	//{
	//	printf("Ð¡¶Ë´æ´¢\n");
	//}
	//else
	//{
	//	printf("´ó¶Ë´æ´¢\n");
	//}
	//char *p = "hello";
	//char ar[] = "hello";
	//printf("%d %d %d %d\n", strlen(p), strlen(ar), sizeof(p), sizeof(ar));

	/*int i = 0, j = 0;
	if ((++i > 0) || (++j > 0))
	{
		printf("%d %d", i, j);
	}*/
	/*int i;
	for (i = 1; i < x; i++)
	{
		inc();
	}*/
	/*int a = 2, i, k;
	for (i = 0; i < 2; i++)
	{
		k = f(a++);
	}
	printf("%d\n", k);*/
	/*globa(g_ul);
	printf("%lu", g_ul);*/

	//int i = 8;
	//int x = 2019;
	////printf("%d\n", fun(2019));
	//while (i)
	//{
	//	i--;
	//	x = x&(x - 1);
	//	printf("%d ", x);
	//}
	/*printf("%d %d %d\n", sizeof(struct test1), sizeof(struct test2), sizeof(struct test3) );*/
	//double **a[3][4];
	//printf("%d\n", sizeof(a));
	//char arr[2][4];
	//strcpy((char *)arr, "you");
	//strcpy(arr[1], "me");
	//arr[0][3] = '&';
	//printf("%s\n", arr);
	//int a = 10;
	//a += a *= a -= a / 3;
	//printf("%d\n",a);
	//int x;
	//x = 5 > 1 + 2 && 2 || 2 * 4 < 4 - !0;
	//printf("%d\n", x);
	system("pause");
    return 0;
}
