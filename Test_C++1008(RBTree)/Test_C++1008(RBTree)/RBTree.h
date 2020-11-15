#pragma once 
#include<map>
namespace YD
{
	enum Color{ RED, BLACK };

	//节点类
	template<class T>
	class RBTreeNode
	{
	private:
		T m_data;
		RBTreeNode<T>* m_lchild;
		RBTreeNode<T>* m_rchlid;
		RBTreeNode<T>* m_parent;
		Color m_color;
	public:
		RBTreeNode(const T& val = T(), Color color = RED) :
			m_color(color),
			m_data(val),
			m_lchild(nullptr),
			m_rchlid(nullptr),
			m_parent(nullptr)
		{}
		template<class T>
		friend class RBTree;
	};

	template<class T>
	class RBTree
	{
	private:
		RBTreeNode<T>* m_head;//head节点的父节点指向root，root的父节点指向head
		size_t m_size;

		//左旋
		void lRound(RBTreeNode<T>* pre)
		{
			RBTreeNode<T>* parent = pre->m_parent;
			RBTreeNode<T>* cur = pre->m_rchlid;
			cur->m_parent = parent;
			//1.和父节点建立关系
			//要旋转的父节点不是head
			if (parent != m_head)
			{
				if (parent->m_lchild == pre)//pre是父节点的左孩子
				{
					parent->m_lchild = cur;
				}
				else
				{
					parent->m_rchlid = cur;
				}
			}
			else
			{
				//父节点是head,就直接对head操作
				m_head->m_parent = cur;
				cur->m_parent = m_head;
			}

			//2.交换孩子，cur被左旋上去，作为pre的父节点，
			//pre成为cur的做左孩子，cur的左孩子成为pre的右孩子
			pre->m_rchlid = cur->m_lchild;
			if (cur->m_lchild)
			{
				//孩子认父亲
				cur->m_lchild->m_parent = pre;
			}
			cur->m_lchild = pre;
			pre->m_parent = cur;
		}

		//右旋
		void rRound(RBTreeNode<T>* pre)
		{
			RBTreeNode<T>* parent = pre->m_parent;
			RBTreeNode<T>* cur = pre->m_rchlid;
			cur->m_parent = parent;

			if (parent != m_head)
			{
				if (pre == parent->m_lchild)
				{
					parent->m_lchild = cur;
				}
				else
				{
					parent->m_rchlid = cur;
				}
			}
			else
			{
				m_head->m_parent = cur;
				cur->m_parent = m_head;
			}

			pre->m_lchild = cur->m_rchlid;
			if (cur->m_rchlid)
			{
				cur->m_rchlid->m_parent = pre;
			}
			cur->m_rchlid = pre;
			pre->m_parent = cur;
		}

		//销毁树
		void destory(RBTreeNode<T>* root)
		{
			if (root)
			{
				destory(root->m_lchild);
				destory(root->m_rchlid);
				delete root;
			}
		}

		//获得根节点
		RBTreeNode<T>* &getRoot()
		{
			return m_head->m_parent;
		}


		//调整3，4，5种情况
		void Adjust(RBTreeNode<T>*& parent, RBTreeNode<T>*& cur)
		{
			RBTreeNode<T>* grand = parent->m_parent;
			RBTreeNode<T>* uncle;
			//情况3. 4.1 5.1 左左，左右
			if (parent == grand->m_lchild)
			{
				//只要没找到根节点，或者父节点不为黑就必须一直向上调整
				while (parent != m_head && parent->m_color == RED)
				{
					grand = parent->m_parent;
					uncle = grand->m_rchlid;
					//情况3：父红，叔红，爷黑
					if (uncle && uncle->m_color == RED)
					{
						//调整为父叔黑，爷红，从爷位置继续向上调
						parent->m_color = BLACK;
						uncle->m_color = BLACK;
						grand->m_color = RED;
						cur = grand;
						parent = cur->m_parent;
					}
					//情况4，5
					else
					{
						//情况5.1：左右
						if (cur == parent->m_rchlid)
						{
							//一次左旋，变成左左，变成情况4.1
							lRound(parent);
							RBTreeNode<T>* tmp = parent;
							parent = cur;
							cur = tmp;
						}
						//情况4.1;左左，一次右旋，父变黑，爷变红
						rRound(grand);
						parent->m_color = BLACK;
						grand->m_color = RED;
						//情况4，5只需一次调整
						break;
					}
				}
			}
				//情况3 4.2. 5.2 右右，右左
			else
			{
				//只要没找到根节点，或者父节点不为黑就必须一直向上调整
				while (parent != m_head && parent->m_color == RED)
				{
					grand = parent->m_parent;
					uncle = grand->m_lchild;
					//情况3：父红，叔红，爷黑
					if (uncle && uncle->m_color == RED)
					{
						//调整为父叔黑，爷红，从爷位置继续向上调
						parent->m_color = BLACK;
						uncle->m_color = BLACK;
						grand->m_color = RED;
						cur = grand;
						parent = cur->m_parent;
					}
					//情况4，5
					else
					{
						//情况5.2：右左
						if (cur = parent->m_lchild)
						{
							//一次右旋，变成右右，变成情况4.2
							rRound(parent);
							RBTreeNode<T>* tmp = parent;
							parent = cur;
							cur = tmp;
						}
						//情况4.2;右右，一次左旋，父变黑，爷变红
						lRound(grand);
						parent->m_color = BLACK;
						grand->m_color = RED;
						//情况4，5只需一次调整
						break;
					}
				}
			}

		}

