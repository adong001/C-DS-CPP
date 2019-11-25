
#include<stack>
#include<vector>

namespace YD
{
	template<class T>
	class TreeNode
	{
	private:
		T m_data;
		TreeNode<T>* m_left;
		TreeNode<T>* m_right;
	public:
		TreeNode(const T& data = T()) :
			m_data(data),
			m_left(nullptr),
			m_right(nullptr)
		{}
		template<class T>
		friend class Tree;
	};

	template<class T>
	class Tree
	{
	private:
		TreeNode<T>* m_root;
		void Destory(TreeNode<T>* root)
		{
			if (root)
			{
				Destory(root->m_left);
				Destory(root->m_right);
				delete root;
			}
		}

		void erase_root(TreeNode<T>* parent, TreeNode<T>* node, const int& status)//删除节点函数,保证节点一定存在
		{
			TreeNode<T>* cur = node;

			if (!cur->m_left && !cur->m_right)//左右孩子都不存在，直接删除
			{
				delete cur;
				cur = nullptr;
			}

			else if (!cur->m_left)//左孩子为空
			{
				delete cur;
				cur = cur->m_right;
			}

			else if (!cur->m_right)//右孩子为空
			{
				delete cur;
				cur = cur->m_left;
			}

			else//左右孩子都存在
			{
				TreeNode<T>* tmp = node->m_right;
				cur = node->m_left;

				for (; tmp->m_left; tmp = tmp->m_left);//找到根节点右孩子中最小的(也就是根节点右孩子中一直找到左孩子为空为止)

				tmp->m_left = cur->m_right;//右边中的最小值的左孩子指向  左边孩子中的最大值
				cur->m_right = node->m_right;//右孩子继承删除节点的右孩子
				delete node;
			}

			if (parent == m_root)//删的是根节点
			{
				parent = cur;
			}

			else if (status == true)//删的是parent的左孩子
			{
				parent->m_left = cur;
			}
			else
			{
				parent->m_right = cur; // 删的是parent的右孩子，让其父节点指向新的节点
			}

		}

	public:

		Tree() :
			m_root(nullptr)
		{}

		~Tree()
		{
			Destory(m_root);
		}

		bool Find(TreeNode<T>* parent, TreeNode<T>* node, bool& status, const T& val)//
		{
			parent = node = m_root;
			if (parent->m_data == val)//val的值为根节点时
			{
				return true;
			}

			//status代表找到目标节点node是父节点parent的左孩子还是右孩子的标志位（true---左孩子， false---右孩子）

			while (node)
			{
				if (node->m_data == val)//找到返回
				{
					break;
				}

				else
				{
					parent = node;//没找到跟新父节点，继续找
				}

				if (parent->m_data > val)//大于当前节点往左孩子里找
				{
					node = parent->m_left;
					status = true;
				}

				else if (parent->m_data < val)//小于当前节点往右孩子里找
				{
					node = parent->m_left;
					status = false;
				}
			}

			if (!node)//找到的节点为空，返回false
			{
				return false;
			}
			return true;
		}

		TreeNode<T>* Find(const T& val)
		{
			if (!m_root)
			{
				return nullptr;
			}

			TreeNode<T>* cur = m_root;

			while (cur)
			{
				if (cur->m_data == val)//找到返回
				{
					return cur;
				}

				else if (cur->m_data > val)//val值小于当前节点值，往左边找
				{
					cur = cur->m_left;
				}

				else   //val值大于当前节点值，往右边找
				{
					cur = cur->m_right;
				}
			}
			return nullptr;
		}

		bool Insert(const T& val)
		{
			if (!m_root)
			{
				m_root = new TreeNode<T>(val);
				return true;
			}

			TreeNode<T>* cur = m_root;
			TreeNode<T>* pre = m_root;
			bool flag = false;//定义一个flag，往左边插为true,右边插为false

			while (cur)
			{
				if (cur->m_data == val)//有相同的值插入不成功
				{
					return false;
				}

				else if (cur->m_data > val)//val值小于当前节点值，往左边插
				{
					pre = cur;
					cur = cur->m_left;
					flag = true;
				}

				else   //val值大于当前节点值，往左边插
				{
					pre = cur;
					cur = cur->m_right;
					flag = false;
				}
			}

			cur = new TreeNode<T>(val);//此时找到的节点肯定是空的，他就必须插在这个位置

			if (flag)//往左边插
			{
				pre->m_left = cur;
			}
			else //往右边插
			{
				pre->m_right = cur;
			}
			return true;
		}



		bool erase(const T& val)
		{
			if (!m_root)
			{
				return false;
			}
			TreeNode<T>* parent = nullptr, *node = nullptr;
			bool status;

			if (!Find(parent, node, status, val))//先找到要删除的节点,找不到直接返回false
			{
				return false;
			}
#if 0
			
#else
			erase_root(parent, node, status);//删除那个节点即可，此时一定会保真删除成功
			return true;
#endif 

		}

		//vector<T> InOrderTree()
		//{
		//	vector<T> res;
		//	if (!m_root)
		//	{
		//		return res;
		//	}

		//	stack<TreeNode<T>*> st;
		//	TreeNode<T>* cur = m_root;
		//	while (cur || !st.empty())
		//	{
		//		for (; cur; cur = cur->m_left)
		//		{
		//			st.push(cur);
		//		}
		//		
		//		if (!st.empty())
		//		{
		//			cur = st.top();
		//			res.push_back(cur->m_data);
		//			st.pop();
		//			cur = cur->m_right;
		//		}
		//	}
		//	return res;
		//}


	};
};