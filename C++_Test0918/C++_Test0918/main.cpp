#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>v1;
	cout << v1.size()<<endl;
	vector<int>v2;
	//cout << v2.size() << endl;
	for (int i = 0; i < 30; i++)
	{
		v2.push_back(i);
		cout << "capacity=" << v2.capacity() << endl;//capacity至少扩1个，每次扩1.5倍(vs)/2倍(gcc)
	}
	for (auto i = v2.begin(); i != v2.end(); i++)
	{
		cout << *i<<" ";
	}
	cout << endl;
	for (auto i = v2.rbegin(); i != v2.rend(); i++)
	{
		cout << *i << " ";
	}
	//insert();//三种
	//erase()//两种
    system("pause");
    return 0;
}