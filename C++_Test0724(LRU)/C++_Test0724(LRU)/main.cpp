#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache
{
private:
	//first存储key,second存储存在list中val的迭代器
	unordered_map<int, list<int>::iterator> m_ht;
	//list存储val
	list<int> m_lt;
	int m_capacity;
	
public:

	LRUCache(int capacity) :
		m_capacity(capacity)
	{}

	int get(int key)
	{
		auto it = m_ht.find(key);//
		if (it != m_ht.end())//找到
		{
			m_lt.push_front(*it->second);//先把get的值更新到第一个
			m_lt.erase(it->second);//删除原来的位置
			m_ht[key] = m_lt.begin();
			return m_lt.front();//
		}
		return -1;
	}

	void put(int key, int value)
	{
		auto it = m_ht.find(key);
		if (it != m_ht.end())//找到
		{
			m_lt.push_front(value);//先把get的值更新到第一个
			m_lt.erase(it->second);//删除原来的位置
			m_ht[key] = m_lt.begin();
			return;
		}
		else//数据不存在，需要添加
		{
			if (m_ht.size() == m_capacity)//LRU已经满了，需要删除一个
			{
				if (m_ht.size() == 1)
				{
					
				}
				m_ht.erase(m_lt.back());//删除哈希表中的最不常用的
				m_lt.pop_back();//删除链表中最不常用的
			}
			m_lt.push_front(value);
			m_ht[key] = m_lt.begin();
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