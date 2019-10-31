#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//隐藏 : 
// 条件：1.派生类继承基类
//       2.派生类与基类有重名成员或函数(非虚函数)
// 后果：1.基类的
//
class Base //基类
{
public:
	int m_a;//重名成员变量
	Base() :
		m_a(10)
	{}
	void func() //重名成员函数
	{
		cout << "Base" << endl;
	}

};


class Test :public Base //派生类
{
public:
	int m_a;//重名成员变量
	Test() :
		m_a(20)
	{}
	void func()//重名成员函数
	{
		cout << "Test" << endl;
	}
};
//定义一个基类的指针赋值给派生类，再通过基类的指针进行访问。
int main()
{
	Test T ;
	Base *Bptr = &T;
	cout << T.m_a<< endl;
	T.func();
	cout << Bptr->m_a << endl;
	Bptr->func();
	system("pause");
	return 0;
}