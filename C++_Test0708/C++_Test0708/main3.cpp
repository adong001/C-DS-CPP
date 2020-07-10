#include<iostream>
using namespace std;

int main3()
{
	int n;
	while (cin >> n)
	{
		int tmp = n;
		int f0 = 0, f1 = 1, f2 = 2;
		while (n--)
		{
			f0 = f1 % 1000000;
			f1 = f2 % 1000000;
			f2 = f0 + f1;
		}
		if (tmp >= 30)
		{
			printf("%06d\n", f0);
		}
		else
		{
			printf("%d\n", f0);
		}
	}
	return 0;
}