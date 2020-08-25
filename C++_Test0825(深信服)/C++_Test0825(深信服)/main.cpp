#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <map>
using namespace std;

//将字符串src中数字a字符转化成字符b
void ChangeStr(string& src, const string& det,char b)
{
	for (auto& e : src)
	{
		if(det.find(e) != string::npos)
		{
			e = b;
		}
	}
}

int main()
{
	int n;
	string src;
	while (cin >> src >> n)
	{
		int a, b;
		map<char, string> mdet;//存储修改的键值对，比如0-1,0-2,3-4，4-5，最终存储为(0,1),(1,#)(3,54)
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			//这个待改变的字符未插入时，就要加入
			if (!mdet[a + '0'].empty())
			{
				if (!mdet[b + '0'].empty())
				{
					//0-1 ,1-2 ,存储就是(0,1),(1,#)->(0,12),(2,#)
					mdet[]
				}
			}
		}
		string det;
		ChangeStr(src, det, b + '0');
		cout << src << endl;
	}
	return 0;
}