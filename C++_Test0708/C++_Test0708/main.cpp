#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int GetWeek(int year, int month, int day)//获得今天是星期几
{
	//吉姆拉尔森公式
	if (month == 1 || month == 2){
		month += 12;
		year -= 1;
	}

	int century = year / 100;
	year %= 100;
	int week = year + (year / 4) + (century / 4) - 2 * century +
		26 * (month + 1) / 10 + day - 1;

	week = (week % 7 + 7) % 7;
	if (week == 0){
		week = 7;
	}
	return week;
}

int GetDay(int year, int month, int num, int week)//获取某年某月的第num个星期week
{
	int firstday = GetWeek(year, month, 1);//这个月第一天是星期firstday
	int tmp1 = (num - 1) * 7;//(num周要加num-1个周，其他领头另算)
	int tmp2 = (week - firstday + 7) % 7;//week-firstday,代表星期几和第一天的星期数之差
	return tmp1 + tmp2 + 1;
}
void new_year_day(int year)
{
	cout << year << "-01-01\n";
}
void martin_day(int year)
{
	cout << year << "-01-" << GetDay(year, 1, 3, 1) << endl;
}
void president_day(int year)
{
	cout << year << "-02-" << GetDay(year, 2, 3, 1) << endl;
}
void memorial_day(int year)
{
	int lastday = GetWeek(year, 5, 31);//获取5月最后一天是星期几
	cout << year << "-05-" << 31 - (lastday - 1) << endl;
}
void independence_day(int year)
{
	cout << year << "-07-04\n";
}
void labor_day(int year)
{
	cout << year << "-09-0" << GetDay(year, 9, 1, 1) << endl;
}
void thanks_day(int year)
{
	cout << year << "-11-" << GetDay(year,11, 4, 4) <<endl;////
}
void christmas_day(int year)
{
	cout << year << "-12-25\n";
}
void holiday_usa(int year)
{
	new_year_day(year);
	martin_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	labor_day(year);
	thanks_day(year);
	christmas_day(year);
	cout << endl;
}

int main0()
{
	int year;
	while (cin >> year)
	{
		holiday_usa(year);
	}
    return 0;
}