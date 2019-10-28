#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Base
{
private:
	int m_a;
public:
	virtual void Func()
	{
		cout << "Base" << endl;
	}
};


int main2()
{
    system("pause");
    return 0;
}