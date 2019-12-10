#include<stack>
#include<vector>
#include <iostream>
using namespace std;

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

		void erase_node(TreeNode<T>*& parent, TreeNode<T>*& node)//删除节点函数,保证节点一定存在
		{

			if (!node->m_left && !node->m_right)//左右孩子都不存在，直接删除
			{
				delete node;
				node = nullptr;
			}

			else if (!node->m_left)//左孩子为空
			{
				if (parent == node)//删的是根
				{
					m_root = node->m_right;
				}
				else
				{
					if (parent->m_left == node)//将父亲的与自己的右孩子相连
					{
						parent->m_left = node->m_right;
					}
					else
					{
						parent->m_right = node->m_right;
					}
				}
				delete node;
			}

			else if (!node->m_right)//右孩子为空
			{
				if (parent == node)//删的是根
				{
					m_root = node->m_left;
				}
				else
				{
					if (parent->m_left == node)//将父亲的与自己的右孩子相连
					{
						parent->m_left = node->m_left;
					}
					else
					{
						parent->m_right = node->m_left;
					}
				}
				delete node;
			}

			else//左右孩子都存在
			{
				TreeNode<T>* tmp = node->m_right;
				TreeNode<T>* cur = node->m_left;

				for (; tmp->m_left; tmp = tmp->m_left);//找到根节点右孩子中最小的(也就是根节点右孩子中一直找到左孩子为空为止)

				tmp->m_left = cur->m_right;//右边中的最小值的左孩子指向  左边孩子中的最大值
				cur->m_right = node->m_right;//右孩子继承删除节点的右孩子

				if (parent == node)//删的是根
				{
					m_root = cur;
				}
				else
				{
					if (parent->m_left == node)//将父节点和新节点重新连接
					{
						parent->m_left = cur;
					}
					else
					{
						parent->m_right = cur;
					}
				}
				delete node;
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

		bool Find(TreeNode<T>* & parent, TreeNode<T>*& node, const T& val)//通过节点的值查找它的地址和父节点的地址
		{
			parent = node = m_root;
			if (node->m_data == val)//val的值为根节点时
			{
				return true;
			}

			while (node)
			{
				if (node->m_data == val)//找到返回
				{
					return true;
				}

				parent = node;//没找到跟新父节点，继续找

				if (parent->m_data > val)//大于当前节点往左孩子里找
				{
					node = parent->m_left;
				}

				else//小于当前节点往右孩子里找
				{
					node = parent->m_right;
				}

			}

			return false;
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

			while (cur)
			{
				if (cur->m_data == val)//有相同的值插入不成功
				{
					return false;
				}

				pre = cur;

				if (cur->m_data > val)//val值小于当前节点值，往左边插
				{
					cur = pre->m_left;
				}

				else   //val值大于当前节点值，往左边插
				{
					cur = pre->m_right;
				}
			}

			cur = new TreeNode<T>(val);//此时找到的节点肯定是空的，他就必须插在这个位置

			if (pre->m_data > cur->m_data)//往左边插
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

			if (!Find(parent, node, val))
				//先找到要删除的节点,找不到直接返回false,
				//找完后node指向要删的那个节点,parent指向他的父亲
			{
				return false;
			}

			erase_node(parent, node);//上面都已经保证这个节点存在，那就一定能删除成功！
			return true;
		}

		vector<T> InOrderTree()
		{
			vector<T> res;
			if (!m_root)
			{
				return res;
			}

			stack<TreeNode<T>*> st;
			TreeNode<T>* cur = m_root;

			while (cur || !st.empty())
			{
				for (; cur; cur = cur->m_left)
				{
					st.push(cur);
				}

				if (!st.empty())
				{
					cur = st.top();
					res.push_back(cur->m_data);
					st.pop();
					cur = cur->m_right;
				}
			}
			return res;
		}

	};
};