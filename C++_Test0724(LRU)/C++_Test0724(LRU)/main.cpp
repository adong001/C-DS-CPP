#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache
{
private:
	//first存储key,second存储存在list中val的迭代器
	unordered_map<int, list<pair<int,int>>::iterator> m_ht;
	//list存储val
	list<pair<int,int>> m_lt;//必须存储key和val,不能只存储val,在删除back的时候map找不到key
	int m_capacity;
public:
	LRUCache(int capacity) :
		m_capacity(capacity)
	{}

	int get(int key)
	{
		auto it = m_ht.find(key);
		if (it != m_ht.end())//找到
		{
 			//m_lt.splice(m_lt.begin(),m_lt,it->second);//splice(it1,list,it2)是把list中的it2的位置剪切到it1的位置
			m_lt.push_front(make_pair(key, it->second->second));//先把get的值更新到第一个
			m_lt.erase(it->second);//删除原来的位置
			m_ht[key] = m_lt.begin();//跟新map中val的位置
			return m_lt.front().second;//返回list中更新的值
		}
		return -1;//没找到就返回-1
	}

	void put(int key, int value)
	{
		auto it = m_ht.find(key);
		if (it != m_ht.end())//找到
		{
			// m_lt.splice(m_lt.begin(),m_lt,it->second);
			m_lt.push_front(make_pair(key, value));//先把put的值更新到第一个
			m_lt.erase(it->second);//删除原来的位置
			m_ht[key] = m_lt.begin();
		}
		else//数据不存在，需要添加
		{
			if (m_ht.size() == m_capacity)//LRU已经满了，需要删除一个
			{
				m_ht.erase(m_lt.back().first);//删除哈希表中的最不常用的
				m_lt.pop_back();//删除链表中最不常用的
			}
			m_lt.push_front(make_pair(key, value));//将put的值跟新到链表最前面
			m_ht[key] = m_lt.begin();//更新map中的值
		}
	}
};

int main()
{
	LRUCache lru(1);
	lru.put(2,1);
	lru.get(2);
	lru.put(3, 2);
	lru.get(2);
	lru.get(3);
	
    return 0;
}