//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//template<class T,size_t N = 10>//非类型模板参数
//class Array
//{
//private:
//	T m_ar[N];//一般应用于给静态数组初始化大小
//public:
//	Array()
//	{
//		cout << N <<endl;
//	}
//};
//
////注意：1.非类型模板参数必须是整型(及其相关类型)，指针，引用
////      2.非类型模板参数必须是const类型
////
//
////题目描述
////求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
//class Solution {
//	
//public:
//	static int tmp;
//	static int sum;
//	Solution()
//	{
//		tmp++;
//		sum += tmp;
//	}
//};
//int Solution:: tmp = 0;
//int Solution:: sum = 0;
//
////class Solution 
////{
////public:
////	int Sum_Solution(int n)
////	{
//		//int a = 1;
//		//n > 1 && (a = n + Sum_Solution(n - 1));
//		////利用&&的短路，使n <= 1 时不执行后面的递归作为一个巧妙的退出条件
//		//return a;
////	}
////};
//
//
//
//int main1()
//{ 
//	Array<int> ar1;
//	Array<char, 100>ar2;
//    system("pause");
//    return 0;
//}