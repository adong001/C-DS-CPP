#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;

//将字符串中的空格转换为%20(源字符空间一般够用)
class Solution1 {
public:
	void replaceSpace(char *str, int length)//length为str字符的空间总字节数
	{
		if (!str && length <= 0)
		{
			return;
		}
		int blankcount = 0;//空格数
		int newlen;
		char* cur = str;
		int oldlen = 0;//字符串长度
		while (*cur != '\0')//找出空格的个数和字符串长度
		{
			if (*cur == ' ')
			{
				blankcount++;
			}
			cur++;
			oldlen++;
		}

		newlen = oldlen + blankcount * 2;//新的字符串长度

		if (newlen > length)//判读给出的长度是否足够将空格扩充成%20
		{
			return;
		}

		for (int i = newlen; cur != str;cur--)//从最后一个开始向后赋值
		{
			if (*cur == ' ')
			{
				str[i] = '0';
				str[i - 1] = '2';
				str[i - 2] = '%';
				i -= 3;
			}
			else
			{
				str[i] = *cur;
				i--;
			}
		}
	}

};


int main1()
{
	char str[30] = "we are friend ";
	Solution1 s;
	s.replaceSpace(str, 30);
	cout << str << endl;
	system("pause");
	return 0;
}