#include<iostream>
#include<vector>
using namespace std;

int Count(vector<int>& high, int pos)
{
	int cnts = 1;
	int Max = -1;
	//只要在[high[pos-1],Max]区间内否可以看见
	//左
	for (int i = pos - 1; i >= 0; i--)
	{
		Max <= high[i] ? (Max = high[i], cnts++) : 1;
	}

	Max = -1;
	//右
	for (int i = pos + 1; i < high.size(); i++)
	{
		Max <= high[i] ? (Max = high[i], cnts++) : 1;
	}
	return cnts;
}

int main()
{
	int a;
	printf("%d\n", a += a *= a %= 6);
	int n;
	while (cin >> n)
	{
		vector<int> High(n);
		for (int i = 0; i < n; i++)
		{
			cin >> High[i];
		}
		vector<int> ret(n);
		for (int i = 0; i < n; i++)
		{
			ret[i] = Count(High, i);
		}
		for (auto& e : ret)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}