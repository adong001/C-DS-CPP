#include"data.h"


Data::Data(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}


ostream & operator << (ostream & os, Data & data)
{
	os << data.m_year << "年" << data.m_month << "月" << data.m_day << "日" << endl;
	return os;
}
Data Data::operator + (int N_Day)const
{
	Data tmp = *this;
	if (!N_Day)
	{
		return tmp;
	}
	while (N_Day)//要跳转的天数作为循环退出条件
	{
		if (N_Day >= 366)
		{
			if ((tmp.m_month >= 3 && IsLeap(tmp.m_year + 1)) || (tmp.m_month <= 2 && IsLeap(tmp.m_year)))
			//if (IsLeap(tmp.m_year))
			{
				N_Day -= 366;
			}
			else
			{
				N_Day -= 365;
			}
			tmp.m_year += 1;
			continue;
		}
		int _MonthDay = MonthDay(tmp.m_year, tmp.m_month);//得到这年这个月的天数
		if (N_Day <= (_MonthDay - tmp.m_day))//判断要跳转的天数加上今天的日期是否大于这月的总天数
		{
			tmp.m_day += N_Day;
			return tmp;
		}
		else//本月剩余天数不够跳转的天数
		{
			N_Day -= (_MonthDay - tmp.m_day);//这月总天数-今天的日，就是这月可以跳过的天数
			tmp.m_day = 0;//日期先置为0,方便进入下月加减
			tmp.m_month++;//这月跳过，month++

			if (tmp.m_month == 13)//若month越界
			{
				tmp.m_year++;//进入新的一年
				tmp.m_month = 1;
			}
		}
	}
	return tmp;
}

Data Data::operator = (Data & data)
{
	m_year = data.m_year;
	m_month = data.m_month;
	m_day = data.m_day;
	return *this;
}

Data Data::operator ++ ()
{
	return (*this= (*this + 1));
}

Data Data::operator -- ()
{
	return (*this = (*this - 1));
}

Data Data:: operator -(int N_Day)const
{
	Data tmp = *this;
	if (!N_Day)
	{
		return tmp;
	}
	while (N_Day)//要跳转的天数作为循环退出条件
	{
		if (N_Day >= 366)
		{
			if ((tmp.m_month >= 3 && IsLeap(tmp.m_year))||(tmp.m_month<=2 && IsLeap(tmp.m_year - 1)))
			{
				N_Day -= 366;
			}
			else
			{
				N_Day -= 365;
			}
			tmp.m_year -= 1;
		}
		else if (N_Day <= tmp.m_day)//判断要跳转的天数加上今天的日期是否大于这月的总天数
		{
			tmp.m_day -= N_Day;
			if (tmp.m_day == 0)//防止减为0
			{
				tmp.m_month--;//这月跳过，month++
				if (tmp.m_month == 0)//若month越界
				{
					tmp.m_year--;//进入新的一年
					tmp.m_month = 12;
				}
				tmp.m_day = MonthDay(tmp.m_year, tmp.m_month);;//日期置为上月的最后一天
			}
			return tmp;
		}
		else//本月剩余天数不够跳转的天数
		{
			N_Day -= tmp.m_day;//这月总天数-今天的日，就是这月可以跳过的天数	
			tmp.m_month--;//这月跳过，month++
			if (tmp.m_month == 0)//若month越界
			{
				tmp.m_year--;//进入新的一年
				tmp.m_month = 12;
			}
			tmp.m_day = MonthDay(tmp.m_year, tmp.m_month);;//日期置为上月的最后一天
		}
	}
	return tmp;
}
bool Data:: operator <(Data & data)const
{
	if (m_year < data.m_year)
	{
		return true;
	}
	else if (m_year == data.m_year)
	{
		if (m_month < data.m_month)
		{
			return true;
		}
		else if (m_month == data.m_month)
		{
			if (m_day < data.m_day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Data:: operator >(Data & data)const
{
	if (m_year > data.m_year)
	{
		return true;
	}
	else if (m_year == data.m_year)
	{
		if (m_month > data.m_month)
		{
			return true;
		}
		else if (m_month == data.m_month)
		{
			if (m_day > data.m_day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Data:: operator <=(Data & data)const
{
	return !(*this>data);
}

bool Data:: operator >=(Data & data)const
{
	return !(*this < data);
}

bool Data:: operator ==(Data & data)const
{
	return (m_year == data.m_year && 
		    m_month == data.m_month &&
			m_day == data.m_day);
}

bool Data:: operator !=(Data & data)const
{
	return !(*this == data);
}

int Yearday(int year, int month, int day)
{
	int ArrMon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int num = day;
	for (int i = 1; i < month;i++)
	{
		num += ArrMon[i];
	}
	if (IsLeap(year))
	{
		num++;
	}
	return num;
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
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}