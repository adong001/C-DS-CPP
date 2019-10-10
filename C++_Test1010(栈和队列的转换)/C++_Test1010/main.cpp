#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//1.用两个队列实现一个栈
template<class T>
class Stack
{
private:
	queue<T> queue1;
public:
	void push(T x)
	{
		queue1.push(x);
	}

	void pop()
	{
		queue<T> queue2;
		while (queue1.size() > 1)
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		queue1 = queue2;
	}

	T& top()
	{
		return queue1.back();
	}

	bool empty()
	{
		return queue1.empty();
	}

	size_t size()
	{
		return queue1.size();
	}
};

int main1()
{
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.pop();
	st.push(3);
	st.push(4);
	st.pop();
	cout << st.top() << endl;
	return 0;
}



//2.用两个栈实现一个队列
template<class T>
class Queue
{
private:
	stack<T> st1;
public:
	void push(T x)
	{
		st1.push(x);
	}

	void pop()
	{
		stack<T> tmp;
		stack<T> st2;

		while (st1.size() > 1)
		{
			st2.push(st1.top());//将st1中的数据逆序入栈进st2
			st1.pop();
		}
		st1.pop();//将st1清空；

		while (!st2.empty())
		{
			st1.push(st2.top());//再将st2的数据逆序入栈进st1,此时的st1已经pop掉第一个元素。
			st2.pop();
		}
	}

	T& front()
	{
		T res;
		stack<T> tmp;
		tmp = st1;

		while (st1.size() > 1)
		{
			st1.pop();
		}
		res = st1.top();//记录front的值

		st1 = tmp;
		return res;
	}

	T& back()
	{
		return st1.top();
	}

	bool empty()
	{
		return st1.empty();
	}

	size_t size()
	{
		return st1.size();
	}

};
int main2()
{
	Queue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.pop();
	cout << qu.front() << endl;
	qu.push(3);
	qu.push(4);
	qu.push(5);
	qu.pop();
	cout << qu.back() << " " << qu.front() << endl;
	system("pause");
	return 0;
}

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


int main()
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