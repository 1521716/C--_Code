#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define MAXVERTEX 10


class Graph {
public:
	//有参构造函数
	Graph(int vertexnum, int edgenum) :vertexnum(vertexnum), edgenum(edgenum)
	{
		
		for (int i = 0; i < vertexnum; i++)
		{
			Vertices.push_back(i);
		}
		
		for (int i = 0; i < vertexnum; i++)
		{
			Edge.push_back(std::vector<int>());
		}
		//辅助遍历数组初始化
		visited.resize(vertexnum, 0);
	}
	
	//拷贝构造(稍后实现)

	//添加边
	void addEdge(int u,int v)
	{
		if (u >= vertexnum || v >= vertexnum)
			return;
		const auto& it = find(Edge[u].begin(), Edge[u].end(), v);
		if (it == Edge[u].end())
		{
			Edge[u].push_back(v);
			Edge[v].push_back(u);
		}
	}

	//DFS
	void DFS(int u)
	{
		visited[u] = 1;
		std::cout << "V" << Vertices[u] << " ";
		if (Edge[u].size() == 0)
			return;
		for (int i = 0; i < Edge[u].size(); i++)
		{
			if (visited[Edge[u][i]] == 0)
			{

				DFS(Edge[u][i]);

			}
		}
	}

	//BFS
	void BFS(int u) {
		std::queue<int> q;
		q.push(u);
		// 入队时立刻标记
		visited[u] = 1;  
		while (!q.empty()) 
		{
			int curr = q.front();
			q.pop();
			std::cout << "V" << Vertices[curr] << " ";
			for (int i = 0; i < Edge[curr].size(); i++) 
			{
				if (visited[Edge[curr][i]] == 0) 
				{
					q.push(Edge[curr][i]);
					// 入队时立刻标记
					visited[Edge[curr][i]] = 1;  
				}
			}
		}
	}

	//重置visited
	bool clearVisited()
	{
		visited.resize(vertexnum, 0);
		return true;
	}

private:
	std::vector<int> Vertices;
	std::vector<std::vector<int>> Edge;
	int vertexnum = 0;
	int edgenum = 0;
	std::vector<int> visited;
};

//测试
//DFS测试
void testDFS()
{
	Graph G(6, 5);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 4);
	G.addEdge(2, 5);
	G.clearVisited();
	G.DFS(0);
}
//BFS测试
void testBFS()
{
	Graph G(6, 5);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 4);
	G.addEdge(2, 5);
	G.clearVisited();
	G.BFS(0);
}

int main()
{
	std::cout << "DFS:";
	testDFS();
	std::cout << std::endl;

	std::cout << "BFS:";
	testBFS();
	std::cout << std::endl;
	return 0;
}