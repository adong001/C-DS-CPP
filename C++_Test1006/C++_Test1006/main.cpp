#include<iostream>
using namespace std;

template<class T>
class A
{
public:
	int a;
};

template<class T>
class B
{

public:
	typedef A<T>* AAA;
	AAA b;
};

template<class T>
class C
{
public:
	typedef B<T>* BBB;
	BBB c;
};




int main()
{
	C<int>c;
	int b = 10;
	int *a = &b;
	c.c = &a;
    system("pause");
    return 0;
}