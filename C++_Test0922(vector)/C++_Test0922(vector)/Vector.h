#pragma once
#include<iostream>
#include<algorithm>

using namespace std;

namespace Bit//用一个名字空间包起来，防止与系统的重复。
{
	template<class T>
	class vector
	{
	private:
		typedef T* iterator;
		typedef const T* c_iterator;
		iterator m_start;
		iterator m_end;
		iterator m_endOfStorage;
	public:
		vector() :
			m_start(nullptr),
			m_end(nullptr),
			m_endOfStorage(nullptr)
		{}

		vector(size_t n, const T& val = T()) :
			m_start(nullptr),
			m_end(nullptr),
			m_endOfStorage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				m_start[i] = val;
			}
		}

		vector(T * start, T * end) :
			m_start(nullptr),
			m_end(nullptr),
			m_endOfStorage(nullptr)
		{
			int extsize = end - start;
			reserve(extsize);
			for (int i = 0; i < extsize; i++)
			{
				m_start[i] = start[i];
			}
		}

		~vector()
		{
			if (!(m_endOfStorage - start))
			{
				delete[]m_start;
			}
			m_start = nullptr;
			m_end = nullptr;
			m_endOfStorage = nullptr;
		}

		iterator begin();
		iterator end();
		c_iterator c_begin();
		c_iterator c_begin();
		size_t size();
		size_t capacity();
		void reserve(size_t _size);
		void resize(size_t _size, const T &val = T());
		T & operator [] (int i);
		const T & operator [] (int i) const;
		void push_back(const T &val);
		void pop_back();
		iterator insert(iterator pos, const T &val);
		iterator insert(iterator pos, int n, const T &val);
		iterator insert(iterator pos, const T * start, const T * end);
		iterator erase(iterator pos);
		iterator erase(iterator start, iterator end);




		iterator begin()
		{
			return m_start;
		}

		iterator end()
		{
			return m_end;
		}

		size_t size()
		{ 
			return m_end - m_start;
		}

		size_t capacity()
		{
			return m_endOfStorage - m_start;
		}

		void reserve(size_t _size)//只扩不缩
		{
			int capacity = m_endOfStorage - start;
			T* tmp;
			if (capacity < _size)
			{
				if (capacity == 0)
				{
					capacity = 1;
				}
				while (capacity < _size)
				{
					capacity *= 2;			
				}

				tmp = new T[capacity];
				memncpy(tmp, m_start, size());
				m_end = tmp + size();
				delete[]m_start;
				m_start = tmp;
				m_endOfStorage = tmp + _size;
			}
		}

		void resize(size_t _size, const T &val = T()){ }
		T & operator [] (int i){ }
		const T & operator [] (int i) const{ }
		void push_back(const T &val){ }
		void pop_back(){ }
		iterator insert(iterator pos, const T &val){ }
		iterator insert(iterator pos, int n, const T &val){ }
		iterator insert(iterator pos, const T * start, const T * end){ }
		iterator erase(iterator pos){ }
		iterator erase(iterator start, iterator end){ }
	};
};