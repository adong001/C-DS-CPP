#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main1()
{
	string s;
	while (getline(cin, s))
	{
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size();)
		{
			int j;
			for (j = i; j < s.size() && !isspace(s[j]); j++);
			reverse(s.begin() + i, s.begin() + j);
			for (; j < s.size() && isspace(s[j]); j++);
			i = j;
		}
		cout << s << endl;
	}
	return 0;
}