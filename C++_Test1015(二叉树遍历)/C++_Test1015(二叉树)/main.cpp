#include<iostream>
#include"Tree.h"
using namespace std;

void test()
{
	/*char* s = "AB##C##";
	char* src = "ABD##E##CF###";
	char flag = '#';*/
	int flag = -1;
	//int sr[] = { 1, 2, - 1,- 1, 2, -1, -1 };
	int sr[] = { 1, 2,4,-1,-1, -1 , 3, -1, 5,-1,  -1 };
	Tree<int> tree(sr, flag); 
	vector<int> vres;

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
	
	//vres = tree.PostOrder_Recursive(tree.ReturnRoot());

	//vres = tree.LevelOrder();
	//vres = tree.LevelNodeMax();
	//vres = tree.LevelOrder();
	//for (auto& i : vres)
	//{
	//	cout << i << " ";
	//}
	//tree.Mirror();
	tree.lowestCommonAncestor();
	/*vres = tree.LevelOrder();
	for (auto& i : vres)
	{
		cout << i << " ";
	}*/

	cout << endl;
}

int findKthLargest(vector<int>& nums, int k) //输出第N大数
{
	if (nums.empty())
	{
		return -1;
	}
	priority_queue<int> pq(nums.begin(),nums.end());
	int i;
	for (i = 0; i < k - 1; i++)
	{
		pq.pop();
	}
	return pq.top();
}

int main()
{
	test();
	/*vector<int> v{ 2, 7, 3, 10, 4, 7, 19, 43, 6 };
	cout<<findKthLargest(v, 3);*/
	system("pause");
	return 0;
}


