#include <iostream>
#include <cmath>
using namespace std;
int main1()
{
	int n;
	while (cin >> n)
	{
		int cnts = 0;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				for (; n % i == 0; n /= i);
				cnts++;
			}
		}
		if (n != 1)
		{
			cnts++;
		}
		cout << cnts << endl;
	}
	return 0;
}