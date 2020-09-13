#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


int main4()
{
	int n, k, d;
	while (cin >> n >> k >> d)
	{
		int cnts = 0;
		int fn[1001] = { 0 };
		fn[1] = 1;
		fn[2] = 2;
		fn[3] = 4;
		for (int i = 4; i < n; i++)
		{
			fn[i] = fn[i - 1] + fn[i - 2];
		}
		for (int i = d; i <= k; i++)
		{
			cnts += fn[i];
			cnts %= 998244353;
		}
		cnts *= 2;
		cnts %= 998244353;
		cout << cnts << endl;
	}
    return 0;
}