#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		if (n < (2 * r * 3.14))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
    return 0;
}