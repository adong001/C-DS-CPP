//#pragma once 
//#include "RBTRee.h"
//#include <set>
//
//template<class K,class V>
//class MyMap
//{
//	private:
//		typedef YD::RBTree<pair<K, V>> RBT;
//		RBT m_rbt;
//		class iterator
//		{
//			RBT * m_ptr;
//		public:
//			iterator(RBT * val = nullptr) :
//				m_ptr(val)
//			{}
//
//			iterator operator++()
//			{
//				m_ptr = RBT::increasement(m_ptr);
//				return *this;
//			}
//
//			iterator operator++(int)
//			{
//				iterator tmp = *this;
//				m_ptr = RBT::increasement(m_ptr);
//				return tmp;
//			}
//
//			iterator operator--()
//			{
//				m_ptr = RBT::decreasement(m_ptr);
//				return *this;
//			}
//
//			iterator operator--(int)
//			{
//				iterator tmp = *this;
//				m_ptr = RBT::decreasement(m_ptr);
//				return tmp;
//			}
//
//			T & operator*()
//			{
//				return m_ptr->m_data;
//			}
//
//			RBT * operator->()
//			{
//				return m_ptr;
//			}
//
//			bool operator==(const iterator & val) const
//			{
//				return m_ptr == val.m_ptr;
//			}
//
//			bool operator!=(const iterator & val) const
//			{
//				return m_ptr != val.m_ptr;
//			}
//		};
//
//	public:
//		const V at(const K& k)
//		{
//			V val = m_rbt.find(k);
//			if ()
//		}
//
//		iterator begin()
//		{
//			return m_head->m_left;
//		}
//
//		iterator end()
//		{
//			return m_head;
//		}
//
//		cbegin()
//		{}
//
//		cend()
//		{}
//
//		find()
//		{}
//
//		const& V operator[]
//		{}
//
//		void clear();
//		bool insert();
//		bool empty();
//		size_t size()
//		{
//			return m_rbt.size();
//		}
//
//};
