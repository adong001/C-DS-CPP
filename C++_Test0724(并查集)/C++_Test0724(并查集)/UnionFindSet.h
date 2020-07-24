#pragma once
#include<vector>
#include<list>
#include<iostream>
using namespace std;

class UnionFindSet
{
private:
	vector<int> m_a;

public:
	UnionFindSet(size_t Size = 0)//构造函数
	{
		m_a.resize(Size, -1);
	}
	UnionFindSet(const vector<int>& v):
		m_a(v)
	{}

	int FindRoot(int index)//查找index的根
	{
		while (m_a[index] >= 0)
		{
			//每个元素存储的值是根节点的下标(>=0)，只有根节点存储的是这个集合的个数(<0)
			index = m_a[index];
		}
		return index;
	}

	bool Union(int x1, int x2)//合并两个集合
	{
		if (x1 == x2)
		{
			return true;
		}
		int root1 = FindRoot(x1);//找到根节点的下标
		int root2 = FindRoot(x2);
		if (root1 != root2)//不是一个集合才合并
		{
			if (m_a[root1] > m_a[root2])//保证root1为大集合，小集合合并到大集合中
			{
				int tmp = root1;
				root1 = root2;
				root2 = tmp;
			}
			m_a[root1] += m_a[root2];//跟节点的值加上新合并的个数
			m_a[root2] = root1;//被合并集合的根节点的值变成新的跟节点的下标
			return true;
		}
		return false;
	}
		
	size_t Count()const//统计根的个数,即集合的个数
	{
		size_t cnts = 0;
		for (auto& e : m_a)
		{
			if (e < 0)
			{
				cnts++;
			}
		}
		return cnts;
	}
};