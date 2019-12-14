#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<ctime>
#include<cstdio>
#include<Windows.h>
#include<stdlib.h>
using namespace std;

int main()
{
	time_t start,end;

	time(&start);
	cout << start << endl;
	Sleep(2000);
	time(&end);
	cout << end << endl;
	cout << end - start << endl;
    system("pause");
    return 0;
}