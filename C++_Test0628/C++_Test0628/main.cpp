#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//struct Data
//{
//	char a;
//	int b;
//	long long c;
//	char d;
//};
//Data data[2][10];
int main1()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int n1 = s1.size();
		int n2 = s2.size();
		int i, j;
		int flag = 1;
		vector<vector<int>> vv(n1 + 1, vector<int>(n2 + 1, 0));
		for (i = 0; i <= n1; i++)
		{
			vv[i][0] = i;
		}
		for (i = 1; i <= n2; i++)
		{
			vv[0][i] = i;
		}
		for (i = 1; i <= n1; i++)
		{
			for (j = 1; i <= n2; i++)
			{
				flag = s1[i] == s2[j] ? 0 : 1;
				//两个串最后一个字符是否相同,不相同，只在vv[i-1][j-1]修改一次就能相等
				//4种情况：
				//1.s2[j-1]在s2[j]的基础上修改一次得到s1[i]
				//2.s1[i-1]在s1[i]的基础上修改一次得到s2[j]
				//3.s1[i-1]在s2[j-1]相同时，s1[i]得到s2[j]就是s1[i-1]得到s2[j-1]
				//4.s1[i-1]在s2[j-1]不同时，s1[i]得到s2[j]就是将s1[i]或s2[j]修改一次
				vv[i][j] = min(min(vv[i][j - 1]+1, vv[i - 1][j]+1),vv[i-1][j-1] + flag);
			}
		}
		cout << vv[i][j] << endl;
	}
    return 0;
}