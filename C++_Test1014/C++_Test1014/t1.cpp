#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
//输入一个数，判断最多使用几部变成斐波那契数(只能给这个数+1或-1)
//  斐波那契数列：1 1 2 3 5 8 13 21......
//例如：
//      输入：  15       //15 -1 -1 = 13 
//      输出：   2  
class Solution {
public:
	size_t BecomeFibSteps(size_t num)
	{
		int fn, fn_1 = 0, fn_2 = 1;
		fn = fn_1 + fn_2;
		while (fn < num)//找到比num大的或相等的那个斐波那契数
		{
			fn_2 = fn_1;
			fn_1 = fn;
			fn = fn_1 + fn_2;
		}  
		int a = fn - num;
		int b = fn_1 - num;

		return min(abs(a), abs(b));

	}
}; //1 2 3 5 8 13 21 
int main1()
{   
	Solution s;
	cout << s.BecomeFibSteps(4) << endl;
    system("pause");
    return 0;
}