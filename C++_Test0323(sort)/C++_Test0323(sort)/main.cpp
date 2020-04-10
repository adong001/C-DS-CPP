#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#define SIZEOF(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

template<class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
bool Greater(T a, T b)
{
	return a > b;
}

template<class T>
bool Less(T a, T b)
{
	return a < b;
}

//template<class T>
//class Pre
//{
//	bool operator()
//	{
//
//	}
//};

template<class T>
void Print(T arr, size_t len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
void Bubble_Sort(T arr[], size_t len, bool (*cmp)(T,T) = Less)//冒泡排序
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (cmp(arr[j + 1], arr[j]))//后者小于前者
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<class T>
void Select_Sort(T arr[], size_t len, bool (*cmp)(T,T) = Less)//选择排序
{
	int min;
	for (int i = 0; i < len - 1; i++)
	{
		min = i;//min记录即将要排序的元素坐标
		for (int j = i + 1; j < len; j++)
		{
			if (cmp(arr[j], arr[min]))//选出最小的
			{
				min = j;

			}
		}
		if (arr[min] < arr[i])
		{
			Swap(arr[min], arr[i]);//与起始位置交换
		}
	}
}

template<class T>
void Insert_Sort(T arr[], size_t len, bool(*cmp)(T,T) = Less)//插入排序
{
	int i,j,tmp;
	for (i = 1; i < len; i++)
	{
		tmp = arr[i];
		for (j = i; j > 0 && cmp(arr[j], arr[j - 1]); j--)//后面小于前面就将前面覆盖到后面
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}

template<class T>
void Shell_Sort(T arr[], size_t len, bool(*cmp)(T, T) = Less)//希尔排序(根据插入排序的优点越有序排序越快的优点优化的一种方法)
{
	int i, j, k, gap, tmp;
	for (gap = len / 2; gap > 0; gap /= 2)//共进行(gap / 2 > 0)趟
	{
		for (k = 0; k < gap; k++)//每趟gap组,对每组进行插入排序
		{
			for (i = k + gap; i < len; i+=gap)//每组起始位置为k + gap,
			{
				tmp = arr[i];
				for (j = i; j >= gap && cmp(tmp, arr[j - gap]); j-=gap)//组类成员每个间隔gap
				{
					arr[j] = arr[j - gap];
				}
				arr[j] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 2, 3, 4, 1, 6, 7, 8, 10, 5, 9 ,0,111,2,3,1,3,34,3,23,2,34};
	//int arr[] = { 2, 3, 4, 1, 6, 7, 8, 10, 5, 9 };
	//Bubble_Sort(arr, SIZEOF(arr));
	//Select_Sort(arr, SIZEOF(arr));
	//Insert_Sort(arr, SIZEOF(arr));
	Shell_Sort(arr, SIZEOF(arr));
	Print(arr, SIZEOF(arr));
	system("pause");
	return 0;
}