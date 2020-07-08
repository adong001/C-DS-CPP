#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <cmath>
using namespace std;

int main1()
{
	int n;
	while (cin >> n)
	{
		cout << n << " = ";
		for (int i = 2; i < n; i++)
		{
			while (n % i == 0 && i != n)
			{
				n /= i;
				cout << i << " * ";
			}
		}
		if (n != 1)
		{
			cout << n ;
		}
		cout << endl;
	}
    return 0;
}