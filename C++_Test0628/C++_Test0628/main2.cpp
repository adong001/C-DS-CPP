#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main3()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		vector<int> v(2 * n, 0);
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> v[i];
		}
		for (int i = 0; i < k; i++)
		{
			vector<int> ret(v);
			for (int j = 0,c1 = 0,c2 = c1+n; c1 < n; j++)
			{
				v[j] = ret[c1];
				j++;
				v[j] = ret[c2];
				c1++, c2++;
			}
		}
		for (int i = 0; i < 2 * n - 1; i++)
		{
			cout << v[i] << " ";
		}
		cout << v[2 * n - 1] << endl;
	}
	return 0;
}