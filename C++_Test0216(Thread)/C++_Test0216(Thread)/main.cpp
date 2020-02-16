#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<thread>
#include<atomic>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	thread t1;
	thread t2;
	thread t3([&](int num)//支持lamba表达式
	{
		a += 10;
		b += 20;
	}, 5);
	system("pause");
	return 0;
}