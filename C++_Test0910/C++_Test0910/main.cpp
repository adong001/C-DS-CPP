#include"data.h"

int main()
{

	Data d1(2019, 9, 10);
	Data d2 = d1;
	d1++;
	cout << (d1) << endl;
	d1--;
	cout << (d1) << endl;
	system("pause");
	return 0;
}