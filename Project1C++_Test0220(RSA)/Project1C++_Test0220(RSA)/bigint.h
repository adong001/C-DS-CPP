#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<ctime>
#include<algorithm>
#include<string>
#include<fstream>
#include<utility>
#include<cmath>

//#include <boost/multipercision/cpp_int.hpp>"//大数库，功能强大(智能指针，lamba表达式)
using namespace std;

/*void test()
{
	boost::multiprecision::cpp_int ci;
	ci = 1024;
	cout << ci << endl;
	ci = 23456789072837823439287165347894382765493230403483049324838947;
	cout << ci << endl;
}*/

class BigInt
{
private:
	string m_number;
	bool less(string& num1, string& num2);
public:

	BigInt();
	BigInt(const string& num);
	BigInt(const int num);

	//通过字符串表示大数
	string add(string num1, string num2);
	string sub(string num1, string num2);
	string mul(string num1, string num2);
	pair<string,string> div(string num1, string num2);//除法返回商和余数

	BigInt operator+(BigInt& bi);
	BigInt operator-(BigInt& bi);
	BigInt operator*(BigInt& bi);
	BigInt operator/(BigInt& bi);
	BigInt operator%(BigInt& bi);

	/*friend BigInt operator +(const char * str, BigInt& b1);
	friend BigInt operator -(const char * str, BigInt& b1);
	friend BigInt operator *(const char * str, BigInt& b1);
	friend BigInt operator /(const char * str, BigInt& b1);
	friend BigInt operator %(const char * str, BigInt& b1);

	BigInt& operator+=(BigInt& bi);
	BigInt& operator-=(BigInt& bi);
	BigInt& operator*=(BigInt& bi);
	BigInt& operator/=(BigInt& bi);
	BigInt& operator%=(BigInt& bi);
	
	BigInt& operator++();
	BigInt operator++(int);//后置
	BigInt& operator--();
	BigInt operator--(int);//后置*/
	
	friend ostream& operator<<(ostream& os, BigInt& bi);
	friend istream& operator>>(istream& is, BigInt& bi);

};