#define _CRT_SECURE_NO_WARNINGS 1
#include"AVL.h"

int main()
{
	YD::AVLTree<int> AVL;
	AVL.Insert(1);
	AVL.Insert(2);
	AVL.Insert(3);
	AVL.Insert(4);
	AVL.Insert(5);
	AVL.Insert(6);
	AVL.Insert(7);
	AVL.Insert(8);
	AVL.Insert(9);
	AVL.Insert(10);
	vector<int> v = AVL.InOrderTree();
	for (auto & i : v)
	{
		cout << i << ' ';
	}
	cout << endl;
	AVL.erase(7);

	v = AVL.InOrderTree();
	for (auto & i : v)
	{
		cout << i << ' ';
	}
	cout << endl;

	AVL.erase(2);

	v = AVL.InOrderTree();
	for (auto & i : v)
	{
		cout << i << ' ';
	}
	cout << endl;

	AVL.erase(5);

	v = AVL.InOrderTree();
	for (auto & i : v)
	{
		cout << i << ' ';
	}
	cout << endl;
    system("pause");
    return 0;
}