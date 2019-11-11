#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//实现任意进制的转换
void BinaryConversion()
{
	int num;
	int dest;
	char table[] = { "0123456789ABCDEF" };
	int flag = 1;
	string str;
	cin >> num >> dest;

	if (dest<2 || dest>16)
	{
		return;
	}

	if (num < 0)
	{
		flag = -1;
		num *= flag;
	}

	while (num)
	{
		str += table[num % dest];
		num /= dest;
	}

	if (flag == -1)
	{
		str += '-';
	}
	for (int i = str.size()-1; i >=0 ; i--)
	{
		cout << str[i];
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