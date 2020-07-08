#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <cmath>
#include <vector> 
using namespace std;

vector<bool> month_prime = { true, true, false, true, 
								false, true, false, true,
								true, false, true, false, true };
vector<int> year_money = { 517, 486 };//非闰年/闰年一整年收益，
bool Isleap(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
int main2()
{
	int y1, m1, d1, y2, m2, d2;
	while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2)
	{
		int money1 = 0, money2 = 0, money3 = 0;
		int f1 = Isleap(y1) ? 1 : 2;
		int f2 = Isleap(y2) ? 1 : 2;
		if (y1 == y2)
		{
			int i = 0;
			if (m1 == m2)
			{
				if (m1 == 2)
				{
					money1 += ((d2 - d1) + 1) * f1;
				}
				else
				{
					money1 += (d2 - d1 + 1) * ((m1%2 != 0) + 1 || (m1 == 8) + 1);//在1-12月中%2!=0也是非素数
				}
			}
			if (m1 <= 2)
			{

			}
			for (; i < m2; i++)
			{
				money1 += month_prime[i];
			}
		}
		else
		{
			if (y1 <= 2)
			{
				int flag = 1;
				money1 += Isleap(y1) ? month_prime[0]: month_prime[2], flag = 2;
				if (y1 == 1)
				{
					money1 = money1- d1 + 1;
				}
				else
				{
					money1 -= ( d1 + 1)* flag;
				}
			}
			for (int i = m1 + 1; i < 13; i++)
			{
				money1 += month_prime[i];
			}
		}
	}
    return 0;
}