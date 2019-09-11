#include"date.h"

int main()
{

	Date d1(2019, 9, 10);
	Date d2 = d1;
	cout << (++d1) << endl;
	cout << (d1++) << endl;
	system("pause");
	return 0;
}