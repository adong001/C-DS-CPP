#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int num;
	char c;
	vector<int> v1, v2;
	while (scanf("%d%c", &num, &c) && c != '\n')
	{
		v1.push_back(num);
	}
	v1.push_back(num);
	while (scanf("%d%c", &num, &c) && c != '\n')
	{
		v2.push_back(num);
	}
	v2.push_back(num);
	int s1 = v1.size();
	int s2 = v2.size();
	int i, j;
	for (i = 0, j = 0; i < s1 && j < s2;)
	{
		if (v1[i] < v2[j])
		{
			cout << v1[i] << " ";
			i++;
		}
		else
		{
			cout << v2[j] << " ";
			j++;
		}
	}
	for (; i < s1; i++)
	{
		cout << v1[i] << " ";
	}
	for (; j < s2; j++)
	{
		cout << v2[j] << " ";
	}
	cout << endl;
	return 0;
}
