#pragma once
#include<cstdio>
#include<cstring>
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
			resize(n);
			for (int i = 0; i < n; i++)
			{
				m_start[i] = val;
			}
			m_end = m_start + size();
		} 

		vector(const vector<T>& V) :
			m_start(nullptr),
			m_end(nullptr),
			m_endOfStorage(nullptr)
		{
			reserve(V.size());
			m_end = m_start + V.size();
			for (int i = 0; i < V.size(); i++)
			{
				m_start[i] = V[i];
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
			m_end = m_start + extsize;
		}

		~vector()
		{
			if (!(m_endOfStorage - m_start))
			{
				delete[]m_start;
			}
			m_start = nullptr;
			m_end = nullptr;
			m_endOfStorage = nullptr;
		}

	    iterator begin()
		{
			return m_start;
		}


		iterator end()
		{
			return m_end;
		}


		c_iterator r_begin()
		{
			return m_end - 1 ;
		}

	
		c_iterator r_end()
		{
			return m_start-1;
		}
		
		const c_iterator c_begin()const
		{
			return m_start;
		}


		const c_iterator c_end()const
		{
			return m_end;
		}

		size_t size()
		{
			return m_end - m_start;
		}

		const size_t size()const
		{
			return m_end - m_start;
		}
		size_t capacity()
		{
			return m_endOfStorage - m_start;
		}



		void reserve(size_t _size)//只扩不缩
		{
			int capacity = m_endOfStorage - m_start;
			T* tmp;
			T Tsize = m_end - m_start;
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
				int i;
				size_t res = size();
				for (i = 0; i < res; i++)
				{
					tmp[i] = m_start[i];
				}
				m_end = tmp + Tsize;
				delete[]m_start;
				m_start = tmp;
				m_endOfStorage = tmp + _size;
			}
		}

	
		void resize(size_t _size, const T &val = T())
		{
			reserve(_size);
			int oldsize = m_end - m_start;
			m_end = m_start + _size;
			if (oldsize < _size)
			{
				while(_size - oldsize)
				{
					m_start[oldsize] = val;
					oldsize++;
				}
			}
		}


		T & operator [] (int i)
		{
			return m_start[i];
		}

		const T & operator [] (int i) const
		{
			return m_start[i];
		}

		void push_back(const T &val)
		{
			insert(m_end, val);
		}
		void pop_back()
		{
			erase(m_end);
		}

		iterator insert(iterator pos, const T &val)
		{
			int tmp = pos - m_start;
			resize(size() + 1);
			pos = m_start + tmp;
			for (auto i = m_end - 1; i != pos; i--)
			{
				*i = *(i - 1);
			}
			*pos = val;
			return pos;
		}
		iterator insert(iterator pos, int n, const T &val)
		{
			int tmp = pos - m_start;
			resize(size() + n);
			pos = m_start + tmp;
			for (auto i = m_end - 1; i != (pos + n - 1) ; i--)
			{
				*i = *(i - n);
			}
			for (int i = 0; i < n; i++)
			{
				*(pos + i) = val;
			}
			return pos;
		}

		iterator insert(iterator pos, const T * _start, const T * _end)
		{
			T _size = _end - _start;
			int tmp = pos - m_start;
			resize(size() + _size);
			pos = m_start + tmp;
			for (auto i = m_end - 1; i != (pos + _size - 1); i--)
			{
				*i = *(i - _size);
			}
			for (int i = 0; i < _size; i++)
			{
				pos[i] = _start[i];
			}
			return pos;
		}

		iterator erase(iterator pos)
		{
			m_end--;
			for (auto i = pos; i < m_end;i++)
			{
				*i = *(i + 1);
			}
			return pos;
		}

		iterator erase(iterator _start, iterator _end)
		{
			int extsize = _end - _start -1;
			for (int i = _start - m_start ; i < m_end - m_start - extsize; i++)
			{
				m_start[i] = m_start[i + extsize];
			}
			m_end -= extsize;
			return _start;
		}
	};
};