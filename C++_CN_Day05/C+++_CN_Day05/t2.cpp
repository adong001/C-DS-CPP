#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


class Finder {
public:

	int BinaryFind(vector<int>ar, int size, int x)
	{
		int left = size - 1;
		int right = 0;
		int mid = (left + right) / 2;
		while (left <= right)
		{
			if (ar[mid] == x)
			{
				return mid;
			}
			else if (ar[mid] > x)
			{
				right = mid - 1;
				mid = (left + right) / 2;
			}
			else
			{
				left = mid + 1;
				mid = (left + right) / 2;
			}
		}
		return -1;
	}


	int findElement(vector<int> A, int n, int x)
	{
		int left = 0;
		int right = n - 1;
		int mid = (left + right) / 2;
		int pos;
		if (A[right] < A[mid])
		{
			while (A[right] < A[mid])
			{
				left = mid + 1;
				mid = (right + left) / 2;
			}
		}
		if (A[left] > A[mid])
		{
			while (A[left] > A[mid])
			{
				right = mid - 1;
				mid = (right + left) / 2;
			}
			pos = mid + 1;

			right = n - 1;
			left = pos;
			mid = (right + left) / 2;
			BinaryFind(A + pos,)

			right = pos - 1;
			left = pos;
			mid = (right + left) / 2;
			while (mid != left && mid != right)
			{
				if (A[mid] == x)
				{
					return mid;
				}
				else if (A[mid] > x)
				{
					left = mid - 1;
					mid = (right + left) / 2;
				}
				else
				{
					right = mid + 1;
					mid = (right + left) / 2;
				}
			}
		}

	}

};
int main2()
{//  6 9 11 45 1 4
	Finder test;
	vector<int> v= { 6, 1, 2, 3, 4, 5 };
	cout<<test.findElement(v, 6, 6)<<endl;
    system("pause");
    return 0;
}