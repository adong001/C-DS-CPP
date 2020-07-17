#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

bool IsReverse111(const char* str,int size)
{
	int i = 0, j = size - 1;
	for (; i < j; i++, j--)
	{
		if (str[i] != str[j])
		{
			return false;
		}
	}
	return true;
}

bool IsAddWord111(const char* str,int size)
{
	for (int i = 0; i < size; i++)
	{
		char tmp[10];
		int k = 0;
		for (int j = 0; j < size; j++)
		{
			if (j != i)
			{
				tmp[k] = str[j];
				k++;
			}
		}
		if (IsReverse111(tmp, k))
		{
			return true;
		}
	}
	return false;
}
int main1()
{
	char s[10];
	int size,i;
	while ( i = scanf("%s",s) != EOF)
	{
		int size = strlen(s);
		if (IsAddWord111(s,size))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}