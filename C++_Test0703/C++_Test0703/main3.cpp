#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		for (auto& e : s)
		{
			if (e <= 'E')
			{
				e = 'Z' - ('E' - e);
			}
			else
			{
				e -= 5;
			}
		}
		cout << s << endl;
	}
}