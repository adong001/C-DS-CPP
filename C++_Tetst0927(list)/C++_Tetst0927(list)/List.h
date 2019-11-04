#pragma once
#include<iostream>
#include"ListNode.h"
#include"Iterator.h"
using namespace std;
template<class T>
class List
{
private:
	typedef ListNode<T>* m_pNode;
	typedef ListIterator<T>* iterator;
	m_pNode m_pHead;   
	void CreateHead()
	{
		m_pHead = new ListNode<T>;
		m_pHead->m_pPre = m_pHead;
		m_pHead->m_pNext = m_pHead;
	}
public:


	List() //构造空的list
	{
		CreateHead();
	}

    List(size_t n, const T& val = T())//构造的list中包含n个值为val的元素
	{
		CreateHead();
		int i;
		for (i = 0; i < n; i++)
		{
			push_back(val);
		}

	}

	//List(const List& res) //拷贝构造函数
	//{
	//	CreateHead();
	//	insert(end(), res.begin(), res.end());
	//}

	List(iterator ﬁrst, iterator last) //用[ﬁrst, last]区间中的元素构造list
	{
		CreateHead();
		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}

	//~List()
	//{
	//	erase(begin(), end());
	//	delete m_pHead;
	//}


	void push_back(const T& val)
	{
		insert(begin(), val);
	}

	iterator begin()
	{
		return iterator(m_pHead->m_pNext);
	}

    iterator end()
	{
		return iterator(m_pHead->m_pPre);
	}

	const iterator cbegin()const
	{
		return iterator(m_pHead->m_pNext);
	}

	const iterator cend()const
	{
		return iterator(m_pHead->m_pPre);
	}
	iterator insert(iterator pos, const T& val)
	{
		m_pNode NewNode = new m_pNode;
		NewNode->m_val = val;
		NewNode->m_pNext = pos->m_pNode->m_pNode;
		NewNode->m_pPre = pos->m_pNode->m_pPre;
		pos->m_pNode->m_pPre= NewNode;
		NewNode->m_pPre->m_pNext = NewNode;
		return NewNode;
	}

	/*iterator insert(iterator pos, T * start, T * end)
	{
	
	}

	iterator insert(iterator pos, iterator start, iterator end)
	{
	
	}*/

};
