#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//
//int GetPos(string s1, string s2, int pos)
//{
//	for (int i = 0; i < s2.size(); i++)
//	{
//		if ((pos = s1.find(s2[i],pos)) == std::string::npos)
//		{
//			return pos;
//		}
//	}
//	return pos;
//}
//
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		int maxpos = -1;
//		int end;
//		bool flag = false;
//		int i;
//		for (i = 0; i < s1.size(); i++)
//		{
//			end = GetPos(s1, s2, i);
//			if (end != std::string::npos)
//			{
//				maxpos = i;
//			}
//		}
//			
//		maxpos == -1 ? cout << 0 << endl : cout << maxpos + 1 << endl;
//	}
//	return 0;
//}

int main11()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<vector<int>> vv(2, vector<int>(3));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> vv[i][j];
			}
		}
		
		int count = 0;
		
		for (int i = 0; i < m; i++)
		{
			count += vv[i][2];
		}
		cout << count<<endl;
	}
	return 0;
}