		static RBTreeNode<T> * increasement(RBTreeNode<T> * cur)
		{
			RBTreeNode<T> * tmp = cur;
			if (cur->m_right)
			{
				tmp = cur->m_right;
				for (; tmp->m_left; tmp = tmp->m_left);
			}
			else
			{
				tmp = tmp->m_parent;
				for (; cur != tmp->m_left && cur == tmp->m_right; tmp = tmp->m_parent)
				{
					cur = tmp;
				}
			}
			return tmp;
		}

		static RBTreeNode<T> * decreasement(RBTreeNode<T> * cur)
		{
			RBTreeNode<T> * tmp = cur;
			if (cur->m_left)
			{
				tmp = cur->m_left;
				for (; tmp->m_right; tmp = tmp->m_right);
			}
			else
			{
				tmp = tmp->m_parent;
				for (; cur != tmp->m_right && cur == tmp->m_left; tmp = tmp->m_parent)
				{
					cur = tmp;
				}
			}
			return tmp;
		}
		public:
			RBTree() :
				m_size(0)
			{
				m_head = new RBTreeNode<T>;
			}
			~RBTree()
			{
				m_size = 0;
				destory(m_head);
				m_head->m_lchild = m_head->m_rchlid = m_head->m_parent = nullptr;
			}

			size_t size()
			{
				return m_size;
			}

			bool empty()
			{
				return m_head->m_parent = nullptr;
			}

			//第一个孩子，最小值
			RBTreeNode<T>* FirstChild()
			{
				RBTreeNode<T>* cur = getRoot();
				for (; cur->m_lchild; cur = cur->m_lchild);
				return cur;
			}
			//最后一个孩子，最大值
			RBTreeNode<T>* LastChild()
			{
				RBTreeNode<T>* cur = getRoot();
				for (; cur->m_rchlid; cur = cur->m_rchlid);
				return cur;
			}

			RBTreeNode<T>* Find(const T& val)
			{
				RBTreeNode<T>* root = getRoot();
				if (root)
				{
					RBTreeNode<T>* cur = root;
					while (cur)
					{
						if (cur->m_data == val)
						{
							return cur;
						}
						else if (cur->m_data < data)
						{
							cur = cur->m_lchild;
						}
						else
						{
							cur = cur->m_rchlid;
						}
					}
					return nullptr;
				}
				return nullptr;
			}

			pair<RBTreeNode<T>*,bool> Insert(const T& val)
			{
				pair<RBTreeNode<T>*, bool> ret(nullptr, false);
				RBTreeNode<T>* & root = getRoot();
				//树不为空
				if (root)
				{
					RBTreeNode<T>* cur = root;
					RBTreeNode<T>* pre = nullptr;
					while (cur)
					{
						if (cur->m_data < val)
						{
							pre = cur;
							cur = cur->m_rchlid;
						}
						else if (cur->m_data > val)
						{
							pre = cur;
							cur = cur->m_lchild;
						}
						else//树中该值插入失败
						{
							ret.first = cur;
							return ret;
						}
					}

					cur = new RBTreeNode<T>(val);
					ret.first = cur;
					if (val < pre->m_data)
					{
						pre->m_lchild = cur;
					}
					else
					{
						pre->m_rchlid = cur;
					}
					cur->m_parent = pre;

					//开始调整红黑树
					//情况3.4.5
					if (pre->m_color == RED)
					{
						Adjust(pre, cur);
					}
					//情况2：父黑不会违反任何规则，直接插入
					else
					{
						//do nothing
					}

				}
				//情况1：树为空，插入的是根节点
				else
				{
					root = new RBTreeNode<T>(val, BLACK);
					root->m_parent = m_head;
					m_head->m_parent = root;
					ret.first = root;
				}
				root->m_color = BLACK;
				m_head->m_lchild = FirstChild();
				m_head->m_rchlid = LastChild();
				m_size++;
				ret.second = true;
				return ret;
			}

			bool erase(const T &val)
			{
				if (m_root == nullptr)
				{
					return false;
				}

				RBTreeNode<T> * cur = m_root;
				RBTreeNode<T> * pre = m_root;

				while (cur)
				{
					if (val < cur->m_data)
					{
						pre = cur;
						cur = cur->m_left;
					}
					else if (val > cur->m_data)
					{
						pre = cur;
						cur = cur->m_right;
					}
					else
					{
						break;
					}
				}

				if (cur == nullptr)
				{
					return false;
				}

				if (cur->m_left && cur->m_right)
				{
					RBTreeNode<T> * cur2 = cur->m_left;
					RBTreeNode<T> * pre2 = cur;

					if (cur2->m_right)
					{
						for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
						pre2->m_right = cur2->m_left;
						cur2->m_left = cur->m_left;
					}

					cur2->m_right = cur->m_right;

					if (cur == pre)
					{
						m_root = cur2;
					}
					else
					{
						if (cur->m_data < pre->m_data)
						{
							pre->m_left = cur2;
						}
						else
						{
							pre->m_right = cur2;
						}
					}

					delete cur;
				}
				else if (cur->m_left)
				{
					if (cur == pre)
					{
						m_root = cur->m_left;
					}
					else
					{
						if (cur->m_data < pre->m_data)
						{
							pre->m_left = cur->m_left;
						}
						else
						{
							pre->m_right = cur->m_left;
						}
					}
					delete cur;
				}
				else
				{
					if (cur == pre)
					{
						m_root = cur->m_right;
					}
					else
					{
						if (cur->m_data < pre->m_data)
						{
							pre->m_left = cur->m_right;
						}
						else
						{
							pre->m_right = cur->m_right;
						}
					}

					delete cur;
				}
			}
	};
};
