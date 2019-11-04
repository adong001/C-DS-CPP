//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
////模板特化
//
////int tmp = 10;
//template<class T1,class T2>
//class Test
//{
//private:
//	T1 m_a;
//	T2 m_b;
//public:
//	Test()
//	{
//		cout << "T1 T2" << endl;
//	}
//};
////1.全特化
//template<>
//class Test<char,int>
//{
//private:
//	char m_a;
//	int m_b;
//public:
//	Test()
//	{
//		cout << "char int" << endl;
//	}
//};
////2.偏特化
//template<class T1>
//class Test<T1, int>
//{
//private:
//	T1 m_a;
//	int m_b;
//public:
//	Test()
//	{
//		cout << "T1 int" << endl;
//	}
//};
//
//
//template<class T1,class T2>
//void Fun(T1 a,T2 b)//模板函数
//{
//	cout << "模板函数" <<endl;
//}
//
//template<>//模板函数的全特化
//void Fun(char a, int b)
//{
//	cout << "全特化" << endl;
//}
//
//template<class T1>//模板函数的偏特化
//void Fun(T1 a, float b)
//{
//	cout << "偏特化" << endl;
//}
//
//
//void Fun(char a, float b)//模板函数的函数重载1
//{
//	cout << "函数重载1" << endl;
//}
//
//void Fun(char a, int b)//模板函数的函数重载2
//{
//	cout << "函数重载2" << endl;
//}
//
//
//int main2()
//{
//	/*Test<double,float> t1;
//	Test<char, int> t2;
//	Test<double, int> t3;*/
//	char char_tmp = 0;
//	int int_tmp = 0;
//	float float_tmp = 0;
//
//	Fun(float_tmp, int_tmp);
//	Fun(char_tmp, int_tmp);
//	Fun(int_tmp, float_tmp);
//	Fun(char_tmp, float_tmp);
//	Fun(char_tmp, int_tmp);
//
//
//    system("pause");
//    return 0;
//}