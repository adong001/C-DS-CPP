#include<iostream>
using namespace std;
#include<typeinfo>

//class Test
//{
//private:
//	int a;
//	int b;
//public:
//	Test():
//		a(0),
//		b(0)
//	{}
//	Test(int aa, int bb) :
//		a(aa),
//		b(bb)
//	{}
//	Test operator =(Test& t);
//	Test operator +(Test& t);
//	Test operator ++();//前置++
//	Test operator ++(int);//后置++
//	friend ostream& operator <<(ostream& os, Test& t);
//	friend istream& operator >>(istream& is, Test& t);
//};
//Test Test::operator =(Test& t)
//{
//	a = t.a;
//	b = t.b;
//	return *this;
//}
//
//Test Test::operator +(Test& t)
//{
//	Test tmp = *this;
//	tmp.a += t.a;
//	tmp.b += t.b;
//	return tmp;
//}
//
//Test Test::operator ++()//前置++
//{
//	a += 1;
//	b += 1;
//	return *this;
//}
//
//Test Test::operator ++(int)//后置++
//{
//	Test tmp = *this;
//	a += 1;
//	b += 1;
//	return tmp;
//}
//
//ostream& operator <<(ostream& os, Test& t)
//{
//	os << t.a << " " << t.b << endl;
//	return os;
//}
//
//istream& operator>> (istream& is, Test& t)
//{
//	is >> t.a >> t.b;
//	return is;
//}
/*Test t1(10, 20);
	Test t2(30, 40);
	Test t3;
	cout << t1 << t2;
	cin >> t3;
	cout << t3;
	t3 = (t1 + t2);
	cout << t3;
	cout<<(t3++);
	cout << t3;
	cout << (++t3);*/
int main()
{
	/*int a = 10;
	auto b ;
	b = 10;
	cout << typeid(b).name() << endl;*/

	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto i : ar)
	{
		cout << i<<" ";
	}
    system("pause");
    return 0;
}