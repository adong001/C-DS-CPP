#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main2()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v(m + 1,INT_MAX);
		v[n] = 0;
		for (int i = n; i <= m; ++i)
		{
			if (v[i] == INT_MAX)
			{
				continue;
			}
			for (int j = 2; j <= sqrt(i); ++j)
			{
				if (i%j == 0 && i + j <= m)
				{
					v[i + j] = min(v[i] + 1, v[i + j]);//更新每一个石板
				}
				if (i/j !=j && i % (i/j) == 0 && i + i/j <= m )
				{
					v[i + i/j] = min(v[i] + 1, v[i + i/j]);//更新另一个非平方数石板
				}
			}
		}
		if (v[m] == INT_MAX)
		{
			cout << -1 << endl;
			continue;
		}
		cout << v[m] <<endl;
	}
    return 0;
}