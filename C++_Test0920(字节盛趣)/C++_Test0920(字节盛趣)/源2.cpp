#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	/**
	*
	* @param inData string字符串 请求参数
	* @return int整型
	*/
	//判断是是否为有序的
	bool IsSort(const vector<int>& lt)
	{
		if (lt.size() <= 1)
		{
			return true;
		}

		for (int i =1; i < lt.size(); i++)
		{
			
			if (lt[i] > lt[i - 1])
			{
				return false;
			}
		}
		return true;
	}

	int sort(string inData)
	{
		vector<int> Lt;
		for (int i = 1,j; i < inData.size() - 2;)
		{
			for (j = i; j < inData.size() && inData[j] != ' '; j++);
			Lt.push_back(atoi(inData.substr(i, j).c_str()));
			for (; inData[j] == ' '; j++);
			i = j;
		}
		int cnts = 0;

		//循环链表，不是有序就将这个元素插在后面(要大于最后一个元素)
		for (int i = 1; i< Lt.size();)
		{
			//有序就返回
			if (IsSort(Lt))
			{
				return cnts;
			}
			else
			{
				if (Lt[i] > Lt[i+1])
				{
					swap(Lt.begin()+i, Lt.end()-1);
					cnts++;
				}
				else
				{
					i++;
				}
			}

		}
		return cnts;
	}
};

int main()
{
	Solution s;
	s.sort("\"19 5 9 224\"");

}