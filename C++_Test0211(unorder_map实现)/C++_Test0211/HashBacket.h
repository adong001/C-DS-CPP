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
		template<class K, class V, class KeyOfValue, class HF>
		friend class HashBucket;
	};


	template<class K, class V, class KeyOfValue, class HF = DealInt>
	class HashBucket//哈希桶
	{
	private:
		vector<HashBucketNode<V>*> m_data;//数组指针
		size_t m_size;//已插入元素的个数
		static long long s_m_primeTable[30];//哈希表数组的长度的数组
		//里面的元素都是素数，第二个素数是第一个素数的两倍向后最近的那个素数，以此类推
		//由数学推论可知，使用除留余数法当哈希数组的容量为素数时，发生哈希冲突的概率最低，
		//因为，每次都要mod数组的容量，当容量为素数时，它的因数就只有自己和1，发生冲突只能
		//是容量的一倍
		static int s_m_PrimePos;//哈希表数组的长度的数组的下标

		int HashFunc(const K& Key)//闭散列线性探测
		{
			HF func;//先根据元素的类型分别处理成int型
			return func(Key) % capacity();//再用除留余数法获取Key值
		}

		void CheckCapacity()
		{
			if (m_size * 100 / capacity() >= 70)//载荷因子限制在0.7---0.8之间
				//载荷因子 = m_size / m_table.size();
			{
				vector<HashBucketNode<V>*> tmp(s_m_primeTable[++s_m_PrimePos], nullptr);
				HashBucketNode<V>* cur;
				tmp.swap(m_data);
				m_size = 0;
				for (int i = 0; i < tmp.size(); i++)
				{
					for (cur = tmp[i]; cur; cur = cur->m_next)
					{
						insert(cur->m_val);
					}
				}
				tmp.clear();
			}
		}
	public:
		class iterator
		{
		public:
			HashBucket<K, V, KeyOfValue, HF>* m_hb;//指向哈希桶的指针
			HashBucketNode<V>* m_node;//指向桶中各个节点的指针

			iterator(HashBucketNode<V>* node = nullptr,
				HashBucket<K, V, KeyOfValue, HF>* hp = nullptr) :
				m_node(node),
				m_hb(hp)
			{}

			iterator(const iterator& it) :
				m_node(it.m_node),
				m_hb(it.m_hb)
			{}

			V& operator*()
			{
				return m_node->m_val;
			}

			V* operator->()
			{
				return &(m_node->m_val);
			}

			iterator operator++()//前置++
			{
				V val = m_node->m_val;
				m_node = m_node->m_next;//m_node存在就不进
				if (!m_node)//此节点为空时，往后的桶中寻找下一个节点
				{
					int BucketNum = m_hb->HashFunc(KeyOfValue()(val)) + 1;
					//通过仿函数KeyOfValue获得Key，val是一个pair<K,V>
					//找到下一个不为空的桶,可能会越界，但是要想++操作就得知道还能不能++
					for (; BucketNum < m_hb->capacity(); BucketNum++)
					{
						if (m_hb->m_data[BucketNum])//这个桶存在节点
						{
							m_node = m_hb->m_data;
							break;
						}
					}
				}
				return *this;
			}
			iterator operator++(int)//后置++
			{
				iterator<K, V, KeyOfValue, HF> tmp = *this;
				++(*this);
				return tmp;
			}

			iterator operator--()//前置--
			{
				V val = m_node->m_val;
				int BucketNum = m_hb->HashFunc(KeyOfValue()(val));
				HashBucketNode<V>* cur = nullptr;
				if (m_hb->m_data[BucketNum] == m_node)
					//这个节点是这个桶的第一个节点，就找上一个桶
				{
					BucketNum--;
					for (; BucketNum >= 0; BucketNum--)
					{
						if (m_hb->m_data[BucketNum])//这个桶中有节点,直接找最后一个就行了
						{

							cur = m_hb->m_data[BucketNum];
							for (; cur->m_next; cur = cur->m_next);
						}
					}
				}
				//else代表这个桶有节点且第一个节点不是m_node
				//直接在里面找m_next==m_node就行

				else
				{
					for (; cur->m_next == m_node; cur = cur->m_next);
				}
				m_node = cur;
				return *this;
			}

			iterator operator--(int)//后置--
			{
				iterator<K, V, KeyOfValue, HF> tmp = *this;
				--(*this);
				return tmp;
			}


			iterator operator == (const iterator& it)
			{
				return m_hb == it.m_hb && m_node == it.m_node;
			}

			iterator operator != (const iterator& it)
			{
				return m_hb != it.m_hb || m_node != it.m_node;
			}
		};

		HashBucket(size_t capacity = s_m_primeTable[0]) ://构造函数
			m_data(capacity, nullptr),//注意：m_table.size()是哈希表的容量，m_size是当前表中有几个元素
			m_size(0)
		{}

		iterator begin()
		{
			int BucketNum = 0;
			for (; BucketNum < capacity(); BucketNum++)
			{
				if (m_data[BucketNum])
				{
					return iterator(m_data[BucketNum], this);
				}
			}
			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}


		size_t size()//哈希数组中节点的个数
		{
			return m_size();
		}

		size_t capacity()//返回哈希数组的容量
		{
			return m_data.size();
		}

		bool empty()const//判断哈希数组是否为空
		{
			return m_size == 0;
		}

		void swap(HashBucket<K, V, KeyOfValue, HF>& ht)//交换两个哈希数组
		{
			m_data.swap(ht);
		}


		bool Is_In_Bucket(const K& key)//判断key是否在哈希表里
		{
			int BucketNum = HashFunc(key);
			HashBucketNode<V>* cur = nullptr;
			for (cur = m_data[BucketNum]; cur; cur = cur->m_next)
			{
				if (KeyOfValue()(cur->m_val) == key)
				{
					return true;
				}
			}
			return false;
		}

		size_t Count_Empty_Bucket(const K& key)//统计空桶的个数
		{
			int count = 0;
			int BucketNum;
			HashBucketNode<V>* cur = nullptr;
			for (BucketNum = 0; BucketNum < capacity(); BucketNum++)
			{
				if (!m_data[BucketNum])
				{
					count++;
				}
			}
			return count;
		}

		size_t Bucket_Size(const K& key)//统计某个桶中节点的个数
		{
			int count = 0;
			int BucketNum = HashFunc(key);
			HashBucketNode<V>* cur;
			for (cur = m_data[BucketNum]; cur; cur = cur->m_next)
			{
				count++;
			}
			return count;
		}

		pair<iterator, bool> insert(const V& val)//插入元素
		{
			CheckCapacity();//检查是否有足够容量可以插入

			int n = HashFunc(val);//获取他的键值
			HashBucketNode<V>* tmp;
			pair<iterator, bool> p;
			if (m_data[n])//当这个键的头部不为空，则进入
			{
				for (tmp = m_data[n]; tmp; tmp = tmp->m_next)
				{
					if (tmp->m_val == val)//找到相同的return 
					{
						p.first = end();
						p.second = false;
						return p;
					}
				}
			}
			tmp = new HashBucketNode<T>(val);
			tmp->m_next = m_data[n];//头插
			m_data[n] = tmp;
			iterator it(m_data[n], this);
			p.first = it;
			p.second = true;
			m_size++;
			return p;
		}


		iterator Find(const V& value)//查找元素
		{
			int n = HashFunc(value);//获取待查找元素的键
			HashBucketNode<V>* cur;

			for (cur = m_data[n]; cur; cur = cur->m_next)
			{
				if (cur->m_val == value)
				{
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}

		iterator erase(const V& val)//删除元素
		{
			int n = HashFunc(KeyOfValue()(val));//获取待查找元素的键
			HashBucketNode<V>* tmp;
			HashBucketNode<V>* cur;
			if (m_data[n])//确保这个桶里有元素
			{
				if (m_data[n]->m_val == val)//头部就是待删值
				{
					iterator res(m_data[n], this);
					++res;//删除后迭代器向后移动防止迭代器失效
					tmp = m_data[n];
					m_data[n] = tmp->m_next;
					delete tmp;
					m_size--;
					return res;
				}
				else//删的元素再中间或不存在
				{
					for (tmp = m_data[n]; tmp->m_next; tmp = tmp->m_next)
					{
						if (tmp->m_next->m_val == val)
						{
							iterator res(tmp->m_next, this);
							++res;//删除后迭代器向后移动防止迭代器失效
							cur = tmp->m_next;
							tmp->m_next = cur->m_next;
							delete cur;
							m_size--;
							return res;
						}
					}
				}
			}
			return end();
		}

		void clear()
		{
			HashBucketNode<V>* tmp;
			for (auto& head : m_data)
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




		~HashBucket()
		{
			clear();
		}

	};
	template<class K, class V, class KeyOfValue, class HF>
	long long HashBucket<K, V, KeyOfValue, HF>::s_m_primeTable[30] = {
		11, 23, 47, 89, 179,
		353, 709, 1409, 2819, 5639,
		11273, 22531, 45061, 90121, 180233,
		360457, 720899, 1441807, 2883593, 5767169,
		11534351, 23068673, 46137359, 92274737, 184549429,
		369098771, 738197549, 1476395029, 2952790016u, 4294967291u };
	template<class K, class V, class KeyOfValue, class HF>
	int HashBucket<K, V, KeyOfValue, HF>::s_m_PrimePos = 0;
};