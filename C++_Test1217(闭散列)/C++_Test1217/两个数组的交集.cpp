#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//给定两个数组，编写一个函数来计算它们的交集。
//
//示例 1:
//
//输入 : nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出 : [2]
//
//示例 2 :
//
//输入 : nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//输出 : [9, 4]
//
//说明 :
//	  输出结果中的每个元素一定是唯一的。
//	  我们可以不考虑输出结果的顺序。

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> common;
		unordered_set<int> s1(nums1.begin(), nums1.end());
		unordered_set<int> s2(nums2.begin(), nums2.end());
		for (auto& e : s2)
		{
			if (!s1.insert(e).second)
			{
				common.push_back(e);
			}
		}
		return common;
	}
};
int main5()
{
    system("pause");
    return 0;
}