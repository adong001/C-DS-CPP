#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Base
{
public:
	int m_a;
	virtual void func()
	{
		cout << "Base::func"<<endl;
	}
};

class TestBase:public Base
{
public:
	int m_b;
	virtual void func()
	{
		cout << "TestBase::func" << endl;
	}
};

class Test :public TestBase
{
public:
	int m_c;
	virtual void func()
	{
		cout << "Test::func" << endl;
	}
};

int main()
{
	Test* T = new Test;
    system("pause");
    return 0;
}