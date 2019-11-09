#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//I like beijing. -->beijing. like I

//gnijieb ekil i

//先将整个串翻转，再将每个单词翻转

void ReserveString(char* src,char *start,char* end)
{
	if (!src||start == end)
	{
		return;
	}
	char tmp;
	for (; start < end; start++, end--)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
	}
}

void ReserveWord()
{
	char ar[100];
	string str;
	getline(cin, str);
	strcpy(ar, str.c_str());
    int length = strlen(ar);
	if (length <= 0)
	{
		return;
	}
	ReserveString(ar, ar, ar + length - 1);

	char* start = ar;
	char* end = ar;
	for (int i = 0; i <= length; i++)
	{
		if (ar[i] == ' '||*end == '\0')
		{
		   ReserveString(ar, start, end - 1);
		   start = end + 1;
		   end = start;
		}

		else
		{
			end++;
		}

	}
	cout << ar << endl;
}


int main2()
{
	while(1)
	{
		ReserveWord();
	}
	system("pause");
	return 0;
}

