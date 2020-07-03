#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void oddInOddEvenInEven(vector<int>& arr, int len)
{
	int i = 0;
	int j = 1;
	while (i < len && j < len)
	{
		if (arr[i] % 2 == 0)//偶数位上找奇数
		{
			i += 2;
			continue;
		}

		if (arr[j] % 2 != 0)//奇数位上找偶数
		{
			j += 2;
			continue;
		}
		swap(arr[i], arr[j]);
	}
}

int main1()
{
	vector<int> arr = { 1, 2, 3, 4 };
	oddInOddEvenInEven(arr, 4);
    return 0;
}