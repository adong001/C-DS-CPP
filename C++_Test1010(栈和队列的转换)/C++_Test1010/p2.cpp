
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
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
int p2()
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