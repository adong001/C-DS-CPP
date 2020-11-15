#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;

int FindKNum(vector<int> v, int k)
{
	int len = v.size();
	if (len <= 0 || k > len)
	{
		return -1;
	}
	//1.≈≈–Ú

	sort(v.begin(), v.end());
	return v[v.size() - k];

	//2.”√∂—
	priority_queue<int, vector<int>,greater<int>> pq;
	for (auto& e : v)
	{
		pq.push(e);
	}
	for (int i = 1; i <= k; i++)
	{
		pq.pop();
	}
	return pq.top();
}