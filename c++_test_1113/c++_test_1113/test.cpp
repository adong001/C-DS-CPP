#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Finder {
public:

	void Swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	int QuickSort(vector<int>& arr, int start, int end)
	{
		int left = start, right = end;
		int pivot = arr[start];

		while (start < end)
		{
			for (; start < end && pivot <= arr[end]; end--);
			for (; start < end && arr[start] <= pivot; start++);
			if (start < end)//若未相遇就交换
			{
				Swap(arr[start], arr[end]);
			}
		}
		Swap(arr[left], arr[end]);//中间是基准值，左边比基准值小，右边比基准值大，
		return end;
	}

	int findK(vector<int>& a, int left, int right, int k)
	{
		int n = a.size();
		if (left <= right)
		{
			int pos = QuickSort(a, left, right);
			if (pos == n - k)
			{
				return a[pos];
			}
			else if (pos < n - k)
			{
				return findK(a, pos + 1, right, k);
			}
			else
			{
				return findK(a, left, pos - 1, k);
			}
		}
		return -1;
	}

	int findKth(vector<int>& a, int n, int K)
	{
		return findK(a, 0, n - 1, K);
	}
};


int upper_bound_(int n, int v, vector<int>& a)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == v)
		{
			int i = mid;
			for (; i - 1 >= 0 && a[i - 1] == v; i--);
			return i + 1;
		}
		else if (a[mid] > v)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

vector<string> split(const string& src)
{
	int start = 0, end = 0;
	vector<string> vs;
	for (; start < src.size();)
	{
		for (; end < src.size() && src[end] != ' '; end++);
		vs.push_back(src.substr(start, end - start));
		for (; end < src.size() && src[end] == ' '; end++);
		start = end;
	}
	return vs;
}
	vector<string> uncommonFromSentences(string A, string B)
	{
		vector<string> vs = split(A +" "+ B);
		vector<string> ret;
		unordered_map<string, int> um;
		for (auto& e : vs)
		{
			um[e]++;
		}
		for (auto& e : um)
		{
			if (e.second == 1)
			{
				ret.push_back(e.first);
			}
		}
		return ret;
	}
int main()
{
	string A = "this apple is sweet";
	string B = "this apple is sour";

	uncommonFromSentences(A,B);
	vector<int> a = { 1,2,4,4,5};
	
	upper_bound_(5, 4, a);
	Finder f;
	cout << f.findKth(a, 9, 3);
	return 0;
}
