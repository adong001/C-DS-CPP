#pragma once
#include<vector>
#include<queue>
#include<stack>
#include"TreeNode.h"

template<class T>
class Tree
{
private:
	TreeNode<T>* m_root;
	static TreeNode<T>* MakeTree(const T* src, const T& flag, size_t& count)//创建一个树
	{
		TreeNode<T>* root;
		if (src[count] == flag)
		{
			count++;     //count做成&后，函数结束后，count依然会继承上次修改的值
			return nullptr;
		}
		root = new TreeNode<T>(src[count]);
		count++;
		root->m_left = MakeTree(src, flag, count);
		root->m_right = MakeTree(src, flag, count);
		return root;
	}

public:
	Tree() :
		m_root(nullptr)
	{}
	Tree(const T* src, T& flag) //构造函数
	{
		if (!src)
		{
			m_root = nullptr;
		}
		else
		{
			size_t i = 0;
			m_root = MakeTree(src, flag, i);
		}
	}

	int PreOrder()//先序非递归
	{
		TreeNode<T>* cur = m_root;s
		vector<T> vres;
		stack<TreeNode<T>*> stmp;
		if (!cur)
		{
			return vres;
		}

		while (cur)
		{
			vres.push_back(cur->val);//将根的值push进容器中

			if (cur->right)//右孩子存在，右孩子入栈，右孩子最后访问，放在栈底
			{
				stmp.push(cur->right);
			}

			if (cur->left)//左孩子存在,左孩子入栈
			{
				stmp.push(cur->left);
			}

			if (!stmp.empty())//栈不为空时访问
			{
				cur = stmp.top();//取栈顶访问
				stmp.pop();//取完栈顶pop掉栈顶元素
			}

			else //栈为空，说明左右孩子都没有，直接给其置空，退出循环
			{
				cur = nullptr;
			}
		}
		return vres;
	}

	//vector<T> PreOrder_Recursive()//先序递归版
	//{
	//	static vector<T> res;
	//	if (m_root)
	//	{
	//		res.push_back(m_root->val);
	//		PreOrder_Recursive(m_root->left);
	//		PreOrder_Recursive(m_root->right);
	//	}
	//	return res;
	//}


	//vector<T> InOrder()//中序遍历
	//{
	//	TreeNode<T>* cur = m_root;
	//	vector<T> vres;
	//	stack<TreeNode<T>*> stmp;

	//	if (!cur)
	//	{
	//		return vres;
	//	}
	//	stmp.push(cur);

	//	while (cur || !stmp.empty())//根和栈都为空时跳出
	//	{
	//		for (; cur && cur->left; cur = cur->left)//先把左孩子都入栈
	//		{
	//			stmp.push(cur->left);
	//		}

	//		if (!stmp.empty())//栈不为空，取栈顶，push进vres，并pop.
	//		{
	//			cur = stmp.top();
	//			vres.push_back(cur->val);
	//			stmp.pop();
	//		}

	//		else //若栈为空，说明树的根节点左孩子已访问完毕，直接给vres push进根的值，访问右孩子
	//		{
	//			vres.push_back(cur->val);
	//		}

	//		cur = cur->right;//进入左孩子
	//		if (cur) //右孩子入不为空，先把右孩子的根push进，否则
	//		{
	//			stmp.push(cur);
	//		}
	//	}
	//	return vres;

	//}
	//vector<T> InOrder_Recursive()//中序递归版
	//{
	//	static vector<T> vres;
	//	if (root)
	//	{
	//		InOrder_Recursive(m_root->left);
	//		vres.push_back(m_root->val);
	//		InOrder_Recursive(m_root->right);
	//	}
	//	return vres;
	//}

};
