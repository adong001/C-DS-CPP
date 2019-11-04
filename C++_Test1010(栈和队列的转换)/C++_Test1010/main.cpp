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




