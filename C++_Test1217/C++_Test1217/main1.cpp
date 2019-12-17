#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	HashTable<int, int> ht;

	ht.insert(pair<int, int>(1, 5));
	ht.insert(pair<int, int>(2, 7));
	ht.insert(pair<int, int>(5, 6));
	ht.insert(pair<int, int>(6, 8));
	ht.insert(pair<int, int>(12, 9));
	ht.insert(pair<int, int>(16, 4));

	
	for (auto e : ht.Table())
	{
		cout << "Key=" << e.m_val.first << " Value=" << e.m_val.second << " Status=" << e.m_status << endl;
	}
	cout << endl;

	ht.erase(6);
	ht.erase(12);

	for (auto e : ht.Table())
	{
		cout << "Key=" << e.m_val.first << " Value=" << e.m_val.second << " Status=" << e.m_status << endl;
	}
	cout << endl;

	ht.insert(pair<int, int>(23, 11));
	ht.insert(pair<int, int>(27, 13));

	for (auto e : ht.Table())
	{
		cout << "Key=" << e.m_val.first << " Value=" << e.m_val.second << " Status=" << e.m_status << endl;
	}

	return 0;
}

//int main()
//{
//	wf::hashTable<string, int, wf::dealString> ht;
//
//	ht.insert(pair<string, int>("abc", 1));
//	ht.insert(pair<string, int>("def", 2));
//	ht.insert(pair<string, int>("ghi", 3));
//	ht.insert(pair<string, int>("jkl", 4));
//
//
//	return 0;
//}