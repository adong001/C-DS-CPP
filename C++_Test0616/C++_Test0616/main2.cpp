#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

bool IsLeap(const int& year)
{
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}
int main3()
{
	int month_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int days = 0;
		days += day;
		if (month <= 2)
		{
			days += 31;
		}
		else
		{
			for (int i = 0; i < month - 1; i++)
			{
				days += month_day[i];
			}
			IsLeap(year) ? days += 1 : days;
		}
		cout << days << endl;
	}
    return 0;
}