#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int main1()
{
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		int m;
		queue<int> q;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			string s;
			int tmp;
			cin >> s;
			switch (s[0])
			{
				case 'P':
				{
					if (s[1] == 'U')
					{
						cin >> tmp;
						q.push(tmp);
					}
					else
					{
						if (q.empty())
						{
							v.push_back(-1);
						}
						else
						{
							q.pop();
						}
					}
					break;
				}
				case 'T':
				{
					if (q.empty())
					{
						v.push_back(-1);
					}
					else
					{
						v.push_back(q.front());
					}
					break;
				}
				case 'S':
				{
					v.push_back(q.size());
					break;
				}
				case 'C':
				{
					while (!q.empty())
					{
						q.pop();
					}
					break;
				}
			}
		}
	}
	for (auto& e : v)
	{
		cout << e << endl;
	}
	return 0;
}