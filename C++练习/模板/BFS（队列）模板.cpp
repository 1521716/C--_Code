/*
 * BFS（队列）模板
 * 
 * 适用场景：
 *   - 图的广度优先遍历
 *   - 层序遍历（树）
 *   - 最短路径问题（无权图）
 *   - 拓扑排序
 *   - 染色问题（二分图判定）
 * 
 * 注意事项：
 *   1. 使用队列（FIFO）保证按层次访问
 *   2. 必须在入队时标记 visited，避免重复入队
 *   3. 弹出后处理当前节点
 *   4. 与DFS选择：
 *      - DFS：递归简单，适合深度探索
 *      - BFS：适合层序访问、无权最短路径
 */

//============= 图的BFS模板 =============
#include<iostream>
#include<vector>
#include<queue>

#define MAXVERTEX 10

class GraphBFS {
public:
    GraphBFS(int vertexnum) :vertexnum(vertexnum) {
        for (int i = 0; i < vertexnum; i++)
            Edge.push_back(std::vector<int>());
        visited.resize(vertexnum, 0);
    }
    
    void addEdge(int u, int v) {
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }
    
    // BFS核心模板
    void BFS(int start) {
        std::queue<int> q;
        q.push(start);
        visited[start] = 1;                     // 入队时立即标记
        
        while (!q.empty()) {
            int curr = q.front();                // 1. 取队首
            q.pop();                             // 2. 弹出
            std::cout << "V" << curr << " ";    // 3. 处理当前节点
            
            for (int i = 0; i < Edge[curr].size(); i++) {
                int neighbor = Edge[curr][i];
                if (visited[neighbor] == 0) {   // 4. 遍历邻居
                    visited[neighbor] = 1;       // 入队时立即标记
                    q.push(neighbor);
                }
            }
        }
    }
    
    // 无权图最短路径（记录距离）
    void shortestPath(int start) {
        std::queue<int> q;
        std::vector<int> dist(vertexnum, -1);
        
        q.push(start);
        dist[start] = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : Edge[curr]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[curr] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        // 输出距离
        for (int i = 0; i < vertexnum; i++)
            std::cout << "V" << i << ": " << dist[i] << " ";
    }
    
    void clearVisited() {
        visited.resize(vertexnum, 0);
    }
    
private:
    std::vector<std::vector<int>> Edge;
    int vertexnum = 0;
    std::vector<int> visited;
};


//============= 二叉树层序遍历模板 =============
class TreeBFS {
public:
    struct TreeNode {
        int val;
        TreeNode* lchild;
        TreeNode* rchild;
    };
    
    // 层序遍历（逐层输出）
    void levelOrder(TreeNode* root) {
        if (!root) return;
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->val << " ";
            
            if (node->lchild) q.push(node->lchild);
            if (node->rchild) q.push(node->rchild);
        }
    }
    
    // 层序遍历（按层分隔）
    void levelOrderByLevel(TreeNode* root) {
        if (!root) return;
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();             // 当前层节点数
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                std::cout << node->val << " ";
                
                if (node->lchild) q.push(node->lchild);
                if (node->rchild) q.push(node->rchild);
            }
            std::cout << std::endl;               // 换行
        }
    }
};
