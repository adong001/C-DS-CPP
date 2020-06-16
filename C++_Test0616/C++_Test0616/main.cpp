#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main1()
{
	string src;
	while (getline(cin, src))
	{
		vector<string> vs;
		int Size = src.size();
		if (Size == 0)
		{
			cout << 0 << endl;
			continue;
		}
		int cnt = 0, pos;
		for (int i = 0; i < Size;)
		{
			if (src[i] == '"')
			{
				pos = i + 1;
				for (++i; i < Size && src[i] != '"'; ++i);
				cnt++;
				string tmp(src.begin() + pos, src.begin() + i);
				vs.push_back(tmp);
				for (; isspace(src[i]) && i < Size; ++i);
			}
			else
			{
				pos = i;
				for (++i; i < Size && !isspace(src[i]); ++i);
				cnt++;
				string tmp(src.begin() + pos, src.begin() + i);
				vs.push_back(tmp);
				for (; isspace(src[i]) && i < Size; ++i);
			}
		}
		cout << cnt << endl;
		for (auto& e : vs)
		{
			cout << e << endl;
		}
	}
	return 0;
}