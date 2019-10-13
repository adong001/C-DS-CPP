#include<iostream>
using namespace std;
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<vector>

class Solution {
public:
	void replaceSpace(char *str, int length) {
		
	}
};

void replaceSpace(char *str, int length) {
	int spacecount = 0;
	int newlen;
	char * cur = str;
	while (*cur != '\0')
	{
		if (*cur == ' ')
		{
			spacecount++;
		}
		cur++;
	}
	newlen = length + spacecount * 3;
	str = (char*)realloc(str,newlen);
	for (int i = newlen - 1; cur != str; cur++,i++)
	{
		if (*cur == ' ')
		{
			str[i] = '%';
			str[i + 1] = '2';
			str[i + 2] = '0';
		}

		else
		{
			str[i] = *cur;
		}
	}
}
int main()
{
	char* str = "W a";
	replaceSpace(str, 3);	cout << str;

	/*int num1, num2;
	vector<int> v;
	cin >> num1 >> num2;
	while (num1 >= 1 && num1 <= pow(10, 9) && num2 >= 1 && num2 <= pow(10, 9))
	{
	v.push_back(num1 + num2);
	cin >> num1 >> num2;
	}
	for (auto i : v)
	{
	cout << i << endl;
	1 1 2 3 5
	}*/
	/*int num1, num2;
	int level;
	int sum = 0;
	num1 = num2 = 1;
	cin >> level;
	for (int i = 0; i <= level; i++)
	{
		sum += num1;
	}
	     */
	
	
	return 0;
}