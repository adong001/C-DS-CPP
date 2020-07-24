#define _CRT_SECURE_NO_WARNINGS 1
#include"UnionFindSet.h"

int main0()
{
	UnionFindSet unf(10);
	unf.Union(0, 6);//三个集合{0,6,7,8}，{1,4,9}，{2,3,5}   
	unf.Union(6, 7);
	unf.Union(0, 8);
	unf.Union(1, 4);
	unf.Union(4, 9);
	unf.Union(2, 3);
	unf.Union(2, 5);
	cout << unf.Count() << endl;
    return 0;
}