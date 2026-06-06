
/*
 * GraphAlgorithm.h — 图算法模板库
 * 包含：Dijkstra 最短路径、Prim 最小生成树
 * 边权支持 int、double 等数值类型
 * 依赖：<vector>, <queue>, <limits>, <algorithm>
 */

#include<iostream>
#include<vector>
#include<queue>
#include<limits>
#include<algorithm>


template<typename T>
std::vector<T> dijkstra(int start, int n, std::vector<std::vector<std::pair<int, T>>>& graph)
{
	//初始化distance数组
	std::vector<T> distance(n, std::numeric_limits<T>::max());
	distance[start] = T{};

	//初始化优先队列（小根堆）<权值，起点>
	std::priority_queue<std::pair<T, int>,std::vector<std::pair<T,int>>,std::greater<>> q;
	q.push({ T{},start });

	//开始重复核心步骤
	while (!q.empty())
	{
		std::pair<T, int> curr = q.top();
		q.pop();

		//陈旧数据则跳过
		if (curr.first > distance[curr.second])
			continue;

		for (const auto& pair : graph[curr.second])
		{
			int u = pair.first;
			T weight = pair.second;
			if (distance[curr.second] + weight < distance[u])
			{
				distance[u] = distance[curr.second] + weight;
				q.push({ distance[u],u });
			}
				
		}
	}

	return distance;
}

template <typename T>
T prim(int start,int n, std::vector<std::vector<std::pair<int, T>>>& graph)
{
	//初始化优先队列（最小堆）
	std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>> q;
	q.push({ T{},start});

	//初始化visited数组
	std::vector<bool> visited(n, false);

	T MST = T{};

	while (!q.empty())
	{
		std::pair<T, int> curr = q.top();
		q.pop();

		if (visited[curr.second])
			continue;

		visited[curr.second] = true;
		MST += curr.first;

		for (const auto &pair : graph[curr.second])
		{
			if (!visited[pair.first])
				q.push({ pair.second,pair.first });
		}
	}

	if (std::find(visited.begin(), visited.end(), false) != visited.end())
		return T(-1);

	return MST;
}