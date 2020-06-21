#include <iostream>
#include <string>
using namespace std;
//int main()
//{
//	int month;
//	while (cin >> month)
//	{
//		int f0 = 0, f1 = 1, f2 = 1, fn;
//		while (--month)
//		{
//			fn = f2;
//			f2 += f1;
//			f0 = f1;
//			f1 = fn;
//			
//		}
//		cout << f1 << endl;
//	}
//}

//#include <iostream>
//#include <string>
//using namespace std;
//bool Match(const char* src, const char* det)
//{
//	if (*src == '\0'&& *det == '\0')//都到末尾，说明匹配正确
//	{
//		return true;
//	}
//	if (*src == '\0' || *det == '\0')//在上面的约束下，有一个结束，说明未匹配正确
//	{
//		return false;
//	}
//	if (*src == *det)//两个字符串相同，同时匹配
//	{
//		return Match(src + 1, det + 1);
//	}
//	else if (*src == '?')//匹配单个
//	{
//		return Match(src + 1, det + 1);
//	}
//	else if (*src == '*')//匹配0个，1个，多个
//	{
//		return Match(src + 1, det) || Match(src + 1, det + 1) || Match(src, det + 1);
//	}
//	return false;
//}
//int main()
//{
//	string src, det;
//	while (cin >> src >> det)
//	{
//		if (Match(src.c_str(), det.c_str()))
//		{
//			cout << "true" << endl;
//		}
//		else
//		{
//			cout << "false" << endl;
//		}
//	}
//}