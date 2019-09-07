#include<iostream>
using namespace std;

int main()
{
	int *p = new int[10]{0};
	for (int i=0;i<10;i++)
	{
		cout << *(p + i) << endl;
	}
    system("pause");
    return 0;
}