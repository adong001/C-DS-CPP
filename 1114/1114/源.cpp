#include<iostream>
#include<multiset>
#include<vector>
using namespace std;
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	multiset<int, greater<int>> ms;
	for (int i = 0; i < input.size(); i++)
	{
		if (i < k)
		{
			ms.insert(input[i]);
		}
		else
		{
			if (*ms.begin() > input[i])
			{
				ms.erase(ms.begin());
				ms.insert(input[i]);
			}
		}
	}
	vector<int> ret;
	for (auto& e : ms)
	{
		ret.push_back(e);
	}
}

int main()
{
	vector<int> a = { 4, 5, 1, 6, 2, 7, 3, 8 };
	GetLeastNumbers_Solution(a, 4);
	return 0;
}