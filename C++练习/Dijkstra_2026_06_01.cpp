#include<iostream>
#include<vector>
#include<queue>


void createGraph(std::vector<std::vector<std::pair<int, int>>>& graph)
{
	
	//创建图
	graph.push_back({ std::vector<std::pair<int,int>>{{1,4},{2,1} } });
	graph.push_back({ std::vector<std::pair<int,int>>{{3,1} } });
	graph.push_back({ std::vector<std::pair<int,int>>{{1,2},{3,5} } });
	graph.push_back({ std::vector<std::pair<int,int>>{{4,3} } });
	graph.push_back({ std::vector<std::pair<int,int>>{} });

}
/*
dist 数组初始化为无穷大，dist[start] = 0。

小根堆 pq 存储(当前距离, 顶点)，初始入(0, start)。

循环直到 pq 为空：

弹出堆顶(d, u)。

如果 d > dist[u]，说明这是陈旧数据，跳过。

遍历 u 的所有邻居(v, w)：

如果 dist[u] + w < dist[v]：

	更新 dist[v] = dist[u] + w。

	将(dist[v], v) 入堆。
*/
/*思考：
	使用优先队列是因为要求最短路径，肯定是尽量选择最小边，所以选择优先队列（最小堆）
	权值为1，退化为BFS

*/
std::vector<int> dijkstra(int start, int n, std::vector<std::vector<std::pair<int, int>>>& graph)
{
	//创建优先队列，维护最小堆
	std::priority_queue<std::pair<int, int>,std::vector<std::pair<int,int>>,std::greater<>> q;
	q.push({ 0,start });

	//创建distance数组，储存当前最短距离
	std::vector<int> distance(n, INT_MAX);
	distance[start] = 0;

	while (!q.empty())
	{
		std::pair<int, int> pair = q.top();
		q.pop();

		if (pair.first > distance[pair.second])
			continue;

		for (const auto& val : graph[pair.second])
		{
			if (distance[pair.second] + val.second < distance[val.first])
			{
				distance[val.first] = distance[pair.second] + val.second;
				q.push({ distance[val.first], val.first });
			}
				
		}
	}
	return distance;

}

int main()
{
	std::vector<std::vector<std::pair<int, int>>> graph;
	std::vector<int> distance;

	createGraph(graph);

	distance = dijkstra(0, graph.size(), graph);

	for (int i = 0; i < distance.size(); i++)
	{
		std::cout << "V0->" << "V" << i << "   " << distance[i] << std::endl;
	}

	return 0;
}