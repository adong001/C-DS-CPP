#include"rsa.h"

void test_key()
{
	RSA rsa;
	int k = 20;
	while (k)
	{
		rsa.GetKeys();
		Key key = rsa.GetAllKey();
		cout << "keys:" << endl;
		cout << "key._eKey:" << key.m_eKey << " " << "key._dKey:" << key.m_dKey << " " << "key._pKey:" << key.m_pKey << endl;
		DataType original = 243;
		DataType decout = rsa.Encrypt(original, key.m_eKey, key.m_pKey);
		cout << "original:" << original << endl;
		cout << "ecrept:" << decout << endl;
		cout << "decrept:" << rsa.Decrypt(decout, key.m_dKey, key.m_pKey);
		cout << endl << endl;
		k--;
	}
}

//void test_boost()
//{
//	char* rsa100 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
//	char* rsa50 = "12345678901234567890123456789012345678901234567890";
//
//	DataType a(rsa100);
//	DataType b(rsa50);
//
//	cout << a / 2 << endl;
//	cout << b / 2 << endl;
//}

void test_file()
{
	RSA rsa;
	rsa.GetKeys();
	rsa.Encrypt("原文件.txt", "加密文件.txt");
	rsa.Decrypt("加密文件.txt", "解密文件.txt");
}

//void test_boost_time()
//{
//	//mt19937:一种随机数产生器
//	rp::mt19937 gen(time(nullptr));
//	cout << "random" << endl;
//	//指定随机数的范围 0 ~ (1<<786) 
//	rp::uniform_int_distribution<mp::cpp_int> dist(0, mp::cpp_int(1) << 768);
//
//	cout << dist(gen) << endl;
//}

//
//void test_add_sub_mul_div()
//{
//	BigInt b1;
//	cout << "2345636789 + 53746238 =" << 2345636789 + 53746238 << "   add = ";
//	cout << b1.add("2345636789", "53746238") << endl << endl;
//
//	cout << "2345636789 - 53746238 =" << 2345636789 - 53746238 << "   sub = ";
//	cout << b1.sub("2345636789", "53746238") << endl << endl;
//
//	cout << "2345 * 53746 =" << 2345 * 53746 << "   mul = ";
//	cout << b1.mul("2345", "53746") << endl << endl;
//
//	cout << "2345636 / 53746 =" << 2345636 / 53746 << "......" << 2345636 % 53746 << "   div = ";
//	cout << b1.div("2345636", "53746").first << "......" << b1.div("2345636", "53746").second << endl << endl;
//
//
//	cout << "53746 / 627 =" << 53746 / 627 << "......" << 53746 % 627 << "   div = ";
//	cout << b1.div("627", "53746").first << "......" << b1.div("627", "53746").second << endl << endl;
//}


int main()
{
	//test_add_sub_mul_div();
	//test_key();
	 //test_boost();
	test_file();
	system("pause");
	return 0;
}