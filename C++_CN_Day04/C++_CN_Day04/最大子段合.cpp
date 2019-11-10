#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int Max_Mid_Sum()
{
	int num;
	vector<int> vres;
	while (cin >> num)
	{
		vres.push_back(num);
		if (cin.get() == '\n')
		{
			break;
		}
	}

	int tmp = 0,j,max = 0;
	for (j = 0; j < vres.size(); j++)
	{
		tmp += vres[j];
		if (tmp>max)
		{
			max = tmp;
		}
		else
		{
			tmp = 0;
		}
	
	}
	return max;
}

int main2()
{
	cout << Max_Mid_Sum() << endl;
    system("pause");
    return 0;
}


#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main1()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++)    {
		// 计算到num[i]的子数组的最大和       
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}
	cout << result << endl;
	system("pause");
	return 0;
}