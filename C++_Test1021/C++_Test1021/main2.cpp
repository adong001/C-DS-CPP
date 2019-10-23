#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Base
{
public:
	int m_a;
	Base(int a):
	m_a(a)
	{
	}

};

class TestBase:public Base
	
{
public:
	int m_a;
	TestBase(int a,int b) :
	    Base(a),
		m_a(b)
	{
	}
};

int main()
{

	TestBase* TB = new TestBase(1, 2);
	Base* B = TB;
	cout <<B->m_a<< endl;
	cout << TB->m_a << endl;
    system("pause");
    return 0;
}