//#pragma once
//#include"ListNode.h"
//template<class T, class Ref, class Ptr>// T T* T&
//class ListIterator
//{
//private:
//	typedef ListNode<T>* m_PNode;
//	typedef ListIterator<T, Ref, Ptr> m_Self;
//	m_PNode m_pNode;
//public:
//	ListIterator(m_PNode pNode = nullptr) :
//		m_pNode(pNode)
//	{}
//
//	ListIterator(const m_Self& res) :
//		m_pNode(res.m_pNode)
//	{}
//
//	T& operator*();
//	T* operator->();
//	Self& operator++();
//	Self operator++(int);
//	Self& operator--();
//	Self& operator--(int);
//	bool operator!=(const Self& l);
//	bool operator==(const Self& l);
//};