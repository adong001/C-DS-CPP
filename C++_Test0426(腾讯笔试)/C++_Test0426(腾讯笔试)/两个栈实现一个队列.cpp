#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int main2()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		string s;
		queue<int> q;
		int tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			switch (s[0])
			{
			  case 'a':
			  {
			  	 cin >> tmp;
			  	 q.push(tmp);
			  	 break;
			  }
			  case 'p':
			  {
				 if (s[1] == 'e')
				 {
					 v.push_back(q.front());
					break;
				 }
				 else
				 {
					q.pop();
					break;
				 }
						  
			  }
			}
		}
		for (auto& e : v)
		{
			cout << e << endl;
		}
	}
    return 0;
}