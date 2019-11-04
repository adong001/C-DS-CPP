//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//
//void adjustdown(int* data, int size,int num)//向下调整函数(大堆)
//{
//	int cur = num;//要往下调整的下标
//	int n;//下标
//	
//	while (cur * 2 + 1 < size)//调整到最后一个非叶子节点坐标
//	{
//		if (cur * 2 + 2 >= size)//没有右孩子
//		{
//			n = cur * 2 + 1;//记录这个节点
//		}
//		else
//		{
//			if (data[cur * 2 + 1] > data[cur * 2 + 2])//左孩子>右孩子
//			{
//				n = cur * 2 + 1;//记录左孩子下标
//			}
//			else//否则记录右孩子下标
//			{
//				n = cur * 2 + 2;
//			}
//		}
//		if (data[cur]< data[n])//若此节点比记录的孩子值小，则交换两者的值
//		{
//			int tmp = data[cur];
//			data[cur] = data[n];
//			data[n] = tmp;
//			cur = n;//记录交换后的坐标，继续进行判断
//		}
//		else //
//		{
//			break;
//		}
//	}
//}
//
//void heappop(int* data,int size)//删除堆顶元素
////把最后一个叶子节点替换为堆顶，size--,再执行向下调整算法
//{
//	if (size == 0)
//	{
//		return;
//	}
//
//	int tmp = data[0];
//	data[0] = data[size - 1];
//	data[size - 1] = tmp;
//	size--;	
//	adjustdown(data, size,0);
//	
//}
//
//void heapsort( int* src, int size)//堆的初始化
//{
//	int i;
//	for (i = size/2-1; i >= 0; i--)
//	{
//		adjustdown(src,size,i);
//	}
//
//	for (; size> 1; size--)
//	{
//		heappop(src, size);
//	}
//}
//
//
//
//void printArray(int *src, int size)
//{
//	int i;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", src[i]);
//	}
//	putchar('\n');
//}
//
//
//int Find_X_Max(int *src, int size, int X)
//{
//	int i;
//	int value;
//	if (size <= 0)
//	{
//		return errno;
//	}
//	
//	for (i = size / 2 - 1; i >= 0; i--)
//	{
//		adjustdown(src, size, i);//初始化堆
//	}
//
//	while (X)
//	{
//		value = src[0];
//		heappop(src, size);
//		--size;
//		--X;
//	}
//	return value;
//
////}
////int main()
////{
////	int data[] = { 1, 20 ,8/*, , 3, 4, 5, 7 , 8,  10 ,6, 9*/ };
////	heapsort(data, 3);
////	printArray(data, 3);
////	/*for (int i = 1; i < 12;i++)
////	printf("%d\n",Find_X_Max(data, 11, i));
////	*/
////    system("pause");
////    return 0;
////}
