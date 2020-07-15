#include <iostream>
#include <string>
using namespace std;
int main1()
{
	int n;
	while (cin >> n)
	{
		int maxnum = 0,tmp = 0;
		char ch;
		string str;
		for (int i = 0; i < n; i++)
		{
			cin >> ch >> str;
			if (str == "connect")
			{
				tmp++;
			}
			else
			{
				tmp--;
			}
			maxnum = maxnum < tmp ? tmp : maxnum;
		}
		cout << maxnum << endl;
	}
	return 0;
}