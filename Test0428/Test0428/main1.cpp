#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//（1）输入年月日输出此日是今年第几天

#define MONTHERROR -1
#define YEARERROR-2
bool Year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int YearMonth_days(int year, int month)
{
	int day;
	if (year < 1)return YEARERROR;
	else if (month < 1 || month>12)return MONTHERROR;
	int Month[12] = { 29, 31, 28, 31, 30, 31, 30.31, 31, 30, 31, 30, 31 };
	if (month == 2 && Year(year))
	{
		day = Month[0];
	}
	else
	{
		day = Month[month];
	}
	return day;
}
int main1()
{
	int year, month, days;
	char ch;
	for (;;)
	{
		cout << "请输入年月：\n";
		cin >> year >> month;
		days = YearMonth_days(year, month);
		switch (days)
		{
		case YEARERROR:cout << "输入年份有误,请重新输入：\n"; break;
		case MONTHERROR:cout << "输入月份有误,请重新输入：\n"; break;
		default:cout << year << "年" << month << "月有" << days << "天" << endl; break;
		}
		cout << "继续请按Y，退出请按N:\n";
		cin >> ch;
		if (ch == 'N' || ch == 'n')break;
	}
	return 0;
}







