#include<iostream>
#include"Tree.h"
using namespace std;





int main()
{
	char* s = "AB##C##";
	char* src = "ABD##E##CF###";
	char flag = '#';
	Tree<char> tree(s, flag);
	vector<char> vres;

	vres = tree.PreOrder();
	for (auto& i : vres)
	{
		cout << i << " ";
	}
	cout << endl;

	vres = tree.PreOrder_Recursive(tree.ReturnRoot());
	for (auto& i : vres)
	{
		cout << i << " ";
	}
	cout << endl;

	vres = tree.InOrder();
	for (auto& i : vres)
	{
		cout << i << " ";
	}
	cout << endl;

	vres = tree.InOrder_Recursive(tree.ReturnRoot());
	for (auto& i : vres)
	{
		cout << i << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}


