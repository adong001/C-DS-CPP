#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main4()
{
	int n;
	string s;
	while (cin >> n >> s)
	{
		int num = 1, first = 1;
		if (n <= 4)//一页可以直接显示四个
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (num == 1 && s[i] == 'U')//当前位置处于第一个要向上翻，位置就变成最后一个
				{
					num = n;
				}
				else if (num == n && s[i] == 'D')//当前位置处于最后一个要向下翻，位置就变成第一个
				{
					num = 1;
				}
				else if (s[i] == 'U')//正常翻
				{
					num--;
				}
				else
				{
					num++;
				}

			}
			for (int i = 1; i <= n - 1; i++)//显示
			{
				cout << i << ' ';
			}
			cout << n << endl;
			cout << num << endl;
		}
		else
		{
			for (int i = 0; i < s.size(); i++)
			{
				//first为前边界
				if (first == 1 && num == 1 && s[i] == 'U')//当前为第一个要向上翻，前边界first变成n前面的第三个
				{
					first = n - 3;
					num = n;
				}
				else if (first == n - 3 && num == n && s[i] == 'D')//当前为最后一个要向下翻，前边界first变成第一个
				{
					first = 1;
					num = 1;
				}
				else if (first != 1 && first == num && s[i] == 'U')//当前位置和前边界处于同一位置，且不是第一个，向上翻转就要和前边界同时向上
				{
					first--;
					num--;
				}
				else if (first != n - 3 && first + 3 == num && s[i] == 'D')//当前位置和前边界相隔3个位置，且不是最后一个，向下翻转就要和前边界同时向下
				{
					first++;
					num++;
				}
				else if (s[i] == 'U')//当前位置在{前边界+1到前边界+2之间},向上翻
				{
					num--;
				}
				else//当前位置在{前边界+1到前边界+2之间},向下翻
				{
					num++;
				}
			}
			for (int i = first; i < first + 3; i++)
			{
				cout << i << ' ';
			}
			cout << first + 3 << endl << num;
			cout << num << endl;
		}
	}
	return 0;
}