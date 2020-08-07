#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

namespace Matrix//邻接矩阵
{
	//顶点的值类型V和边的类型W,D为true是代表有向图，false代表无向图
	template<class V, class W, bool D = false>
	class Graph
	{
	private:
		vector<V> m_vertex;//顶点集合
		vector<vector<W>> m_line;//边集合
		unordered_map<V, int> m_pos;//顶点的值对应在顶点集合中的下标
	public:
		Graph(const V* a, int n)//构造函数
		{
			m_vertex.resize(n);
			m_line.resize(n);
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
			//2.修改邻接矩阵中的值
			m_line[srcIndex][detIndex] = weight;
			if (D == false)//无向图要添加两条边
			{
				m_line[detIndex][srcIndex] = weight;
			}
		}

		void _DFS(int srcIndex, vector<bool>& visted)
		{
			visted[srcIndex] = true;
			cout << m_vertex[srcIndex] << "[" << srcIndex << "]";
			for (int i = 0; i < m_vertex.size(); i++)
			{
				if (m_line[srcIndex][i] != W() && visted[i] != true)
				{
					cout << " -(" << m_line[srcIndex][i] << ")- ";
					_DFS(i, visted);
				}
			}
		}
		void DFS(const V& v)//深度优先遍历
		{
			int index = GetPosInMatrix(v);
			vector<bool> flag(m_vertex.size(), false);//标记已经遍历的为true
			_DFS(index, flag);
			cout << endl;
		}

		void BFS(const V& v)//广度优先遍历
		{
			int index = GetPosInMatrix(v);
			vector<bool> flag(m_vertex.size(), false);//标记已经遍历的为true
			queue<int> q;
			q.push(index);
			flag[index] = true;
			while (!q.empty())
			{
				int levelsize = q.size();//每一层的个数
				for (int i = 0; i < levelsize; i++)
				{
					int pos = q.front();
					cout << m_vertex[pos] << "[" << pos << "]";
					for (int i = 0; i < m_vertex.size(); i++)
					{
						if (flag[i] != true && m_line[pos][i] != W())
						{
							q.push(i);
							flag[i] = true;
						}
					}
					q.pop();
				}
				cout << endl;
			}
			cout << endl;
		}
	};

	void TestGraph()
	{
		string a[8] = { "詹姆斯", "库里", "韦德", "汤普森", "杜兰特", "保罗", "科比", "乔丹" };
		Graph<string, int> g(a, 8);
		g.AddEdge("詹姆斯", "韦德", 100);
		g.AddEdge("詹姆斯", "库里", 98);
		g.AddEdge("詹姆斯", "保罗", 98);
		g.AddEdge("库里", "汤普森", 99);
		g.AddEdge("库里", "杜兰特", 90);
		g.AddEdge("杜兰特", "汤普森", 90);
		g.AddEdge("科比", "乔丹", 100);
		/*g.DFS("詹姆斯");
		g.DFS("保罗");
		g.DFS("乔丹");*/
		g.BFS("詹姆斯");
		g.BFS("保罗");
		g.BFS("乔丹");
	}
}

namespace List//邻接表
{
	template<class W>//两个顶点一个权重构成一个节点
	struct ListNode
	{
		int m_det;//顶点
		W m_w;//边的权重
		ListNode* m_next;
		ListNode(int det, W w) :
			m_det(det),
			m_w(w)
		{
			m_next = nullptr;
		}
	};

	template<class V, class W, bool D = false>
	class Graph
	{
	private:
		typedef ListNode<W> Edge;
		vector<V> m_vertex;//顶点集合    
		vector<Edge*> m_list;//邻接表，每个元素由一个链表组成，
		unordered_map<V, int> m_pos;//顶点的值对应在顶点集合中的下标

