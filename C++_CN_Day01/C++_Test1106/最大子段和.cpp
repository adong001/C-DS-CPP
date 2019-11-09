#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//求最大子段和(为负数时=0)
int maxSubSum(int* a, int length)//动态规划
{
	int Max = 0, Sum = 0;
	for (int i = 1; i < length; i++)
	{
		Sum += a[i];
		if (Sum > Max)
		{
			Max = Sum;
		}
		else if (Sum < 0)
		{
			Sum = 0;
		}
	}
	return Max;
}
int main1()
{
	int ar[] = { -1, -2, -3 , 2, 1, 7, -10, 19, 3};
	cout << maxSubSum(ar, 9) << endl;
	return 0;
}