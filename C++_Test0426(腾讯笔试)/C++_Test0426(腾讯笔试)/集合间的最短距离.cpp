#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct Pos
{
	int x;
	int y;
};

int main4()
{
	int n;
	while (cin >> n)
	{
		int m;	
		vector<float> ret(n);
		for (int i = 0; i < n; i++)
		{
			cin >> m;
		
			vector<Pos> v1(m);
			vector<Pos> v2(m);
			float tmp = 0;
			float min = 100000.0;
			for (int i = 0; i < m; i++)
			{
				cin >> v1[i].x >> v1[i].y;
			}
			for (int i = 0; i < m; i++)
			{
				cin >> v2[i].x >> v2[i].y;
			}
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m; j++)
				{
					tmp = sqrt(pow((v1[i].x - v2[j].x), 2) + pow((v1[i].y - v2[j].y), 2));
					min = tmp < min ? tmp : min;
				}
			}
			ret[i] = min;
		}	
		for (auto& e : ret)
		{
			printf("%.3f\n", e);
		}
	}
    return 0;
}