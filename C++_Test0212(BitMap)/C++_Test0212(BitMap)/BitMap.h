#pragma once
#include<vector>
using namespace std;

namespace YD
{
	class BitMap
	{
	private:
		vector<int> m_bit;
		size_t m_bcount;
	public:
		BitMap(size_t bitc) :
			m_bit(bitc / 32 + 1),
			m_bcount(bitc)
		{}
		void set(size_t pos)//某位置1
		{
			if (pos > m_bcount)
			{
				return;
			}
			m_bit[pos / 32] |= (1 << (pos % 32));
		}

		void reset(size_t pos)//某位置0
		{
			if (pos > m_bcount)
			{
				return;
			}
			m_bit[pos / 32] &= ~(1 << (pos % 32));
		}

		bool get(size_t pos)//获取这位的状态
		{
			if (pos > m_bcount)
			{
				return false;
			}
			return (m_bit[pos / 32] >> (pos % 32)) & 1;
		}

		size_t size()
		{
			return m_bcount;
		}

		size_t count()//1的个数
		{
			const char* pCount = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";
								//0  1 2 3 4 5 6 7 8 9 a b c d e f 中1的个数
			size_t size = m_bit.size();
			size_t count = 0;
			size_t i;
			for (i = 0; i < size; i++)
			{
				int value = m_bit[i];//先拿一个int
				int j;
				for (j = 0; j < sizeof(m_bit[0]); j++,value >>= 8)
				{
					char c = value;
					count += pCount[c & 0x0f];
					count += pCount[(c >> 4) & 0x0f];
				}
			}
			return count;
		}


	};
};
