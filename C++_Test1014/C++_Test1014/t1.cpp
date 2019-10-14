#include<iostream>
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
		int step = 0;//步数
		vector<int> v;
		int a = 1;
		int b = 1;
		v.push_back(1);
		v.push_back(1);
		while(num > )

	}
};
int main()
{   
	Solution s;
	cout << s.BecomeFibSteps(15) << endl;
    system("pause");
    return 0;
}