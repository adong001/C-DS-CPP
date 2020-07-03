#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindNum(vector<int>& arr, int val)//存在就返回-1，不存在就返回第一个比它大的值，
{
	int tmp = arr.size();
	for (int i = 0; i < arr.size(); i++)
	{
		if (val == arr[i])
		{
			return -1;
		}
		if (arr[i] > val)
		{
			tmp = i;
		}
	}
	return tmp;
}

bool GetNum(vector<int>& arr, int val)//是否存在子集和为val
{
	int ret = FindNum(arr, val);
	if (ret == -1)//存在就返回真
	{
		return true;
	}
	for (int i = 0; i < ret; i++)//不存在，就在比它小的数据中组合子集找到val
	{

	}
}

int getFirstUnFormedNum(vector<int>& arr, int len)
{
	sort(arr.begin(), arr.end());
	for (int i = arr[1]; i < arr[len - 1]; i++)//[min,max]区间中min和max一定右子集相加得到，不参与判断
	{
		if (!GetNum(arr,i))
		{
			return arr[i];
		}
	}
	return arr[len - 1] + 1;
}
int main()
{
	int len;
	while (cin >> len)
	{
		vector<int> arr(len, 0);
		for (int i = 0; i < len; i++)
		{
			cin >> arr[i];
		}
		cout << getFirstUnFormedNum(arr, len) <<endl;
	}
    return 0;
}