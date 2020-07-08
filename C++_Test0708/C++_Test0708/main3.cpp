#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int GetFib(int n)
{
	int f0 = 0, f1 = 1, f2 = 1, f;
	while (n--)
	{
		f = f2;
		f2 = (f1 + f2) % 1000000;
		f0 = f1;
		f1 = f;
	}
	return f1;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n < 29)
		{
			printf("%d\n", GetFib(n));
		}
		else
		{
			printf("%06d\n", GetFib(n));
		}
	}
	return 0;
}