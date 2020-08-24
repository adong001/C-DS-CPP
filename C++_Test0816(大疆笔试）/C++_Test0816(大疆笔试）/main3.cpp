#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//判断回文串
bool Palindrome(const char* str)
{
	const char* end = str;
	const char* start = str;
	//找到字符串末尾


	end = str + strlen(str) - 1;
	if (start == end)
	{
		//只有一个字符就返回true;
		return true;
	}

	for (; start < end; start++, end--)
	{
		//不是回味串直接返回
		if (*start != *end)
		{
			return false;
		}
	}
	//检测完所有就true
	return true;
}

int main()
{
	char src[100] = { 0 };
	int n;
	while (scanf("%s", src) != EOF)
	{
		if (Palindrome(src))
		{
			printf("true\n");
		}
		else
		{
			printf("false\n");
		}
		memset(src, 0, 100);
	}
	return 0;
}