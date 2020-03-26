#include"rsa.h"

void RSA::ProdureKeyFile(const char* ekey_file, const char* dkey_file, const char* pkey_file)//产生钥匙文件
{
	int keys = 3;
	int length = sizeof(DataType);
	ofstream fe(ekey_file);
	ofstream fd(dkey_file);
	ofstream fp(pkey_file);

	while (keys--)
	{
		DataType prime1 = GetPrime();
		DataType prime2 = GetPrime();
		while (prime1 == prime2)
		{
			prime2 = GetPrime();
		}
		DataType orla = GetOrla(prime1, prime2);
		DataType pKey = GetPKey(prime1, prime2);
		DataType eKey = GetEKey(orla);
		DataType dKey = GetDKey(m_key.m_eKey, orla);
		fe.write((char*)&eKey, length);
		fd.write((char*)&dKey, length);
		fp.write((char*)&pKey, length);
	}
	fe.close();
	fd.close();
	fp.close();
}


//void RSA::ProdureKeyFile(const char* ekey_file, const char* dkey_file, const char* pkey_file)//产生钥匙文件
//{
//	int keys = 3;
//	int length = sizeof(DataType);
//	ofstream fe(ekey_file, ofstream::binary);
//	ofstream fd(dkey_file, ofstream::binary);
//	ofstream fp(pkey_file, ofstream::binary);
//
//	while (keys--)
//	{
//		DataType prime1 = GetPrime();
//		DataType prime2 = GetPrime();
//		while (prime1 == prime2)
//		{
//			prime2 = GetPrime();
//		}
//		DataType orla = GetOrla(prime1, prime2);
//		DataType pKey = GetPKey(prime1, prime2);
//		DataType eKey = GetEKey(orla);
//		DataType dKey = GetDKey(m_key.m_eKey, orla);
//		fe.write((char*)&eKey, length);
//		fd.write((char*)&dKey, length);
//		fp.write((char*)&pKey, length);
//	}
//	fe.close();
//	fd.close();
//	fp.close();
//}

void GetRandom()
{
	//mt19937:一种随机数产生器  
	rp::mt19937 gen(time(nullptr));
	cout << "random" << endl;
	//指定随机数的范围 0 ~ (1<<786) 
	rp::uniform_int_distribution<mp::cpp_int> dist(0, mp::cpp_int(1) << 128);

	cout << dist(gen) << endl;
}

bool IsPrimeBigInt(DataType& data)
{
	rp::mt11213b gen(time(nullptr));
	if (mp::miller_rabin_test(data, 25, gen))
	{
		if (mp::miller_rabin_test((data - 1) / 2, 25, gen))
		{
			return true;
		}
	}
	return false;
}

void RSA::Encrypt(const char* filename, const char* fileout)//文件加密
{
	ifstream fin(filename, ifstream::binary);
	ofstream fout(fileout, ifstream::binary);
	if (!fin.is_open())
	{
		perror("input file open failed\n");
		return;
	}
	
	int length = sizeof(DataType);
	//读取的字节一定是DataType的整数倍，保证一次不会读取半个DataType的数据
	char* bufferin = new char[NUMBER];
	DataType* bufferout = new DataType[NUMBER];
	int curNum;

	while (!fin.eof())
	{
		fin.read(bufferin, NUMBER);//每次读NUMBER个字节的数据
		curNum = fin.gcount();//真正读到的字节数，有可能后面读到空
		int i;
		for (i = 0; i < curNum; i++)
		{
			bufferout[i] = Encrypt((DataType)bufferin[i], m_key.m_eKey, m_key.m_pKey);
			//每次将一个字节加密成一个DataType型，写入bufferout缓冲区中
		}
		fout.write((char*)bufferout, curNum * length);
		//因为每次将一个字节加密成一个DataType型，共加密curNum次，bufferout每个元素大小为DataType
		//所以要向fout写入curNum * length个字节
	}
	delete[] bufferin;
	delete[] bufferout;
	fin.close();
	fout.close();
}

void RSA::Decrypt(const char* filename, const char* fileout)//文件解密
{

	ifstream fin(filename, ifstream::binary);
	ofstream fout(fileout, ifstream::binary);
	if (!fin.is_open())
	{
		perror("input file open failed\n");
		return;
	}	
	
	int length = sizeof(DataType);
	int curNum;

    DataType* bufferin = new DataType[NUMBER];
	char* bufferout = new char[NUMBER];

	while (!fin.eof())
	{
		fin.read((char*)bufferin, NUMBER * length);//每次读NUMBER个DataType字节的数据
		curNum = fin.gcount();//真正读到的字节数，有可能后面读到空
		curNum /= length;//真正读到curNum个DataType字节的数据，下面就解密curNum次
		int i;
		for (i = 0; i < curNum; i++)
		{
			//每次以DataType为单位进行解密，curNum个DataType字节的数据，共解密curNum次
			//每次将一个DataType为单位的数据解密成一个字节的数据，写入bufferout缓冲区中
			bufferout[i] = (char)Decrypt(bufferin[i], m_key.m_dKey, m_key.m_pKey);
		}
		fout.write(bufferout, curNum);
		//解密curNum次，就得到curNum字节得数据，写入fout文件中
	}
	delete[] bufferin;
	delete[] bufferout;
	fin.close();
	fout.close();
}

