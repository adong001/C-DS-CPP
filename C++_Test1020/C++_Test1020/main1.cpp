#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Test
{
 
public: static int count;
	Test()
	{
		count++;
	}
};
int Test::count = 0;

int main()
{
	Test T1;
	Test T2;
	Test T3;
	cout << T1.count << endl;
	cout << Test::count << endl;
    system("pause");
    return 0;
}