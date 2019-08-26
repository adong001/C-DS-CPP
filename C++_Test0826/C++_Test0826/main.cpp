#include<iostream>
using namespace std;

void Swap(int &aa, int &bb)//aa是a的引用(别名)，bb是b的引用(别名)
{
	int tmp = aa;
	aa = bb;
	bb = tmp;
}
//引用特性
//1. 引用在定义时必须初始化 
//2. 一个变量可以有多个引用 
//3. 引用一旦引用一个实体，再不能引用其他实体


void TestRef()
{
	int a = 10;
	//int& ra;   // 该条语句编译时会出错 
	int& ra = a;
	int& rra = a;
	printf("%p  %p  %p\n", &a, &ra, &rra);
}
void TestConstRef()
{
	const int a = 10;
	//int& ra = a;   // 该语句编译时会出错，a为常量 
	const int& ra = a;
	// int& b = 10;  // 该语句编译时会出错，b为常量 
	const int& b = 10;
	double d = 12.34;
	//int& rd = d;  // 该语句编译时会出错，类型不同 
	const int& rd = d;
}

int& add(int a, int b)
{
	int c = a + b;
	return c;//反回了局部变量的引用
}

//void(auto &a, auto &b)//auto不能作为函数参数和返回值类型
//{
//	return a + b;
//}
int main()
{
	int i = 10;
	char j = 'j';

	auto a = i;//C++11版本才有auto
	cout << typeid(a).name() << endl;

	auto b = 'j';
	cout << typeid(b).name() << endl;

	auto c = &j;
	cout << typeid(c).name() << endl;

	auto d = 10;
	cout << typeid(d).name() << endl;

	auto *e = &i;
	cout << typeid(e).name() << endl;
	//auto ar[] = { 1, 2, 3, 4 };//报错，auto不能用来声明数组
	//auto aa = 1, bb = 2.33;//报错，一行只能判断一种类型
	//int likui = 100;
	//int &heixuanfeng = likui;//定义时为引用(取别名)，否则为取地址
	//cout << "likui = " << likui << " heixaunfeng = " << heixuanfeng << endl;//值相等
	//cout << "&likui = " << &likui << " &heixaunfeng = " << &heixuanfeng << endl;//地址相同，两者是一个东西，两个名字而已。
	//int a = 10, b = 20;
	//cout << "a = " << a << " b = " << b << endl;
	//Swap(a, b);
	//cout << "a = " << a << " b = " << b << endl;
	//int &ret = add(1, 2);//ret值为随机值
	//add(3, 4);
	//cout << "add(1,2)=" << ret << endl;

	system("pause");
	return 0;
}