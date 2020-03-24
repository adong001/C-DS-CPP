//#include"bigint.h"
//#include"rsa.h"
//BigInt::BigInt()
//{
//	RSA rsa;
//	rsa.getKeys();
//	Key key = rsa.getallKey();
//}
//
//BigInt::BigInt(const string& num) //构造函数
//{
//	m_number = num;
//}
//
//
//BigInt::BigInt(const int num)//构造函数
//{
//	int tmp = num;
//	while (tmp)
//	{
//		m_number.insert(0, 1, tmp % 10 + '0');
//		tmp /= 10;
//	}
//}
//
//bool BigInt::less( string& num1,  string& num2)//num1<num2返回真
//{
//	if (num1.size() > num2.size())
//	{
//		return false;
//	}
//	else if (num1.size() < num2.size())
//	{
//		return true;
//	}
//	else
//	{
//		return num1 < num2;
//	}
//}
//
//
////RSA算法的数据都是大的正整数，所以这里不用考虑负数和0
//string BigInt::add(string num1, string num2)
//{
//	int len1 = num1.size();
//	int len2 = num2.size();
//	string ret;
//
//	if (less(num1, num2))//让num1做较大的数
//	{
//		swap(num1, num2);
//		swap(len1, len2);
//	}
//
//	ret.resize(len1);
//	int step = 0;//进位
//	int i, j, tmp;
//
//	for (i = len1 - 1, j = len2 - 1; i >= 0; --i)//从后往前加
//	{
//		if (j >= 0)//较小的数还未加完
//		{
//			tmp = num1[i] + num2[j] + step - 2 * '0';
//			--j;
//		}
//		else//较小的数加完，较大的数和进位加
//		{
//			tmp = num1[i] + step - '0';
//		}
//
//		ret[i] = tmp % 10 + '0';//加完的个位放在ret后面
//		step = tmp / 10;//进位
//	}
//	if (step == 1)
//	{
//		ret.insert(0, 1, '1');//若最高位向上进位，只能进1
//	}
//	return ret;
//
//}
//
////RSA算法的不会用到减法，这里只是为了写除法，只考虑大正整数数减小正整数，不考虑0，负数其他情况
//string BigInt::sub(string num1, string num2)
//{
//	string ret;
//	int len1 = num1.size();
//	int len2 = num2.size();
//
//	ret.resize(len1);
//	int step = 0;//进位
//	int i, j, tmp;
//
//	for (i = len1 - 1, j = len2 - 1; i >= 0; --i)
//	{
//		tmp = 0;
//		if (j >= 0)//较小的数还未减完
//		{
//			if (num1[i] < num2[j])//需要借位
//			{
//				tmp = 10;//向上一位借一位，相当于+10
//				num1[i - 1]--;//向上借位上一位-1
//			}
//			ret[i] = num1[i] + tmp - num2[j] + '0';
//			--j;
//		}
//
//		else
//		{
//			if (num1[i] < '0')//这一位被后一位借完后小于0，则向前一位借
//			{
//				ret[i] = num1[i] + 10;
//				--num1[i - 1];
//			}
//			else
//			{
//				ret[i] = num1[i];//借位大于0，就保留
//			}
//		}
//
//	}
//	//删除前置0,比如0008---》8
//	while (ret.size() > 1 && ret[0] == '0')
//	{
//		ret.erase(0, 1);//不断删除头部的0
//	}
//	return ret;
//}
//
//
////同样，乘法只考虑大正整数*大正整数
//string BigInt::mul(string num1, string num2)
//{
//	
//	int len1 = num1.size();
//	int len2 = num2.size();
//	if (less(num1, num2))//让num1做较大的数
//	{
//		swap(num1, num2);
//		swap(len1, len2);
//	}
//    string ret = "0";
//	for (int i = len2 - 1; i >= 0; --i)
//	{
//		int digit = num2[i] - '0';//获得当前乘数对应位的值
//		int step = 0;//进位
//
//		string tmp = num1;//当前乘积结果
//		for (int j = len1 - 1; j >= 0; --j)
//		{
//			tmp[j] = (tmp[j] - '0') * digit + step;//整数值
//
//			if (tmp[j] > 9)
//			{
//				step = tmp[j] / 10;
//				tmp[j] %= 10;
//			}
//
//			else//没有进位
//			{
//				step = 0;
//			}
//			tmp[j] += '0';//还原成字符
//
//		}
//		if (step > 0)//判断最最后一位是否还要进位
//		{
//			tmp.insert(0, 1, step + '0');
//		}
//		tmp.append(len2 - 1 - i, '0');//num2个位乘num1 tmp后面不加0，十位相乘加一个0，以此类推
//
//		//下面累计一次乘法的结果
//		ret = add(ret, tmp);
//	}
//	return ret;
//}
//
//
//
//pair<string, string> BigInt::div(string num1, string num2)//除法返回商和余数
//{
//	//借助减法实现-->105/2 = 105-20-20-20-20-20  商=减的次数，余数=不能减的数
//
//	int len1 = num1.size();
//	int len2 = num2.size();
//	if (less(num1, num2))//这个除法只是用来获取余数, num1 % num2 = num2 % num1,为了方便计算，就让大除小
//	{
//		swap(num1, num2);
//		swap(len1, len2);
//	}
//	string ret;//商
//	string rem = num1;//余数
//
//	int diffNum = num1.size() - num2.size();//给除数进行放大，按照10的倍数放大
//	num2.append(diffNum, '0');
//	for (int i = 0; i <= diffNum; ++i)
//	{
//		//记录减法执行的次数
//		char count = '0';
//		while (true)
//		{
//			if (less(rem, num2))//余数小于除数
//			{  
//				break;
//			}
//			rem = sub(rem, num2);//余数不断减去除数，减的次数count就是商
//			++count;
//		}
//		ret += count;
//		//除数减小10倍
//		num2.pop_back();
//	}
//
//	//删除前置的0
//	while (ret.size() > 1 && ret[0] == '0')
//	{
//		ret.erase(0, 1);
//	}
//
//	return make_pair(ret, rem);
//}
//
//
//BigInt BigInt::operator+(BigInt& bi)
//{
//	string ret = add(m_number, bi.m_number);
//	return BigInt(ret);
//}
//
//BigInt BigInt::operator-(BigInt& bi)
//{
//	string ret = sub(m_number, bi.m_number);
//	return BigInt(ret);
//}
//
//BigInt BigInt::operator*(BigInt& bi)
//{
//	string ret = mul(m_number, bi.m_number);
//	return BigInt(ret);
//}
//
//BigInt BigInt::operator/(BigInt& bi)
//{
//	string ret = div(m_number, bi.m_number).first;
//	return BigInt(ret);
//}
//
//BigInt BigInt::operator%(BigInt& bi)
//{
//	string ret = div(m_number, bi.m_number).second;
//	return BigInt(ret);
//}
//
//
//ostream& operator<<(ostream& os, BigInt& bi)
//{
//	os << bi.m_number;
//	return os;
//}
//istream& operator>>(istream& is, BigInt& bi)
//{
//	is >> bi.m_number;
//	return is;
//}
//
//
//
