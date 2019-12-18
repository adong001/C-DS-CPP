#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//列题1：
//在大小为 2N 的数组 A 中有 N + 1 个不同的元素，其中有一个元素重复了 N 次。
//返回重复了 N 次的那个元素。

class Solution {
public:
	int repeatedNTimes(vector<int>& A)
	{
		unordered_set<int> s;
		for (auto& e : A)
		{
			if (!(s.insert(e).second))
			{
				return e;
			}
		}
	}
};


int repeatedNTimes(vector<int>& A)
{
	unordered_map<int, int> um;
	int n = A.size() / 2;

	for (auto & e : A)
	{
		um[e]++;
	}

	for (auto & e : um)
	{
		if (e.second == n)
		{
			return e.first;
		}
	}
	return -1;
}

int main2()
{
    system("pause");
    return 0;
}