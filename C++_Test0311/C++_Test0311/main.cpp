#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<string, int> m;
	int* ip = reinterpret_cast<int *>(12);
	int i = reinterpret_cast<int>(ip);
	cout << i << endl;
    system("pause");
    return 0;
}