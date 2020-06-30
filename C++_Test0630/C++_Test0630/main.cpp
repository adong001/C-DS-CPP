#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		if (num1 == 0)
		{
			return num2;
		}
		else if (num2 == 0)
		{
			return num1;
		}
		else
		{
			return Add(num1^num2, (num1&num2) << 1);
		}
	}
};
int main1()
{
	Solution s;
	cout << s.Add(11, 20) << endl;
    return 0;
}