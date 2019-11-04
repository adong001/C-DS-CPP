#include<iostream>
#include<typeinfo>
#include"seqlish.h"
using namespace std;

class Heap
{
private:
	int m_a;
	Heap() :
		m_a(0)
	{}
public:
	static Heap* HeapOnly();
};

Heap* Heap::HeapOnly()
{
	Heap *hp = new Heap;
	return hp;
}


class Stack
{
private:
	int m_a;
	Stack() :
		m_a(0)
	{}
public:
	static Stack StackOnly();
};

Stack Stack::StackOnly()
{
	Stack st;
	return st;
}

template<typename T> //template<class T>typename和class可替换
void Swap(T& left, T& right) 
{
	
	T temp = left;  
	cout << typeid(temp).name() << endl; 
	left = right;   
	right = temp; 
}

void Swap(int & left, int & right)//传入int时先调用这个函数，否则调用模板
{

	int temp = left;
	left = right;
	right = temp;
}

template<typename T>
int FindVlaue(T *ar, size_t size, T value)
{
	for (int i = 0; i < size; i++)
	{
		if (value == ar[i])
		{
			return i;
		}
	}
	return -1;
}

template<class T>
class Test
{
	T m_a;
public:
	Test(T s) :
		m_a(s)
	{}
	void show()
	{
		cout << m_a << endl;
	}
};

int main()
{
	Test<int>a(10);
	a.show();
	//int ia = 10, ib = 20;
	//double da = 3.14, db = 6.18;
	//Swap(ia,ib);
	////Swap<int>(ia, ib);//指定模板类型(只能调用模板函数)//显示实例化
	//cout << ia << " " << ib << endl;
	//Swap(da, db);//隐式实例化
	//cout << da << " " << db << endl;
	//Heap::HeapOnly();//堆上的对象
	//Stack::StackOnly();//栈上创建对象
	system("pause");
	return 0;
}