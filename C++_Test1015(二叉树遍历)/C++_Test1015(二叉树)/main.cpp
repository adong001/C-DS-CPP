#include<iostream>
#include"Tree.h"
using namespace std;

void test()
{
	char* s = "AB##C##";
	char* src = "ABD##E##CF###";
	char flag = '#';
	Tree<char> tree(src, flag);
	vector<char> vres;

	//vres = tree.PreOrder();
	//for (auto& i : vres)
	//{
	//	cout << i << " ";
	//}
	//cout << endl;

	//vres = tree.PreOrder_Recursive(tree.ReturnRoot());
	//for (auto& i : vres)
	//{
	//	cout << i << " ";
	//}
	//cout << endl;

	//vres = tree.InOrder();
	//for (auto& i : vres)
	//{
	//	cout << i << " ";
	//}
	//cout << endl;

	//vres = tree.InOrder_Recursive(tree.ReturnRoot());
	vres = tree.PostOrder_Recursive(tree.ReturnRoot());
	for (auto& i : vres)
	{
		cout << i << " ";
	}
	cout << endl;
}



int main()
{
	test();
	system("pause");
	return 0;
}


