#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;

//int main()
//{
//	string n1, n2;
//	while (cin >> n1 >> n2)
//	{
//		string ret;
//		int carry = 0, sum = 0;
//		int i = n1.size() - 1;
//		int j = n2.size() - 1;
//		if (i < j)
//		{
//			n1.insert(n1.begin(),j-i,'0');
//			i = j;
//		}
//		else
//		{
//			n2.insert(n2.begin(), i - j, '0');
//		}
//		for (; i >= 0; i--)
//		{
//			sum = n1[i] + n2[i] - 2 * '0'+ carry;
//			carry = sum / 10;
//			ret.push_back(sum % 10 + '0');
//		}
//		if (carry > 0)
//		{
//			ret += '1';
//		}
//		reverse(ret.begin(), ret.end());
//		cout << ret << endl;
//	}
//    return 0;
//}
int main()
{
	int n;
	while(cin >> n)
	{
		if (n <= 2)
		{
			cout << -1 << endl;
			continue;
		}
		if(n%2)
		int ret;
		vector<vector<int>> vv(n, vector<int>(2 * n - 1, 0));
		vv[0][0] = 1;

		
	}
	return 0;
}