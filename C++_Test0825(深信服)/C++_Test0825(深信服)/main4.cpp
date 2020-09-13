#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Things
{
	int Priority;//优先级
	int Requistie;//必要
	int id;
};

bool cmp(const Things& th1,const Things& th2)
{
	if (th1.Requistie > th2.Requistie)
	{
		return true;
	}
	else if(th1.Requistie == th2.Requistie)
	{
		return th1.Priority > th2.Priority;
	}
	return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<Things> th(n);
		for (int i = 0; i < n; i++)
		{
			cin >> th[i].Priority >> th[i].Requistie;
			th[i].id = i + 1;
		}
		sort(th.begin(), th.end(), cmp);
		for (auto&e : th)
		{
			cout << e.id << " ";
		}
		cout << endl;
	}
	return 0;
}