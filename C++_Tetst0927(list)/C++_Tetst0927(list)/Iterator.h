#pragma once
#include"ListNode.h"

template<class T>
class ListIterator
{
private:
	typedef ListNode<T>* m_PNode;
	m_PNode m_pNode;
public:
	ListIterator(m_PNode pNode = nullptr) :
		m_pNode(pNode)
	{}

	ListIterator(const m_PNode& res) :
		m_pNode(res.m_pNode)
	{}

	T& operator*()
	{
		return m_pNode->m_val;
	}

	T* operator->()
	{
		return &(m_pNode->m_val);
	}

	T& operator++()//前置++
	{
		m_pNode = m_pNode->m_pNext;
		return *this;
	}
	
	T& operator++(int)//后置++
	{
		m_PNode tmp = *this->m_pNode;
		*this->m_pNode = *this->m_pNode->m_pNext;
		 return tmp;
	}

	
	T& operator--()//前置--
	{
		m_pNode = m_pNode->m_pPre;
		return *this;
	}

	
	T& operator--(int)//后置--
	{
		m_PNode tmp = *this->m_pNode;
		*this->m_pNode = *this->m_pNode->m_pPre;
		return tmp;
	}

	
	bool operator != (const m_PNode& L)
	{
		return m_pNode != L;
	}

	
	bool operator == (const m_PNode& L)
	{
		return !(m_pNode != L);
	}
};