#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Solution {
public:
	int jumpFloorII(int number)
	{
		return 1 << (number - 1);
	}
};
int main1()
{
	int n;
	while (cin >> n)
	{
		Solution s;
		cout << s.jumpFloorII(n) << endl;
	}
    return 0;
}