#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_map>
#include"unordered_map.h"
using namespace std;

int main()
{



	YD::unordered_map<int, int> m;
	unordered_map<int, int> m2;
	m2.begin();
	m2.insert(make_pair(2, 1));
	//m.insert(12, 1);
    system("pause");
    return 0;
}