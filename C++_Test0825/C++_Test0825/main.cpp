#include<iostream>
using namespace std;//声明使用库提供的std名字空间内的库函数
//namespace N0
//{
//	namespace N1//名字空间
//	{
//		int add(int a, int b)
//		{
//			cout << "1\n";
//			return a + b;
//		}
//	}
//
//	namespace N2
//	{
//		int add(int a, int b)
//		{
//			cout << "2\n";
//			return a + b;
//		}
//	}
//}
void fun(int a = 0)
{
	cout << a << endl;
}

void fun1(int a = 10,int b=20,int c=  30)
{
	cout << a << endl;
	cout << b << endl; 
	cout << c << endl;
}
void fun2(int a , int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
void fun3(int a , int b , int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
void fun4(int a , int b , int c )
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
int main()
{
	fun(10);
	fun();
	fun2(200, 300);
	//cout <<N1::add(2, 5);//std是系统提供的名字空间，cout自动识别类型打印
	//cout <<N0:: N1::add(2, 5);//名字空间可嵌套
	system("pause");
    return 0;
}
