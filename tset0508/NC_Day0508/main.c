#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int size = 0;
//	int num = 6;
//	int temp = 0;
//	int sum = 0;
//	int weight[20] = { 0 };
//	scanf("%d%d",&num, &size);
//	for (int i = 0; i<num; i++)
//	{
//		scanf("%d", &weight+i);
//	}
//	for (int i = 0; i < num-1; i++)
//	{
//		for (int j = 0; j < num- 1- i; j++)
//		{
//			if (weight[j] > weight[j+1])
//			{
//			    temp=weight[j];
//				weight[j] = weight[j+1];
//				weight[j+1] = temp;
//			}
//		}
//	}
//	int i;
//	for ( i = 0;sum + weight[i] < size && i<num; i++)
//	{
//		sum += weight[i];
//	}
//	printf("%d\n", i-1);
//	system("pause");
//	return 0;

//int main()
//{
//    int size = 0;
//	int num = 6;
//	int temp = 0;
//	int count = 0;
//    int weight[20] = { 0 };
//		scanf("%d%d",&num, &size);
//		for (int i = 0; i<num; i++)
//		{
//			scanf("%d", &weight[i]);
//		}
//		for (int i = 0; i < num-1; i++)
//		{
//			for (int j = 0; j < num- 1- i; j++)
//			{
//				if (weight[j] > weight[j+1])
//				{
//				    temp=weight[j];
//					weight[j] = weight[j+1];
//					weight[j+1] = temp;
//				}
//			}
//		}
//		for (int i = 0, j = num - 1; i <= j; j--)
//		{
//			if (weight[i] + weight[j] <= size)
//			{
//				i++;
//			}
//			count++;
//		}
//		printf("%d\n", count);
//	system("pause");
//	return 0;
//}

int main()
{
	int i = 0;
	int size = 0;
	int num = 6;
	int temp = 0;
	int count = 0;
	int weight[20] = { 0 };
	scanf("%d%d", &num, &size);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (weight[j] > weight[j + 1])
			{
				temp = weight[j];
				weight[j] = weight[j + 1];
				weight[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n - 1; i++)
	{
		sort(num + i, n - i);

		num[i + 1] = num[i] + num[i + 1];
		sum += num[i + 1];
	}
	printf("%d")
		system("pause");
	return 0;
}p    