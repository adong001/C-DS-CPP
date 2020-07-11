#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main0()
{
	string src, det;
	while (cin >> src >> det)
	{
		int cnts = 0;
		int i = 0;
		while (size_t pos = src.find(det, i) != string::npos)
		{
			cnts++;
			i = pos + det.size();
		}
		cout << cnts << endl;
	}
	return 0;
}