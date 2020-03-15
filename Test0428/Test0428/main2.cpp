#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#define YEARERROR -2
#define MONTHERROR -1
#define DAYSERROR -3
int Month[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool Year(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int YearMonth_days(int year, int month)
{
	int day;
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
int YearMonth_total(int year, int month, int days)
{
	int total, M_month = 0, D_days;
	if (year < 1)return YEARERROR;
	if (month < 1 || month>12)return MONTHERROR;
	D_days = YearMonth_days(year, month);
	if (days < 1 || days>D_days)return DAYSERROR;
	if (12 >= month&&month>2)
	{
		for (int i = 1; i < month; i++)
		{
			M_month += Month[i];
		}
		total = days + M_month + Year(year);
	}
	else if (month > 1){ total = Month[1] + days; return total; }
	else{ total = days; return total; }
	return total;
}
int main2()
{
	int year, month, days, total;
	char ch;
	for (;;)
	{
		cout << "请输入年月日：\n";
		cin >> year >> month >> days;
		total = YearMonth_total(year, month, days);
		switch (total)
		{
		case YEARERROR:cout << "输入年份有误,请重新输入：\n"; break;
		case MONTHERROR:cout << "输入月份有误,请重新输入：\n"; break;
		case DAYSERROR:cout << "输入日有误,请重新输入：\n"; break;
		default:cout << "此日为此年的" << total << "天" << endl; break;
		}
		cout << "继续请按Y，退出请按N:\n";
		cin >> ch;
		if (ch == 'N' || ch == 'n')break;
	}
	return 0;
}

//（2）输入年月日加上多少天输出日期


bool Is_Leap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int YearMonth_To_Day(int year, int month)
{
	if (year < 1) return YEARERROR;
	if (month < 1 || month > 12) return MONTHERROR;
	//int total_day[]={0,31,59,90,120,151,181,21,243,273,304,334}; 
	//total = total_day[month - 1] + day + (month >= 2 && Is_Leap(year));
	int days[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && Is_Leap(year))
	{
		month = 0;
	}
	return days[month];
}

int YearMonthDays_To_total(int year, int month, int days)
{
	int total = 0;
	if (year < 1) return YEARERROR;
	if (month < 1 || month > 12) return MONTHERROR;
	if (days < 1 || days>31)return DAYSERROR;
	int mday = YearMonth_To_Day(year, month);
	for (int i = 1; i < month; ++i)
	{
		total = total + YearMonth_To_Day(year, i);
	}
	total = total + days;
	return total;
}
int main22()
{
	int year, month, days;
	int total;
	char ch;
	for (;;)
	{
		cout << "input year month days:";
		cin >> year >> month >> days;
		total = YearMonthDays_To_total(year, month, days);
		switch (total)
		{
		case YEARERROR:cout << "intput year is error!" << endl; break;
		case MONTHERROR:cout << "intput year is error!" << endl; break;
		case DAYSERROR:cout << "intput year is error!" << endl; break;
		default:cout << year << " year " << month << " month " << days << " days=> ";
			cout << total << endl;
			break;
		}
		cout << "Y继续，N退出" << endl;
		cin >> ch;
		if (ch == 'N' || ch == 'n')break;
	}
	return 0;
}