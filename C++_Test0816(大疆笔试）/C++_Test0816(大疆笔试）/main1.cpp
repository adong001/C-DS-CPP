#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int backpack(int m, vector<int>& A, vector<int>& V)
{
	if (A.empty() || V.empty() || m < 1)
	{
		return 0;
	}
	const int N = A.size();
	//多加一列，用于设置初始条件，因为第一件商品要用到前面的初始值
	const int M = m + 1;
	vector<int> result;
	//初始化所有位置为0，第一行都为0，初始条件
	result.resize(M, 0);
	//这里商品的索引位置不需要偏移，要和未优化的方法区分开
	//这里的i-1理解为上一行，或者未更新的一维数组值
	for (int i = 0; i != N; ++i)
	{
		for (int j = M - 1; j > 0; --j)
		{
			//如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
			if (A[i] > j)
			{
				result[j] = result[j];
			}
			//如果可以装下，分两种情况，装或者不装
			//如果不装，则即为(i-1, j)
			//如果装，需要腾出放第i个物品大小的空间： j - A[i],装入之后的最大价值即为(i - 1, j A[i-1]) + 第i个商品的价值V[i]
			//最后在装与不装中选出最大的价值
			else
			{
				int newValue = result[j - A[i]] + V[i];
				result[j] = max(newValue, result[j]);
			}
		}
	}
	//返回装入前N个商品，物品大小为m的最大价值
	return result[m];
}

int main2()
{
	//游戏个数和完的天数
	int Games, PlayDays;
	//本题就是一个01背包变换题
	while (cin >> Games >> PlayDays)
	{
		vector<int> A(Games);//游戏天数
		vector<int> V(Games);//游戏时间
		for (int i = 0; i < Games; i++)
		{
			cin >> A[i] >> V[i];
		}
		cout << backpack(PlayDays, A, V) << endl;

	}
	return 0;
}