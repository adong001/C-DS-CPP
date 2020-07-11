#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main1()
{
	int n;
	while (cin >> n)
	{
		string s;
		getchar(); //Ë¢ÐÂ»º³åÇø
		while(n--)
		{
			getline(cin , s);
			bool flag = false;
			if (s.find(',', 0) != string::npos || s.find(' ', 0) != string::npos)
			{
				flag = true;
			}
			if (flag)
			{
				cout << "\"" << s << "\"";
			}
			else
			{
				cout << s;
			}
			if (n == 0)
			{
				cout << endl;
			}
			else
			{
				cout << ", ";
			}
		}
	}

    return 0;
}