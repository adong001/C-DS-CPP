#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include"Tool.h"
/*
排序方法		平均情况		最好情况		最坏情况	辅助空间		稳定性

冒泡			O(n^2)			O(n)			O(n^2)		O(1)			稳定
选择			O(n^2)			O(n^2)			O(n^2)		O(1)			稳定
插入			O(n^2)			O(n)			O(n^2)		O(1)			稳定
希尔			O(nlogn)-O(n^2)	O(n^1.3)		O(n^2)		O(1)			不稳定
堆				O(nlogn)		O(nlogn)		O(nlogn)	O(1)			不稳定
归并			O(nlogn)		O(nlogn)		O(nlogn)	O(n)			稳定
快速			O(nlogn)		O(nlogn)		O(n^2)		O(logn)-O(n)	不稳定

*/
//以下所有排序函数格式为 
//template<class T>
//void Sort(vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
//默认比较规则为从小到大排序(Less)，从大到小修改第三个参数为Greater即可

//1.冒泡排序
//算法思想：(1)从第0个元素开始，和后面的n-1个元素比较，遇见比他小的，就交换，
//			(2)再从第1个元素开始比较后面n-2个....直到找完到n-1为止
template<class T>
void Bubble_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (!cmp(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}


//2.插入排序
//算法思想：(1)从第1个元素开始，从后向前找，找到前面第一个比他大的元素就向后挪，	
//			(2)直到找到比它小的元素或找到边界为止....依次找到第n个
template<class T>
void Insert_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		//tmp记录当前位置的值
		tmp = arr[i];

		//从前面的i-1找起，找到比他大的就把大的向后挪
		for (j = i; j > 0 && cmp(tmp, arr[j - 1]); j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;

	}
}

//3.选择排序
//算法思想：(1)每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，
//			(2)直到全部待排序的 数据元素排完
template<class T>
void Choice_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	int i, j, peak;
	for (i = 1; i < n; i++)
	{
		//peak记录（i,n-1]中极值(极大值或极小值)
		peak = arr[i];
		//peak < arr[j - 1](从小到大)时，继续找出前面的比peak小的值，插在他后面，没找到时前面的覆盖后面的
		for (j = i; j > 0 && cmp(peak,arr[j - 1]); j--)
		{
			arr[j] = arr[j - 1];
		}
		//arr[j-1]是最终找到的极值，插在他的后面，arr[i]就被这轮peak的值覆盖
		arr[j] = peak;
	}
}


//4.希尔排序
//算法思想：(1)利用插入排序数据越小，顺序性越高的特点，将所有数据分成grap组(grap初始化=n/2)
//			(2)每组数据坐标距离为grap,grap为趟数，每组成员执行一次插入排序,每趟grap/=2,直至grap=0
template<class T>
void Shell_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	int i, j, peak;
	//grap--趟数，执行log2(n)趟，
	//每趟共grap组，每组相邻数据距离为grap，每组n/grap个元素
	for (int grap = n / 2; grap > 0; grap /= 2)
	{
		//每趟将各个组执行插入排序即可
		//这层是组循环，共grap组
		for (i = 0; i < grap; i++)
		{
			//这里循环是插入排序
			for (i = 1; i < n; i++)
			{
				//peak记录（i,n-1]中极值(极大值或极小值)
				peak = arr[i];
				//peak < arr[j - 1](从小到大)时，继续找出前面的比peak小的值，插在他后面，没找到时前面的覆盖后面的
				for (j = i; j > 0 && cmp(peak, arr[j - 1]); j--)
				{
					arr[j] = arr[j - 1];
				}
				//arr[j-1]是最终找到的极值，插在他的后面，arr[i]就被这轮peak的值覆盖
				arr[j] = peak;
			}
		}
	}
}


//5.归并排序
//算法思想：(1)是建立在归并操作上的一种有效的排序算法,该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
//			(2)将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有 序，再使子序列段间有序。
//			(3)若将两个有序表合并成一个有序表，称为二路归并。

