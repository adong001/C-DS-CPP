#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

class Arithmetic
{
private:
	int m_son;
	int m_mother;
public:
	Arithmetic()
	{}

	Arithmetic(const string& num)
	{
		int pos = num.find('/');
		string tmp = num.substr(0, pos);
		m_son = atoi(tmp.c_str());
		tmp = num.substr(pos+1);
		m_mother = atoi(tmp.c_str());
	}

	Arithmetic(int son, int mother) :
		m_son(son),
		m_mother(mother)
	{}

	int GetMaxCommon(int num1, int num2)//求最大公约数，约分
	{
		int tmp = num2;
		while (num1 % num2 != 0)
		{
			tmp = num1 % num2;
			num1 = num2;
			num2 = tmp;
		}
		return tmp;
	}
	void Print()
	{
		cout << m_son << "/" << m_mother <<endl;
	}

	Arithmetic operator+(const Arithmetic& num)
	{
		//获取未约分结果
		Arithmetic Ari(m_son*num.m_mother + m_mother*num.m_son, m_mother*num.m_mother);
		//求最大公约数,求最大公约数时都转换成正数
		int maxcommon = GetMaxCommon(abs(Ari.m_son), abs(Ari.m_mother));
		//约分
		Ari.m_son /= maxcommon;
		Ari.m_mother /= maxcommon;
		return Ari;
	}

	Arithmetic operator - (const Arithmetic& num)
	{
		//获取未约分结果
		Arithmetic Ari(m_son*num.m_mother - m_mother*num.m_son, m_mother*num.m_mother);
		//求最大公约数
		int maxcommon = GetMaxCommon(abs(Ari.m_son), abs(Ari.m_mother));
		//约分
		Ari.m_son /= maxcommon;
		Ari.m_mother /= maxcommon;
		return Ari;
	}

	Arithmetic operator *(const Arithmetic& num)
	{
		//获取未约分结果
		Arithmetic Ari(m_son * num.m_son, m_mother*num.m_mother);
		//求最大公约数
		int maxcommon = GetMaxCommon(abs(Ari.m_son), abs(Ari.m_mother));
		//约分
		Ari.m_son /= maxcommon;
		Ari.m_mother /= maxcommon;
		return Ari;
	}

	Arithmetic operator / (const Arithmetic& num)
	{
		//(a/b) / (c/d) = (a/b) * (d/c)
		Arithmetic Ari(num.m_mother, num.m_son);
		return (*this * Ari);
	}
};

int main3()
{
	string num1, num2;
	int son1, son2, mother1, mother2;//分子分母
	char flag, ch;//输入的/和运算符
	while (cin >> num1 >> ch >> num2)
	{
		Arithmetic Ari1(num1);
		Arithmetic Ari2(num2);
		Arithmetic res;
		switch (ch)
		{
			case '+':
			{
				res = Ari1 + Ari2;
				break;
			}
			case '-':
			{
				res = Ari1 - Ari2;
				break;
			}
			case '*':
			{
				res = Ari1 * Ari2;
				break;
			}
			case '/':
			{
				res = Ari1 / Ari2;
				break;
			}
			default:
			{
				break;
			}
			
		}
		res.Print();
	}
	return 0;
}