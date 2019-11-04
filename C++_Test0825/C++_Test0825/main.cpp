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
//void fun(int a = 0)
//{
//	cout << a << endl;
//}
//
//void fun1(int a = 10,int b=20,int c=  30)
//{
//	cout << a << endl;
//	cout << b << endl; 
//	cout << c << endl;
//}
//void fun2(int a = 10 , int b , int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//void fun3(int a , int b , int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//void fun4(int a , int b, int c =10);
//
//void fun4(int a , int b , int c =10 )
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}

//int add(int a, int b)
//{
//	return a + b;
//}
//
//double add(double a, double b)
//{
//	return a + b;
//}
//short Add(short left, short right) { return left + right; }
//
//int Add(short left, short right) { return left + right; }

void Swap(int &aa, int &bb)
{
	int tmp = aa;
	aa = bb;
	bb = tmp;
}
 inline int Add(int a, int b) 
{ 
	int c = a + b;
    return c;
}
int main()
{
	int ret = Add(2, 4);
	/*int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;*/

	/*int a = 10;
	int& ra = a;
	ra = 20;
	int* pa = &a;
	*pa = 20;*/
	/*int a = 10;
	int b = 20;
	cout << "a=" << a << "  b=" << b << endl;
	Swap(a, b);
	cout << "a=" << a << "  b=" << b << endl;*/
	//int a = 10;
	//int &b = a;
	//int &c = a;
	//cout << "a = " << a << " b = " << b << " c = " << c << endl;

	/*int a = 10;
	int b = 20;
	int &c = a;
	c = b;
	*/
	//const int a = 10;
	//int &A = a;  //编译出错，a为常量
	//int &B = 100;//编译出错，100为常量
	//int c = 100;
	//float &C = c;//编译出错，c和C类型不同
	/*int CaiXuKun = 100;
	int &KunKun = CaiXuKun;
	int &
	cout << "CaiXuKun = " << CaiXuKun << " KunKun = " << KunKun << endl;
	cout << "&CaiXuKun = " << &CaiXuKun << " &KunKun = " << &KunKun << endl;*/
	system("pause");
	return 0;
}

