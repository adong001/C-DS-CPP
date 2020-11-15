#include<iostream>
#include"RBTree.h"
#include"myset.h"
#include <map>
#include <set>
using namespace std;

int main()
{
	MySet<int> ms;
	ms.insert(1);

	ms.insert(2);
	ms.insert(3);
	ms.insert(4);
	ms.size();
	//MySet<int>::iterator it = ms.begin();
	map<int, char> mp;
	mp.size();
	set<int> s;
	pair<map<int, char>::iterator, bool> = mp.insert(1, 2);
	YD::RBTree<int> rbt;
	rbt.Insert(3);
	rbt.Insert(1);
	rbt.Insert(5);

	rbt.Insert(7);
	rbt.Insert(2);
	rbt.Insert(4);
	return 0;

}