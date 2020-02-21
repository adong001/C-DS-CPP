#include"bigint.h"

BigInt::BigInt(const string& num)//构造函数
{

}


BigInt::BigInt(const int num)//构造函数
{

}

string BigInt::add(string num1, string num2)
{
	int len1 = num1.size();
	int len2 = num2.size();
	string ret;
	if (len1 == 1 && num1[0] == '0' || len2 == 1 && num2[0] == '0')
		//一个数是0,结果返回另一个数的值，稍微提高效率
	{
		return num1[0] == '0' ? num2 : num1;
	}


	if (num1[0] == '-' && num2[0] == '-')//负负
	{
		string s1(num1.begin() + 1, num1.end());
		string s2(num2.begin() + 1, num2.end());
		ret += '-';
		ret += add(s1, s2);//两个负数相加 == 他们绝对值相加再取反
		return ret;
	}

	if (num1[0] == '-' && num2[0] != '-')//负正，正负
	{
		string tmp;
		if (num1[0] == '-')//num1为负数
		{
			tmp.append(num1.begin() + 1, num1.end());
			return sub(num2, tmp);//正负数相加 == 正数 - 负数的绝对值
		}
		else
		{
			tmp.append(num2.begin() + 1, num2.end());
			return sub(num1, tmp);//正负数相加 == 正数 - 负数的绝对值
		}
	}

	//正正
	if (num1.size() < num2.size())//让num1做较大的数
	{
		swap(num1, num2);
		swap(len1, len2);
	}

	ret.resize(len1);
	int step = 0;//进位
	int i, j, tmp;

	for (i = len1 - 1, j = len2 - 1; i >= 0; --i)
	{
		if (j >= 0)//较小的数还未加完
		{
			tmp = num1[i] + num2[j] + step - 2 * '0';
			--j;
		}
		else
		{
			tmp = num1[i] + step - '0';
		}
		ret[i] = tmp % 10 + '0';
		step = tmp / 10;
	}
	if (step == 1)
	{
		ret.insert(0, 1, '1');//若最高位向上进位，只能进1
	}
	return ret;

}

string BigInt::sub(string num1, string num2)
{
	string ret;
	int len1 = num1.size();
	int len2 = num2.size();

	if (len1 == 1 && num1[0] == '0')//num1为0时
	{
		if (num2[0] == '-')//num2为负数时
		{
			ret.append(num2.begin() + 1, num2.end());//0-负数=负数的绝对值
			return ret;
		}
		else
		{
			return  num2;
		}
	}

	else if (len2 == 1 && num2[0] == '0')//num2为0时
	{
		return  num1;
	}


	else if (num1[0] == '-' && num2[0] != '-') //负 - 正 = -(|负|+正)
	{
		string tmp(num1.begin() + 1, num1.end());
		ret += '-';
		ret += add(tmp, num2);
		return ret;
	}

	else if (num1[0] != '-' && num2[0] == '-') //正 - 负 = |负| + 正
	{
		string tmp(num2.begin() + 1, num2.end());
		return add(num1,tmp);
	}


	else if (num1[0] == '-' && num2[0] == '-')//负负  负1 - 负2 = |负2| -|负1|
	{
		string s1(num1.begin()+ 1, num1.end()); //负1的绝对值
		string s2(num2.begin()+ 1, num2.end()); //负2的绝对值

		//return sub(s2,s1);//此处直接递归也可以(递归进去可能出现小-大还会进一次栈)，但是下面的方案更优一点
		if (len1 > len2 || len1 == len2 && num1 > num2)//负1的绝对值 > 负2的绝对值,会减成负数，等价于-(|负1|-|负2|)
		{
			ret += '-';
			ret += sub(s1, s2);
			return ret;
		}
		else//负2的绝对值 >= 负1的绝对值
		{
			return sub(s2, s1);
		}
	}

	else if (num1[0] != '-' && num2[0] != '-')//正正
	{
		if (len1 < len2 || len1 == len2 && num1 < num2)//小 - 大 = -(大 - 小)
		{
			ret += '-';
			ret += sub(num2, num1);
			return ret;
		}


		else
		{
			ret.resize(len1); //到这里计算的只可能是：正1 - 正2 && 正1 > 正2
			int step = 0;//进位
			int i, j, tmp;

			for (i = len1 - 1, j = len2 - 1; i >= 0; --i)
			{
				tmp = 0;
				if (j >= 0)//较小的数还未减完
				{
					if (num1[i] < num2[j])//需要借位
					{
						tmp = 10;//向上一位借一位，相当于+10
						num1[i - 1]--;//向上借位上一位-1
					}
					ret[i] = num1[i] + tmp - num2[j] + '0';
					--j;
				}

				else
				{
					if (num1[i] < '0')
					{
						ret[i] = num1[i] + 10;
						--num1[i - 1];
					}
					else
					{
						ret[i] = num1[i];
					}
				}

			}
			//删除前置0,比如0008---》8
			while (ret.size() > 1 && ret[0] == '0')
			{
				ret.erase(0, 1);//不断删除头部的0
			}
			return ret;
		}
	}
}

