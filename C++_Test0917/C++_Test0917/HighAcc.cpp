#include"HighAcc.h"

HighAcc::HighAcc(string& s)
{
	m_size = s.size();
	string::reverse_iterator i;//迭代器
	int j;
	memset(m_data, 0, NUMSIZE);//将数组全部置为0；
	for (j = 0, i = s.rbegin(); i != s.rend(); i++, j++)//从最后一位开始逆置字符串
	{
		m_data[j] = *i - '0';//将字符数字转换为该数字对应ASCII的标号，
		//例如，字符‘1’- ASCII标号为1的字符SOH(start of headline)
	}
	/*for (auto &i = s.end(); i != s.begin(); i--, j++)
	{
	m_data[j] = *i - '0';
	}*/
}
HighAcc HighAcc::operator *(HighAcc& H)
{
	int tmp, i, j;
	HighAcc sum;
	if (m_size == 1 && m_data[0] == 0 ||
		H.m_size == 1 && H.m_data[0] == 0)//任何数 * 0 = 0
	{
		return sum;
	}
	for (i = 0; i < m_size; i++)
	{
		for (j = 0; j < H.m_size; j++)
		{
			tmp = m_data[i] * H.m_data[j] + sum.m_data[i + j];
			sum.m_data[i + j] = tmp % 10;
			sum.m_data[i + j + 1] += tmp / 10;
		}
	}
	sum.m_size = m_size + H.m_size - !sum.m_data[m_size + H.m_size - 1];//，两数相乘，积长度为两数长度之和或-1，
	//若最高位不为真，则长度-1，
	return sum;
}


HighAcc HighAcc::operator +(HighAcc& H)
{
	int tmp, i;
	HighAcc sum;
	/*if (m_size == 1 && m_data[0] == 0 ||
		H.m_size == 1 && H.m_data[0] == 0)
		{
		sum = H;
		}*/
	int MaxSize = m_size > H.m_size ? m_size : H.m_size;
	sum.m_size = MaxSize + 1;//n位数+m位数=n+m或n+m+1位数（多拿一位，防止进位）
	for (i = 0; i < MaxSize; i++)
	{
		tmp = m_data[i] + H.m_data[i] + sum.m_data[i];
		sum.m_data[i] = tmp % 10;
		sum.m_data[i + 1] = tmp / 10;
	}
	sum.m_size -= !sum.m_data[MaxSize];//若最高位不为零，则不用减去
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


HighAcc::operator string()//string强制转换符重载
{
	int i;
	string s;
	for (i = m_size - 1; i >= 0; i--)
	{
		s.push_back(m_data[i] + '0');//push进string类中时转换为字符型
	}
	return s;
}