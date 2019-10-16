#include<iostream>
#include"Tree.h"
using namespace std;





int main()
{
	char* src = "ABD##E##CF###";
	char flag = '#';
	Tree<char> T(src, flag);
	system("pause");
	return 0;
}


