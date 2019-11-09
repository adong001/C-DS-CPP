#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//有1,2,3...n的的无序数组，求排序算法，并且要使时间复杂度为O(n),
//空间复杂度为O(1),使用交换，而且只能一次交换两个数
void sort(int*ar, int n)
{
	int tmp,i;
	for (i = 0; i < n; i++)
	{
		while (ar[i] != i + 1)//顺序一定是ar[i] = i+1,
		{
			tmp = ar[ar[i]-1];//必须先换ar[ar[i]-1]，否则ar[i]一换，ar[ar[i]-1]的值就跟着变了
			ar[ar[i]-1] = ar[i];
			ar[i] = tmp;
		}
	}
}

int main3()
{
	int ar[] = { 10, 4, 8, 1, 3, 9, 2, 7, 6, 5 };
	sort(ar, 10);
	for (auto& i : ar)
	{
		cout << i << " ";
	}
	cout << endl;
    system("pause");
    return 0;
}