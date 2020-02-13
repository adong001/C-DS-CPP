#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string>
#include"HashSet.h"
using namespace std;

int main()
{
	YD::HashSet<int> set;
	set.insert(1);
	set.insert(8);
	set.insert(13);
	set.insert(7);
	set.insert(2);
	set.insert(15);
	set.insert(18);
	set.insert(23);
	set.insert(17);
	set.insert(12);
	set.insert(25);
	set.insert(58);
	set.insert(33);
	set.insert(27);
	set.insert(22);

	set.erase(2);
	set.erase(27);

	set.claer();

	system("pause");
	return 0;
}