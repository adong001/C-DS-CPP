#include"HighAcc.h"

int main()
{
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	HighAcc a(s1);
	HighAcc b(s2);
	cout << (string)(a + b);
    system("pause");
    return 0;
}