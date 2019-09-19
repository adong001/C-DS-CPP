#include"HighAcc.h"

HighAcc::HighAcc(string& s)
{
	m_size = s.size();
	m_data = new char[m_size];
	string::reverse_iterator i;
	int j;
	for (j = 0,i = s.rbegin(); i !=s.rend(); i++,j++)
	{
		m_data[j] = *i - '0';
	}
}
//HighAcc HighAcc::operator *(HighAcc& H)
//{
//
//}

HighAcc HighAcc::operator +(HighAcc& H)
{
	int tmp, i;
	HighAcc sum;
	//DealData();
	//H.DealData();
	int MaxSize = m_size > H.m_size ? m_size : H.m_size;
	sum.m_size = MaxSize + sum.m_data[MaxSize];
	sum.m_data = new char[sum.m_size];
	for (i = 0; i < MaxSize; i++)
	{
		tmp = m_data[i] + H.m_data[i] + sum.m_data[i];
		sum.m_data[i] = tmp % 10;
		sum.m_data[i] = tmp / 10;
	}
	sum.m_size = MaxSize + sum.m_data[MaxSize];
	return sum;
}

//void HighAcc::DealData()
//{
//	int i, j;
//	char tmp;
//	for (i = 0, j = m_size - 1; i < j; i++, j--)
//	{
//		tmp = m_data[i]-'\0';
//		m_data[i] = m_data[j]-'\0';
//		m_data[j] = tmp;
//	}
//}


//ostream& operator <<(ostream& os, HighAcc& H)
//{
//	int i;
//	for (i = H.m_size - 1; i > 0; i++)
//	{
//		os << H.m_data[i];
//	}
//	os << endl;
//	return os;
//}
//
//istream& operator >>(istream& is, HighAcc& H)
//{
//	char tmp[1024];
//	is >> tmp;
//	H.m_size = strlen(tmp);
//	H.m_data = new char[H.m_size];
//	strcpy(H.m_data, tmp);
//	return is;
//}


HighAcc::operator string()
{
	int i;
	string s;
	for (i = m_size - 1; i >= 0; i++)
	{
		s.push_back(m_data[i]+'0');
	}
	return s;
}