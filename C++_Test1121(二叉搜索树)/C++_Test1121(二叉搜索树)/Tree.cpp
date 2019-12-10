#include"BinaryTree.h"
int main()
{
	YD::Tree<int> bst;

	bst.Insert(5);
	bst.Insert(2);
	bst.Insert(8);
	bst.Insert(0);
	bst.Insert(1);
	bst.Insert(4);
	bst.Insert(7);
	bst.Insert(9);
	bst.Insert(3);
	bst.Insert(6);
	vector<int> v = bst.InOrderTree();
	for (auto & i : v)
	{
		cout << i << ' ';
	}
	cout << endl;
	bst.erase(7);

	v = bst.InOrderTree();
	for (auto & i : v)
	{
		cout << i << ' ';
	}
	cout << endl;

	bst.erase(2);

	v = bst.InOrderTree();
	for (auto & i : v)
	{
		cout << i << ' ';
	}
	cout << endl;

	bst.erase(5);

	v = bst.InOrderTree();
	for (auto & i : v)
	{
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}