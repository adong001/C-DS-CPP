#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

struct Elem
{
	int m_key;
	int m_value;

	Elem operator = (Elem e)
	{
		m_key = e.m_key;
		m_value = e.m_value;
		return *this;
	}
};

class LRU
{
private:
	int m_size;
	list<Elem> m_lkv;
	unordered_map<int, list<Elem>::iterator> m_umlit;

public:
	LRU(int size) :
		m_size(size)
	{}

	void Set(Elem k_val)
	{
		if (m_umlit.find(k_val.m_key) == m_umlit.end())//不存在
		{
			if (m_lkv.size() == m_size)//缓存已满
			{
				//back代表最不常用，front代表最常用
				int k = m_lkv.back().m_key;
				m_lkv.pop_back();//删除最不常用的
				m_umlit.erase(k);//map中也删除最不常用的元素
			}
			m_lkv.push_front(k_val);//添加新的为最常用的
			m_umlit[k_val.m_key] = m_lkv.begin();//新添加的second为它在m_lkv中位置

			
		}
		else//要添加的元素存在，那就修改它的value
		{
			auto itl = m_umlit[k_val.m_key];
			itl->m_value = k_val.m_value;
			Elem tmp = *itl;//将这个修改的元素变成最常用的，先保存它，再删掉它，最后放在front位置即可
			m_umlit.erase(itl->m_key);
			m_umlit[k_val.m_key] = m_lkv.begin();
			m_lkv.push_front(tmp);
		}
	}

	void Get(int key)
	{
		if (m_umlit.find(key) == m_umlit.end())//不存在
		{
			cout << -1 << endl;
		}
		else//存在
		{
			//将这个修改的元素变成最常用的，先保存它，再删掉它，最后放在front位置即可
			auto itl = m_umlit[key];
			Elem tmp = *itl;
			m_lkv.erase(itl);
			m_lkv.push_front(tmp);
			m_umlit[key] = m_lkv.begin();
			cout << tmp.m_value << endl;
		}
	}

};



int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int op,ky;
		Elem tmp;
		LRU lru(k);
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> op;
			if (op == 1)//set操作
			{
				cin >> tmp.m_key >> tmp.m_value;
				lru.Set(tmp);
			}
			else //get操作
			{
				cin >> ky;
				lru.Get(ky);
			}
		}
	}
    return 0;
}