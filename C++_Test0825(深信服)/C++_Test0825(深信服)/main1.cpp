#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//判断两行是否相等
bool Judge(vector<int> ar1, vector<int> ar2)
{
	for (int i = 0; i < ar1.size(); i++)
	{
		if (ar1[i] != ar2[i])
		{
			return false;
		}
	}
	return true;
}

void Print(vector<vector<int>> arr, int row)
{
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j < arr[0].size(); j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
bool Equal(vector<bool>& mirror, int start, int end)
{
	for (; start < end; start++, end--)
	{
		if (mirror[start] != mirror[end])
		{
			return false;
		}
	}
	return true;
}

int main2()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<vector<int>> arr(n, vector<int>(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
		vector<bool> mirror(n);//存储两行之间的关系，相等就是true
		mirror[0] = true;
		for (int j = 1; j <n; j++)
		{
			mirror[j] = Judge(arr[0], arr[j]);
		}
		int start = 0, end = n - 1;
		while (1)
		{
			if (Equal(mirror, start, end))
			{
				end /= 2;
			}
			else
			{
				break;
			}
		}
		Print(arr, end);
	}
	return 0;
}
