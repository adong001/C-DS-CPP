#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//实现任意进制的转换
void BinaryConversion()
{
	int num;
	int dest;
	cin >> num >> dest;
	if (dest<2 || dest>16)
	{
		return;
	}
	char ar[20];
	int i;
	for (i = 0; num / dest != 0; i++)
	{
		if (num % dest > 9)
		{
			ar[i] = num % dest + 'A' - 10;
		}
		else
		{
			ar[i] = num % dest + '0';
		}
		num /= dest;
	}
	if (num % dest > 9)
	{
		ar[i] = num % dest + 'A' - 10;
	}
	else
	{
		ar[i] = num % dest + '0';
	}
	for (; i >= 0; i--)
	{
		cout << ar[i];
	}

}
int main()
{
	while (1)
	{
		BinaryConversion();
	}
	system("pause");
	return 0;
}