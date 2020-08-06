#include<iostream>
#include<vector>
using namespace std;
int main4()
{
	char c;
	int G1, G2, S1, S2, K1, K2;
	int n1 = 17 * 29;
	int n2 = 29;
	while (cin >> G1 >> c >> S1 >> c >> K1)
	{
		cin >> G2 >> c >> S2 >> c >> K2;
		int t1 = G1*n1 + S1*n2 + K1;
		int t2 = G2*n1 + S2*n2 + K2;
		int t = t2 - t1;
		if (t1 > t2)
		{
			t *= -1;
			cout << "-";
		}
		cout << t/n1 << "." << (t%n1) / n2 << "." << (t%n1%n2) / 1 << endl;

	}
	return 0;
}