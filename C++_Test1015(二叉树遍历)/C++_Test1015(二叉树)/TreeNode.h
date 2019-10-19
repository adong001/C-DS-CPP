#pragma once
#include"Tree.h"

template<class T>
class Tree;
template<class T> //节点模板类
class TreeNode
{
private:
	T m_val;
	TreeNode<T>* m_left;
	TreeNode<T>* m_right;
public:
	TreeNode(const T& val = 0) :
		m_val(val),
		m_left(nullptr),
		m_right(nullptr)
	{}
	template<class T>
	friend class Tree;
};
