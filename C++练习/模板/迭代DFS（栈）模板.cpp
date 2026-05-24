/*
 * 迭代DFS（栈）模板
 * 
 * 适用场景：
 *   - 深度优先遍历（避免递归栈溢出）
 *   - 图的连通分量遍历
 *   - 迭代版本的前/中/后序遍历
 *   - 非递归版本的深度搜索
 * 
 * 注意事项：
 *   1. 使用栈（LIFO）模拟递归调用
 *   2. 需手动管理 visited[] 标记
 *   3. 入栈时就要标记 visited，避免重复入栈
 *   4. 与递归版本核心区别：处理时机不同
 *      递归版：弹出时处理
 *      迭代版：可入栈时处理（根据需求调整）
 */

//============= 图的迭代DFS模板 =============
#include<iostream>
#include<vector>
#include<stack>

#define MAXVERTEX 10

class GraphDFS {
public:
    GraphDFS(int vertexnum) :vertexnum(vertexnum) {
        for (int i = 0; i < vertexnum; i++)
            Edge.push_back(std::vector<int>());
        visited.resize(vertexnum, 0);
    }
    
    void addEdge(int u, int v) {
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }
    
    // 迭代DFS核心模板
    void DFS(int start) {
        std::stack<int> s;
        s.push(start);
        visited[start] = 1;                    // 入栈时标记
        
        while (!s.empty()) {
            int curr = s.top();                 // 1. 取栈顶
            s.pop();                           // 2. 弹出
            std::cout << "V" << curr << " ";   // 3. 处理当前节点
            
            for (int i = 0; i < Edge[curr].size(); i++) {
                int neighbor = Edge[curr][i];
                if (visited[neighbor] == 0) {  // 4. 遍历邻居
                    visited[neighbor] = 1;      // 入栈时立即标记
                    s.push(neighbor);
                }
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


//============= 二叉树迭代DFS（栈）模板 =============
struct TreeNode {
    int val;
    TreeNode* lchild;
    TreeNode* rchild;
};

class TreeDFS {
public:
    // 先序遍历（根-左-右）
    void preOrder(TreeNode* root) {
        if (!root) return;
        std::stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            std::cout << node->val << " ";     // 根先处理
            
            if (node->rchild) s.push(node->rchild);  // 右孩子先入栈
            if (node->lchild) s.push(node->lchild);  // 左孩子后入栈
        }
    }
    
    // 中序遍历（左-根-右）
    void inOrder(TreeNode* root) {
        std::stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->lchild;           // 一路向左
            }
            curr = s.top();
            s.pop();
            std::cout << curr->val << " ";     // 处理根
            curr = curr->rchild;                // 转向右
        }
    }
    
    // 后序遍历（左-右-根）
    void postOrder(TreeNode* root) {
        if (!root) return;
        std::stack<TreeNode*> s1, s2;
        s1.push(root);
        
        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);                      // 逆序收集
            
            if (node->lchild) s1.push(node->lchild);
            if (node->rchild) s1.push(node->rchild);
        }
        
        while (!s2.empty()) {
            std::cout << s2.top()->val << " ";
            s2.pop();
        }
    }
};
