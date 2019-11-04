#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
void mymalloc1(char **p)
	{
		static char a[100];
		*p = a;
	}
char *mymalloc()
{
	static char a[100];
	return a;
}
int main()
{
	
	char *str;
	mymalloc(&str);
	/*str = mymalloc();*/
	strcpy(str, "hehe");
	puts(str);

    system("pause");
    return 0;
}