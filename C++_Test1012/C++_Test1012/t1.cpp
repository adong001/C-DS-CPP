#include<iostream>
#include<vector>
using namespace std;

int main1()
{
	vector<vector<int >> v;
	v[0][0] = 1;
	//v[1][2] = 10;
	cout << v[0][0] << endl;

	v.push_back(vector<int>());
	for (int i = 0; i < 4; i++)
	{
		v[0].push_back(i);
	}
	v.push_back(vector<int>());
	for (int i = 0; i < 4; i++)
	{
		v[1].push_back(i);
	}
	cout << v.size() << "" << endl;
	cout << v[0].size() << "" << endl;
    system("pause");
    return 0;
}