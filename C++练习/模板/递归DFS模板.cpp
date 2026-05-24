/*
 * 递归DFS模板
 * 
 * 适用场景：
 *   - 图的深度优先遍历
 *   - 岛屿问题（Flood Fill）
 *   - 连通分量问题
 *   - 树的深度遍历（前/中/后序）
 *   - 路径搜索、回溯问题
 * 
 * 注意事项：
 *   1. 必须有 visited[] 数组标记已访问节点，避免重复访问
 *   2. 递归深度受栈空间限制，深度过大可能栈溢出
 *   3. 适用于连通图，若图不连通需遍历所有节点作为起点
 *   4. 对于树遍历，visited 可省略（通过父子关系自然避免重复）
 */

//============= 图的递归DFS模板 =============
#include<iostream>
#include<vector>
#include<algorithm>

#define MAXVERTEX 10

class Graph {
public:
    Graph(int vertexnum) :vertexnum(vertexnum) {
        for (int i = 0; i < vertexnum; i++)
            Edge.push_back(std::vector<int>());
        visited.resize(vertexnum, 0);
    }
    
    void addEdge(int u, int v) {
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }
    
    // 递归DFS核心模板
    void DFS(int u) {
        visited[u] = 1;                              // 1. 标记当前节点已访问
        std::cout << "V" << u << " ";               // 2. 处理当前节点（访问/输出）
        
        for (int i = 0; i < Edge[u].size(); i++) {  // 3. 遍历所有邻居
            if (visited[Edge[u][i]] == 0) {          // 4. 若邻居未访问
                DFS(Edge[u][i]);                      // 5. 递归深入
            }
        }
    }
    
    void clearVisited() {
        visited.resize(vertexnum, 0);
    }
    
private:
    std::vector<std::vector<int>> Edge;
    int vertexnum = 0;
    std::vector<int> visited;
};


//============= 岛屿问题DFS模板 =============
class FloodFill {
public:
    // 岛屿数量统计
    int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (dfs(grid, i, j))
                    count++;
        return count;
    }
    
private:
    // Flood Fill 递归模板
    int dfs(std::vector<std::vector<char>>& grid, int i, int j) {
        // 越界检查
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return 0;
        // 不是岛屿（海水或已访问）
        if (grid[i][j] == '0')
            return 0;
        
        // 标记为已访问（海水）
        grid[i][j] = '0';
        
        // 四个方向扩展
        dfs(grid, i + 1, j);  // 下
        dfs(grid, i - 1, j);  // 上
        dfs(grid, i, j + 1);  // 右
        dfs(grid, i, j - 1);  // 左
        
        return 1;
    }
};
