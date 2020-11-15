#include<vector>
class Solution {

private:
	//旋转90°
	vector<string> rotate(vector<string>& s)
	{
		int n = s.size();
		vector<string> ret(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ret[i] += s[n - j - 1][i];
			}
		}
		return ret;
	}

	string decip(vector<string>& s1, vector<string>& s2)
	{
		int n = s1.size();
		string ret;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (s1[i][j] == '0')
				{
					ret += s2[i][j];
				}
			}
		}
		return ret;
	}
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	* 返回一行字符串，表示原文。
	* @param s1 string字符串vector N*N的01矩阵，表示解密纸，0表示透明，1表示涂黑
	* @param s2 string字符串vector 字符矩阵，表示密文
	* @return string字符串 */
	string rotatePassword(vector<string>& s1, vector<string>& s2)
	{
		string ret;
		for (int i = 0; i < 4; i++)
		{
			ret += decip(s1, s2);
			s1 = rotate(s1);
		}
		return ret;
	}
};