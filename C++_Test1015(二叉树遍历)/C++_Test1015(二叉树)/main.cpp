#include<iostream>
#include"Tree.h"
using namespace std;





int main()
{
	char* s = "AB##C##";
	char* src = "ABD##E##CF###";
	char flag = '#';
	Tree<char> T(s, flag);
	system("pause");
	return 0;
}


