#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace YD
{
	class DealInt//仿函数,当键值类型为int时返回int
	{
	public:
		int operator ()(const int num)
		{
			return num;
		}
	};

	class DealString//当键值类型为string时处理成int返回
	{
	public:
		int operator ()(const string& str)
		{
			int seed = 128;//种子
			int sum = 0;
			for (auto& e : str)
			{
				sum = seed * sum + e;//128进制，第一位是第一个字符，第二位是第二个字符
			}
			return sum & 0x7fffffff;//可能越界，取后32位即可(不转也行，会隐式转换)
		}
	};

	enum Status//各个元素的状态
	{
		EMPTY,//空
		EXIST,//存在元素
		DELETE//已删除，此位置可以插入，但后面还有相同Key值的元素
	};

	template<class Value>
	struct Elem//每个元素的属性
	{
		Value m_val;//值
		Status m_status;//状态
		Elem(const Value& value = Value(), const Status& status = Status()) :
			m_val(value),
			m_status(status)
		{}
	};

	template<class Value, class DealFunc = DealInt>
	class HashSet//闭散列线性探测
	{
	private:

		vector<Elem<Value>> m_table;//哈希数组
		size_t m_size;//哈希表元素的个数
		static long long s_m_primeTable[30];//哈希表数组的长度的数组
		//里面的元素都是素数，第二个素数是第一个素数的两倍向后最近的那个素数，以此类推
		//由数学推论可知，使用除留余数法当哈希数组的容量为素数时，发生哈希冲突的概率最低，
		//因为，每次都要mod数组的容量，当容量为素数时，它的因数就只有自己和1，发生冲突只能
		//是容量的一倍
		static int s_m_PrimePos;//哈希表数组的长度的数组的下标

		int HashFunc(const Value& value)//闭散列线性探测
		{
			DealFunc func;//先根据元素的类型分别处理成int型
			return func(value) % capacity();//再用除留余数法获取Key值
		}


		void CheckCapacity()
		{
			if (m_size * 100 / capacity() >= 70)//载荷因子限制在0.7---0.8之间
				//载荷因子 = m_size / m_table.size();
			{
				HashSet<Value> newHt(s_m_primeTable[++s_m_PrimePos]);
				for (int i = 0; i < capacity(); i++)
				{
					if (m_table[i].m_status == EXIST)
					{
						newHt.insert(m_table[i].m_val);
					}
				}
				swap(newHt);
			}
		}

	public:
		HashSet(size_t capacity = 11) ://构造函数
			m_table(capacity),//注意：m_table.size()是哈希表的容量，m_size是当前表中有几个元素
			m_size(0)
		{
			for (int i = 0; i < capacity; i++)//初始化状态
			{
				m_table[i].m_status = EMPTY;
			}
		}

		//vector<Elem> Table()//
		//{
		//	return m_table;
		//}
		size_t size()const//哈希数组存在的元素的个数
		{
			return m_size();
		}

		size_t capacity()const//返回哈希数组的容量
		{
			return m_table.size();
		}

		bool empty()const//判断哈希数组是否为空
		{
			return m_size == 0;
		}

		void swap(HashSet<Value>& ht)//交换两个元素的位置
		{
			m_table.swap(ht.m_table);
		}

		bool insert(const Value& p)//插入元素
		{
			CheckCapacity();//检查是否有足够容量可以插入

			int n = HashFunc(p);//获取他的键值
			while (m_table[n].m_status == EXIST)//当这个键已经存在元素，则线性向后探测
			{
				if (m_table[n].m_val == p)
				{
					return false;
				}
				n = (n == capacity()) ? 0 : n + 1;//到最后一个元素还没有探测出，调到第一个继续循环探测
				//因为第一步已经CheckCapacity容量保证够
			}

			m_table[n].m_val = p;//找到合适的位置，修改那个位置的值和状态
			m_table[n].m_status = EXIST;
			m_size++;//哈希数组里面的元素长度++
			return true;
		}


		int Find(const Value& value)//查找元素
		{
			int n = HashFunc(value);//获取待查找元素的键
			int flag = n;//记录键
			while (m_table[n].m_status != EMPTY)//若这个位置的状态是有元素或已删除
			{
				if (m_table[n].m_status == EXIST && m_table[n].m_val == value)
				{//找到状态为元素存在且值等于查找的元素就返回他的下标
					return n;
				}
				n = (n == m_size) ? 0 : n + 1;//循环
				if (flag == n)
				{
					return -1;//循环找回来，没有就返回-1
				}
			}
			return -1;
		}

		bool erase(const Value& value)//删除元素
		{
			int ret = Find(value);//获取待删除元素的键
			if (ret < 0)//先查找，如找不到就直接return
			{
				return false;
			}

			else//找到就将那个位置的状态置为DELETE,防止找不到和这个元素同一键的元素
			{
				m_table[ret].m_status = DELETE;
				m_size--;
				return true;
			}
		}

		void claer()
		{
			m_table.clear();
			m_size = 0;
		}

	};
		
	template<class Value, class DealFunc>
	long long HashSet<Value, DealFunc>::s_m_primeTable[30] = {
		11, 23, 47, 89, 179,
		353, 709, 1409, 2819, 5639,
		11273, 22531, 45061, 90121, 180233,
		360457, 720899, 1441807, 2883593, 5767169,
		11534351, 23068673, 46137359, 92274737, 184549429,
		369098771, 738197549, 1476395029, 2952790016u, 4294967291u };
	template<class Value, class DealFunc>
	int HashSet<Value, DealFunc>::s_m_PrimePos = 0;
};