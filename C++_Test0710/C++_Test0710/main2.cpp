#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main2()
{
	string src,det;
	while (getline(cin, src))
	{
		getline(cin, det);
		vector<string> vs;
		int Size = src.size();
		for (int i = 0; 0 <= i && i < Size;)
		{
			
			if (src[i] == '"')
			{
				int pos = src.find('"', i + 1);
				vs.push_back(src.substr(i + 1, pos- i - 1)); 
				i = pos + 1;
			}
			else
			{
				int pos = src.find(',', i + 1);
				vs.push_back(src.substr(i, pos- i));
				i = pos;
			}
			while (0 < i && i < Size && (src[i] == ',' || src[i] == ' '))
			{
				i++;
			}
		}
		bool flag = false;
		for (auto& e : vs)
		{
			if (det == e)
			{
				cout << "Ignore\n";
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "Important!\n";
		}
	}
    return 0;
}