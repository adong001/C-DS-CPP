#pragma once
#include"TreeNode.h"
template<class T>
class Tree
{
private:
	TreeNode<T>* m_root;
	TreeNode<T>* MakeTree(TreeNode<T>* root,T* src,T& flag,size_t count)
public:
	Tree(T* src = nullptr,T& flag) //¹¹Ôìº¯Êý
	{
		if (!src)
		{
			m_root = nullptr;
		}
		else
		{
			m_root = MakeTree(m_root, src, flag, 0);
		}
	}

};