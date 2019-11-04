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

		while (!qtmp.empty())
		{
			cur = qtmp.front();
			qtmp.pop();
			vres.push_back(cur->m_val);
			if (cur->m_left)
			{
				qtmp.push(cur->m_left);
			}

			if (cur->m_right)
			{
				qtmp.push(cur->m_right);
			}
		}
		return vres;

	}

	size_t TreeDepth()//求树的深度,需要递归，就得传参，只能重载一个函数封装一下
	{
		return TreeDepth(m_root);
	}

	size_t TreeDepth(TreeNode<T>* root)//求树的深度
	{
		if (!root)
		{
			return 0;
		}
		int LeftChildDepth = TreeDepth(root->m_left);
		int RightChildDepth = TreeDepth(root->m_right);
		return LeftChildDepth > RightChildDepth ? LeftChildDepth + 1 : RightChildDepth + 1;
	}
	// 递归实现层序遍历
	//由于层序遍历是一种广度优先的遍历，所以我们需要通过层数控制整个函数的运行
	//每轮循环传入要输出的层数
	//然后当层数不等于0时，向下递归，每次递归层数减一
	//当层数等于0的时候，则说明已经到达了要输出的那一层，递归的结束条件就满足了，直接输出值即可
	//vector<T> LevelOrder_Recursive()
	//{
	//	size_t LevelNum = TreeDepth();
	//	vectoc<T> vres;
	//	vres = LevelOrder_Recursive(m_root, LevelNum,vres);
	//	return vres;
	//}

	//vector<T> LevelOrder_Recursive(TreeNode<T>* root, int LevelNum, vector<T> vtmp)
	//{
	//	vector<T> vres = vtmp;
	//	if (!root)
	//	{
	//		vres.push_back(root->m_val);//根不为空，先把根push进去
	//        if(LevelNum > 1)
	//		{
	//			LevelOrder_Recursive(root->m_left, LevelNum - 1, vres);
	//			LevelOrder_Recursive(root->m_right, LevelNum - 1,vres);
	//		}
	//	}
	//	return vres;
	//}

	vector<int> LevelNodeNums()//求每层节点个数
	{
		queue<TreeNode<T>*> qtmp;
		vector<int> vres;//模板特换为int，存节点个数
		if (!m_root)
		{
			return vres;
		}
		int length = 1;
		TreeNode<T>* cur = m_root;
		qtmp.push(cur);//先将根节点push进去
		while (!qtmp.empty())
		{
			vres.push_back(length);
			for (int i = 0; i < length; i++)
			{
				cur = qtmp.front();
				qtmp.pop();
				if (cur->m_left)
				{
					qtmp.push(cur->m_left);
				}

				if (cur->m_right)
				{
					qtmp.push(cur->m_right);
				}
			}//for循环结束，就代表一层结束
			length = qtmp.size();
		}
		return vres;
	}

	vector<T> LevelNodeMax()//求每层节点的最大值
	{
		queue<TreeNode<T>*> qtmp;
		vector<T> vres;
		T Max;
		int length = 1;
		TreeNode<T>* cur = m_root;
		if (!m_root)
		{
			return vres;
		}
		qtmp.push(cur);//先将根节点push进去

		while (!qtmp.empty())
		{
			Max = qtmp.front()->m_val;
			for (int i = 0; i < length; i++)//length为这层的节点数，一个for循环为一层遍历
			{
				cur = qtmp.front();
				if (Max < qtmp.front()->m_val)
				{
					Max = qtmp.front()->m_val;
				}
				qtmp.pop();

				if (cur->m_left)
				{
					qtmp.push(cur->m_left);
				}

				if (cur->m_right)
				{
					qtmp.push(cur->m_right);
				}
			}//for循环结束，就代表一层结束
			vres.push_back(Max);
			length = qtmp.size();
		}
		return vres;
	}

	vector<T> LevelNodeAverage()//求每层节点的平均值
	{
		queue<TreeNode<T>*> qtmp;
		vector<T> vres;
		T sum = 0;//一层节点值的总和，类型有可能为int float ,double用模板
		T average;//一层节点平均值，这里使用模板类型，有其他需求可以改
		int length = 1;//一层节点个数
		TreeNode<T>* cur = m_root;

		if (!m_root)
		{
			return vres;
		}

		qtmp.push(cur);//先将根节点push进去

		while (!qtmp.empty())
		{
			for (int i = 0; i < length; i++)//length为这层的节点数，
			{
				cur = qtmp.front();
				sum += qtmp.front()->m_val;//将这层的所有结点值相加
				qtmp.pop();

				if (cur->m_left)
				{
					qtmp.push(cur->m_left);
				}

				if (cur->m_right)
				{
					qtmp.push(cur->m_right);
				}
			}//for循环结束，就代表一层结束
			average = sum / length;//求这层平均值
			sum = 0; //sum 清0，为下一层做准备
			vres.push_back(average);
			length = qtmp.size();//队列的长度就是下一层结点的个数
		}
		return vres;
	}


	//操作给定的二叉树，将其变换为源二叉树的镜像。
	//void  Mirror(TreeNode<T>* root)//递归版
	//{
	//	if (!root)
	//	{
	//		return;
	//	}


	//}

	void  Mirror()//非递归版
	{
		queue<TreeNode<T>*> qtmp;
		if (!m_root)
		{
			return ;
		}
		TreeNode<T>* cur = m_root;
		qtmp.push(cur);//先将根节点push进去
		while (!qtmp.empty())
		{
			cur = qtmp.front();
			swap(cur->m_left, cur->m_right);
			qtmp.pop();
			if (cur->m_left)
			{
				qtmp.push(cur->m_left);
			}

			if (cur->m_right)
			{
				qtmp.push(cur->m_right);
			}
		}
	}

	TreeNode<T>* lowestCommonAncestor(TreeNode<T>* p, TreeNode<T>* q)//最小公共祖先节点
	{
		TreeNode<T>* cur = m_root;
		stack<TreeNode<T>*> stmp;
		stack<bool> tag;
		stack<TreeNode<T>*> s1;
		stack<TreeNode<T>*> s2;
		//此方法利用后序遍历 孩子比祖先先出的特点
		if (!cur && !p && !q)
		{
			return nullptr;
		}

		do
		{
			for (; cur; cur = cur->m_left)//进所有的左孩子
			{
				stmp.push(cur);
				tag.push(false);//访问标志位置false
			}

			while (!stmp.empty() && tag.top())
			{
				cur = stmp.top();//找到这个节点时，让这个s1栈等于这个stmp栈，他记录了从根节点到p节点的路径
				//同样的方法,使s2栈也等于stmp,记录从根节点到q节点的路径
				if (p == cur || q == cur)//s1和s2是节点的地址，所以是唯一的，不用担心重复
				{
					if (s1.empty())//谁为空给谁
					{
						s1 = stmp;
					}

					else
					{
						s2 = stmp;
					}
				}
				stmp.pop();
				tag.pop();
			}

			if (!stmp.empty())
			{
				cur = stmp.top()->m_right;
				tag.top() = true;
			}
		} while (!stmp.empty());

		if (s1.size() < s2.size())//使s1作为一个长的栈
		{
			swap(s1, s2);
		}

		int i;
		int len = s1.size() - s2.size();
		for (i = 0; i < len; i++)//让两个对其
		{
			s1.pop();
		}
		while (s1.top() != s2.top())//两个长度相等，找相同的那个祖先就好了
		{
			s1.pop();
			s2.pop();
		}
		return s1.top();
	}
};
