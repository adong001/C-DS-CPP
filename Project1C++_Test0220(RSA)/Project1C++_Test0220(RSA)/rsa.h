#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<ctime>
#include<fstream>
#include<cmath>
#define NUMBER 256
using namespace std;
typedef long DataType;
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
	DataType getPKey(DataType prime1,DataType prime2);//获取公钥
	DataType getOrla(DataType prime1, DataType prime2);//欧拉函数
	DataType getEKey(DataType orla);//获取公钥e
	DataType getDKey(DataType ekey, DataType orla);
	DataType getGcd(DataType data1, DataType data2);//获取两个数的最大公约数
	void getKeys();
	Key getallKey();


	void ecrept(const char* filename, const char* fileout)//文件加密
	{
		ifstream fin(filename, ifstream::binary);
		ofstream fout(fileout, ifstream::binary);
		if (!fin.is_open())
		{
			perror("input file open failed\n");
			return;
		}
		char* buffer = new char[NUMBER];
		DataType* bufferout = new DataType[NUMBER];
		while (!fin.eof())
		{
			fin.read(buffer, NUMBER);
			int curNum = fin.gcount();//真正读到的字节数
			for (int i = 0; i < curNum; i++)
			{
				ecrept((DataType)buffer[i],m_key._eKey, m_key._pKey);//以DataType为单位进行加密
			}
			fout.write((char*)bufferout, curNum * sizeof(DataType));//加密后，写入到fout中
		}
		fin.close();
		fout.close();
	}
	void dcrept(const char* filename, const char* fileout)//文件解密
	{

		ifstream fin(filename, ifstream::binary);
		ofstream fout(fileout, ifstream::binary);
		if (!fin.is_open())
		{
			perror("input file open failed\n");
			return;
		}
		char* bufferout = new char[NUMBER];
		DataType* buffer = new DataType[NUMBER];
		while (!fin.eof())
		{
			fin.read((char*)buffer, NUMBER*sizeof(DataType));
			int curNum = fin.gcount();//真正读到的字节数
			curNum /= sizeof(DataType);
			for (int i = 0; i < curNum; i++)
			{
				bufferout[i] = decrept((buffer[i], m_key._eKey, m_key._pKey);//以DataType为单位进行加密
			}
			fout.write(bufferout, curNum);//加密后，写入到fout中
		}
		fin.close();
		fout.close();
	}
};