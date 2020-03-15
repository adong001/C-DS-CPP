#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//（4）输入一个数，查找它在数组中的下标
#define ERROR 1
#define LONGERROR -1
#define POINTERROR -2
int Find(int ar[], int p, int n)
{
	if (p == NULL)return POINTERROR;
	if (n < 1)return LONGERROR;
	for (int i = 0; i < n; i++)
	{
		if (p == ar[i]){ return i + 1; }
	}
	return ERROR;
}


int main4()
{
	char ch;

	int a, b, ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
	int n = sizeof(ar) / sizeof(ar[0]);
	for (;;)
	{
		cout << "输出要查找的数：";
		cin >> a;
		b = Find(ar, a, n);
		switch (b)
		{
		case POINTERROR:cout << "输入的数据为空" << endl << endl; break;
		case LONGERROR: cout << "此数组为空" << endl << endl; break;
		case ERROR:cout << "此数组中没有这个数" << endl << endl; break;
		default:cout << "他是第" << b << "个数" << endl << endl; break;
		}
		cout << "继续查找输入Y，退出输入N" << endl << endl;
		cin >> ch;
		if (ch == 'N' || ch == 'n')break;
	}
	return 0;
}