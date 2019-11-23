#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void test1()
{
	char* ptr;
	char src[] = "helloworld";
	ptr = src;
	ptr += 5;
	cout << ptr << endl;
}

void test2()
{
	char* ptr = "abc";
	char* src = "abc123";
	while (*ptr = *src)
		printf("%c,%c", *ptr, *src);
}

namespace test3
{
	class A
	{
	public:
		A(){ p(); }
		virtual void p(){ printf("A"); }
		virtual ~A(){ p(); }
	};

	class B :public A
	{
	public:
		B(){ p(); }
		virtual void p(){ printf("B"); }
		virtual ~B(){ p(); }
	};
};


namespace test4
{
	class A
	{
	public:
		virtual ~A(){ cout << "A"; }
	};

	class B
	{
	public:
		virtual ~B(){ cout << "B"; }
	};

	class C :public A,public B
	{
	public:
		virtual ~C(){ cout << "C"; }
	};
};


int main()
{
	//test1();
	//test2();
	/*test3::A* a = new test3::B();
	delete a;*/
	test4::C* c = new test4::C;
	test4::B* b1 = dynamic_cast<test4::B*>(c);
	test4::A* a2 = dynamic_cast<test4::A*>(b1);
	delete a2;
    system("pause");
    return 0;
}