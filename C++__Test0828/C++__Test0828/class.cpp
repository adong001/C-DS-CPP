#include<iostream>
using namespace std;
class ct//类是一个特殊的结构体，结构体没有类的多态，继承性
{
public:
	char a;
	int b;
	double c;
	void Print1()
	{
		cout << b << endl;
	}
	void Print2();

};

void ct:: Print2()
{
	cout << c << endl;
}

int main()
{
	ct c;
	c.b = 100;
	c.c = 3.4;
	c.Print1();
	c.Print2();
	cout << sizeof(ct) << endl;
    system("pause");
    return 0;
}