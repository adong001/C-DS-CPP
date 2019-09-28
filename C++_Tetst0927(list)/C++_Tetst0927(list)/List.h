#pragma once
#include<iostream>
//#include"ListNode.h"
#include"Iterator.h"

using namespace std;
template<class T>
class ListNode;

template<class T>   
class List
{
private:
	typedef ListNode<T> m_Node;
	typedef m_Node* m_PNode;
	m_PNode m_pHead;   
public:
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T&> const_iterator;
	List(); //构造空的list
	List(size_type n, const value_type& val = value_type()); //构造的list中包含n个值为val的元素
	List(const List& x); //拷贝构造函数
	List(ListIterator ﬁrst, ListIterator last) //用[ﬁrst, last]区间中的元素构造list
	void CreateHead();
	void push_back(const T& val);

};
