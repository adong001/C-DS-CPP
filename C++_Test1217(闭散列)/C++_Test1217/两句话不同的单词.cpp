#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_set>
using namespace std;

//给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
//如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
//返回所有不常用单词的列表。您可以按任何顺序返回列表。
//
//示例 1：
//输入：A = "this apple is sweet", B = "this apple is sour"
//输出：["sweet", "sour"]
//
//示例 2：
//输入：A = "apple apple", B = "banana"
//输出：["banana"]
//
//提示：
//0 <= A.length <= 200
//0 <= B.length <= 200
//A 和 B 都只包含空格和小写字母。


class Solution {
public:
	
	unordered_set<string> GetWord(string s)
	{
		unordered_set<string> ss;
		int i, j;
		for (i = 0; i < s.size();i = j)
		{
			for (j = i + 1; j < s.size(); j++)
			{
				if (j < s.size() ||isspace(s[j]))
				{
					ss.insert(s.substr(i, j - i));
					break;
				}
			}
			j++;
			while (isspace(s[j]) && j < s.size())
			{
				j++;
			}
		}
		return ss;
	}
	vector<string> uncommonFromSentences(string A, string B)
	{
		unordered_set<string> ss1,ss2;
		vector<string> vs;
		ss1 = GetWord(A);
		ss2 = GetWord(B);
		for (auto& e : ss2)
		{
			if (!ss1.insert(e).second)
			{
				vs.push_back(e);
			}
		}
		return vs;
	}
};
int main4()
{
	string A = "this apple is sweet", B = "this apple is sour";
	Solution s;
	unordered_set<string> ss1;
	vector<string> vs;
	ss1 = s.GetWord(A);
	vs = s.uncommonFromSentences(A, B);
	for (auto&e : vs)
	{
		cout << e << " ";
	}
    system("pause");
    return 0;
}