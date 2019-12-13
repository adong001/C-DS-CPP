#include"BinaryTree.h"
#include<set>
#include<algorithm>
#include<vector>
int minimumTotal(vector<vector<int> > &triangle)
{
	for (int i = triangle.size() - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
		}
	}
	return triangle[0][0];
}
int main()
{
	vector<vector<int>> iv{ { -1 }, { 2, 3 }, { 1, -1, -3 } };
	minimumTotal(iv);

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