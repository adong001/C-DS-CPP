#include<iostream>
#include"string.h"
#include<cstdio>
#include<typeinfo>
using namespace std;



int main()
{
	string s1;//构造函数共20种
	string s2("wuyifan");
	string s3(s2);
	string s4(5, '6');
	s4 += s3;
	s4 += "hahaha";
	//cout << s1 << endl
	//	 << s2 << endl
	//	 << s3 << endl
	//	 << s4 << endl;
	//cout << s1.size() << endl//字符串容器中size和length没有区别，实现也相同
	//	 << s2.size() << endl
	//	 << s3.size() << endl
	//	 << s4.size() << endl;
	//cout << s1.length() << endl
	//	 << s2.length() << endl
	//	 << s3.length() << endl
	//	 << s4.length() << endl;
	//cout << s1.capacity() << endl//容量大小为16的倍数-1，只增不减
	//	 << s2.capacity() << endl
	//	 << s3.capacity() << endl
	//	 << s4.capacity() << endl;

	//s1.push_back('1');
	//s1.resize(10,'n');//缺省空格，不够的用缺省的补上
	//cout << s1.size() << endl;
	//s1.push_back('2');
	//cout << s1 << endl;

	//s2.reserve(20);//若传入数据小于16，不改变，否则扩容16
	//cout << s2.size() << "  " << s2.capacity() << endl;

	//string::iterator i;//迭代器  
	//for (i = s2.begin(); i != s2.end(); i++)//c++98写法
	//{
	//	cout << *i;
	//}

	//cout << endl;

	//for (auto &j : s2)//c++11写法(底层为迭代器写法)
	//{
	//	cout << j;
	//}
	s1 += "Hello";
	s1.resize(10);
	s1 += 'a';
	cout << typeid(s1).name() << endl;
	cout << typeid(s1.c_str()).name() << endl;//s1.c_str是s1对象中的成员字符串
	cout << s1 <<endl;//<<的重载打印长度为size
	cout << s1.c_str() << endl;//遇到‘\0’停止
	//cout << s4.empty() << endl;//判空，为空返回1，否则返回0
	//s4.clear();//清空(只清空数据，不改capacity,size = 0)
	//cout << s4.empty() << endl;

	s2.append(10, 'a');//后面+10个'a'
	s2.append("hahah");//和+=一样基本使用+=
	s2.append("adadaad");
	cout << s2 << endl;
	//s1.getline();
	//s4.resize(100);//改size的值，若超过capacit会调用reserve()
	//cout << s4.size() << endl;
    system("pause");
    return 0;
}