#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

void DeleteSameString()
{
	string src;
	char hx[256] = {};
	getline(cin, src);
	for (int i = 0; i < src.size(); i++)
	{
		if (hx[src[i]] == 0)
		{
			hx[src[i]] = 1;
			cout<<src[i];
		}
	}
	cout<< endl;
}

int main1()
{
	DeleteSameString();
	system("pause");
	return 0;
}

