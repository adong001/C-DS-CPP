#include"data.h"

Data::Data(int year, int month, int day, int N_Day)
{
	m_year = year;
	m_month = month;
	m_day = day;
	if (N_Day)
	{
		FindNData(m_year,m_month,m_day, N_Day);
		printf("第%d天后为%d年%d月%d日\n", N_Day, m_year,m_month, m_day);
	}
}
void Data::FindNData(int &year, int &month, int &day, int N_Day)
{
	while (N_Day)//要跳转的天数作为循环退出条件
	{
		int _MonthDay = MonthDay(year, month);//得到这年这个月的天数
		if (N_Day <= (_MonthDay - day))//判断要跳转的天数加上今天的日期是否大于这月的总天数
		{
			day += N_Day;
			return;
		}
		else//本月剩余天数不够跳转的天数
		{
			N_Day -= (_MonthDay - day);//这月总天数-今天的日，就是这月可以跳过的天数
			day = 0;//日期先置为0,方便进入下月加减
			month++;//这月跳过，month++

			if (month == 13)//若month越界
			{
				year++;//进入新的一年
				month = 1;
			}
		}
	}
}

int MonthDay(int year, int month)
{
	int ArrMon[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//闰年二月取第一个元素，平年1-12依次从第二个元素取
	if (IsLeap(year) && month == 2)//若为闰年且为二月，
	{
		return ArrMon[0];
	}
	return ArrMon[month];
}

int IsLeap(int year)
{
	return ((year % 100 == 0 && year % 100 != 0) || year % 400 == 0);
}