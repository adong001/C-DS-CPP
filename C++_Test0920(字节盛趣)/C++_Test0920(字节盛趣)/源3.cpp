
 struct Interval {
	int start;
	int end;
 };


class Solution
{
private:
	static const int mod;
	int FindPath(vector<vector<bool>> vv, int start, int end)
	{
		static int cnts = 0;
		int sum = 0;
		if (vv[start][end] == true && end == vv.size() - 1)
		{
			return cnts;
		}
		if (vv[start][end] == false)
		{
			return -1;
		}
		return FindPath(vv, )
	}
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	* 在Interval类中返回结果，其中start表示有效字的个数，end表示全部有效字编号的和除以100000007的余数。
	* @param N int整型 字的总数
	* @param M int整型 连接关系的总数
	* @param conn Interval类vector 全部连接关系
	* @return Interval类
	*/

	Interval trim(int N, int M, vector<Interval>& conn)
	{
		Interval ret;
		//两点联通就值true
		vector<vector<bool>> grap(N + 2, vector<bool>(N + 2, false));
		for (int i = 0; i < M; i++)
		{
			vv[conn[i].start][conn[i].end] = true;
		}
		for (int i = 1; i <= N; i++)
		{
			int cnts = 0;
			if (vv[0][i] == true)
			{
				cnts += FindPath(vv, i);
			}
		}
		ret.start =
			return ret;
	}
};
int Solution::mod = 100000007;