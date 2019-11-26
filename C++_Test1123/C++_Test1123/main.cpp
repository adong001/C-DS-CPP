#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>
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
		int a, b, c;
		virtual ~C(){ cout << "C"; }
	};


//int main1()
//{
//	//test1();
//	//test2();
//	/*test3::A* a = new test3::B();
//	delete a;*/
//	test4::C* c = new test4::C;
//	test4::B* b1 = dynamic_cast<test4::B*>(c);
//	test4::A* a2 = dynamic_cast<test4::A*>(b1);
//	delete a2;
//    system("pause");
//    return 0;
//}

int main()
{
	/*map<string, int> m;
	m.insert(pair<string, int>("AAA", 100));
	m.insert(pair<string, int>("BBB", 200));
	m.insert(make_pair("CCC", 300));
	for (auto& mi : m)
	{
		cout << mi.first << " " << mi.second << endl;
	}*/

	C* c = new C[3];
	c[0].a = 10;

	c[1].a = 20;
	c[2].a = 30;
	cout << c[1].a << c[2].a << endl;
	system("pause");
	return 0;
}