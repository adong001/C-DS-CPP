#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>

void reverseString(char* str, int size)
{
	int i;
	char temp; 
	for (i = 0; i < size / 2; ++i)
	{
		temp = str[i];
		str[i] = str[size -i - 1];
		str[size -i - 1] = temp;
	}
}
int main()
{
	char str[20] = "bitekejiy";
	int size = strlen(str);
	reverseString(str, size);
	puts(str);
    system("pause");
    return 0;
}