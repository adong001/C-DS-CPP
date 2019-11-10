#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int StrToInt(string str)
	{
		int num = 0;
		int flag = 1;
		if (str.empty())
		{
			return 0;
		}

		for (int i = 0; i < str.size();i++)
		{
			if (str[i] == '-' && i== 0)
			{
				flag = -1;
			}
			else if (str[i] == '+' && i == 0)
			{
				flag = 1;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				num *= 10;
				num += (str[i] - '0');
			}
			else
			{
				return 0;
			}
		}
		return num * flag;
	}
};
int main2()
{
	Solution test;
	string s;
	while (1)
	{
		cout << test.StrToInt(s) << endl;
	}
    system("pause");
    return 0;
}