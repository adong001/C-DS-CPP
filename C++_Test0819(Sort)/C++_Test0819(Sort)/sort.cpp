#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include<time.h>

int main()
{
	std::vector<int> v(100);
	void(*pfun[3])(std::vector<int>&, size_t, bool(*cmp)(int, int))
		= { Bubble_Sort, Insert_Sort, Choice_Sort };

	for (int i = 0; i < 3; i++)
	{
		Test_Sort(pfun[i], v, 100);
	}
    return 0;
}