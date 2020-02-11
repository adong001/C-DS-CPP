#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class DealInt
{
public:
	int operator ()(const int num)
	{
		return num;
	}
};

class DealString
{
public:
	int operator ()(const string& str)
	{
		int seed = 128;//种子
		int sum = 0;
		for (auto& e : str)
		{
			sum = seed * sum + e;//128进制，第一位是第一个字符，第二位是第二个字符
		}
		return sum & 0x7fffffff;//可能越界，取后32位即可(不转也行，会隐式转换)
	}
};

enum Status
{
	EMPTY,
	EXIST,
	DELETE
};


template<class Key, class Value,class DealFunc = DealInt>
class HashTable
{
private:

	struct Elem
	{
		pair<Key, Value> m_val;
		Status m_status;
		Elem(const Key& key = Key(), const Value& value = Value(), const Status& status = Status()) :
			m_val(key, value),
			m_status(status)
		{}
	};

	vector<Elem> m_table;
	size_t m_size;

	int HashFunc(const Key& key)//哈希算法函数，可自定义
	{
		DealFunc func;
		return func(key) % m_table.capacity();
	}


public:

	HashTable(size_t capacity = 11) :
		m_table(capacity),//注意：m_table.size()是哈希表的容量，m_size是当前表中有几个元素
	；	m_size(0)
	{}

	//现在还没有实现迭代器，这里暂且做一个接口访问表里面的元素
	vector<Elem> Table()
	{
		return m_table;
	}

	size_t capacity()
	{
		return m_table.size();
	}

	bool empty()
	{
		return m_size == 0;
	}

	void swap(HashTable<Key, Value>& ht)
	{
		m_table.swap(ht.m_table);
		swap(m_size, ht.m_size);
	}

	bool insert(const pair<Key, Value>& p)
	{
		/*if (!checkCapacity())//检查是否有足够容量可以插入
		{
			return false;
		}*/

		int n = HashFunc(p.first);
		while (m_table[n].m_status == EXIST)
		{
			if (m_table[n].m_val.first == p.first)
			{
				return false;
			}
			n = (n == capacity()) ? 0 : n + 1;
		}

		m_table[n].m_val = p;
		m_table[n].m_status = EXIST;
		m_size++;
		return true;
	}


	int Find(const Key& key)
	{
		int n = HashFunc(key);
		int flag = n;//记录最初的位置
		while (m_table[n].m_status != EMPTY)
		{
			if (m_table[n].m_status == EXIST && m_table[n].m_val.first == key)
			{
				return n;
			}
			n = (n == m_size) ? 0 : n + 1;
			if (flag == n)
			{
				return -1;//循环找回来，说明没有此键值对
			}
		}
	}

	bool erase(const Key& key)
	{
		int ret = Find(key);

		if (ret < 0)
		{
			return false;
		}

		else
		{
			m_table[ret].m_status = DELETE;
			m_size--;
		}
	}

};