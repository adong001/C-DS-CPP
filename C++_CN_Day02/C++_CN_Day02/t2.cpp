#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
//I like beijing. -->beijing. like I

//gnijieb ekil i
//template<class T>
//void ReserveString(T& src)
//{
//	string str(src);
//	vector<string> vstr;
//	if (str.empty())
//	{
//		return;
//	}
//	int count = 0;
//	for(auto& i:str)
//	{
//		if (i == ' ')
//		{
//			count++;
//		}
//	}
//
//	vstr.resize(count+1);
//	string::iterator isp = str.begin();
//	string::iterator end = str.end();
//
//	for (int i =0;isp != end;isp++,i++)
//	{
//		while (isp != end && *isp != ' ' )
//		{
//			vstr[i].push_back(*isp);
//			isp++;
//		}
//		if (isp == end)
//		{
//			break;
//		}
//	}
//	int v_size = vstr.size();
//	for (int i = 0; i < v_size / 2; i++)
//	{
//		swap(vstr[i], vstr[v_size - 1 - i]);
//	}
//	strcpy(src, vstr[0].c_str());
//	char res[] = " ";
//	for (int i = 1; i < v_size; i++)
//	{
//		strcat(src, res);
//		strcat(src, vstr[i].c_str());
//	}
//
//}

void ReserveString()
{
	string str;
	getline(cin, str);
	if (str.empty())
	{
		return;
	}
	char tmp =0;
	string::iterator ipb = str.begin();
	string::iterator ipe = str.end()-1;
	while (*ipe == ' ')
	{
		ipe = str.erase(ipe);
		if (ipe == ipb && *ipe== ' ')
		{
			return;
		}
	}
	for (; ipb <= ipe; ipb++, ipe--)
	{
		tmp = *ipb;
		*ipb = *ipe;
		*ipe = tmp;
	}
	ipb = str.begin();
	ipe = str.end();
	string::iterator res = str.begin();
	string::iterator flag = str.begin();
	for (; ipb != ipe; )
	{
		while (res != ipe && *res != ' ')
		{
			res++;
		}
		if (res != ipe)
		{
			flag = res + 1;
			res--;
		}
		else
		{
			flag = ipe;
		}
		
		for (; res != ipe && ipb <= res; ipb++, res--)
		{
			tmp = *ipb;
			*ipb = *res;
			*res = tmp;
		}
		res = ipb = flag;
	}
	cout << str;
}

int main()
{
	while(1)
	{
		ReserveString();
	}
	system("pause");
	return 0;
}


#include <string.h>
#include <stdio.h>
#include <ctype.h>
void ReserveStr(char *arr, int start, int end)
{
	char ch;
	if (arr == NULL)
		return;
	while (start<end)
	{
		ch = arr[start];
		arr[start] = arr[end];
		arr[end] = ch;
		start++;
		end--;
	}
}

void ReserveWord(char *arr)
{
	int start = 0;
	int end = 0;
	int len = strlen(arr);
	if (arr == NULL)
		return;

	ReserveStr(arr, 0, len - 1);
	while (start<len)
	{
		end = start;
		if (arr[start] != ' ')
		{
			while (arr[end] != ' '&&arr[end] != '\0')
			{
				end++;
			}
			ReserveStr(arr, start, end - 1);
			start = end;
		}
		else
		{
			start++;
		}

	}
}

int main()
{
	char str[100];
	gets(str);
	ReserveWord(str);
	printf("%s", str);
}
