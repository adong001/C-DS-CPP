#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int GetMaxBag(int n, vector<int> w, vector<int> v)
{
	if (n < 1 || w.empty() || v.empty())
	{
		return 0;
	}
	int N = w.size();
	int M = n + 1;
	vector<vector<int>> dp(N, vector<int>(M, 0));
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			//第i个商品在A中对应的索引为i-1: i从1开始
			//如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
			if (w[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			//如果可以装下，分两种情况，装或者不装
			//如果不装，则即为(i-1, j)
			//如果装，需要腾出放第i个物品大小的空间： j - A[i-1],
			//装入之后的最大价值即为(i - 1, j - A[i - 1]) + 第i个商品的价值V[i - 1]
			//最后在装与不装中选出最大的价值
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
			}
		}
	}
	return dp[N - 1][M - 1];
}

int main()
{
	int n;
	while (cin >> n)
	{
		string s1, s2;
		cin >> s1;
		cin >> s2;
		int len1 = s1.size();
		int len2 = s2.size();
		vector<int> w;
		vector<int> v;
		for (int i = 0; i < len1;)
		{
			string tmp;
			if (s1[i] == ',')
			{
				i++;
				continue;
			}
			for (; i < len1 && s1[i] != ','; i++)
			{
				tmp += s1[i];
			}
			w.push_back(atoi(tmp.c_str()));
		}
		for (int i = 0; i < len2;)
		{
			string tmp;
			if (s2[i] == ',')
			{
				i++;
				continue;
			}
			for (; i < len2 && s2[i] != ','; i++)
			{
				tmp += s2[i];
			}
			v.push_back(atoi(tmp.c_str()));
		}
		cout << GetMaxBag(n, w, v) << endl;
	}
    return 0;
}