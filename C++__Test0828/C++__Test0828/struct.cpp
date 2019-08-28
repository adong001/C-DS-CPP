#include<iostream>
using namespace std;


//struct A1
//{
//	char a;
//	int b;
//	double c;//两个函数不占空间，两个函数只是在这个域里，可以调用域里的成员
//	void Print1()//可直接调用自己的成员函数，c语言只能在结构体定义函数指针，还要传参
//	{
//		cout << b << endl;
//	}
//	void Print2();
//
//};
//struct A2//c++允许结构体成员为空，且大小为1个字节，C语言不允许这样定义
//{
//
//};
//
//void A1::Print2()//通过::域操作符直接调定义struct的成员函数
//{
//	cout << c << endl;;
//}

//namespace N1
//{
//	int n = 200;
//	void Print3()
//	{
//		cout << n << endl;//调用名字空间域里的全局变量a
//	}
//}
//
//int main()
//{
//	A1 A;
//	A.b = 100;
//	A.c = 3.14;
//	A.Print1();
//	A.Print2();
//    system("pause");
//    return 0;
//}                                                 