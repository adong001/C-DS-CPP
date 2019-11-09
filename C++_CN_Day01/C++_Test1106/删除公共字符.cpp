#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”


void DeleteString_C(char* src, const char* dest)
{
	if (!src||!dest)
	{
		return;
	}
	char* ip1,*tmp = src;
	const char* ip2;
	for (ip2 = dest; *ip2; ip2++,tmp = src)//遍历dest，依次在src中查找删除
	{
		while(*tmp)//找到第一个要删的位置
		{
			if (*tmp != *ip2)
			{
				tmp++;
			}
			else
			{
				break;
			}
		}

		if (*tmp)//如果要删的字符在src中没有就不删，继续第一个for循环找下一个要删的字符
		{
			for (ip1 = tmp++; *tmp; ip1++, tmp++)//（ip1=tmp++）tmp要覆盖ip1，所以跳到的下一个位置
			{
				while (*tmp == *ip2)
			    //直到找到不是删的那个字符例如：src = "haaat",dest="a";
				//就要找到‘t’为止;
				{
					tmp++;
				}
				*ip1 = *tmp;//将后面的字符移到前面；
			}
			*ip1 = '\0';//因为tmp在'\0'位置跳出了，没有给ip1的下一个位置赋字符串结束符
		}
		
	}
}


template<class T>
void DeleteString_CPP(T src,const T dest)
{
	string src_str(src);
	string dest_str(dest);
	if (src_str.empty() || dest_str.empty())
	{
		return;
	}
	int pos;
	string::iterator ip1; 
	string::iterator src_begin = src_str.begin();//循环内多次调用end函数，这里直接用一个变量存它，减少栈开销
	string::const_iterator ip2 = dest_str.begin();
	string::const_iterator dest_end = dest_str.end();//循环内多次调用end函数，这里直接用一个变量存它，减少栈开销
	for (; ip2 != dest_end; ip2++)
	{
		do
		{
			pos = src_str.find(*ip2);//找到dest第一个字符在src中的位置返回(找不到返回-1)

			if (pos >= 0)//找到了
			{
				ip1 = src_begin + pos;//ip1记录要删除字符串位置的迭代器
				src_str.erase(ip1);
			}

		}while (pos >= 0);//src里面可能有重复的待删字符，使用while循环删除至找不到为止(pos = -1)
	}
	strcpy(src, src_str.c_str());
}


void DeleteSameString()
{
	string src;
	string dest;
	getline(cin, src);
	getline(cin, dest);
	char str[256] = {};
	string tmp;
	if (src.empty() || dest.empty())
	{
		return;
	}
	int i;
	for (i = 0; i < dest.size(); i++)
	{
		str[dest[i]]++;
	}

	for (i = 0; i < src.size(); i++)
	{
		if (str[src[i]] == 0)
		{
			tmp += src[i];
		}
	}
	cout << tmp << endl;

}



int main2()
{
	//
	DeleteSameString();
    system("pause");
    return 0;
}