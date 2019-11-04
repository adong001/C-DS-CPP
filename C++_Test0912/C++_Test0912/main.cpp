#include<iostream>
#include<cstring>//c语言中string库
#include<string>//c++中的string库
using namespace std;

int main()
{
	/*string s1;
	string s2("I am a good student");
	string s3(5, 'M');
	string s4(s2);
	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;*/
	/*string s1("hello world");
	string const s2("welcome in");
	cout << s1[3] << " " << s2[5] << endl;*/
	//cout << "s1.size =" << s1.size() << "   s1.length =" << s1.length() << endl;
	//cout << "s2.size =" << s2.size() << "   s2.length =" << s2.length() << endl;
	//cout << "s3.size =" << s3.size() << "   s3.length =" << s3.length() << endl;
	//cout << "s4.size =" << s4.size() << "   s4.length =" << s4.length() << endl;
	//cout << "s1.capacity =" << s1.capacity() << endl;
	//cout << "s2.capacity =" << s2.capacity() << endl;
	//cout << "s3.capacity =" << s3.capacity() << endl;
	//cout << "s4.capacity =" << s4.capacity() << endl;

	//s2.reserve(100);
	//cout << "s2.capacity =" << s2.capacity() << endl;
	/*cout << s1.empty() << endl;
	cout << s2.empty() << endl;*/
	/*cout << "s2.size = "<<s2.size()  <<endl;
	cout << "s2.capacity = " << s2.capacity() << endl;
	s2.clear();
	cout << s2 << endl;
	cout << "s2.size = " << s2.size() << endl;
	cout << "s2.capacity = " << s2.capacity() << endl;*/
	/*cout << s3.size() << endl;
	s3.resize(20);
	cout << s3 << endl;
	cout << s3.size() << endl;

	cout << s3.capacity() << endl;
*/

	string s1;
	string s2("Student");
	//cout << s2.substr() << endl;
	//cout << s2.substr(20, 5) << endl;
	//cout << s2.substr(-1, 5) << endl;
	//cout << s2.substr(2, -1) << endl;
	//cout << s2.substr(-2, 10) << endl;

	cout << s2.find("ud");
	cout << s2.find(s1);
	char str[1000] = { 0 };
	scanf("%d[0-9]",str);//限定输入（正则表达式）
	scanf("%d[^\n]", str);
	scanf("%d[a-z]", str);
	fgets(str, 1000, stdin);
	
	cin.getline(str, 10);

	getline(cin, s1);
	cout << s1;
	//cout << s2.rfind('e') << endl;
	//cout << s2.rfind('e',2) << endl;
	//cout << s2.rfind('a') << endl;


	/*cout << s2.find('e') << endl;
	cout << s2.find('e',2) << endl;
	cout << s2.find('a') << endl;*/

	//printf("%s\n", s2.c_str());
	//s1.append("I am ");
	//s1.append(s2);

	//s1.append('a');

	//cout << s1 << endl;


	//s1 += 'I';
	//s1 += " am ";
	//s1 += s2;
	//cout << s1 << endl;



	//s2.push_back('s');
	//cout << s2 << endl;
	//s2.push_back("hahah");

    system("pause");
    return 0;
}