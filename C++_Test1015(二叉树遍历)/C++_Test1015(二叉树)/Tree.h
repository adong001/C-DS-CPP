#pragma once
#include<vector>
#include<queue>
#include<stack>
#include"TreeNode.h"
using namespace std;


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

	TreeNode<T>* ReturnRoot()
	{
		return m_root;
	}

	vector<T> PreOrder()//先序非递归
	{
		TreeNode<T>* cur = m_root;
		vector<T> vres;
		stack<TreeNode<T>*> stmp;
		if (!cur)
		{
			return vres;
		}

		while (cur)
		{
			vres.push_back(cur->m_val);//将根的值push进容器中

			if (cur->m_right)//右孩子存在，右孩子入栈，右孩子最后访问，放在栈底
			{
				stmp.push(cur->m_right);
			}

			if (cur->m_left)//左孩子存在,左孩子入栈
			{
				stmp.push(cur->m_left);
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

	vector<T> PreOrder_Recursive(TreeNode<T>* root)//先序递归版
	{
		static vector<T> res;
		if (root)
		{
			res.push_back(root->m_val);
			PreOrder_Recursive(root->m_left);
			PreOrder_Recursive(root->m_right);
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
			for (; cur && cur->m_left; cur = cur->m_left)//先把左孩子都入栈
			{
				stmp.push(cur->m_left);
			}

			if (!stmp.empty())//栈不为空，取栈顶，push进vres，并pop.
			{
				cur = stmp.top();
				vres.push_back(cur->m_val);
				stmp.pop();
			}

			else //若栈为空，说明树的根节点左孩子已访问完毕，直接给vres push进根的值，访问右孩子
			{
				vres.push_back(cur->m_val);
			}

			cur = cur->m_right;//进入左孩子
			if (cur) //右孩子入不为空，先把右孩子的根push进，否则
			{
				stmp.push(cur);
			}
		}
		return vres;

	}
	vector<T> InOrder_Recursive(TreeNode<T>* root)//中序递归版
	{
		static vector<T> vres;
		if (root)
		{
			InOrder_Recursive(root->m_left);
			vres.push_back(root->m_val);
			InOrder_Recursive(root->m_right);
		}
		return vres;
	}

	vector<T> PostOrder()//后序非递归版
	{
		TreeNode<T>* cur = m_root;
		vector<T> vres;
		stack<TreeNode<T>*> stmp;
		stack<int> sflag;//访问标记位，1为左孩子已经访问，0为未访问左孩子

		if (!cur)
		{
			return vres;
		}
		do
		{	//过程1
			for (; cur; cur = cur->m_left)
			{
				stmp.push(cur);//把根及所有左孩子push进栈
				sflag.push(0);//访问标志位置0
			}
			//过程3
			while (!stmp.empty() && sflag.top())//栈不为空且访问标志位为1(左孩子已访问),开始打印,循环打印，直至栈为空或标志位为0时
			{
				cur = stmp.top();//取栈顶
				vres.push_back(cur->m_val);//push进vres
				stmp.pop();//pop掉栈顶
				sflag.pop();//这个节点左右孩子及自己都以访问完毕，标志位pop掉
			}

			//过程2
			if (!stmp.empty())//到这里时，说明没有左孩子了
			{
				cur = stmp.top();//取栈顶
				sflag.top() = 1;//没左孩子，标志位置为1
				cur = cur->m_right;//左孩子没有，访问右孩子
			}

		} while (!stmp.empty());
		return vres;
	}




	vector<T> PostOrder_Recursive(TreeNode<T>* root)//后序递归版
	{
		static vector<T> vres;
		if (root)
		{
			InOrder_Recursive(root->m_left);
			InOrder_Recursive(root->m_right);
			vres.push_back(root->m_val);
		}
		return vres;
	}

	vector<T> LevelOrder()//层序非递归版
	{
		queue<TreeNode<T>*> qtmp;
		vector<T> vres;
		if (!m_root)
		{
			return vres;
		}

		TreeNode<T>* cur = m_root;
		qtmp.push(cur);//先将根节点push进去

		while (cur)
		{

			vres.push_back(cur->m_val);
			if (cur->m_left)
			{
				qtmp.push(cur->m_left);
			}

			if (cur->m_right)
			{
				qtmp.push(cur->m_right);
			}

			qtmp.pop();
			if (!qtmp.empty())
			{
				cur = qtmp.front();
			}
			else
			{
				cur = nullptr;
			}
		}
		return vres;

	}
	vector<T> LevelOrder_Recursive(size_t LevelNodeNums, TreeNode<T>* root)//层序递归版
	{
		static vector<T> vres;
		size_t Num;//这层的节点数
		int count = 0;
		if (!root)
		{
			return vres;
		}
		vres.push_back(root->m_val);
		for (Num = 0; Num < LevelNodeNums; Num++)
		{
			if (root)
			{
				if (root->m_left->m_left)
				{
					count++;
				}
				if (root->m_left->m_right)
				{
					count++;
				}
				LevelOrder_Recursive(count, root->m_left);
				count = 0;
				if (root->m_right->m_left)
				{
					count++;
				}
				if (root->m_right->m_right)
				{
					count++;
				}
				LevelOrder_Recursive(count,root->m_right);
			}
		}
	return vres;
}
	/ 递归实现层序遍历
		//由于层序遍历是一种广度优先的遍历，所以我们需要通过层数控制整个函数的运行
		//每轮循环传入要输出的层数
		//然后当层数不等于0时，向下递归，每次递归层数减一
		//当层数等于0的时候，则说明已经到达了要输出的那一层，递归的结束条件就满足了，直接输出值即可
		void leavlOrder()
	{
			cout << "递归实现层序遍历:";
			int l = leavl(_root);
			for (int i = 0; i < l; ++i)
			{
				leavlOrder(_root, i);
			}
			cout << endl;
		}

	void leavlOrder(BSTNode *node, int l)
	{
		if (node != nullptr)
		{
			if (l == 0)
			{
				cout << node->_data << " ";
				return;
			}
			leavlOrder(node->_left, l - 1);
			leavlOrder(node->_right, l - 1);
		}
	}

};
