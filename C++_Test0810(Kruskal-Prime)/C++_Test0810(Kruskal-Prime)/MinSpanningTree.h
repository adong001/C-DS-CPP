#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

namespace Kruskal//Kruskal算法
{
	//顶点的值类型V和边的类型W,D为true是代表有向图，false代表无向图
	template<class V, class W, bool D = false>
	class Graph
	{
	private:
		vector<V> m_vertex;//顶点集合
		vector<int> m_arr;//并查集集合，检测环
		map<W, pair<int, int>> m_map;//边集合
		unordered_map<V, int> m_pos;//方便直接找到顶点下标
	public:
		Graph(const V* a, int n)//构造函数
		{
			m_vertex.resize(n);
			m_arr.resize(n, -1);
			for (int i = 0; i < n; i++)
			{
				m_vertex[i] = a[i];
				m_pos[a[i]] = i;
			}
		}

		int Find(int index)//查找元素在哪个集合中
		{
			while (m_arr[index] >= 0)
			{
				index = m_arr[index];
			}
			return index;
		}

		bool Union(int srcindex, int detindex)
		{
			if (srcindex == detindex)//相同顶点不能合并
			{
				return false;
			}
			m_arr[srcindex] += m_arr[detindex];//det合并到src中
			m_arr[detindex] = srcindex;
			return true;

		}

		//获取顶点src在矩阵中的下标
		int GetPosInMatrix(const V& src)
		{
			if (m_pos.find(src) != m_pos.end())
			{
				return m_pos[src];
			}
			throw invalid_argument("非法顶点");
		}

		//添加一条从src到det权重为weight的边
		void AddEdge(const V& src, const V& det, const W& weight)
		{
			int srcIndex = GetPosInMatrix(src);
			int detIndex = GetPosInMatrix(det);
			m_map[weight] = { srcIndex, detIndex };//合并两条边

		}

		void kruskal()
		{
			W Sum = W();
			auto mit = m_map.begin();
			for (int i = 0; i < m_vertex.size() - 1; i++, mit++)//n个顶点，最小生成树有n-1个边
			{
				int x = Find(mit->second.first);
				int y = Find(mit->second.second);
				if (Union(x, y) == false)//两个顶点属于一个集合，不能合并会形成环
				{
					i--;//不能合并时，i++会少算一条边，这里需要和循环里面的++抵消
					continue;
				}
				Sum += mit->first;
				cout << m_vertex[mit->second.first] << "[" << mit->second.first << "] ---(" << mit->first << ")---";
				cout << m_vertex[mit->second.second] << "[" << mit->second.second << "]\n";
			}
			cout << "最小生成树的总权值：" << Sum << endl;
		}
	};
	void TestGraph()
	{
		string a[7] = { "韦德", "杜兰特", "库里", "詹姆斯", "保罗", "科比", "汤普森" };
		Graph<string, int> g(a, 7);
		g.AddEdge("詹姆斯", "汤普森", 18);
		g.AddEdge("詹姆斯", "库里", 24);
		g.AddEdge("詹姆斯", "保罗", 14);
		g.AddEdge("库里", "汤普森", 22);
		g.AddEdge("库里", "杜兰特", 25);
		g.AddEdge("韦德", "杜兰特", 10);
		g.AddEdge("韦德", "保罗", 28);
		g.AddEdge("科比", "保罗", 16);
		g.AddEdge("科比", "汤普森", 12);
		cout << "Kruskal :\n";
		g.kruskal();
	}
}


namespace Prime//Prime算法
{
	//顶点的值类型V和边的类型W,D为true是代表有向图，false代表无向图
	template<class V, class W, bool D = false>
	class Graph
	{
	private:
		pair<W, pair<int, int>> m_min;//存储最小的边
		vector<V> m_vertex;//顶点集合
		vector<vector<W>> m_line;//边集合
		unordered_map<V, int> m_pos;//顶点的值对应在顶点集合中的下标,
	public:
		Graph(const V* a, int n)//构造函数
		{
			m_vertex.resize(n);
			m_line.resize(n);
			m_min = { INT_MAX, { -1 , -1 } };
			for (int i = 0; i < n; i++)
			{
				m_vertex[i] = a[i];
				m_line[i].resize(n, W());
				m_pos[a[i]] = i;
			}
		}

		//获取顶点src在矩阵中的下标
		int GetPosInMatrix(const V& src)
		{
			if (m_pos.find(src) != m_pos.end())
			{
				return m_pos[src];
			}
			throw invalid_argument("非法顶点");
		}
		//添加一条从src到det权重为weight的边
		void AddEdge(const V& src, const V& det, const W& weight)
		{
			//1.先获取两个顶点在矩阵中的下标
			int srcIndex = GetPosInMatrix(src);
			int detIndex = GetPosInMatrix(det);
			if (m_line[srcIndex][detIndex] != W())//这条边已经存在了,不用在插入
			{
				return;
			}

			if (m_min.first > weight)//找到最小的边
			{
				m_min.first = weight;
				m_min.second = { srcIndex, detIndex };
			}

			//2.修改邻接矩阵中的值
			m_line[srcIndex][detIndex] = weight;
			if (D == false)//无向图要添加两条边
			{
				m_line[detIndex][srcIndex] = weight;
			}
		}

		void prime()
		{
			W Sum = W();
			//1.初始化，找到最小的边，就是m_pos的begin()位置
			unordered_set<int> s;//存储已经找到的顶点的下标
			s.insert(m_min.second.first);
			s.insert(m_min.second.second);
			Sum += m_min.first;
			cout << m_vertex[m_min.second.first] << "[" << m_min.second.first << "] ---(" << m_min.first << ")---";
			cout << m_vertex[m_min.second.second] << "[" << m_min.second.second << "]\n";
			//2.寻找找到节点中相连边的最小值
			
			for (int i = 1; i < m_vertex.size()-1; i++)
			{
				pair<W, pair<int, int>> min = { INT_MAX, { -1, -1 } };
				for (auto& e : s)
				{
					for (int i = 0; i < m_vertex.size(); i++)
					{
						if (m_line[e][i] != W() && s.find(i) == s.end())//边存在且连接的节点不在s中
						{
							min.first = min.first > m_line[e][i] ? m_line[e][i] : min.first;
							min.second = { e, i };
						}
					}
					
				}
				cout << m_vertex[min.second.first] << "[" << min.second.first << "] ---(" << min.first << ")---";
				cout << m_vertex[min.second.second] << "[" << min.second.second << "]\n";
				s.insert(min.second.second);
				Sum += min.first;
			}
			cout << "最小生成树的总权值：" << Sum << endl;
		}
	};

	void TestGraph()
	{
		string a[7] = { "韦德", "杜兰特", "库里", "詹姆斯", "保罗", "科比", "汤普森" };
		Prime::Graph<string, int> g(a, 7);
		g.AddEdge("詹姆斯", "汤普森", 18);
		g.AddEdge("詹姆斯", "库里", 24);
		g.AddEdge("詹姆斯", "保罗", 14);
		g.AddEdge("库里", "汤普森", 22);
		g.AddEdge("库里", "杜兰特", 25);
		g.AddEdge("韦德", "杜兰特", 10);
		g.AddEdge("韦德", "保罗", 28);
		g.AddEdge("科比", "保罗", 16);
		g.AddEdge("科比", "汤普森", 12);
		cout << "Prime :\n";
		g.prime();
	}
}

