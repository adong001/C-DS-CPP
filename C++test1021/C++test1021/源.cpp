#include<iostream>
#include<string>
using namespace std;

class A
{
private:
	int m_a;
public:
	virtual void f1() 
	{
		cout << "A_1  ";
	}
	void f2()
	{
		cout << "A_2  ";
	}
};

class B
{
private:
	int m_b;
public:
	virtual void f1() 
	{
		cout << "A_1  ";
	}
	void f2()
	{
		cout << "A_2  ";
	}
};


class C :public A ,public B 
{
private:
	int m_c;
public:
	virtual void f1()
	{
		cout << "C_1  ";
	}
	void f2()
	{
		cout << "A_2  ";
	}
};
string FindChatRecord(const string& key = string(), const string& maskword = string())
{
	string str;
	str = key;
	str = maskword;
	return str;
}


class Finder {
public:

	void Swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	int QuickSort(vector<int> a, int left, int right)
	{
		int pivot = a[left];
		while (left < right)
		{
			for (; left < right && a[right] <= pivot; right--);
			for (; left < right && a[left] >= pivot; left++);
			if (right < left)
			{
				Swap(a[right], a[left]);
			}
		}
		Swap(a[right], a[pivot]);
		return right;//基准值位置
	}

	int findK(vector<int> a, int left, int right, int k)
	{
		if (left <= right)
		{
			int pos = QuickSort(a, left, right);
			if (pos == k - 1)
			{
				return a[pos];
			}
			else if (pos < k - 1)
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

	int findKth(vector<int> a, int n, int K)
	{
		return findK(a, 0, n - 1, K);
	}
};
int main()
{

	vector<int> a = { 9, 2, 4, 1, 6, 3, 8, 5, 7 };
	Finder f;
	f.findKth(a, 10, 3);
	A a;
	B b;
	string s1 = "sss";
	string s2 = "qqq";
	cout << FindChatRecord(s1);
	cout << FindChatRecord(s1,s2);
	cout << FindChatRecord();
	return 0;
}