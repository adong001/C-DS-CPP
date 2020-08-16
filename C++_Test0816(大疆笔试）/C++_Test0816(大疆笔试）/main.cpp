#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main1()
{
	//顶点个数和边的个数,终点路标
	int vertex, edge, end;
	int Inf = 0x3fffffff;
	while (cin >> vertex >> edge)
	{
		//邻接矩阵存储顶点之间的权值;先初始化为最大值，代表不通
		vector<vector<int>> Graph(vertex, vector<int>(vertex, Inf));
		//输入各边的值
		int x, y;
		for (int i = 0; i < edge; i++)
		{
			cin >> x >> y;
			cin >> Graph[x][y];
		}
		//输入终点路标
		cin >> end;
		//求最短路径（Floyd算法，多源最短路径),本题应该
		for (int k = 0; k < vertex; k++)
		{
			for (int i = 0; i <vertex; i++)
			{
				for (int j = 0; j < vertex; j++)
				{
					//i->j最短路径是i直接到j或i到k,k到j间接到达的最小值
					if (Graph[i][j] > Graph[i][k] + Graph[k][j])
					{
						Graph[i][j] = Graph[i][k] + Graph[k][j];
					}
				}
			}
		}
		cout << Graph[0][end] << endl;
	}
	return 0;
}