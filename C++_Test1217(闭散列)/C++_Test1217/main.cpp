#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;

int main1()
{
	unordered_map<string,int> um;
	//与map的区别就是map插入会排序，而这个只是根据插入顺序进行存储
	//因为map底层实现是红黑树，插入和删除时会进行调整，从而导致数据一直是顺序存储的
	//而unordered_map底层实现是哈希
	um.insert(pair<string, int>("AAA", 100));
	um.insert(pair<string, int>("CCC", 300));
	um.insert(pair<string, int>("DDD", 400));
	um.insert(make_pair("FFF", 600));
	um.insert(pair<string, int>("EEE", 500));
	um["BBB"] = 200;
	um["GGG"] = 700;
	for (auto& e : um)
	{
		cout << e.first << " " << e.second << endl;
	}

    system("pause");
    return 0;
}