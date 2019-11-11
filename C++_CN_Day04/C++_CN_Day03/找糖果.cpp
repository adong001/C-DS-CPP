#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//题目：A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上具体有多少个糖果, 
//但是我们知道以下的信息：A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
//现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足所有题设条件。

//void FindCandy()
//{
//	int A, B, C;
//	vector<int> v;
//	int n;
//	while (cin >> n)
//		v.push_back(n);
//	A = (v[0] + v[2]) / 2;
//	B = (v[1] + v[3]) / 2;
//	C = v[3] - B;
//	if ((A - B == v[0]) && (B - C == v[1]) && (A + B == v[2]) && (B + C == v[3])){
//		cout << A << " " << B << " " << C << endl;
//	}
//	else{
//		cout << "No" << endl;
//	}
//}
void FindCandy()
{
	int A_B, B_C, AB, BC;
	int A, B1, B2, C;
	cin >> A_B >> B_C >> AB >> BC;
	if (A_B<-30 && A_B>30 && B_C<-30 && B_C>30 &&
		AB<-30 && AB>30 && BC<-30 && BC>30 &&
		A_B > AB && B_C > BC)
	{
		cout << "NO" << endl;
		return;
	}

	A = (A_B + AB) / 2;
	C = (BC - B_C)/2;
	B1 = (AB - A_B) / 2;
	B2 = (B_C + BC) / 2;

	if (B1 == B2)
	{
		cout << A << " " << B1 << " " << C << endl;
	}
	else
	{
		cout << "No" << endl;
	}

}

int main1()
{
	FindCandy();
	system("pause");
	return 0;
}