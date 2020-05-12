#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int main22()
{
	int n;
	while (cin >> n)
	{
		int k;
		priority_queue<int,vector<int>,greater<int>> heap;
		int tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			heap.push(tmp);
		}
		cin >> k;
		for (int i = 0; i < k - 1; i++)
		{
			tmp = heap.top();
			heap.pop();
			while (tmp == heap.top())//ШЅжи
			{
				heap.pop();
			}
		}
		cout << heap.top() << endl;
	}
	return 0;
}