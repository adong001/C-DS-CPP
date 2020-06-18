#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
using namespace std;

bool IsPrefectNum(int n)
{
	int cnts = 0;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (n / i != i && i != 1)
			{
				cnts += n / i;
			}
			cnts += i;
		}
	}
	return (cnts == n) ? true : false;
}

int count(int n)
{
	int cnts = 0;
	for (int i = 6; i <= n; i++)
	{
		if (IsPrefectNum(i))
		{
			cout << i << endl;
			cnts++;
		}
	}
	return cnts;
}
int main5()
{
	int n;
	while (cin >> n)
	{
		cout << count(n) << endl;
	}
    return 0;
}