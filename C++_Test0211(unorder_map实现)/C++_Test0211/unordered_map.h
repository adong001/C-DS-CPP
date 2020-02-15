#pragma once
#include"HashBacket.h"


namespace YD
{
	

	template<class K,class V,class KeyOfValue,class HF = DealInt>
	class unordered_map
	{
	private:
		class KeyOfValue
		{
		public:
			const K& operator()(const pair<K, V>& data)//仿函数，目的是通过Value获取Key的值
			{
				return data.first;
			}
		};
		HashBucket<K, pair<K, V>, KeyOfValue, HF> m_hb;
		typename typedef iterator<K, V, KeyOfValue, HF>::iterator iterator;
	public:
		
		unordered_map() :
			m_hb()
		{}

		~unordered_map()
		{
			m_hb.~HashBucket();
		}

		iterator begin()
		{
			return m_hb.begin();
		}

		iterator end()
		{
			return m_hb.end();
		}

		size_t size()
		{
			return m_hb.size();
		}

		size_t capacity()
		{
			return m_hb.capacity();
		}

		bool empty()
		{
			return m_hb.empty();
		}

		void swap(unordered_map<K, V, KeyOfValue, HF>& hb)
		{
			m_hb.swap(hb.m_hb);
		}

		pair<iterator, bool> insert(const pair<K, V>& val)
		{
			return m_hb.insert(val);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> p = m_hb.insert(pair<K, V>(key, V()));//不存在就插入一个
			iterator it = p.first;
			return p.second;
		}
		const V& operator[](const K& key)const
		{
			pair<iterator, bool> p = m_hb.insert(pair<K, V>(key, V()));//不存在就插入一个
			iterator it = p.first;
			return p.second;
		}
	};
};