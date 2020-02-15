#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;


template<class T>
class unknown
{
public:
	void get_type(string& val)
	{
		cout << "this is string type" << endl;
	}

	void get_type(vector<int>& val)
	{
		cout << "this is vector<int> type" << endl;
	}

	void get_type(map<int,int>& val)
	{
		cout << "this is map<int,int> type" << endl;
	}
	void get_type(vector<int>& val)
	{
		cout << "this is vector<int> type" << endl;
	}
};


int main()
{
    system("pause");
    return 0;
}