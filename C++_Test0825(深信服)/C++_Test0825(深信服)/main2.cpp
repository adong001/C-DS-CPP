#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int GetPlanNums(vector<int>& goods, int n, int m, int k)
{
	//思路：先找出一个连续超过k的区间，判断长度是否大于m,小于就找下一个区间，大于就++这个区间的方案数
	//方案数计算：[start,end]区间内，方案数=(end-start)-m+1
	int start = 0;
	int end = 0;
	int cnts = 0;//方案数
	for (; start < n; start = end)
	{
		//1.找出一个连续超过k的区间
		for (; end < n && goods[end] >= k; end++);

		//2.得出区间plan数
		//区间长度大于m
		if ((end - start) >= m)
		{
			cnts += ((end - start) - m + 1);
			//越过小于k的区间
		}
		for (; end < n && goods[end] < k; end++);
	}
	return cnts;
}

int main3()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<int> goods(n);
		for (int i = 0; i < n; i++)
		{
			cin >> goods[i];
		}
		cout << GetPlanNums(goods, n, m, k) << endl;
	}
	return 0;
}