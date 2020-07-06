#include"Sort.h"

void Print(int *ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
	}
	putchar('\n');
}

void InsertSort(int *ar, int n)//插入排序
{ 
	//时间复杂度 :O(n^2)
	//优点: 1.数组规模越小，插排越快
	//      2.数组越有序，插排越快
	int tmp;
	int i, j;
	for (i = 1; i < n; i++)
	{
		tmp = ar[i];
		for (j = i; j > 0 && ar[j - 1]>tmp; j--)
		{
			ar[j] = ar[j - 1];
		}
		ar[j] = tmp;
	}
}

void ShellSort(int *ar, int n)//希尔排序(最小增量法)
{ 
	//多重插入排序，对多重插入排序的优化(数组规模越小，越有序)
	int i, j, k;
	int grap, tmp; 
	for (grap = n / 2; grap > 0; grap /= 2)//次数
	{      
		for (k = 0; k<grap; k++)//分组
		{
			for (i = grap + k; i < n; i += grap)
			{
				tmp = ar[i];
				for (j = i; j >= grap && ar[j - grap]>tmp; j -= grap)
				{
					ar[j] = ar[j - grap];
				}
				ar[j] = tmp;
			}
		}
	}
}

//void SelectioSort(int *ar, int n)
//{
//
//}

void MergeSort(int *ar, int n)//归并排序
{//需要借助一个辅助空间
	int *tmp = (int *)malloc(n*sizeof(int));
	mergesort(ar, tmp, 0, n - 1);
	free(tmp);
}
void mergesort(int *arr, int *tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	mergesort(arr, tmp, start, mid);
	mergesort(arr, tmp, mid + 1,end);
	int a = start;
	int b = mid + 1;
	int c = start;
	while (a<mid && b<=end)
	{

		if (arr[a] < arr[b])
		{
			tmp[c] = arr[a];
			a++;
		}
		else
		{
			tmp[c] = arr[b];
			b++;
		}
		c++;
	}
	for (; a <= mid; a++)
	{
		tmp[c] = arr[a];
		c++;
	}
	for (; b <= end; b++)
	{
		tmp[c] = arr[b];
		c++;
	}

	for (int i = start; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}、


int left = start,right = end;
//		GetPivot(arr,start, end);//让start成为基准元素
//		int pivot = arr[start];
//
//		while (start < end)
//		{
//			for (; start < end && cmp(pivot,arr[end] , true) ; end--);//从右往左比基准值小的
//			
//			for (; start < end && cmp(arr[start],pivot, true) ; start++);//从左往右比基准值大的
//
//			if (start < end)//若未相遇就交换
//			{
//				Swap(arr[start], arr[end]);
//			}
//		}
//		Swap(arr[left], arr[end]);//中间是基准值，左边比基准值小，右边比基准值大，
//		return end;