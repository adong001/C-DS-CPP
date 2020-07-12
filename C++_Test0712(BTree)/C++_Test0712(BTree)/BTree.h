#pragma once
#include<vector>
#include<time.h>

template<class K, size_t M = 3>
struct BTreeNode
{
	K m_keys[M];//次节点存储的值
	BTreeNode<K, M>* m_child[M + 1];//孩子节点个数
	BTreeNode<K, M>* m_parent;//父节点，有可能有两个父节点，只存比它小的那个
	size_t m_keysize;//次节点共有几个值

	BTreeNode()//构造函数
	{
		for (int i = 0; i < M; i++)
		{
			m_child[i] = nullptr;
		}
		m_parent = nullptr;
		m_keysize = 0;
	}
};

template<class K, size_t M>
class BTree
{
	typedef BTreeNode<K, M> Node;
private:
	Node* m_root;
public:
	/*BTree() :
		m_root(nullptr)
	{}*/
	/*查找函数，
	成功-first=父节点,	second=次节点在这一层的位置;
	失败-first=父节点,	second=-1;*/
	pair<Node*,int> Find(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = m_root;
		while (cur)
		{
			int i;
			for (i = 0; i < cur->m_keysize;)
			{
				if (key < cur->m_keys[i])//小于当前值，break，去左孩子找,
				{
					break;
				}
				else if (key > cur->m_keys[i])//大小与当前值,去当前值的下一个元素去找
				{
					++i;
				}
				else//找到了
				{
					return make_pair(cur, i);
				}
			}

			//当进左孩子或找到最后一个值还没找到时进入下一层
			parent = cur;
			cur = cur->m_child[i];
		}
		return make_pair(parent, -1);
	}

	void InsertKey(Node* node, const K& key, Node* child)//在node节点插入key
	{
		int end = node->m_keysize - 1;
		for (; end >= 0 && node->m_keys[end] > key; end--)//这个值比最后一个大，就把后面的向后挪
		{
			node->m_keys[end + 1] = node->m_keys[end];
			node->m_child[end + 2] = node->m_child[end + 1];
		}
		node->m_keys[end + 1] = key;//把大于key的挪后面去，end+1就空下了，自己顶上去
		node->m_child[end + 2] = child;
		if (child)
		{
			child->m_parent = node;
		}
		node->m_keysize++;

	}

	bool Insert(const K& key)//插入函数，
	{
		if (m_root == nullptr)//第一次插入，根为空
		{
			m_root = new Node;
			m_root->m_keys[0] = key;
			m_root->m_keysize = 1;
			return true;
		}
		pair<Node*, int> ret = Find(key);
		if (ret)//存在就不能再插入
		{
			return false;
		}

		Node* node = ret.first;
		K k = key;
		Node* child = nullptr;
		while (1)
		{
			InsertKey(node, key, child);//先插入，M阶我们开辟了M个值，可以存储M个值
			//，只要每次插入后就会判断是否需要分分裂，保证不会越界

			if (node->m_keysize < M)//没有超过每一个节点插入值的个数就插入成功
			{
				return true;
			}
			else//node->m_keysize == M,说明节点满了，需要分裂
			{

				int mid = M / 2;
				Node* newnode = new Node;
				int i;
				for (i = mid + 1; i < M; i++)//把右半部分拷贝到新节点中
				{
					newnode->m_keys[i - mid - 1] = node->m_keys[i];
					newnode->m_child[i - mid - 1] = node->m_child[i];//左孩子也拷贝过来
					if (node->m_child[i])
					{
						node->m_child[i]->m_parent = newnode->m_keys[i - mid - 1];//孩子认父亲
					}
					node->m_keys[i - mid - 1] = K();//该值挪走就置空
					node->m_child[i] = nullptr;//孩子挪走就置空
					node->m_keys[i - mid - 1] = nullptr;
					newnode->m_keysize++;
				}
				newnode->m_child[i - mid - 1] = node->m_child[i];//最后一个右孩子孩子坐标为M
				if (node->m_child[i])
				{
					node->m_child[i]->m_parent = newnode->m_keys[i - mid - 1];//孩子认父亲
				}
				node->m_child[i] = nullptr;//孩子挪走就置空
				node->m_keysize -= (newnode->m_keysize + 1);

				//第mid个值要拿到parent上去，有两种情况，
				if (node->m_parent == nullptr)//父节点为空
				{
					m_root = new Node;
					m_root->m_keys[0] = node->m_keys[mid];//第mid个值要拿到parent第一个值上
					m_root->m_child[0] = node;//父节点左孩子是当前节点
					m_root->m_child[1] = newnode;//右孩子是分裂出来的节点
					node->m_parent = newnode->m_parent = m_root;
					node->m_keys[mid] = K();//该节点挪走就置空
					return true;
				}
				else//父节点不为空，就相当于给父节点插入一个值为node->m_keys[mid]的孩子
				{
					//使用迭代，node变成父节点，child父节点左孩子，循环上去，就是给node插入k
					k = node->m_keys[mid];
					child = newnode;
					node = node->m_parent;
				}
			}
		}
		return true;
	}

	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
		{
			return;
		}
		int i = 0;
		for (; i < cur->m_keysize;i++)//
		{
			_InOrder(cur->m_child[i]);//先遍历左子树
			cout << cur->m_keys[i] << " ";//输出自己
		}
		_InOrder(cur->m_child[i]);//遍历最后一个值的右子树
	}

	void InOrder()
	{
		_InOrder(m_root);
		cout << endl;
	}
};

