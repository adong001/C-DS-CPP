#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>

#include<vector>
using namespace std;

//2. 标题：数组中出现次数超过一半的数字 | 时间限制：1秒 | 内存限制：32768K | 
//
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//
//例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }
//
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出 0。
//
//解题思路1：
	//一个数字在数组中出现次数超过一半；那么删除掉2个不相同的数字后，
	//这个数字在新数组中出现的次数也是超过一半；不断重复上述过程，最后一个留下的数字就是目标数字
//	遇见某个数时tmp记录这个数，num++，下一个数还是这个数继续num++，
//	否则,如果num>0,num--,如果num<=0,则tmp记录下一个数的值，并且num++，直至数组结束。
//	最后看num是否>0,大于就存在这样的数，否则不存在。
//解题思路2：
//	1.把数组排个序
//	2.获得到最中间的那个数
//	3.在数组中找他出现了几次
//	4.次数大于size/2就返回它，否则返回0
		  
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty())
		{
			return 0;
		}

		int tmp = numbers[0];
		int num = 1;
		int i;

		for (i = 1; i < numbers.size();i++)
		{
			if (numbers[i] == tmp)//记录这个值
			{
				num++;//计数器++
			}

			else//当前的值和tmp保存的值不一致
			{
				if (num > 0)//计数器记录的tmp的值大于1个
				{
					num--;
				}

				else//tmp之前出现的次数小于1次,重新给tmp赋值
				{
					tmp = numbers[i];
					num = 1;
				}
			}
		}
		num = count(numbers.begin(),numbers.end(),tmp);

		if (num>numbers.size() / 2)
		{
			return tmp;
		}
		return 0;
	}
};
int main()
{
	Solution test;
	vector<int> ar = { 1, 2, 3, 2, 4, 2, 5, 2, 3 };//
	cout << test.MoreThanHalfNum_Solution(ar) << endl;
    system("pause");
    return 0;
}