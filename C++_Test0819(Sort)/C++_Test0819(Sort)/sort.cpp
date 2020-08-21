#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include<time.h>

int main()
{
	std::vector<int> v(100);
	//函数指针类型的声明
	typedef void(*PFUNC)(std::vector<int>&, size_t, bool(*cmp)(int, int));
	PFUNC pfun[] = { Bubble_Sort, Insert_Sort, Choice_Sort };

	for (int i = 0; i < sizeof(pfun)/sizeof(PFUNC); i++)
	{
		Test_Sort(pfun[i],v,100);
	}
    return 0;
}