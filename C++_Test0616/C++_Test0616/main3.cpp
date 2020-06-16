#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class myClass
{
public:
	void foo();
	void func();
};
void myClass::foo()
{ 
	delete this; 
}
void myClass::func()
{ 
	myClass *a = new myClass();
	a->foo(); 
}
//class A 
//{
//public: void f() 
//{
//	printf("A\n");
//}
//}; 
//class B : public A 
//{ 
//public: 
//	virtual void f() 
//	{ printf("B\n"); } 
//}; 
//int main() { A *a = new B; a->f(); 
//delete a; 
//return 0; 
//}
//int main()
//{
//	myClass m;
//	m.func();
//    return 0;
//}

class A {
public: 
	A() { printf("A "); }
	~A() { printf("deA "); } 
}; 
class B 
{ public:
	B(){ printf("B "); }
	~B() { printf("deB "); } 
}; 
class C : public A, public B { 
public:
	C() { printf("C "); }
	~C() { printf("deC "); } 
}; 
int main() {
	A *a = new C();
	delete a; 
	return 0;
}

class Gloves 
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right) 
	{
		int sum = 0;
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (left[i] == 0 || right[i] == 0)
			{
				sum += left[i] + right[i];
			}
			else
			{
				int left_min = min(left_min, left[i]);
				int right_min = min(right_min, right[i]);
				left_sum += left[i];
				right_sum += right[i];
			}
		}
		return sum = min(left_sum - left_min + 1 ,right_sum - right_min + 1)+ 1;
	}
};