#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

string FindLongestSonstr(const string& src)
{
	int len = src.size();
	if (len <= 1)
	{
		return src;
	}
	int max = -1, start = 0;
	for (int i = 0; i < len; i++)
	{
		if (len - i < max)
		{
			break;
		}
		set<char> st;
		for (int j = i; j < len; j++)
		{
			if (st.find(src[j]) == st.end())
			{
				st.insert(src[j]);
				int tmp  = j - i + 1;
				if (tmp > max)
				{
					max = tmp;
					start = i;
				}
			}
			else
			{
				break;
			}
		}
	}
	return src.substr(start, start + max);
}

int main0()
{
	string src;
	while (cin >> src)
	{
		cout << FindLongestSonstr(src) << endl;
	}
	return 0;
}