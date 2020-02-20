#include"rsa.h"

void test()
{
	RSA rsa;
	rsa.getKeys();
	Key key = rsa.getallKey();
	cout << "keys:" << endl;
	cout << key._eKey << " " << key._dKey << " " << key._pKey << endl;
	DataType original = 2;
	DataType decout = rsa.ecrept(original, key._eKey, key._pKey);
	cout << "original£º" << original << endl;
	cout << "ecrept :" << decout << endl;
	cout << "decreptL" << rsa.decrept(original, key._dKey, key._pKey);
}

int main()
{
	test();
    system("pause");
    return 0;
}