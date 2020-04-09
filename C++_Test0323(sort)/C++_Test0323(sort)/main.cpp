#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
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
void Bubble_Sort(T& arr,size_t len,T Pre = NULL)//冒泡排序
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<class T>
void Select_Sort(T& arr, size_t len, T Pre = NULL)//选择排序
{
	int min;
	for (int i = 0; i < len - 1; i++)
	{
		min = i;//min记录即将要排序的元素坐标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[min] > arr[j])//选出最小的
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

int main()
{
	int arr[] = { 2, 3, 4, 1, 6, 7, 8, 10, 5 ,9};
	Select_Sort(arr, 10);
	//Bubble_Sort(arr, 10);
	Print(arr,10);
    system("pause");
    return 0;
}