template<class T>
void Deal_Merge_Sort(std::vector<T>& arr, T* tmp,int start,int end, bool(*cmp)(T, T))
{
	//分解带一个元素时不再分解
	if (start >= end)
	{
		return;
	}
	//1.分解

	int mid = (start + end) / 2;
	//递归处理[start,mid]区间数据
	Deal_Merge_Sort(arr, tmp, start, mid, cmp);
	//递归处理[mid + 1,end]区间数据
	Deal_Merge_Sort(arr, tmp, mid + 1, end, cmp);

	//2.合并
	//合并两个有序数组，下标为[OrderArr1,OrderArr2)和[OrderArr2,end]
	//到新数组tmp中，下标为[NewArr,end]
	int OrderArr1 = start;
	int OrderArr2 = mid + 1;
	int NewArr = start;

	//开始合并，
	while (OrderArr1 <= mid && OrderArr2 <= end)
	{
		//假入cmp是从小到大排序，就将小的赋值给tmp
		if (cmp(arr[OrderArr1], arr[OrderArr2]))
		{
			tmp[NewArr] = arr[OrderArr1];
			OrderArr1++;
		}
		else
		{
			tmp[NewArr] = arr[OrderArr2];
			OrderArr2++;	
		}
		NewArr++;
	}
	//合并过程中，可能会由于某一个数组访问越界导致循环终止，
	//此时就要将没有越界的数组后面未访问的数据加入到tmp中

	//假如arr[Orderarr1,mid]没有越界，就将它剩下的左右数据直接拷贝过来(本来就是有序的，不需要排)
	for (; OrderArr1 <= mid; OrderArr1++, NewArr++)
	{
		tmp[NewArr] = arr[OrderArr1];
	}

	//假如arr[Orderarr2,end]没有越界，就将它剩下的左右数据直接拷贝过来(本来就是有序的，不需要排)
	for (; OrderArr2 <= end; OrderArr2++, NewArr++)
	{
		tmp[NewArr] = arr[OrderArr2];
	}

	//最后tmp就是一个排好序的数组，将他拷贝到arr中
	for (int i = start; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}

template<class T>
void Merge_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	//开一个辅助空间
	////std::tr1::shared_ptr<T> tmp(new T(200));
	T* tmp = (T*)malloc(sizeof(T)*n);
	Deal_Merge_Sort(arr, tmp, 0, n - 1,cmp);
	free(tmp);
}


//5.快速排序
//算法思想	:任取待排序元素序列中 的某元素作为基准值，按照该排序码将待排序集合分割成两子序列，
//			左子序列中所有元素均小于基准值，右子序列中所有元素均大于基准值，
//			然后最左右子序列重复该过程，直到所有元素都排列在相应位置上为止
template<class T>
void GetPivot(std::vector<T>& arr, int start, int end)//获取基准值位置
{
	srand((unsigned)time(NULL));
	//随机获取一个start - end中间的值，放在第一个元素的位置
	int pivot = rand() % (end - start + 1) + start;
	swap(arr[start], arr[pivot]);
}


template<class T>
void Recursion_Quick_Sort(std::vector<T>& arr, int start, int end, bool(*cmp)(T, T))
{
	if (start >= end)
	{
		return;
	}
	int left = start, right = end;
	//获取基准值
	GetPivot(arr, start, end);
	int pivot = arr[start];
	//start向后走一个，基准值是start
	start++;
	while (start < end)
	{
		//从右向左找比基准值小的
		for (; start < end && cmp(pivot, arr[end]); end--);

		//从右向左找比基准值大的
		for (; start < end && cmp(arr[start], pivot); start++);

		//两边都找到后未相遇就交换
		if (start < end)
		{
			swap(arr[start], arr[end]);
		}
	}
	//此时,循环退出的条件只能是start==end,且一定是从右向左时越界，所以arr[left]< arr[pivot],交换pivot和left位置
	swap(arr[left], arr[end]);

	//在递归排一次左右两边
	Recursion_Quick_Sort(arr, left,end - 1, cmp);
	Recursion_Quick_Sort(arr, end + 1, right, cmp);
}

template<class T>
void Quick_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	Recursion_Quick_Sort(arr, 0, n - 1, cmp);//递归版
	//NonRecursion_Quick_Sort(arr, 0, n - 1, cmp);//非递归
}