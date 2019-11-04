#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//BTNode* BinaryTreeCreate(BTDataType* src)//创建二叉树
//{
//	static int s_n = 0;
//	if (src[s_n] == '#')
//	{
//		s_n++;
//		return NULL;
//	}
//	BTNode *cur = (BTNode *)malloc(sizeof(BTNode));
//	cur->_data = src[s_n];
//	s_n++;
//	cur->lchild = BinaryTreeCreate(src);
//	cur->rchild = BinaryTreeCreate(src);
//	return cur;
//}
//
//void BinaryTreeDestory(BTNode* root)//后序遍历销毁
//{
//	if (root != NULL)
//	{
//		BinaryTreePostOrder(root->lchild);
//		BinaryTreePostOrder(root->rchild);
//		free(root);
//	}
//}
class MinStack
{
private:
	stack<int> m_Data;
	stack<int> m_MinData;
public:
	MinStack()
	{

	}

	void push(int x)
	{
		m_Data.push(x);
		if (m_MinData.size() < 1 || x < m_MinData.top())//MinData中没有数据或MinData的栈顶值大于x
		{
			m_MinData.push(x);
		}
	}

	void pop()
	{
		if (m_Data.top() <= m_MinData.top())
		{
			m_MinData.pop();
		}
		m_Data.pop();
	}

	int top()
	{
		if (m_Data.empty())
		{
			return INT_MAX;
		}
		return m_Data.top();
	}

	int getMin()
	{
		if (m_MinData.empty())
		{
			return INT_MAX;
		}
		return m_MinData.top();
	}
};
//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) --将元素 x 推入栈中。
//pop() --删除栈顶的元素。
//top() --获取栈顶元素。
//getMin() --检索栈中的最小元素。

//示例 :
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 - 3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 - 2.


int p1()
{
	MinStack minStack;
	minStack.push(-2);
	/*minStack.push(0);
	minStack.push(-3);*/
	cout << minStack.getMin() << endl;;
	minStack.pop();
	cout << minStack.top() << endl;;
	cout << minStack.getMin() << endl;;
	return 0;
}
