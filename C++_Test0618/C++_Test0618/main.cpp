#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Base 
{public: 
	virtual int foo(int x) { return x * 10; }
	int foo(char x[14]) { 
		printf("%d\n", sizeof(x));
		return sizeof(x) + 10;
	} 
};
class Derived: public Base 
{ 
public:
	int foo(int x) { return x * 20; }
	virtual int foo(char x[10]) { return sizeof(x) + 20; } } ; 
int main1() {
	Derived stDerived; Base *pstBase = &stDerived;
	char x[10];
	printf("%d\n", pstBase->foo(100) + pstBase->foo(x));
	return 0;
}

struct Test { 
	int a;

	Test(int) {} 
	Test(){}
	void fun() {} }; 
void main2(void) { 
	Test a(1); 
	a.fun(); 
	Test b(); 
	//b.fun(); 
}

//class A
//{
//public:
//	void f1()
//	{
//		cout << "A1" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "A2" << endl;
//	}
//};
//class B :public A
//{
//public:
//	void f1()
//	{
//		cout << "B1" << endl;
//	}
//	void f2()
//	{
//		cout << "B2" << endl;
//	}
//};
//
//int main()
//{
//	/*int a1[3],a2[3],a3[3];
//	int(*p)[3] = &a1;*/
//	A* a1;
//	B b;
//	a1 = &b;
//	A* p = new A;
//	a1->f1();
//	a1->f2();
//	p->f1();
//	p->f2();
//
//	int i = 1,j = 1,m = 1,n = 1;
//	printf("++i,++i:%d,%d\n", ++i, ++i);
//	printf("++j,j++:%d,%d\n", ++j, j++);
//	printf("m++,++m:%d,%d\n", ++m, ++m);
//	printf("n++,n++:%d,%d\n", n++, n++); 
//		return 0;
//}