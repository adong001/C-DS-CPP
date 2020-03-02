#pragma once
#include"bigint.h"
//
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/miller_rabin.hpp>//大素数检测
#define NUMBER 20
using namespace std;
typedef long DataType;
//typedef boost::multiprecision::int1024_t DataType;
struct Key
{
	DataType _eKey;//加密秘钥，e
	DataType _dKey;//解密秘钥, d
	DataType _pKey;//n
};

/*
	1.产生素数
	2.求n
	3.求f(n)
	4.求e (1< e < f(n), e和f(n)构成互质，随机选择)
	5.求d (e * d % f(n) = 1)
	(e , n) (d , n)
	*/

class RSA
{
private:
	Key m_key;
public:
	DataType ecrept(DataType data, DataType ekey, DataType pkey);//加密函数
	DataType decrept(DataType data, DataType dkey, DataType pkey);//解密函数
	DataType getPrime();//获取素数
	bool IsPrime(DataType data);//判断是否为素数
	DataType getPKey(DataType prime1, DataType prime2);//获取公钥
	DataType getOrla(DataType prime1, DataType prime2);//欧拉函数
	DataType getEKey(DataType orla);//获取公钥e
	DataType getDKey(DataType ekey, DataType orla);
	DataType getGcd(DataType data1, DataType data2);//获取两个数的最大公约数
	void getKeys();
	Key getallKey();

	void ecrept(const char* filename, const char* fileout);//文件加密
	void dcrept(const char* filename, const char* fileout);//文件解密

};