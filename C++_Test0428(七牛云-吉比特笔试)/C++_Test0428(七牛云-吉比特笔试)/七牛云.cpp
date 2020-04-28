#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//
//bool JudgeEqu(const vector<string> vs)
//{
//	for (int i = 1; i < vs.size(); i++)
//	{
//		if (vs[i] == vs[i - 1])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//string Judge(const vector<string> vs)
//{
//	string ret = "Yes";
//	string tmp;
//	for (int i = 1; !vs.empty() || !JudgeEqu(vs);i++)
//	{
//		
//	}
//	return ret;
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<string> vs(n);
//		vector<string> vr(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> vs[i];
//			vr[i] = Judge(vs);
//		}
//		for (auto& e : vr)
//		{
//			cout << e << endl;
//		}
//	}
//    return 0;
//
//}
vector<int> set(1001);
int find(int x)
{
	return x == set[x] ? x : (set[x] = find(set[x]));
}

int main1()
{
		int n,m;
		while (cin >> n >> m)
		{	
			int a, b;
			for (int i = 1; i <= n; i++)
			{
				set[i] = i;
			}
			for (int i = 0; i <= m; i++)
			{
				cin >> a >> b;
				int fx = find(a);
				int fy = find(b);
				set[fx] = fy;
			}
			int count = 0;
			for (int i = 1; i <= n; i++)
			{
				if (set[i] == i)
				{
					count++;
				}
			}

			if (count == 1)
			{
				cout << "YES" << endl;
			}

			else
			{
				cout << "NO" << endl;
			}
		}
	return 0;
}

//vector<vector<int>> vv(1010, vector<int>(1010));
//vector<int> v(1010);
//int n;
//void dfs(int x)
//{
//	v[x] = 1;
//	for (int i = 0; i <= n; i++)
//	{
//		if (!v[i] && vv[x][i])
//		{
//			v[i] = 1;
//			dfs(i);
//		}
//	}
//}
//
//int main()
//{
//	int m;
//	while (cin >> n >> m)
//	{	
//		int a, b;
//		for (int i = 0; i < 1010; i++)
//		{
//			v[i] = 0;
//			for (int j = 0; j < 1010; j++)
//			{
//				vv[i][j] = 0;
//			}
//		}
//		for (int i = 0; i < m; i++)
//		{
//			cin >> a >> b;
//			vv[a][b] = 1;
//		}
//		dfs(1);
//		if (v[n] != 1)
//		{
//			cout << "NO" << endl;
//		}
//		else
//		{
//			cout << "YES" << endl;
//		}
//	}
//}