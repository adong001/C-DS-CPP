#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <cmath>
#include <vector> 
using namespace std;

int MonenyofMonth[] = { 29, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };//每月转的钱
int DayofMonth[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//每月天数
vector<bool> month_prime = { false, true, true, false, true, //是否为素数月
							false, true, false, false, false, true, false };
vector<int> year_money = { 580, 579 };//闰年/非闰年一整年收益，

bool Isleap(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int main()
{
	int y1, m1, d1, y2, m2, d2;
	while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2)
	{
		int money = 0;
		bool f1 = Isleap(y1);//是否为闰年
		bool f2 = Isleap(y2);

		if (y1 == y2 && m1 == m2)//同年同月
		{
			money += month_prime[m1 - 1] ? (d2 - d1 + 1) : (d2 - d1 + 1) * 2;//非素数月就要*2
		}
		else if (y1 == y2 && m1 != m2)//同年不同月
		{
			//起始月
			//(DayofMonth[m1] - d1 + 1) --这个月最后一天-起始天数+1就是这个月经营的总天数
			//Isleap(y1) && m1 == 2) ? 1 : 0 --这个月是2月且这年是闰年这个月总天数就是29要+1
			//month_prime[m1 - 1] ? 1 : 2 --这个月为非素数月就要*2
			money += ((DayofMonth[m1] - d1 + 1) + ((f1 && m1 == 2) ? 1 : 0)) * (month_prime[m1 - 1] ? 1 : 2);
			m1++;

			//中间月
			for (; m1 < m2; m1++)
			{
				if (m1 == 2 && f1)//闰年且2月，多一天
				{
					money++;
				}
				money += MonenyofMonth[m1];
			}

			//结束月
			money += d2  * (month_prime[m2 - 1] ? 1 : 2);
		}
		else //不同年不同月
		{
			//开始年
			//开始月
			money += ((DayofMonth[m1] - d1 + 1) + ((f1 && m1 == 2) ? 1 : 0)) * (month_prime[m1 - 1] ? 1 : 2);
			m1++;
			//中间月
			for (; m1 <= 12; m1++)
			{
				if (m1 == 2 && f1)//闰年且2月，多一天
				{
					money++;
				}
				money += MonenyofMonth[m1];
			}
			y1++;

			//中间年
			for (; y1 < y2; y1++)
			{
				bool f = Isleap(y1);
				money += Isleap(y1) ? year_money[0]: year_money[1];//区分是否为闰年即可
			}

			//结束年
			money += d2 * (month_prime[m2 - 1] ? 1 : 2);
			for (--m2; m2 > 0; m2--)
			{
				if (m2 == 2 && f2)//闰年且2月，多一天
				{
					money++;
				}
				money += MonenyofMonth[m2];
			}
		}
		cout << money << endl;
	}
    return 0;
}