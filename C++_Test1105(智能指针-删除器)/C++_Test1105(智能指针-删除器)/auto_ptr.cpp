#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<memory>
using namespace std;

namespace Auto
{
	template<class T>
	class auto_ptr
	{
	private:
		T* m_ptr;
	public:

		auto_ptr(T* ptr = nullptr) :
			m_ptr(ptr)
		{}

		auto_ptr(auto_ptr& aptr)
		{
			m_ptr = aptr.m_ptr;
			aptr = nullptr;
		}
		/*auto_ptr<T>& operator =(T* src)
		{
			if (src)
			{
				if (m_ptr)
				{
					delete m_ptr;
				}
				m_ptr = src;
				*this = *((T*)this);
				return *this;
			}
		}
*/
		auto_ptr<T>& operator =(auto_ptr<T>& aptr)
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
	cout << *b1<< endl;
	system("pause");
	return 0;
}