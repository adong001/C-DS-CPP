#include<iostream>
#include<fstream>
using namespace std;
class Data
{
	int m_a;
	int m_b;
public:
	Data()
		:m_a(0)
		, m_b(0)
	{}
	Data(int a, int b)
		:m_a(a)
		, m_b(b)
	{}
	friend ostream & operator <<(ostream & os, Data & data);
	friend istream & operator >>(istream & is, Data & data);//友元函数
	friend class Test;//友元类(单向性,不可传递性).友元破坏了C++的私有权限，尽量不要使用
};

class Test
{
	int test;
public:
	Test()
	{
		Data data(2, 3);
		cout << data.m_a << data.m_b << endl;
	}
};


ostream & operator <<(ostream & os, Data & data)
{
	os << data.m_a << "  " << data.m_b << endl;
	return os;
}

istream & operator >>(istream & is, Data & data)
{
	is >> data.m_a >> data.m_b;
	return is;
}
int main()
{
	Data data;
	fstream("1.txt");

	//cin >> data;	
	//operator>>(cin, data);//是上式的原型
	//cout << data << endl;
	//operator<<(cout<<data, endl);//是上式的原型
	system("pause");
	return 0;
}
