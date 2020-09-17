#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int FindEnd(const string& src, int start)
{
	int cnts = 1, Size = src.size(),i;
	for (i = start + 1; i < Size && cnts > 0;i++)
	{
		if (src[i] == '[')
		{
			cnts++;
		}
		else if (src[i] == ']')
		{
			cnts--;
		}
	}
	return i - 1;
}

string MergeDecomp(const string& src, int start, int end)
{
	string ret;
	//1.Êý×Ö
	int i = src.find( '|',start);
	int num = atoi(src.substr(start + 1, i).c_str());
	string tmp;
	//2.×Ö·û´®
	for (i++; i < end; )
	{
		for (; src[i] != '[' && src[i] != ']'; tmp += src[i], i++);
		if (i < end && src[i] == '[')
		{
			int pos = FindEnd(src, i);
			tmp += MergeDecomp(src, i, pos);
			i = pos + 1;
		}
	}
	for (int j = 0; j < num; ret += tmp,j++);
	return ret;
}

int main1()
{
	string src;
	while (cin >> src)
	{
		string det;
		int Size = src.size();
		for (int i = 0; i < Size;)
		{
			for (; i < Size && src[i] != '['; det += src[i],i++);
			if (i < Size && src[i] == '[')
			{
				int end = FindEnd(src, i);
				det += MergeDecomp(src, i, end);
				i = end + 1;
			}
		}
		cout << det << endl;
	}
	return 0;
}