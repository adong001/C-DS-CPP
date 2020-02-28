#include"rsa.h"

//bool IsPrimeBigInt(DataType& data)
//{
//	brdm::mt11213b gen(time(nullptr));
//	if (miller_rabin_test(data, 25, gen))
//	{
//		if (miller_rabin_test((data - 1) / 2, 25, gen))
//		{
//			return true;
//		}
//	}
//	return false;
//}

void RSA::ecrept(const char* filename, const char* fileout)//文件加密
{
	ifstream fin(filename, ifstream::binary);
	ofstream fout(fileout, ifstream::binary);
	if (!fin.is_open())
	{
		perror("input file open failed\n");
		return;
	}
	int length = sizeof(DataType);
	int size = NUMBER * length;

	//读取的字节一定是DataType的整数倍，保证一次不会读取半个DataType的数据
	char* bufferin = new char[size];
	DataType* bufferout = new DataType[NUMBER];
	int curNum;

	while (!fin.eof())
	{
		fin.read(bufferin, size);//每次读NUMBER个DataType字节的数据
		curNum = fin.gcount();//真正读到的字节数，有可能后面读到空
		int k = curNum / length;//以DataType为单位进行加密,k为加密次数
		int i, j;
		for (i = 0,j = 0; i < k; i++,j += length-1)
		{
			//加密后，先写入bufferout缓冲区中
			bufferout[i] = ecrept((DataType)bufferin[j], m_key._eKey, m_key._pKey);
		}
		fout.write((char*)bufferout, curNum);//加密后，写入到fout中
	}
	delete[] bufferin;
	delete[] bufferout;
	fin.close();
	fout.close();
}

void RSA::dcrept(const char* filename, const char* fileout)//文件解密
{

	ifstream fin(filename, ifstream::binary);
	ofstream fout(fileout, ifstream::binary);
	if (!fin.is_open())
	{
		perror("input file open failed\n");
		return;
	}	
	
	int length = sizeof(DataType);
	int size = NUMBER * length;

	//读取的字节一定是DataType的整数倍，保证一次不会读取半个DataType的数据
	DataType* bufferin = new DataType[NUMBER];
	char* bufferout = new char[size];
	int curNum;

	while (!fin.eof())
	{
		fin.read((char*)bufferout, size);//每次读NUMBER个DataType字节的数据
		curNum = fin.gcount();//真正读到的字节数，有可能后面读到空
		int k = curNum / length;//以DataType为单位进行解密,k为解密次数
		int i, j;
		for (i = 0,j = 0; i < k; i++, j += length - 1)
		{
			//解密后，先写入bufferout缓冲区中
			bufferout[j] = (char)ecrept(bufferin[i], m_key._dKey, m_key._pKey);
		}
		fout.write(bufferout, curNum);//解密后，写入到fout中
	}

	delete[] bufferin;
	delete[] bufferout;
	fin.close();
	fout.close();
}

DataType RSA::ecrept(DataType data, DataType ekey, DataType pkey)//加密函数
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

DataType RSA::decrept(DataType data, DataType dkey, DataType pkey)//解密函数
{


	//msgE-->明文，data-->密文，dkey-->私钥，pkey-->n
	//解密：msgE = (data^dkey)%n 
	return ecrept(data, dkey, pkey);
}


DataType RSA::getPrime()//获取素数
{
	/*boost::random::mt199937 gen(time(NULL));
	  boost::random::uniform_int_distribution<DataType> dist(0,DataType(1)<<256);
	  */
	srand(time(NULL));
	DataType prime;
	while (true)
	{
		prime = rand() % 100 + 2;
		if (IsPrime(prime))
		{
			break;
		}
	}
	return prime;
}

bool RSA::IsPrime(DataType data)//判断是否为素数
{
	if (data % 2 == 0)
	{
		return false;
	}

	for (int i = 3; i <= sqrt(data); i += 2)//从2以后，偶数一定不是素数
	{
		if (data % i == 0)
		{
			return false;
		}
		return true;
	}
}
DataType RSA::getPKey(DataType prime1, DataType prime2)//获取n
{
	//f(n) = f(p1*p2)
	return prime1 * prime2;
}

DataType RSA::getOrla(DataType prime1, DataType prime2)//欧拉函数，
{
	//f(nm) = f(n)f(m) = (n-1)(m-1)
	return (prime1 - 1)*(prime2 - 1);
}

DataType RSA::getEKey(DataType orla)//获取加密秘钥e
{
	//1 < e < f(n)
	/*boost::random::mt199937 gen(time(NULL));
	boost::random::uniform_int_distribution<DataType> dist(2,orla);
	*/
	srand(time(NULL));
	DataType ekey;
	while (true)
	{
		//ekey = dist(gen);
		ekey = rand() % orla;//模后肯定小于f(n)
		if (ekey > 1 && getGcd(ekey, orla) == 1)//1 < e < orla e与orla互质(最大公约数=1)
		{
			return ekey;
		}
	}

}
DataType RSA::getDKey(DataType ekey, DataType orla)//获取解密秘钥d
{
	// e * d % f(n) = 1  (f(n) = orla)
	//DataType x = 0, y = 0;
	//exGcd(ekey, orla, x, y);
	////变换，让私钥d是一个比较小的值
	//return (x% orla + orla) % orla;
	DataType dkey = orla / ekey;
	while (true)
	{
		if ((dkey * ekey) % orla == 1)
		{
			return dkey;
		}
		++dkey;
	}
	return dkey;
	
}
DataType RSA::getGcd(DataType data1, DataType data2)//获取两个数的最大公约数
{
	//传的时候data1 >= data2
	if (data2 == 0)
	{
		return data1;
	}
	return getGcd(data2, data1 % data2);
}

void RSA::getKeys()
{
	DataType prime1 = getPrime();
	DataType prime2 = getPrime();
	while (prime1 == prime2)
	{
		prime2 = getPrime();
	}

	DataType orla = getOrla(prime1, prime2);
	m_key._pKey = getPKey(prime1, prime2);
	m_key._eKey = getEKey(orla);
	m_key._dKey = getDKey(m_key._eKey,orla);
}

Key RSA::getallKey()//对外封装访问私有成员的接口
{
	return m_key;
}
//求私钥

//求模范元素(公钥e)
DataType exGcd(DataType a, DataType b, DataType& x, DataType& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	DataType gcd = exGcd(b, a % b, x, y);
	DataType x1 = x, y1 = y;
	x = y1;
	y = x1 - a / b * y1;
	return gcd;
}