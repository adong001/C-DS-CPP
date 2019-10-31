#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Base
{
public:
	int m_a;
	virtual void func()
	{
		cout << "Base" << endl;
	}

	virtual~Base()
	{
		cout << "~Base" << endl;
	}
};

class Test : public Base
{
public:
	int m_b;
	virtual void func()
	{
		cout << "Test" << endl;
	}

	virtual~Test()
	{
		cout << "~Test" << endl;
	}


};

int main()
{
	Base* B1 = new Base;
	Base* B2 = new Test;
	delete B1;
	delete B2;
	//T.~Test();
	/*Base B;
	Test T;
	Base* Bptr = &T;
	T.func();
	Bptr->func();
	B.func();*/
    system("pause");
    return 0;
}