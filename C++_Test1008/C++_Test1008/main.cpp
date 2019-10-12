#include<iostream>
#include<stack>
using namespace std;

//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//
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


/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/


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
	MinStack minStack ;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-5);
	minStack.push(10);
	minStack.push(8);
	minStack.push(-10);
	cout << minStack.getMin() << endl;  // --> 返回 - 10.
	minStack.pop();
	cout << minStack.top()<< endl;  //  --> 返回 8.
	cout << minStack.getMin() << endl;  // --> 返回 - 5.

    system("pause");
    return 0;
}