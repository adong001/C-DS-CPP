#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"BTree.h"
using namespace std;
#define MY_TEST

void Test()
{
#ifdef MY_TEST
	int a[] = { 53, 139, 75, 49, 145, 36, 101 };

	BTree<int, 3> t;
	for (int i = 0; i < 7; i++)
	{
		t.Insert(a[i]);
	}
	t.InOrder();
#else	
	vector<int> v(10000);
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(rand());
	}
	BTree<int, 1024> t;
	for (auto& e : v)
	{
		t.Insert(e);
	}
	t.InOrder();
#endif
}

int main()
{
	Test();
    return 0;
}