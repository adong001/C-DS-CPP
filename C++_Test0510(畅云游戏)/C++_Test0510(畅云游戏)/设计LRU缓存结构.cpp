#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
#include<map>
using namespace std;
struct K_val
{
	int x;
	int y;
};

struct K
{
	char s1[100];
	int a;
	char b;
	long long c;
};

int main()
{
	int n, k;

	K key;
	K* p = &key;
	p++;
	//cout << *p <<endl;
	cout << sizeof(key) << endl;

	while (cin >> n >> k)
	{
		int op;
		queue<K_val> smm;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> op;
			if (op == 1)
			{
				K_val kv;
				cin >> kv.x >> kv.y;
				if (smm.size() < k)//»º´æÃ»Âú
				{
					smm.push(kv);
				}
				else
				{
					smm.pop();
					smm.push(kv);
				}
			}
			else
			{
				cin >> x;
				
			}
		}
	}
    return 0;
}