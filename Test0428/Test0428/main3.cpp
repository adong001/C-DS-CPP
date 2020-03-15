#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//（3）用一个函数交两个整型的值

int swag(int *a, int *b)
{
	int p = *a;
	*a = *b;
	*b = p;
	return 0;
}
int main()
{
	int x = 10, y = 20;
	cout << "x=" << x << "  y=" << y << endl;
	swag(&x, &y);
	cout << "x=" << x << "  y=" << y << endl;
	return 0;
}