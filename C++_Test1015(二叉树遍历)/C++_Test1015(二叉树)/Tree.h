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
	TreeNode<T>* MakeTree(TreeNode<T>* root, T* src, T& flag, size_t count)//创建一个树
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
			m_root = MakeTree(m_root, src, flag, 0);
		}
	}

	vector<T> PreOrder()//先序非递归
	{
		TreeNode* cur = m_root;
		vector<T> vres;
		stack<TreeNode<T>*> stmp;
		if (!cur)
		{
			return vres;
		}

		stmp.push(cur);//把根先压进去

		do{
			vres.push_back(cur->val);

			if (cur->right)//右孩子存在，右孩子入栈
			{
				stmp.push(cur->right);
			}

			if (cur->left)//左孩子存在，左孩子的值push进容器中,左孩子入栈
			{
				stmp.push(cur->left);
			}

			cur = stmp.top();//取栈顶访问
			stmp.pop();//取完栈顶pop掉栈顶元素
		} while (cur != root);//出栈至只有一个根时，退出
		return vres;
	}

	vector<T> PreOrder_Recursive()//先序递归版
	{
		static vector<T> res;
		if (m_root)
		{
			res.push_back(m_root->val);
			PreOrder_Recursive(m_root->left);
			PreOrder_Recursive(m_root->right);
		}
		return res;
	}


	vector<T> InOrder()//中序遍历
	{
		TreeNode<T>* cur = m_root;
		vector<T> vres;
		stack<TreeNode<T>*> stmp;

		if (!cur)
		{
			return vres;
		}
		stmp.push(cur);

		while (cur || !stmp.empty())//根和栈都为空时跳出
		{
			for (; cur && cur->left; cur = cur->left)//先把左孩子都入栈
			{
				stmp.push(cur->left);
			}

			if (!stmp.empty())//栈不为空，取栈顶，push进vres，并pop.
			{
				cur = stmp.top();
				vres.push_back(cur->val);
				stmp.pop();
			}

			else //若栈为空，说明树的根节点左孩子已访问完毕，直接给vres push进根的值，访问右孩子
			{
				vres.push_back(cur->val);
			}

			cur = cur->right;//进入左孩子
			if (cur) //右孩子入不为空，先把右孩子的根push进，否则
			{
				stmp.push(cur);
			}
		}
		return vres;

	}
	vector<T> InOrder_Recursive()//中序递归版
	{
		static vector<T> vres;
		if (root)
		{
			InOrder_Recursive(m_root->left);
			vres.push_back(m_root->val);
			InOrder_Recursive(m_root->right);
		}
		return vres;
	}

};
