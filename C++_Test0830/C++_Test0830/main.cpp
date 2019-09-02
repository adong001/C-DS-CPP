#include<iostream>
using namespace std;

class Test
{
public:
	const int i;
	int &ri;
	//Test(int &a) : i(3), ri(a)
	//{}
	/*Test()//±àÒë³ö´í£¬
	{
	i = 10;
	ri = i;
	}*/
};


class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);    Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();   
	Date operator--(int);  
	bool operator>(const Date& d)const;  
	bool operator>=(const Date& d)const; 
	bool operator<(const Date& d)const;   
	bool operator<=(const Date& d)const;  
	bool operator==(const Date& d)const;  
	bool operator!=(const Date& d)const;
private:   
	int _year;  
	int _month;   
	int _day;
};

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
int main()
{

	system("pause");
	return 0;
}