string BigInt::mul(string num1, string num2)
{
	string ret;
	int len1 = num1.size();
	int len2 = num2.size();
	if (len1 == 1 || len2 == 1)
	{
		if (len1 == 1 && num1[0] == '0' || len2 == 1 && num2[0] == '0')//任何数乘以0=0
		{
			return ret;
		}

		if (len1 == 1 && num1[0] == '1' || len2 == 1 && num2[0] == '1')//任何数乘以1=任何数
		{
			return num1[0] == '1' ? num2 : num1;
		}
	}

	if (len1 == 2 && num1[0] == '-'&& num1[1] == '1')//num1==-1
	{
		if (num2[0] == '-')
		{
			ret.append(num2.begin() + 1, num2.end());
			return ret;
		}
		else
		{
			ret += '-';
			ret.append(num2.begin(), num2.end());
			return ret;
		}
	}

	if (len1 == 2 && num1[0] == '-'&& num1[1] == '1')//num2==-1
	{
		if (num1[0] == '-')
		{
			ret.append(num1.begin() + 1, num1.end());
			return ret;
		}
		else
		{
			ret += '-';
			ret.append(num1.begin(), num1.end());
			return ret;
		}
	}

	string s1, s2;

	if (num1[0] == '-' && num2[0] == '-')//负负 得正
	{
		s1.append(num1.begin() + 1, num1.end());
		s2.append(num2.begin() + 1, num2.end());
		return mul(s1, s2);
	}

	else if (num1[0] == '-' || num2[0] == '-')//正负/负正
	{	
		if (num1[0] == '-')
		{
			s1.append(num1.begin() + 1, num1.end());
			s2 = num2;
		}
		else
		{
			s1 = num1;
			s2.append(num2.begin() + 1, num2.end());
		}
		ret += '-';
		ret += mul(s1, s2);
		return ret;
	}

	else //if (num1[0] != '-' && num2[0] != '-')//正正
	{

		if (num1.size() < num2.size())//让num1做较大的数
		{
			swap(num1, num2);
			swap(len1, len2);
		}

		ret = "0";
		for (int i = len2 - 1; i >= 0; --i)
		{
			int digit = num2[i] - '0';//获得当前乘数对应位的值
			int step = 0;//进位

			string tmp = num1;//当前乘积结果
			for (int j = len1 - 1; j >= 0; --j)
			{
				tmp[j] = (tmp[j] - '0') * digit + step;//整数值

				if (tmp[j] > 9)
				{
					step = tmp[j] / 10;
					tmp[j] %= 10;
				}

				else//没有进位
				{
					step = 0;
				}
				tmp[j] += '0';//还原成字符

			}
			if (step > 0)//判断最最后一位是否还要进位
			{
				tmp.insert(0, 1, step + '0');
			}
			tmp.append(len2 - 1 - i, '0');

			//下面累计一次乘法的结果
			ret = add(ret, tmp);
		}
		return ret;
	}
}
pair<string, string> BigInt::div(string num1, string num2)//除法返回商和余数
{
	pair<string, string> ret;
	return ret;
}


