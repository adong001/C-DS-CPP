/**
* struct Interval {
*	int start;
*	int end;
* };
*/

class Solution
{
private:
	//排列出所有组合
	vector<string> dp(int n, int k, string str2, int cnts)
	{
		vector<string> ret;
		if (cnts <= 0)
		{
			return ret;
		}
		char ch = 'x';
		if (int i = 0; i <= n - k; i++)
		{
			string tmp = str2;
			cnts--;
			dp(, )

		}
		return ret;
	}
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	* 返回Interval类，start代表汪仔最少做对了多少道题，end代表汪仔最多做对了多少道题。
	* @param n int整型 选择题总数
	* @param k int整型 朋友做对的题数
	* @param str1 string字符串 长度为n只包含ABCD的字符串，其中第i个代表汪仔第i题做出的选择
	* @param str2 string字符串 长度为n只包含ABCD的字符串，其中第i个代表朋友第i题做出的选择
	* @return Interval类
	*/
	Interval solve(int n, int k, string str1, string str2)
	{
		solve ret;
		int Max = -1;
		int Min = n + 1;
		vector<string> vs = dp(str2);
		for (int i = 0; i < vs.size(); i++)
		{
			int cnts = 0;
			for (int j = 0; j < n; j++)
			{
				if (str1[j] == vs[i][j])
				{
					cnts++;
				}
			}
			Min = Min > cnts ? cnts : Min;
			Max = Max < cnts ? cnts : Max;
		}
		ret.start = Min;
		ret.end = Max;
		return ret;
	}
};