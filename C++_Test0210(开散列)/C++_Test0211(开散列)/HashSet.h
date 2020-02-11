#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace YD
{
	class DealInt
	{
	public:
		int operator ()(const int num)
		{
			return num;
		}
	};

	class DealString
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

	template<class T>//节点类
	class HashBucketNode
	{
		T m_val;
		HashBucketNode<T>* m_next;
		HashBucketNode(const T& val = T()) :
			m_val(val),
			m_next(nullptr)
		{}
		template<class T, class SW>
		friend class HashSet;
	};


	template<class T, class SW = DealInt>
	class HashSet//开散列线性探测
	{
	private:
		vector<HashBucketNode<T>*> m_data;//数组指针
		size_t m_size;//已插入元素的个数
		static long long s_m_primeTable[30];//哈希表数组的长度的数组
		//里面的元素都是素数，第二个素数是第一个素数的两倍向后最近的那个素数，以此类推
		//由数学推论可知，使用除留余数法当哈希数组的容量为素数时，发生哈希冲突的概率最低，
		//因为，每次都要mod数组的容量，当容量为素数时，它的因数就只有自己和1，发生冲突只能
		//是容量的一倍
		static int m_PrimePos;//哈希表数组的长度的数组的下标

		int HashFunc(const T& value)//闭散列线性探测
		{
			SW func;//先根据元素的类型分别处理成int型
			return func(value) % capacity();//再用除留余数法获取Key值
		}

		void CheckCapacity()
		{
			if (m_size * 10 / capacity() >= 75)//载荷因子限制在0.7---0.8之间
				//载荷因子 = m_size / m_table.size();
			{
				vector<HashBucketNode<T>*> tmp(s_m_primeTable[++m_PrimePos], nullptr);
				HashBucketNode<T>* cur;

				for (int i = 0; i < capacity(); i++)
				{
					for (cur = tmp[i]; cur; cur = cur->m_next)
					{
						insert(cur->m_val);
					}
				}
				swap(tmp);
			}
		}

	public:
		HashSet(size_t capacity = s_m_primeTable[0]) ://构造函数
			m_data(capacity, nullptr),//注意：m_table.size()是哈希表的容量，m_size是当前表中有几个元素
			m_size(0)
		{}


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
			return m_data.size();
		}

		bool empty()const//判断哈希数组是否为空
		{
			return m_size == 0;
		}

		void swap(HashSet<T,SW>& ht)//交换两个元素的位置
		{
			m_data(ht);
		}

		bool insert(const T& val)//插入元素
		{
			CheckCapacity();//检查是否有足够容量可以插入

			int n = HashFunc(val);//获取他的键值
			HashBucketNode<T>* tmp;
			if (m_data[n])//当这个键的头部不为空，则进入
			{
				for (tmp = m_data[n]; tmp; tmp = tmp->m_next)
				{
					if (tmp->m_val == val)//找到相同的return 
					{
						return false;
					}
				}
			}
			tmp = new HashBucketNode<T>(val);
			tmp->m_next = m_data[n];//头插
			m_data[n] = tmp;
			m_size++;
			return true;
		}


		HashBucketNode<T>* Find(const T& value)//查找元素
		{
			int n = HashFunc(value);//获取待查找元素的键
			HashBucketNode<T>* cur;

			for (cur = m_data[n]; cur;cur = cur->m_next)
			{
				if (cur->m_val == value)
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool erase(const T& value)//删除元素
		{
			int n = HashFunc(value);//获取待查找元素的键
			HashBucketNode<T>* tmp,cur;
			if (m_data[n])//确保这个桶里有元素
			{
				if (m_data[n] == value)//头部就是待删值
				{
					tmp = m_data[n];
					m_data[n] = tmp->m_next;
					delete tmp;
				}
				else//删的元素再中间或不存在
				{
					for (tmp = m_data[n]; tmp->m_next; tmp = tmp->m_next)
					{
						if (tmp->m_next->m_val == value)
						{
							cur = tmp->m_next;
							tmp->m_next = cur->m_next;
							delete cur;
						}
					}
				}
				m_size--;
				return true;
			}
			return false;
		}

		void claer()
		{
			HashBucketNode<T>* tmp;
			for (auto& head :m_data)
			{
				while (head)
				{
					tmp = head;
					head = head->m_next;
					delete tmp;
				}
			}
			m_size = 0;
		}

	};
	template<class T, class SW>
	long long HashSet<T, SW>::s_m_primeTable[30] = {
		11, 23, 47, 89, 179,
		353, 709, 1409, 2819, 5639,
		11273, 22531, 45061, 90121, 180233,
		360457, 720899, 1441807, 2883593, 5767169,
		11534351, 23068673, 46137359, 92274737, 184549429,
		369098771, 738197549, 1476395029, 2952790016u, 4294967291u };
	template<class T, class SW>
	int HashSet<T, SW>::m_PrimePos = 0;
};