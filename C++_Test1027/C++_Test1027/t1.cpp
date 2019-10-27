#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
#include <algorithm>
using namespace std;
//一个含有n项的数列(n <= 2000000)，求出每一项前的m个数到它这个区间内的最小值。
//若前面的数不足m项则从第1个数开始，若前面没有数则输出0。
//
//输入输出格式
//输入格式：
//第一行两个数n，m。
//
//第二行，n个正整数，为所给定的数列。
//
//输出格式：
//n行，第i行的一个数ai，为所求序列中第i个数前m个数的最小值。
//
//输入输出样例
//输入样例#1： 复制
//6 2
//7 8 1 4 3 2s
//输出样例#1： 复制
//0
//7
//7
//1
//1
//3

void Front_MaxValue(int *ar)
{
	int i ;
	int Min = 0;
	int tmp;
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m;j++)
	{
		tmp = min(ar[j], ar[j + 1]);
	}                                                                              
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			Min = i ;
		}
		else if (i < m)
		{
			Min = ar[0];// 7 8 1 4 3 2  6  2
		}

		else
		{
			Min =  
		}

		cout << Min << endl;
	}
}

int main()
{
    system("pause");
    return 0;
}