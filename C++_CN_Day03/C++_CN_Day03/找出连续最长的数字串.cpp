#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//1. 标题：字符串中找出连续最长的数字串 | 时间限制：1秒 | 内存限制：32768K 
//   读入一个字符串str，输出字符串str中的连续最长的数字串 
//
//输入描述： 个测试输入包含1个测试用例，一个字符串str，长度不超过255。 
//
//输出描述： 在一行内输出str中里连续最长的数字串。 
//
//示例1 : 输入 abcd12345ed125ss123456789 
//	    输出 123456789

int main1()
{
	string str;
	string tmp;
	int length = 0;
	auto pos = str.begin();
	int Max_length = 0;
	getline(cin, str);

	if (str.empty())
	{
		return 0;
	}
	//abcd12345ed125ss123456789
	for (auto i = str.begin(); i != str.end();)
	{
		/*while(i!= str.end() && ((i+1)!=str.end())&& ((*(i + 1) - *i) == 1))//找最长的连续串(包括数字)
		{
		auto ip = (*(i + 1) - *i);
		length++;
		i++;
		}*/
		while (i != str.end() && ((i + 1) != str.end()) && ((*(i + 1) - *i) == 1)&&'0'<= *i && *i <= '9')//只找连续数字
		{
			auto ip = (*(i + 1) - *i);
			length++;
			i++;
		}
		length++;
		i++;

		if (length > Max_length)
		{
			Max_length = length;
			pos = i;
		}
		length = 0;
	}
	tmp.insert(tmp.begin(), pos - Max_length, pos);
	cout << tmp << endl;

	return 0;
}


//int main()
//{
//	vector<int> v;
//	v.push_back(100);
//	v.push_back(200);
//	v.push_back(300);
//	v.push_back(400);
//	v.push_back(500);
//	for (auto ip = v.begin(); ip != v.end(); ip++)
//	{
//		if (*ip == 200)
//		{
//			ip = v.erase(ip);
//			cout << *ip << endl;
//		}
//	}
//	for (auto& i : v)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//    system("pause");
//    return 0;
//}

