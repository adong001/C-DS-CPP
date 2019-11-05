#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main4()
{
    system("pause");
	return 0;

}		auto_ptr<T>& operator =(auto_ptr<T>& aptr)
{
	if (m_ptr != aptr.m_ptr)//判断是不是自己给自己赋值
	{
		if (m_ptr)
		{
			delete m_ptr;
		}
		m_ptr = aptr.m_ptr;
	}
	return *this;
}

T& operator *()
{
	return *m_ptr;
}

T* operator ->()
{
	return m_ptr;
}

~auto_ptr()
{
	if (m_ptr)
	{
		delete m_ptr;
	}
	m_ptr = nullptr;
	cout << "析构！" << endl;
}
	};
};

int main()
{
	int ar[] = { 1, 2, 3, 4, 5 };
	char br[] = "hello";
	Auto::auto_ptr<int> a1;
	Auto::auto_ptr<char>b1;
	a1 = ar;
	b1 = br;
	auto_ptr<T> r;

	cout << *a1 << endl;
	cout << *b1 << endl;
	system("pause");
	return 0;
}