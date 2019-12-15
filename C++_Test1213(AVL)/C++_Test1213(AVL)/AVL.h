#pragma once




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
		int m_bf;//平衡因子
		TreeNode<T>* m_left;
		TreeNode<T>* m_right;
		TreeNode<T>* m_parent;
	public:
		TreeNode(const T& data = T()) :
			m_data(data),
			m_bf(0),
			m_left(nullptr),
			m_right(nullptr),
			m_parent(nullptr)
		{}
		template<class T>
		friend class AVLTree;
	};

	template<class T>
	class AVLTree
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

		void erase_node(TreeNode<T>* parent, TreeNode<T>* node)//删除节点函数,保证节点一定存在
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


		void LRound(TreeNode<T>* pre)//左旋
		{

			TreeNode<T>* parent = pre->m_parent;
			TreeNode<T>* cur = pre->m_right;//当需要左旋时找右孩子(pre->m_bf = 2 ,pre->m_right->m_bf = 1时才左旋调整)

			//第一步将自己的父亲和右孩子连接
			cur->m_parent = parent;

			if (parent)//如果父亲存在
			{
				//这里进来要判断pre是parent的左孩子还是右孩子
				if (parent->m_left == pre)//如果pre是父亲的左孩子，将父亲的左孩子与cur连接
				{
					parent->m_left = cur;
				}
				else//将cur挂到parent的右孩子上
				{
					parent->m_right = cur;
				}
			}

			else//如果父节点不存在，那么pre已经是根了,直接换根即可
			{
				m_root = cur;
			}

			//第二步，处理cur孩子的问题，因为cur要被旋上去，他的左孩子要指向pre,
			//之前的左孩子就得挂到pre的右孩子上(之前pre的右孩子是cur,
			//cur的左孩子小于cur但大于pre, 所以让其变成pre的右孩子)

			pre->m_right = cur->m_left;//父亲认儿子

			//儿子认父亲
			if (cur->m_left)//先要判断cur的左孩子是否存在
			{
				cur->m_left->m_parent = pre;
			}

			//第三步，处理cur和pre的关系，因为cur被旋了上去，现在cur是pre的父亲
			pre->m_parent = cur;
			cur->m_left = pre;

			//第四步，改变平衡因子
			//之所以要对pre和cur执行左旋，是因为在不插那个节点之前cur->m_bf = 0,pre->m_bf = 1,树平衡，
			//当cur的右孩子插入一个节点后，导致cur->m_bf  = 1,pre->m_bf = 2,需要调整pre和cur。
			//在调整完毕之后，cur的右孩子没变，但左孩子加了一个pre节点，使得cur->m_bf = 0
			//pre的左孩子没变,右孩子少了一个cur，使得pre->m_bf = 0

			cur->m_bf = pre->m_bf = 0;
		}

		void RRound(TreeNode<T>* pre)//右旋
		{
			//他跟左旋是镜像关系，所有的东西都是相反的

			TreeNode<T>* parent = pre->m_parent;
			TreeNode<T>* cur = pre->m_left;//当需要右旋时找左孩子(pre->m_bf = -2 ,pre->m_left->m_bf = -1时才左旋调整)

			//第一步将自己的父亲和左孩子连接
			cur->m_parent = parent;

			if (parent)//如果父亲存在
			{
				//这里进来要判断pre是parent的左孩子还是右孩子
				if (parent->m_left == pre)//如果pre是父亲的左孩子，将父亲的左孩子与cur连接
				{
					parent->m_left = cur;
				}
				else//将cur挂到parent的右孩子上
				{
					parent->m_right = cur;
				}
			}

			else//如果父节点不存在，那么pre已经是根了,直接换根即可
			{
				m_root = cur;
			}

			//第二步，处理cur孩子的问题，因为cur要被旋上去，他的右孩子要指向pre,
			//之前的右孩子就得挂到pre的左孩子上(之前pre的左孩子是cur,
			//cur的右孩子大于cur但小于pre, 所以让其变成pre的左孩子)

			pre->m_left = cur->m_right;//父亲认儿子

			//儿子认父亲
			if (cur->m_right)//先要判断cur的左孩子是否存在
			{
				cur->m_right->m_parent = pre;
			}

			//第三步，处理cur和pre的关系，因为cur被旋了上去，现在cur是pre的父亲
			pre->m_parent = cur;
			cur->m_right = pre;

			//第四步，改变平衡因子
			//之所以要对pre和cur执行右旋，是因为在不插那个节点之前cur->m_bf = 0,pre->m_bf = -1,树平衡，
			//当cur的左孩子插入一个节点后，导致cur->m_bf  = -1,pre->m_bf = -2,需要调整pre和cur。
			//在调整完毕之后，cur的左孩子没变，但右孩子加了一个pre节点，使得cur->m_bf = 0
			//pre的右孩子没变,左孩子少了一个cur，使得pre->m_bf = 0

			cur->m_bf = pre->m_bf = 0;
		}


		void LRRound(TreeNode<T>* pre)//先左再右旋
		{
			//先左旋变成左左，再右旋

			TreeNode<T>* left = pre->m_left; //先对pre的左孩子进行左旋操作
			TreeNode<T>* newroot = left->m_right;//经过两次旋转之后，pre的左孩子的右孩子将被旋到pre的位置

			int flag = newroot->m_bf;//记录pre左孩子的右孩子的平衡因子

			LRound(left);//先将pre的左孩子左旋，变成左左后
			RRound(pre);//再对pre右旋，就能使树恢复平衡

			if (flag == 1)//如果newroot节点之前的平衡因子是1，说明在newroot的右孩子插入了节点(或删除了左孩子的某个节点)，
				//左孩子高度比右孩子高度小1，导致其平衡因子变成1，
				//经过第一次对left(newroot->parent)的左旋之后,newroot的左孩子跑到了left的右孩子上，所以导致left的左孩子比右孩子低1。
				//再经过对pre的右旋之后，使newroot的右孩子挂到了pre的右孩子上,pre的高度平衡
			{
				left->m_bf = -1;  //左旋之后left和newroot的平衡因子都被置为0，现在因为将left的bf置为-1即可，
			}

			else if (flag == -1)//如果newroot节点之前的平衡因子是-1，说明在左孩子插入了节点(或删除了右孩子的某个节点)，
				//.......最后newroot的右孩子(右比左低1)经过两次旋转，挂到了pre的左孩子上
			{
				pre->m_bf = 1;
			}
			else//如果flag == 0时，说明newroot是新插入的节点，没有左右孩子，两次旋转之后，三个节点的bf都将置0
			{
				//do nothing
			}

		}

		void RLRound(TreeNode<T>* pre)//先右再左旋
		{
			//LRRound的镜像，左右取反
			//先右旋变成右右，再左旋

			TreeNode<T>* right = pre->m_right; //先对pre的右孩子进行右旋操作
			TreeNode<T>* newroot = right->m_left;//经过两次旋转之后，pre的右孩子的左孩子将被旋到pre的位置

			int flag = newroot->m_bf;//记录pre右孩子的左孩子的平衡因子

			RRound(right);//先将pre的右孩子右旋，变成右右后
			LRound(pre);//再对pre左旋，就能使树恢复平衡

			if (flag == 1)//如果newroot节点之前的平衡因子是1，说明在newroot的左孩子插入了节点(或删除了左孩子的某个节点)，
				//左孩子高度比右孩子高度小1，导致其平衡因子变成1，
				//经过第一次对right(newroot->parent)的右旋之后,newroot的右孩子跑到了right的左孩子上，所以导致right的左孩子比右孩子低1。
				//再经过对pre的左旋之后，使newroot的左孩子挂到了pre的右孩子上,pre的高度平衡
			{
				right->m_bf = -1;  //右旋之后right和newroot的平衡因子都被置为0，现在因为将right的bf置为-1即可，
			}

			else if (flag == -1)//如果newroot节点之前的平衡因子是-1，说明在左孩子插入了节点(或删除了右孩子的某个节点)，
				//.......最后newroot的右孩子(右比左低1)经过两次旋转，挂到了pre的左孩子上
			{
				pre->m_bf = 1;
			}
			else//如果flag == 0时，说明newroot是新插入的节点，没有左右孩子，两次旋转之后，三个节点的bf都将置0
			{
				//do nothing
			}

		}

		void ModifyBF(TreeNode<T>* cur,TreeNode<T>* pre)
		{
			while (pre)
			{
				//修改父节点平衡因子
				if (pre->m_left == cur)//cur被被插入到cur的左边
				{
					pre->m_bf--;
				}
				else//cur被插入到pre的右边
				{
					pre->m_bf++;
				}

				if (pre->m_bf == 0)//插入后父节点平衡因子 = 0
					//说明父节点另一个孩子存在，且树平衡，插入cur后
					//pre->bf = 0,意味着pre的高度没变，就不会影响上面节点的bf,无需调整，直接break
				{
					break;
				}

				else if (pre->m_bf == 1 || pre->m_bf == -1)
					//插入cur后pre的bf变为1或-1，说明pre节点原来的的左右高度是平衡的，cur插在了左右任意一边后，
					//pre的左右高度不相同，就会导致他的父节点高度改变一直向上遍历，直到根或者需要调整
				{
					cur = pre;
					pre = pre->m_parent;
				}

				else //若平衡因子绝对值大于1时，这是就要开始调整
				{
					if (pre->m_bf == 2)//右右 或 右左
					{
						if (pre->m_right->m_bf == 1)//右右
						{
							LRound(pre);//一次左旋解决问题
						}

						else//右左  、、睡到市成都市单词别开生面
						{
							RLRound(pre);//先右再左
						}
					}

					else
					{
						if (pre->m_left->m_bf == 1)//左左
						{
							RRound(pre);//一次右旋解决问题
						}

						else//左右
						{
							LRRound(pre);//先左再右
						}

					}
					break;//旋转完后树已经平衡，直接break
				}

			}
		}

	public:

		AVLTree() :
			m_root(nullptr)
		{}

		~AVLTree()
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
			cur->m_parent = pre;

			/*******************以下内容为修改平衡因子*********************/

			ModifyBF(cur, pre);

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

		vector<T> InOrderTree()//中序遍历
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