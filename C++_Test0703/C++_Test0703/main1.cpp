#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main2()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		int cnts = 0;
		while (n >= 2)
		{
			n % 3 == 0 ? n /= 3 : n = n / 3 + 1;
			cnts++;
		}
		cout << cnts << endl;
	}
	return 0;
}