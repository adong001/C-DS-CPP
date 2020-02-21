#include"rsa.h"
#include"bigint.h"

void test()
{
	RSA rsa;
	rsa.getKeys();
	Key key = rsa.getallKey();
	cout << "keys:" << endl;
	cout << key._eKey << " " << key._dKey << " " << key._pKey << endl;
	DataType original = 2;
	DataType decout = rsa.ecrept(original, key._eKey, key._pKey);
	cout << "original：" << original << endl;
	cout << "ecrept :" << decout << endl;
	cout << "decreptL" << rsa.decrept(original, key._dKey, key._pKey);
}



void test_add_sub()
{
	BigInt b1;
	cout << "2345636789 + 53746238 ="  << 2345636789 + 53746238 <<"   add = ";
	cout << b1.add("2345636789", "53746238") << endl << endl;

	cout << "-75378478278 + 53746238 =" << -75378478278 + 53746238 << "   add = ";
	cout << b1.add("-75378478278", "53746238") << endl << endl;

	cout << "6726743467 + -6746283898982 =" << 6726743467 + -6746283898982 << "   add = ";
	cout << b1.add("6726743467", "-6746283898982") << endl << endl;

	cout << "-2399287847488 + -674348787829128 =" << -2399287847488 + -674348787829128 << "   add = ";
	cout << b1.add("-2399287847488", "-674348787829128") << endl << endl;



	cout << "2345636789 - 53746238 =" << 2345636789 - 53746238 << "   sub = ";
	cout << b1.sub("2345636789", "53746238") << endl << endl;

	cout << "-75378478278 - 53746238 =" << -75378478278 - 53746238 << "   sub = ";
	cout << b1.sub("-75378478278", "53746238") << endl << endl;

	cout << "6726743467 - -6746283898982 =" << 6726743467 - -6746283898982 << "   sud = ";
	cout << b1.sub("6726743467", "-6746283898982") << endl << endl;

	cout << "-2399287847488 - -674348787829128 =" << -2399287847488 - -674348787829128 << "   sud = ";
	cout << b1.sub("-2399287847488", "-674348787829128") << endl << endl;
}

void test_mul_div()
{
	//使用*号精度不够
	BigInt b1;
	cout << "2345636 * 53746238 =" << 2345636 * 53746238 << "   mul = ";
	cout << b1.mul("2345636", "53746238") << endl << endl;

	cout << "-7537847 * 53746238 =" << -7537847 * 53746238 << "   mul = ";
	cout << b1.mul("-7537847", "53746238") << endl << endl;

	cout << "6726743 * -6746283898982 =" << 6726743 * -6746283898982 << "   mul = ";
	cout << b1.mul("6726743", "-6746283898982") << endl << endl;

	cout << "-239928784 * -674348787 =" << -239928784 * -674348787 << "   mul = ";
	cout << b1.mul("-239928784", "-674348787") << endl << endl;
}

int main()
{
	//test_add_sub();
	//test_mul_div();
	test();
    system("pause");
    return 0;
}