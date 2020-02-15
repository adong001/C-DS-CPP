#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Test
{
private:
	int m_a;
	char m_c;
public:
	Test(int a= 0,char c= '\0'):
	m_a(a),
	m_c(c)
	{}

	Test(char c) :
		Test(0,c)
	{}

	void show()
	{
		cout << m_a << ' ' << m_c << endl;
	}
};

int main()
{
	Test t('a');
	t.show();
    system("pause");
    return 0;
}