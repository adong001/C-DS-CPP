#include"rsa.h"

void test_key()
{
	RSA rsa;
	int k = 20;
	while (k)
	{
		rsa.getKeys();
		Key key = rsa.getallKey();
		cout << "keys:" << endl;
		cout << "key._eKey:" << key._eKey << " " << "key._dKey:" << key._dKey << " " << "key._pKey:" << key._pKey << endl;
		DataType original = 243;
		DataType decout = rsa.ecrept(original, key._eKey, key._pKey);
		cout << "original:" << original << endl;
		cout << "ecrept:" << decout << endl;
		cout << "decrept:" << rsa.decrept(decout, key._dKey, key._pKey);
		cout << endl << endl;
		k--;
	}
}

void test_file()
{
	RSA rsa;
	rsa.getKeys();
	rsa.ecrept("原文件.txt", "加密文件.txt");
	rsa.dcrept("加密文件.txt", "解密文件.txt");
}


void test_add_sub_mul_div()
{
	BigInt b1;
	cout << "2345636789 + 53746238 =" << 2345636789 + 53746238 << "   add = ";
	cout << b1.add("2345636789", "53746238") << endl << endl;

	cout << "2345636789 - 53746238 =" << 2345636789 - 53746238 << "   sub = ";
	cout << b1.sub("2345636789", "53746238") << endl << endl;

	cout << "2345 * 53746 =" << 2345 * 53746 << "   mul = ";
	cout << b1.mul("2345", "53746") << endl << endl;

	cout << "2345636 / 53746 =" << 2345636 / 53746 << "......" << 2345636 % 53746 << "   div = ";
	cout << b1.div("2345636", "53746").first << "......" << b1.div("2345636", "53746").second << endl << endl;


	cout << "53746 / 627 =" << 53746 / 627 << "......" << 53746 % 627 << "   div = ";
	cout << b1.div("627", "53746").first << "......" << b1.div("627", "53746").second << endl << endl;
}

int main()
{
	test_add_sub_mul_div();
	//test_key();
	//test_file();
	system("pause");
	return 0;
}