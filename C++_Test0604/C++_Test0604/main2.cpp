#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
class LCA 
{
public:
	int getLCA(int a, int b)
	{
		/*vector<int> v1,v2;
		for (; a; v1.push_back(a), a /= 2);
		for (; b; v2.push_back(b), b /= 2);
		int tmp = 1;
		for (int i = v1.size() - 1, j = v2.size() - 1; i >= 0 && j >= 0; i--, j--)
		{
			if (v1[i] != v2[j])
			{
				break;
			}
			tmp = v1[i];
		}
		cout << tmp << endl;*/
		while (a != b)
		{
			if (a > b)
			{
				a /= 2;
			}
			else
			{
				b /= 2;
			}
		}
		return a;
	}
};
int main2()
{
	int num;
	while (cin >> num)
	{
		int max = 0,sum = 0;
		for (int i = 0; i < 32;i++)
		{
			int sum = 0;
			for (; ((num >> i) & 1) && i < 32;i++)
			{
				sum++;
			}
			sum > 0 ? i-- : i;
			max = max < sum ? sum : max;
		}
		cout << max << endl;
	}
    return 0;
}