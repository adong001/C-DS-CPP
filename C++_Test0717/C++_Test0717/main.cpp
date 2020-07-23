#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
bool IsReverse(const string& str)
{
	int i = 0, j = str.size() - 1;
	for (; i < j; i++, j--)
	{
		if (str[i] != str[j])
		{
			return false;
		}
	}
	return true;
}

bool IsAddWord1(const string& str)
{
	int Size = str.size();
	for (int i = 0; i < Size; i++)
	{
		string tmp = str.substr(0, i);
		//substr函数就是截取str串的下标从i开始，j个长度的大小
		//string& substr(size_t pos,size_t size);
		if (IsReverse(tmp += str.substr(i + 1, Size - i)))
		{
			return true;
		}
	}
	return false;
}
bool IsAddWord(const string& str)
{
	if (!str.empty())
	{
		return true;
	}
	if (str.length() > 10) {
		return false;
	}
	for (int i = 0; i < str.length(); i++)
	{
		char* ch1 = new char[str.length() - 1];
		int k = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (j != i) 
			{
				ch1[k] = str[j];
				k++;
			}

		}
		if (IsReverse(ch1))
		{
			return true;
		}
	}
	return false;
}

int main1()
{
	string s;
	while (cin >> s)
	{
		if (IsAddWord(s))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}