#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

bool IsPalindrome(string& src)
{
	if (src.empty())
	{
		return false;
	}
	int _size = src.size();
	for (int i = 0; i < _size / 2; i++)
	{
		if (src[i] != src[_size - i - 1])
		{
			return false;
		}
	}
	return true;
}

int ToPalindrome()
{
	string src;
	string dest;
	getline(cin, src);
	getline(cin, dest);
	if (src.empty() || dest.empty())
	{
		return -2;
	}
	int src_size = src.size();
	int i;
	for (i = -1; i < src.size(); i++)
	{
		string tmp = src;
		tmp.insert(i, dest);
		if (IsPalindrome(tmp))
		{
			return i;
		}
	}

}


int main()
{
	string s1("haha");
	s1.insert(0, "o");
	cout << s1 << endl;
	cout << ToPalindrome()<<endl;
    system("pause");
    return 0;
}



////判断回文字符串
//bool palindrome(const string& str) {	//传引用
//	int begin = 0;
//	int end = str.size() - 1;
//	while (begin<end) {
//		if (str[begin] != str[end]) {
//			return false;
//		}
//		begin++;
//		end--;
//	}
//	return true;
//}
//int main() {
//	std::string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int count = 0;
//	for (int i = 0; i <= str1.size(); ++i) {
//		// 将字符串2插入到字符串1的每个位置，再判断是否是回文        
//		string str = str1;
//		str.insert(i, str2);
//		if (palindrome(str)) {
//			++count;
//		}
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}




