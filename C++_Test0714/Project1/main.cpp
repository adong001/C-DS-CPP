#include <iostream>
using namespace std;

int Getnum(int num)
{
	int cnts = 0;
	int tmp = num;
	do
	{
		if (num % 2 == 0)
		{
			num /= 2;
		}
		else
		{
			num = num * 3 + 1;
		}
		cnts++;
	} while (num > tmp);
	return cnts;
}

int main0()
{
	int n;
	while (cin >> n)
	{
		int maxnum = n, maxcnts = 0, tmp;
		for (int i = 2; i <= n; i++)
		{
			tmp = Getnum(i);
			if (maxcnts < tmp)
			{
				maxcnts = tmp;
				maxnum = i;
			}
		}
		cout << maxnum << endl << maxcnts << endl;
	}
	return 0;
}