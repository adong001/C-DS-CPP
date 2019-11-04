#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

void Print(int *src, int n)
{
	for (int i = 0; i<n; i++)
	{
		printf("%d ", src[i]);
	}
	putchar('\n');
}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

AdjustDown(int* data,int size, int n)//向下调整算法（只调整根节点）
{
	int tmp;
	while (n * 2 + 1 < size)//判断是否是非叶子结点，左孩子不越界
	{
		if (n * 2 + 2 >= size)//右孩子不存在
		{
			tmp = n * 2 + 1;//记录左孩子坐标
		}
		else
		{
			if (data[n * 2 + 1] > data[n * 2 + 2])//左右孩子都存在
			{
				tmp = n * 2 + 1;//左大于右，记录左坐标
			}
			else
			{
				tmp = n * 2 + 2;//右大于左，记录右坐标
			}
		}
		if (data[n] < data[tmp])//根节点与记录坐标相比，根<tmp,交换，否则break
		{
			Swap(&data[n], &data[tmp]);
			n = tmp;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(int *data,int size)//删除堆顶元素,保证产生新堆
{
	if (data == NULL)
	{
		return;
	}
	Swap(&data[0], &data[size - 1]);//堆首尾元素交换
	size--;//长度--，保护堆尾已排好的最大元素
	AdjustDown(data,size, 0);//从头结点执行向下整算法，使得又成为一个新堆
}


void HeapSort(int *src, int n)
{
	assert(src);
	for (int i = (n - 1) / 2; i > 0; i--)
	{
		AdjustDown(src, n, i);//从最后一个非叶子结点到堆首执行向下调整算法，形成新堆
	}
	for (int i = n; i > 1; i--)
	{
		HeapPop(src, i);//长度--，保护堆尾已排好的最大元素，执行n-1次直至排好
	}
}


int main()
{
	int src[] = { 10, 9, 3, 4, 6, 7, 2, 8, 1, 5 };
	int n = sizeof(src) / sizeof(src[0]);
	//SelectionSort(src, n);
	HeapSort(src, n);
	Print(src, n);
	return 0;
}
//HeapType* HeapTop(  hp)//判断堆是否为空，为空返回0，否则返回第一个元素
//{
//	assert(hp);
//	if (data == NULL)
//	{
//		return (HeapType)0;
//	}
//	return data;
//
//}
//
//void HeapInit(  hp, HeapType* a, int n)//初始化堆
//{
//	assert(hp);
//	hp->capacity = n * 2;
//	size = n;
//	data = (HeapType*)malloc(sizeof(HeapType)*hp->capacity);
//	for (int i = 0; i < n; i++)
//	{
//		data[i] = a[i];
//	}
//	for (int i = (n - 1) / 2; i>0; i--)//从最后一个非叶子结点开始执行向下调整算法
//	{
//		AdjustDown(hp, i);
//	}
//}
//
//void SelectionSort(int *src, int n)
//{
//	int i, j;
//	int min;
//	for (i = 0; i < n - 1; i++)//外层循环只循环n-1次，前n-1个元素排好整个数组就完成了
//	{
//		min = i;//min记录即将要排序的元素坐标
//		for (j = i + 1; j < n; j++)//内从循环坐标为i+1个元素开始直至最后一个元素
//		{
//			if (src[min] > src[j])//从未排序元素中查找最小的元素用min记录他的坐标
//			{
//				min = j;
//			}
//		}
//		if (src[i] > src[min])
//		{
//			Swap(&src[i], &src[min]);//找到未排序元素中的最小值与它交换
//		}
//	}
//}
//
//void ShellSort(int *src, int n)
//{
//	int gap;//组的间距
//	int k;//组内成员的个数
//	int i, j;
//	for (gap = n / 2; gap > 0; gap /= 2)
//	{
//		for (k = 0; k < gap; k++)
//		{
//			for (i = gap + k; i< n; i += gap)//每组成员之间的间距为gap
//			{
//				int tmp = src[i];
//				for (j = i; j >= gap && src[j - gap] > tmp; j -= gap)
//				{
//					src[j] = src[j - gap];
//				}
//				src[j] = tmp;
//			}
//		}
//	}
//}