#include<iostream>
#include<cstring>//cÓïÑÔÖĞstring¿â
#include<string>//c++ÖĞµÄstring¿â
using namespace std;

int main()
{
	string s1;
	string s2("I am a good student");
	string s3(5, 'M');
	string s4(s2);
	//cout << s1 << endl
	//	 << s2 << endl
	//	 << s3 << endl
	//	 << s4 << endl;
	//cout << "s1.size =" << s1.size() << "   s1.length =" << s1.length() << endl;
	//cout << "s2.size =" << s2.size() << "   s2.length =" << s2.length() << endl;
	//cout << "s3.size =" << s3.size() << "   s3.length =" << s3.length() << endl;
	//cout << "s4.size =" << s4.size() << "   s4.length =" << s4.length() << endl;
	//cout << "s1.capacity =" << s1.capacity() << endl;
	//cout << "s2.capacity =" << s2.capacity() << endl;
	//cout << "s3.capacity =" << s3.capacity() << endl;
	//cout << "s4.capacity =" << s4.capacity() << endl;

	s2.reserve(100);
	cout << "s2.capacity =" << s2.capacity() << endl;


    system("pause");
    return 0;
}