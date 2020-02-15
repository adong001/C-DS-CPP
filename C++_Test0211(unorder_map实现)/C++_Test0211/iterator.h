#pragma once
#include"HashBacket.h"
namespace YD
{
	//迭代器类
	template<class K, class V, class KeyOfValue, class HF = DealInt>
	class iterator
	{
	public:
		HashBucket<K, V, KeyOfValue, HF>* m_hb;//指向哈希桶的指针
		HashBucketNode<V>* m_node;//指向桶中各个节点的指针

		iterator(HashBucketNode<V>* node = nullptr,
			HashBucket<K,V,KeyOfValue,HF>* hp =  nullptr):
			m_node(node),
			m_hb(hp)
		{}
			
		iterator(const iterator& it):
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
			iterator<K,V,KeyOfValue,HF> tmp = *this;
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
			iterator<K, V,KeyOfValue, HF> tmp = *this;
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
};