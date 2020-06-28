#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int N, M;//迷宫的横纵坐标
vector<vector<int>> maze;//迷宫
vector<vector<int>> path_tmp;//路径
vector<vector<int>> path_best;//最终路径

void FindPath(int n, int m)
{
	maze[n][m] = 1;//设置为已走
	path_tmp.push_back({ n, m });//将当前路径加入进来
	if (n == N - 1 && m == M - 1)//走到终点
	{
		//如果找到了路径且最优路径之前为空，那这条就是最优路径
		//如果找到的路径长度小于之前找到的路径，那这条就是最优路径
		if (path_best.empty() || path_tmp.size() < path_best.size())
		{
			path_best = path_tmp;
		}
	}
	if (n + 1 < N && maze[n + 1][m] != 1)
	{
		FindPath(n + 1, m);
	}
	if (m + 1 < M && maze[n][m + 1] != 1)
	{
		FindPath(n, m + 1);
	}
	if (n - 1 >= 0 && maze[n - 1][m] != 1)
	{
		FindPath(n - 1, m);
	}
	if (m - 1 >= 0 && maze[n][m - 1] != 1)
	{
		FindPath(n, m - 1);
	}
	maze[n][m] = 0;//这个位置找完所有结果后，恢复现场
	path_tmp.pop_back();//将当前位置退出
}

int main2()
{
	while (cin >> N >> M)
	{
		maze.resize(N,vector<int>(M,0));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> maze[i][j];
			}
		}
		FindPath(0, 0);
		for (int i = 0; i < path_best.size(); i++)
		{
			cout << "(" << path_best[i][0] << "," << path_best[i][1] << ")" << endl;
		}
	}
    return 0;
}