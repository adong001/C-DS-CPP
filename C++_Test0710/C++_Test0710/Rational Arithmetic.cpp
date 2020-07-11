#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*每个输入文件包含一个测试用例，它在一行中给出格式为“a1 / b1 a2 / b2”的两个有理数。
分子和分母都在long范围内,如果有负号，它必须只出现在分子前面。分母保证为非零数字。

对于每个测试用例，用4行打印总和、差异，两个有理数的乘积和商。

每种格式行是“number1 operator number2=结果”。
注意，所有有理数必须是最简单的形式“ka/b”，其中k是整数部分，a/b是最简单的分数部分。
如果数字为负数，必须包含在一对圆括号。
如果除法中的分母是零，输出结果是“Inf”.它保证所有输出整数都在范围内长内
*/
typedef long long LL;
class RationalNumber
{
private:
	LL m_son;//分子
	LL m_mother;//分母
	LL m_inter;//整数部分
	bool m_zore;//分母为0就是true
	bool m_negative;//为负数就是true;
public:
	RationalNumber(LL son, LL mother);//构造函数
};

RationalNumber::RationalNumber(LL son, LL mother)
{
	m_zore = false;
	m_negative = false;
	if (mother == 0)//直接返回
	{
		m_zore = true;
		return;
	}
	if (son < 0)
	{
		m_zore = true;
		if (m_mother < 0)
		{
			m_zore = !m_negative;
		}
	}
	m_inter = son / mother;//整数部分
	m_son = son % mother;
	m_mother = r

}
int main()
{
	LL n1, d1, n2, d2;
	scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
	RationalNumber rn1(n1, d1), rn2(n2, d2); //轻松+愉快的使用函数时间 
	cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << '\n';
	cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << '\n';
	cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << '\n';
	cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << '\n';
	return 0;
}