		//1.顶点集合存储 顶点值 ，下表对应标号
		//2.通过顶点的值在m_pos中找到对应的标号
		//3.邻接表中存储一个链表，邻接表下标代表src的下标
		//这个链表中存储的各个节点中有一个det下标和src与det之间的边权重
		//通过src的下标和det的下标在顶点集合中找到两个顶点的值,和权重w就确定了一对关系
	public:
		Graph(const V* a, int n)//构造函数
		{
			m_vertex.resize(n);
			m_list.resize(n);
			for (int i = 0; i < n; i++)
			{
				m_list[i] = nullptr;
				m_vertex[i] = a[i];
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

		//判断是否存在一个关系
		bool JudgeExitLine(const V& src, const V& det, const W& weight)
		{
			int srcIndex = GetPosInMatrix(src);
			int detIndex = GetPosInMatrix(det);
			Edge* cur = m_list[srcIndex];
			while (cur)
			{
				if (cur->m_det == detIndex && cur->m_w == weight)
				{
					return true;
				}
				cur = cur->m_next;
			}
			return false;
		}

		//给m_list[src]的添加一个关系(src,det,weight)
		void AddSrcEdge(int srcIndex, int detIndex, const W& weight)
		{
			Edge* node = new Edge(detIndex, weight);
			//采用头插
			node->m_next = m_list[srcIndex];//新节点插在头上
			m_list[srcIndex] = node;//更新头结点
		}


		//添加一条从src到det权重为weight的边
		void AddEdge(const V& src, const V& det, const W& weight)
		{
			if (JudgeExitLine(src, det, weight))//判断这个关系不存在时，在插入
			{
				return;
			}
			//1.先获取两个顶点在矩阵中的下标
			int srcIndex = GetPosInMatrix(src);
			int detIndex = GetPosInMatrix(det);

			//2.给邻接表中链表添加一个节点
			AddSrcEdge(srcIndex, detIndex, weight);
			if (D == false)//无向图要添加两条边
			{
				AddSrcEdge(detIndex, srcIndex, weight);
			}
		}

		void _DFS(int srcIndex, vector<bool>& flag)
		{
			flag[srcIndex] = true;
			cout << m_vertex[srcIndex] << "[" << srcIndex << "]";
			Edge* tmp = m_list[srcIndex];
			while (tmp)
			{
				if (flag[tmp->m_det] != true)
				{
					cout << " -(" << m_list[srcIndex]->m_w << ")- ";
					_DFS(tmp->m_det, flag);
				}
				tmp = tmp->m_next;
			}
		}
		void DFS(const V& v)//深度优先遍历
		{
			int index = GetPosInMatrix(v);
			vector<bool> flag(m_vertex.size(), false);//标记已经遍历的为true
			_DFS(index, flag);
			cout << endl;
		}

		void BFS(const V& v)//广度优先遍历
		{
			int index = GetPosInMatrix(v);
			vector<bool> flag(m_vertex.size(), false);//标记已经遍历的为true
			queue<int> q;
			q.push(index);
			flag[index] = true;
			while (!q.empty())
			{
				int levelsize = q.size();//每一层的个数
				for (int i = 0; i < levelsize; i++)
				{
					int pos = q.front();
					cout << m_vertex[pos] << "[" << pos << "]";
					Edge* node = m_list[pos];
					while (node)
					{
						if (flag[node->m_det] != true)
						{
							q.push(node->m_det);
							flag[node->m_det] = true;
						}
						node = node->m_next;
					}
					q.pop();
				}
				cout << endl;
			}
			cout << endl;
		}
	};

	void TestGraph()
	{
		string a[8] = { "詹姆斯", "库里", "韦德", "汤普森", "杜兰特", "保罗", "科比", "乔丹" };
		Graph<string, int> g(a, 8);
		g.AddEdge("詹姆斯", "韦德", 100);
		g.AddEdge("詹姆斯", "库里", 98);
		g.AddEdge("詹姆斯", "保罗", 98);
		g.AddEdge("库里", "汤普森", 99);
		g.AddEdge("库里", "杜兰特", 90);
		g.AddEdge("杜兰特", "汤普森", 90);
		g.AddEdge("科比", "乔丹", 100);
		/*g.DFS("詹姆斯");
		g.DFS("保罗");
		g.DFS("乔丹");*/
		g.BFS("詹姆斯");
		g.BFS("保罗");
		g.BFS("乔丹");
	}
}