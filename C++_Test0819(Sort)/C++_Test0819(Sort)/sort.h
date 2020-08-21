#pragma once
#include<iostream>
#include<vector>
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
	int i, j,tmp;
	for (i = 1; i < n; i++)
	{
		//tmp记录当前位置的值
		tmp = arr[i];

		//从前面的i-1找起，找到比他大的就把大的向后挪
		for (j = i; j > 0 && cmp(tmp, arr[j-1]); j--)
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
	for (i = 0; i < n - 1; i++)//外层只找n-1个就结束了
	{
		//peak记录（i,n-1]中极值(极大值或极小值)的下标
		peak = i;

		//找出（i,n-1]中的极值
		for (j = i + 1; j < n; j++)
		{
			//arr[j] < arr[peak] 跟新peak的值为j
			if (cmp(arr[j], arr[peak]))
			{
				peak = j;
			}
		}
		//如果找到的极值小于(大于)arr[i]就交换
		if (cmp(arr[peak], arr[i]))
		{
			swap(arr[peak], arr[i]);
		}
	}
}


//4.希尔排序
//算法思想：(1)每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，
//			(2)直到全部待排序的 数据元素排完
template<class T>
void Choice_Sort(std::vector<T>& arr, size_t n, bool(*cmp)(T, T) = Less)
{
	std::cout << __FUNCTION__ << std::endl;
	int i, j, peak;
	for (i = 0; i < n - 1; i++)//外层只找n-1个就结束了
	{
		//peak记录（i,n-1]中极值(极大值或极小值)的下标
		peak = i;

		//找出（i,n-1]中的极值
		for (j = i + 1; j < n; j++)
		{
			//arr[j] < arr[peak] 跟新peak的值为j
			if (cmp(arr[j], arr[peak]))
			{
				peak = j;
			}
		}
		//如果找到的极值小于(大于)arr[i]就交换
		if (cmp(arr[peak], arr[i]))
		{
			swap(arr[peak], arr[i]);
		}
	}
}