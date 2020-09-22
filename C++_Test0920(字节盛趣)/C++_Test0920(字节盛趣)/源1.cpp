#include<iostream>
#include<string>
using namespace std;

int main2()
{
	string src, det;
	while (cin >> src >> det)
	{
		for (int i = 0, j = 0; i < src.size() && j < det.size();)
		{
			for (; src[i] == det[j] || det[j] == '.'; i++, j++);
			if (j >= det.size())
			{
				if (i >= src.size())
				{
					cout << true << endl;
					break;
				}
				cout << false << endl;
				break;
			}
			else if (det[j] == '*' && j + 1 == det.size())
			{
				cout << true << endl;
				break;
			}
			else
			{
				int pos = 0;
				for (; pos < det.size() && det[j + pos] == '*'; pos++);
				i += pos;
				j += pos;
			}
		}
	}
	return 0;
}

