#pragma once 
#include <set>
#include "RBTRee.h"




template<class T>
class MySet
{
	private:
	typedef YD::RBTree<T> RBT;
	RBT m_rbt;

	class iterator
	{
		RBT * m_ptr;
	public:
		iterator(RBT * val = nullptr) :
			m_ptr(val)
		{}

		iterator operator++()
		{
			m_ptr = increasement(m_ptr);
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp = *this;
			m_ptr = RBT::increasement(m_ptr);
			return tmp;
		}

		iterator operator--()
		{
			m_ptr = RBT::decreasement(m_ptr);
			return *this;
		}

		iterator operator--(int)
		{
			iterator tmp = *this;
			m_ptr = RBT::decreasement(m_ptr);
			return tmp;
		}

		T & operator*()
		{
			return m_ptr->m_data;
		}

		RBT * operator->()
		{
			return m_ptr;
		}

		bool operator==(const iterator & val) const
		{
			return m_ptr == val.m_ptr;
		}

		bool operator!=(const iterator & val) const
		{
			return m_ptr != val.m_ptr;
		}

		iterator begin()
		{
			iterator ret(m_rbt.FirstChild());
			return ret;
		}

		iterator end()
		{
			iterator ret(m_rbt.LastChild());
			return ret;
		}
	};

public:

	iterator find(const T& k)
	{
		RBT* cur = m_rbt.Find(k);
		iterator it(cur);
		return it
	}


	void clear()
	{
		m_rbt.~RBTree();
	}

	pair<iterator, bool> insert(const T& k)
	{
		pair<iterator, bool> ret(nullptr, false);
		return m_rbt.Insert(k);
		if (cur != nullptr)
		{
			ret.second = true;
		}
		return ret;
	}

	bool empty()
	{
		return m_rbt.empty();
	}

	size_t size()
	{
		return m_rbt.size();
	}

};