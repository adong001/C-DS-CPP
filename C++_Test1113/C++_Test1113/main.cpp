#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Base
//{
//public:
//	int m_a;
//	Base(int a = 0) :
//		m_a(a)
//	{}
//};
//
//class Test:public Base
//{
//public:
//	int m_b;
//	Test(int a = 0,int b = 0 ) :
//		Base(a),
//		m_b(b)
//	{}
//};
//
//void func1()
//{
//	int a = 10;
//	int b = 20;
//	if (a < b)
//	{
//		throw "抛出异常a>b";
//	}
//}
//
//
//void func2()
//{
//	func1();
//}
//
//int main()
//{
//	try
//	{
//		func2();
//
//	}
//	catch (char& a)
//	{
//		cout << a<<endl;
//	}
//	catch (const char* a)
//	{
//		cout << a << endl;
//	}
//	catch (...)
//	{
//		cout << "未捕获！" << endl;
//	}
//    system("pause");
//    return 0;
//}




int main()
{
	try{
		vector<int> v(10, 5);  // 这里如果系统内存不够也会抛异常    
		v.reserve(1000000000);// 这里越界会抛异常       
		v.at(10) = 100;
	}
	catch (const exception& e) // 这里捕获父类对象就可以   
	{
		cout << e.what() << endl;
	}

	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}

	return 0;
}