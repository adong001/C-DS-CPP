#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s1, s2;
	while(cin >> s1 >> s2)
	{
		int c1 = s1.size();
		int c2 = s2.size();
		int max = 0;
		if (c1 > c2)
		{
			s1.swap(s2);
			swap(c1, c2);
		}
		vector<vector<int>> vv(c1 + 1, vector<int>(c2 + 1, 0));
		for (int i = 1; i <= c1; i++)
		{
			for (int j = 1; j <= c2; j++)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					vv[i][j] = vv[i - 1][j - 1] + 1;
				}
				if (vv[i][j] > max)
				{
					max = vv[i][j];
				}
			}
		}
		cout << max << endl;
	}
    return 0;
}