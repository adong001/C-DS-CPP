#include"String.h"
int main()
{
	String s("student");
	const String s2("studentr");
	cout <<("student" > s );
	cout <<("studentw" >= s);
	cout <<("student" <= s );
	cout <<("student" > s);
	cout <<("student" != s);
	/*cout << s + "kkk" << endl;
	cout << s + s2 << endl;
	cout << "KKKK" + s << endl;*/
	/*cout << (s >= "student");
	cout << (s <= "studente");
	cout << (s > "student");
	cout << (s >= s2);
	cout << (s <=s2);
	cout << (s <= s2);*/
	/*cout << (s > "student");
	cout << (s > "student");
	cout << (s > "student");
	cout << (s > "student");*/
	system("pause");
    return 0;
}
