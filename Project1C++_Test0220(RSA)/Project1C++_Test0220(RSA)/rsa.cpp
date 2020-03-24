#include"rsa.h"

void GetRandom()
{
	//mt19937:一种随机数产生器
	rp::mt19937 gen(time(nullptr));
	cout << "random" << endl;
	//指定随机数的范围 0 ~ (1<<786) 
	rp::uniform_int_distribution<mp::cpp_int> dist(0, mp::cpp_int(1) << 768);

	cout << dist(gen) << endl;
}

bool IsPrimeBigInt(DataType& data)
{
	rp::mt11213b gen(time(nullptr));
	if (miller_rabin_test(data, 25, gen))
	{
		if (miller_rabin_test((data - 1) / 2, 25, gen))
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
	int size = NUMBER * length;

	//读取的字节一定是DataType的整数倍，保证一次不会读取半个DataType的数据
	char* bufferin = new char[size];
	DataType* bufferout = new DataType[NUMBER];
	int curNum;

	while (!fin.eof())
	{
		fin.read(bufferin, size);//每次读NUMBER个DataType字节的数据
		curNum = fin.gcount();//真正读到的字节数，有可能后面读到空
		curNum /= length;//读到curNum个DataType字节的数据
		int i,j;
		for (i = 0,j = 0; i < curNum; i++)
		{
			//加密后，先写入bufferout缓冲区中
			bufferout[i] = Encrypt((DataType)bufferin[j], m_key.m_eKey, m_key.m_pKey);
			j += length;//bufferin是char每次偏移DataType大小的位置
		}
		fout.write((char*)bufferout, curNum * length);//加密后，写入到fout中
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
	int size = NUMBER * length;
	int curNum;

    DataType* bufferin = new DataType[NUMBER];
	char* bufferout = new char[size];

	while (!fin.eof())
	{
		fin.read((char*)bufferin, size);//每次读NUMBER个DataType字节的数据
		curNum = fin.gcount();//真正读到的字节数，有可能后面读到空
		curNum /= length;//读到curNum个DataType字节的数据
		int i, j;
		for (i = 0, j = 0; i < curNum; i++)
		{
			//加密后，先写入bufferout缓冲区中
			bufferout[j] = (char)Decrypt(bufferin[i], m_key.m_dKey, m_key.m_pKey);
			j += length;//bufferout是char每次偏移DataType大小的位置
		}
		fout.write(bufferout, curNum * length);//加密后，写入到fout中
	}
	//读取的字节一定是DataType的整数倍，保证一次不会读取半个DataType的数据

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
	rp::mt19937 gen(time(NULL));
	rp::uniform_int_distribution<DataType> dist(DataType(1), DataType(1) << 256);
	//随机获取一个50位到256位的大数
	//srand(time(NULL));  
	DataType prime;
	while (true)
	{
		//prime = rand() % 100 + 2;
		prime = dist(gen);
		if (IsPrime(prime))
		{
			break;
		}
	}
	cout << "prime = " << prime << endl;
	return prime;
}

bool RSA::IsPrime(DataType data)//判断是否为素数
{
	rp::mt11213b gen(time(nullptr));
	if (miller_rabin_test(data, 25, gen))
	{
		if (miller_rabin_test((data - 1) / 2, 25, gen))
		{
			return true;
		}
	}
	return false;
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
DataType ExGcd(DataType a, DataType b, DataType& x, DataType& y)
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