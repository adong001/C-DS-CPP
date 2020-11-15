#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = a;
}
int partition(vector<int>& a, int start, int end)
{
	int pivot = a[start];
	int left = start, right = end;
	while (left <= right)
	{
		for (; left < right && pivot >= a[right]; right--);
		for (; left < right && pivot <= a[left]; left++);
		if (left < right)
		{
			Swap(a[left], a[right]);
		}
	}
	Swap(a[start], a[right]);
	return right;
}
void QuickSort(vector<int>& input, int start, int end, int k)
{
	if (start < end)
	{
		int pivot = partition(input, start, end);
		if (pivot + 1 == k)
		{
			return;
		}
		QuickSort(input, start, pivot - 1, k);
		QuickSort(input, pivot + 1, end, k);
	}
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	if (k > input.size())
	{
		return{};
	}
	QuickSort(input, 0, input.size() - 1, k);
	return{ input.begin(), input.begin() + k };
}


int main2()
{
	vector<int> ss = { 4, 5, 1, 6, 2, 7, 3, 8 };
	GetLeastNumbers_Solution(ss, 4);
	return 0;
}