#include"data.h"

Data::Data(int year, int month, int day, int N_Day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}
//Data::Data(int year, int month, int day, int N_Day)
//{
//	m_year = year;
//	m_month = month;
//	m_day = day;
//	if (N_Day)
//	{
//		FindNData(year,month,day, N_Day);
//		printf("第%d天后为%d年%d月%d日\n", N_Day, year,month, day);
//	}
//}
//void Data::FindNData(int &year, int &month, int &day, int N_Day)
//{
//	while (N_Day)//要跳转的天数作为循环退出条件
//	{
//if (N_Day >= 366)
//{
//	NewData.m_year + 1;
//	if (IsLeap(NewData.m_year))//是润年
//	{
//		N_Day -= 366;
//	}
//	else
//	{
//		N_Day -= 365;
//	}
//}
//		int _MonthDay = MonthDay(year, month);//得到这年这个月的天数
//		if (N_Day <= (_MonthDay - day))//判断要跳转的天数加上今天的日期是否大于这月的总天数
//		{
//			day += N_Day;
//			return;
//		}
//		else//本月剩余天数不够跳转的天数
//		{
//			N_Day -= (_MonthDay - day);//这月总天数-今天的日，就是这月可以跳过的天数
//			day = 0;//日期先置为0,方便进入下月加减
//			month++;//这月跳过，month++
//
//			if (month == 13)//若month越界
//			{
//				year++;//进入新的一年
//				month = 1;
//			}
//		}
//	}
//}

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
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

Data Data:: operator+(int N_Day)const
{
	int _MonthDay;
	Data NewData(m_year, m_month,m_day);
	while (N_Day)//要跳转的天数作为循环退出条件
	{
		if (N_Day >= 366)
		{
			NewData.m_year += 1;
			if (IsLeap(NewData.m_year))//是润年
			{
				N_Day -= 366;
			}
			else
			{
				N_Day -= 365;
			}
			continue;
		}
	   _MonthDay = MonthDay(NewData.m_year, NewData.m_month);//得到这年这个月的天数
		if (N_Day <= (_MonthDay - NewData.m_day))//判断要跳转的天数加上今天的日期是否大于这月的总天数
		{
			NewData.m_day += N_Day;
			return NewData;
		}
		else//本月剩余天数不够跳转的天数
		{
			N_Day -= (_MonthDay - NewData.m_day);//这月总天数-今天的日，就是这月可以跳过的天数
			NewData.m_day = 0;//日期先置为0,方便进入下月加减
			NewData.m_month++;//这月跳过，month++

			if (NewData.m_month == 13)//若month越界
			{
				NewData.m_year++;//进入新的一年
				NewData.m_month = 1;
			}
		}
	}
	return NewData;
}

ostream & operator <<(ostream & os, Data & data)
{
	os << data.m_year << "年" << data.m_month << "月" << data.m_day << "日" << endl;
	return os;
}