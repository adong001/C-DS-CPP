#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<xutility>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/multiprecision/miller_rabin.hpp>//大素数检测
#define NUMBER 256   //一次解密NUMBER个DataType字节大小的数据

using namespace std;
namespace mp = boost::multiprecision;
namespace rp = boost::random;
typedef long DataType;
//typedef mp::uint1024_t DataType;//DataType是一个1024位的无符号大正数


struct Key
{ 
	DataType m_eKey;//加密秘钥，e
	DataType m_dKey;//解密秘钥, d
	DataType m_pKey;//n
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
public:	DataType ExGcd(DataType a, DataType b, DataType& x, DataType& y);//求模范元素(公钥e)
	DataType Encrypt(DataType data, DataType ekey, DataType pkey);//加密函数
	DataType Decrypt(DataType data, DataType dkey, DataType pkey);//解密函数
	DataType GetPrime();//获取素数
	bool IsPrime(DataType data);//判断是否为素数
	DataType GetPKey(DataType prime1, DataType prime2);//获取公钥
	DataType GetOrla(DataType prime1, DataType prime2);//欧拉函数
	DataType GetEKey(DataType orla);//获取公钥e
	DataType GetDKey(DataType ekey, DataType orla);//获取私钥d
	DataType GetGcd(DataType data1, DataType data2);//获取两个数的最大公约数
	Key GetAllKey();//对外封装访问私有成员的接口

	void GetKeys();//获取全部的钥匙
	void Encrypt(const char* filename, const char* fileout);//文件加密
	void Decrypt(const char* filename, const char* fileout);//文件解密

};