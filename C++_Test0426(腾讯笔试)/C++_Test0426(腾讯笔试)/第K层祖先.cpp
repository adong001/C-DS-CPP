#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		int x, k;
		for (int i = 0; i < n; i++)
		{
			int c1 = 1, c2 = 0;
			cin >> x >> k;
			int tmp = x;
			while (tmp > 1)
			{
				tmp /= 2;
				c1++;
			}
			tmp = k;
			k = c1 - k;
			while (k)
			{
				k--;
				x /= 2;
			}
			v[i] = (x <= 0 || tmp >= c1) ? -1 : x;
		}
		for (auto& e : v)
		{
			cout << e << endl;
		}
	}
		return 0;
}
