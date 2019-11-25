#include"BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
	YD::Tree<int> bst;

	bst.Insert(5);
	bst.Insert(2);
	bst.Insert(8);
	bst.Insert(0);
	bst.Insert(1);
	bst.Insert(4);s
	bst.Insert(7);
	bst.Insert(9);
	bst.Insert(3);
	bst.Insert(6);

	bst.erase(7);
	//vector<int> v = bst.InOrderTree();

	/*for (auto & i : v)
	{
		cout << i << ' ';
	}*/
	return 0;
}