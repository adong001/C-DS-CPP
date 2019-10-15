#include"Tree.h"

template<class T>
TreeNode<T>* Tree<T>::MakeTree(TreeNode<T>* root, T* src, T& flag, size_t count)
{
	TreeNode<T>* cur = root;

	if (src[count] == flag)
	{
		return nullptr;
	}
	root = new TreeNode<T>;
	root->m_val = src[count];
	count++;
	root->m_left = MakeTree(root->m_left, src, flag, count); 
	cout++;
	root->m_right = MakeTree(root->m_right, src, flag, count);
	return cur;
}