#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//1.数组中有一个数字出现的次数超过数组长度的一半，
//请找出这个数字。
//例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，
//因此输出2。如果不存在则输出0。
int MoreThanHalfNum_Solution1(vector<int>&numbers)
{
	int sum = 0, tmp = 0;
	for (auto& i :numbers)
	{
		sum = (sum^i)&~tmp;
		tmp = (tmp^i)&~sum;
	}
	return sum;
}

int MoreThanHalfNum_Solution2(vector<int>& numbers)
{
	int tmp = numbers[0], icount = 1;
	for (int i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == tmp)
		{
			icount++;
		}
		else
		{
			if (icount > 1)
			{
				icount--;
			}
			else
			{
				tmp = numbers[i];
			}
		}
	}

	if (numbers.size() / 2 < count(numbers.begin(), numbers.end(), tmp))
	{
		return tmp;
	}
	return 0;
}
int main()
{
	int ar2[] = { 1, 2, 3, 2, 4, 2, 5, 2, 3 };
	int ar1[] = { 2, 2, 2, 2, 2, 1, 3, 4, 5 };
	int ar[]  =  { 1, 2, 3, 2, 2, 2, 5, 4, 2};
	vector<int>v;
	for (int i = 0; i < 9; i++)
	{
		v.push_back(ar[i]);
	}
	cout << MoreThanHalfNum_Solution2(v) << endl;
	system("pause");
	return 0;
}


//例如:{6, -3, -2, 7, -15, 1, 2, 2}, 
//	连续子向量的最大和为8(从第0个开始, 到第3个为止)。
//	给一个数组，返回它的最大连续子序列的和
template<class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}
int FindGreatestSumOfSubArray(vector<int>& array)
{
	if (!array.size())
	{
		cout << "数组长度错误！";
		return errno;
	}
	int maxResult = 0;
	int i;
	int *tmp = new int[array.size()];
	memset(tmp, 0, sizeof(int)* array.size());
	*tmp = array[0];
	for (i = 1; i < array.size(); i++)
	{
		tmp[i] = Max(array[i] + tmp[i - 1], array[i]);
		if (maxResult < tmp[i])
		{
			maxResult = tmp[i];
		}
	}
	return maxResult;
}
int main2()
{
	int ar[] = { 6, -3, -2, 7, -15, 1, 2, 2 };
	int ar1[] = { 0, -2, 11, -4, 13, -5, -2 };
	vector<int>v;
	for (auto& i : ar)
	{
		v.push_back(i);
	}
	cout << FindGreatestSumOfSubArray(v) << endl;
	system("pause");
	return 0;
}

//
//给定一个整数数组 nums，其中恰好有两个元素只出现一次，
//其余所有元素均出现两次。找出只出现一次的那两个元素。

vector<int> singleNumber(vector<int>& nums)
{
	vector<int>res;
	int num1 = 0, num2 = 0;
	int tmp = 0;

	for (auto& i : nums)//将所有数先异或，得到单独两个数的异或值
	{
		tmp ^= i;
	}

	int j;
	for (j = 0; j < 32; j++)
	{
		if ((tmp >> j) & 1)//这异或值某一位为1说明这两个数的这一位不相同，随便取一位为1的都可以。
		{	               
			break;
		}
	}

	for (auto& i : nums)//这一位为1的被num1异或，相同的自然异或得0，最后只剩下单独数中的一个，num2一样。
	{
		if ((i >> j) & 1)
		{
			num1 ^= i;
		}
		else
		{
			num2 ^= i;
		}
	}

	res.push_back(num1);//最后将找到的两个单独数push进res中返回。
	res.push_back(num2);
	return res;
}

int main3()
{
	int ar[] = { 1, 2, 1, 3, 2, 5 };
	vector<int>v;
	v.insert(v.begin(), ar, ar + 6);
	cout << singleNumber(v)[0] << " " << singleNumber(v)[1] << endl;
	system("pause");
	return 0;
}