DataType RSA::Encrypt(DataType data, DataType ekey, DataType pkey)//加密函数
{
	//msgE-->密文，data-->明文，ekey-->公钥，pkey-->n
	/*加密：msgE = (data^ekey)% pkey 
				 = ((data^(b0*2^0) * data^(b1*2^1)*......*data^(bn*2^n))% pkey 
	             = ((data^(2^i)) *......*(data^(2^n)))% pkey  //i代表data 比特位为1的位数
				 = (((data^(2^i)) % pkey) *......*((data^(2^n)) % pkey))% pkey
令Ai = (data^(2^i))% pkey
  An = (data^(2^n))% pkey
     = (data^(2^(n-1))% pkey * data^(2^(n-1))% pkey)% pkey
	 = (An-1 * An-1) %pkey
				 = (Ai * ......* An);
				 这样每次都%pkey，就不会产生数据溢出
	*/
	DataType Ai = data;
	DataType msgE = 1;
	//data^ekey % pkey
	while (ekey)
	{
		if (ekey & 1)//取出比特位为1的
		{
			msgE = (msgE * Ai) % pkey;//msgE = 叠乘Ai ,第一个Ai = data^ 2^ i % pkey
		}
		ekey >>= 1;//取下一位
		Ai = (Ai * Ai) % pkey; //Ai+1 = (Ai * Ai) % pkey
	}
	return msgE;//密文
}

DataType RSA::Decrypt(DataType data, DataType dkey, DataType pkey)//解密函数
{
	//msgE-->明文，data-->密文，dkey-->私钥，pkey-->n
	//解密：msgE = (data^dkey)%n 
	return Encrypt(data, dkey, pkey);
}


DataType RSA::GetPrime()//获取素数
{
	/*rp::mt19937 gen(time(NULL));
	rp::uniform_int_distribution<DataType> dist(DataType(1), DataType(1) << 256);*/
	//随机获取一个50位到256位的大数
	srand(time(NULL));  
    DataType prime;
	while (true)
	{
		prime = rand() % 100 + 2;
		//prime = dist(gen);
		if (IsPrime(prime))
		{
			break;
		}
	}
	return prime;
}

bool RSA::IsPrime(DataType data)//判断是否为素数
{
	/*rp::mt11213b gen(time(nullptr));
	if (mp::miller_rabin_test(data, 25, gen))
	{
		if (mp::miller_rabin_test((data - 1) / 2, 25, gen))
		{
			return true;
		}
	}
	return false;*/

	for (int i = 2; i <= sqrt(data); i++)
	{
		if (data % i == 0)
		{
			return false;
		}
	}
	return true;
}
DataType RSA::GetPKey(DataType prime1, DataType prime2)//获取n
{
	//f(n) = f(p1*p2)
	return prime1 * prime2;
}

DataType RSA::GetOrla(DataType prime1, DataType prime2)//欧拉函数，
{
	//f(nm) = f(n)f(m) = (n-1)(m-1)
	return (prime1 - 1)*(prime2 - 1);
}

DataType RSA::GetEKey(DataType orla)//获取加密秘钥e
{
	//1 < e < f(n)
	rp::mt19937 gen(time(NULL));
	rp::uniform_int_distribution<DataType> dist(2,orla);//获取一个2--orla的大数
	
	//srand(time(NULL));
	DataType ekey;
	while (true)
	{
		ekey = dist(gen);
		//ekey = rand() % orla;//模后肯定小于f(n)
		if (ekey > 1 && GetGcd(ekey, orla) == 1)//1 < e < orla e与orla互质(最大公约数=1)
		{
			return ekey;
		}
	}

}
DataType RSA::GetDKey(DataType ekey, DataType orla)//获取解密秘钥d
{
	// e * d % f(n) = 1  (f(n) = orla)
	DataType x = 0, y = 0;
	ExGcd(ekey, orla, x, y);
	//变换，让私钥d是一个比较小的值
	return (x % orla + orla) % orla;
	/*DataType dkey = orla / ekey;
	while (true)
	{
		if ((dkey * ekey) % orla == 1)
		{
			return dkey;
		}
		++dkey;
	}
	return dkey;*/
	
}
DataType RSA::GetGcd(DataType data1, DataType data2)//获取两个数的最大公约数
{
	//传的时候data1 >= data2
	if (data2 == 0)
	{
		return data1;
	}
	return GetGcd(data2, data1 % data2);
}

void RSA::GetKeys()
{
	DataType prime1 = GetPrime();
	DataType prime2 = GetPrime();
	while (prime1 == prime2)
	{
		prime2 = GetPrime();
	}

	DataType orla = GetOrla(prime1, prime2);
	m_key.m_pKey = GetPKey(prime1, prime2);
	m_key.m_eKey = GetEKey(orla);
	m_key.m_dKey = GetDKey(m_key.m_eKey,orla);
}

Key RSA::GetAllKey()//对外封装访问私有成员的接口
{
	return m_key;
}
//求私钥

//求模范元素(公钥e)
DataType RSA::ExGcd(DataType a, DataType b, DataType& x, DataType& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	DataType gcd = ExGcd(b, a % b, x, y);
	DataType x1 = x, y1 = y;
	x = y1;
	y = x1 - a / b * y1;
	return gcd;
}