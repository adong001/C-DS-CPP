#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<ctime>
//#define SIZEOF(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

template<class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
bool Greater(T a, T b,bool flag = false)
{
	return flag ? a >= b : a > b;
}

template<class T>
bool Less(T a, T b, bool flag = false)
{
	return flag ? a <= b : a < b;
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
void Bubble_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)//冒泡排序
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
void Select_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)//选择排序
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
void Insert_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)//插入排序
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
void Shell_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)//希尔排序(根据插入排序的优点越有序排序越快的优点优化的一种方法)
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


template<class T>
class HeapSort
{
private:
	static void AdjustDown(vector<T>& arr, size_t len, int pos, bool(*cmp)(T, T))//向下调整算法构建堆,Less默认构建大堆，排升序
	{
		int tmp;
		while (pos * 2 + 1 < len)//判断是否为非叶子节点，是叶子点就不需要调整
		{
			if (pos * 2 + 2 >= len)//没有右孩子
			{
				tmp = pos * 2 + 1;
			}
			else//左右孩子都有
			{
				if (cmp(arr[pos * 2 + 1], arr[pos * 2 + 2]))//要构建大堆，根要大于孩子，记录大的孩子
				{
					tmp = pos * 2 + 2;
				}
				else
				{
					tmp = pos * 2 + 1;
				}
			}

			if (cmp(arr[pos], arr[tmp]))//根换成最大的
			{
				Swap(arr[pos], arr[tmp]);
				pos = tmp;//继续向下调整，被交换的孩子肯定会对下层产生影响，没有被交换的不用关
			}
			else//根本来就是最大的,是从后向前往下调整，说明根大于左右孩子，说明左右孩子也是正确，就不用再就绪往下走了
			{
				break;
			}
		}
	}

	static void HeapPop(vector<T>& arr, size_t n, bool(*cmp)(T, T)) //堆顶和堆尾交换
	{
		Swap(arr[0], arr[n - 1]);//堆首尾交换
		n--;//长度--
		AdjustDown(arr, n, 0, cmp);//从首向下调整
	}


public:
	static void Heap_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)
	{
		for (int i = (len - 1)/2; i >= 0; --i)//构建堆
		{
			AdjustDown(arr, len, i, cmp);
		}
		for (int j = len; j > 0; --j)//排一次，重新构建一次
		{
			HeapPop(arr, j, cmp);
		}
	}
};


template<class T>
class MergeSort
{
private:

	static void Merge_Sort(vector<T>& arr, size_t start, size_t end, bool(*cmp)(T, T))
	{
		if (start >= end)//越界
		{
			return;
		}
		int mid = (start + end) / 2;
		Merge_Sort(arr, start, mid, cmp);//递归排序小区间
		Merge_Sort(arr, mid + 1, end, cmp);

		int x = start;
		int y = mid + 1;
		vector<int> tmp;
		while (x <= mid && y <= end)
		{
			if (cmp(arr[x], arr[y]))//把连个区间的小的一次放进去
			{
				tmp.push_back(arr[x]);
				x++;
			}
			else
			{
				tmp.push_back(arr[y]);
				y++;
			}
		}

		for (; x <= mid; x++)//一个区间越界，另一个没有完全放进去，监测哪个没有越界放进去
		{
			tmp.push_back(arr[x]);
		}
		for (; y <= end; y++)
		{
			tmp.push_back(arr[y]);
		}

		for (int i = start; i <= end; i++)//排好序后放在对应位置
		{
			arr[i] = tmp[i - start];
		}
	}
public:
	static void Merge_Sort(vector<T>& arr, size_t len, bool(*cmp)(T, T) = Less)
	{
		Merge_Sort(arr,0, len - 1, cmp);
	}
};

template<class T>
class QuickSort
{
private:
	static int GetPivot(vector<T>& arr, int start, int end)//获取基准元素，优化算法
	{
		srand((unsigned int)(time(NULL)));
		int pos = rand() % (end - start + 1) + start;
		return pos;
	}
public:
	static void Quick_Sort(vector<int>& arr, int start, int end, bool(*cmp)(T, T,bool) = Less)
	{
		int left = start,right = end;
		int pivot = GetPivot(arr, start, end);
		Swap(arr[start], arr[pivot]);//让start成为基准元素
		while (start < end)
		{
			for (; start < end && cmp(arr[end], pivot, true) ; end--);//从右往左比基准值小的
			
			for (; start < end && cmp(pivot,arr[start], true) ; start++);//从左往右比基准值大的

			if (start < end)//若未相遇就交换
			{
				Swap(arr[start], arr[end]);
			}
		}
		Swap(arr[left], arr[end]);
		Quick_Sort(arr, left, end - 1);
		Quick_Sort(arr, end + 1, right);
	}
};


int main()
{
	//vector<int> arr = { 2, 3, 4, 1, 6 };
	 vector<int> arr = { 2, 3, 4, 1, 6, 7, 8, 10, 5, 9 ,0,111,2,3,1,3,34,3,23,2,34};
	//int arr[] = { 2, 3, 4, 1, 6, 7, 8, 10, 5, 9 };
	//Bubble_Sort(arr,arr.size());
	//Select_Sort(arr,arr.size());
	//Insert_Sort(arr,arr.size());
	//Shell_Sort(arr,arr.size());
	//HeapSort<vector<int>>::Heap_Sort(arr, arr.size());
	 //MergeSort<int>::Merge_Sort(arr, arr.size());
	 QuickSort<int>::Quick_Sort(arr, 0,arr.size()-1);
	Print(arr, arr.size());
	system("pause");
	return 0;
}