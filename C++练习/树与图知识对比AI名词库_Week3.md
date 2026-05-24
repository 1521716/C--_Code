# 树与图知识对比

## 1. 基础定义对比

| 对比维度 | 树 | 图 |
|---------|-----|-----|
| **结构** | 由节点组成的层次结构 | 由节点和边组成的网状结构 |
| **逻辑关系** | 一对多（父子关系） | 多对多（任意节点间可相连） |
| **根节点** | 有唯一的根节点 | 无根概念 |
| **环路** | 不存在环路 | 可能存在环路 |
| **连接方式** | 边连接父子节点 | 边连接任意节点 |

---

## 2. 存储方式

### 2.1 树的存储

**节点结构体**：
```cpp
typedef struct TreeNode {
    int val;
    TreeNode* lchild;
    TreeNode* rchild;
} TreeNode, *BTree;
```

**常见存储方式**：
- **孩子指针**：每个节点存储指向孩子的指针
- **孩子兄弟表示法**：左孩子右兄弟，可表示任意树
- **顺序存储**：完全二叉树可用数组存储

### 2.2 图的存储

**邻接表**：
```cpp
std::vector<std::vector<int>> Edge;  // 每个顶点一行，存储邻居
```

**两种主要方式**：

| 存储方式 | 结构 | 适用场景 | 时间复杂度 |
|---------|------|---------|-----------|
| **邻接表** | `vector<list<int>>` | 稀疏图 | 遍历邻居：O(度) |
| **邻接矩阵** | `int matrix[N][N]` | 稠密图 | 判断连接：O(1) |

---

## 3. 二叉树与BST性质

### 3.1 二叉树性质

- 第i层最多有 `2^(i-1)` 个节点
- 深度为k的二叉树最多有 `2^k - 1` 个节点
- 叶节点数 = 度为2的节点数 + 1

### 3.2 二叉搜索树（BST）性质

- 左子树所有节点 `< 根节点`
- 右子树所有节点 `> 根节点`
- 中序遍历得到升序序列
- 搜索、插入、删除平均时间复杂度：`O(log n)`

### 3.3 BST插入与搜索

```cpp
// 插入
void helpInsert(TreeNode*& T, int val) {
    if (T == NULL) {
        T = new TreeNode;
        T->val = val;
        T->lchild = T->rchild = NULL;
    } else if (val < T->val) {
        helpInsert(T->lchild, val);
    } else {
        helpInsert(T->rchild, val);
    }
}

// 搜索
TreeNode* helpSearch(TreeNode* T, int val) {
    if (T == NULL) return NULL;
    if (T->val == val) return T;
    return val < T->val ? helpSearch(T->lchild, val) : helpSearch(T->rchild, val);
}
```

---

## 4. 树的遍历

### 4.1 前中后序遍历（递归模板）

```cpp
// 先序遍历（DLR）
void helpShowDLR(TreeNode* T) {
    if (T != NULL) {
        std::cout << T->val << " ";
        helpShowDLR(T->lchild);
        helpShowDLR(T->rchild);
    }
}

// 中序遍历（LDR）
void helpShowLDR(TreeNode* T) {
    if (T != NULL) {
        helpShowLDR(T->lchild);
        std::cout << T->val << " ";
        helpShowLDR(T->rchild);
    }
}

// 后序遍历（LRD）
void helpShowLRD(TreeNode* T) {
    if (T != NULL) {
        helpShowLRD(T->lchild);
        helpShowLRD(T->rchild);
        std::cout << T->val << " ";
    }
}
```

### 4.2 层序遍历

```cpp
void levelOrder(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        std::cout << node->val << " ";
        if (node->lchild) q.push(node->lchild);
        if (node->rchild) q.push(node->rchild);
    }
}
```

### 4.3 遍历方式对比

| 遍历方式 | 顺序 | 栈/队列 | 典型应用 |
|---------|------|---------|---------|
| 前序 | 根-左-右 | 栈/递归 | 文件系统遍历 |
| 中序 | 左-根-右 | 栈/递归 | BST升序输出 |
| 后序 | 左-右-根 | 栈/递归 | 删除树释放内存 |
| 层序 | 按层 | 队列 | 最短路径、层信息 |

---

## 5. 图的遍历

### 5.1 DFS（深度优先搜索）

**递归模板**：
```cpp
void DFS(int u) {
    visited[u] = 1;
    std::cout << "V" << u << " ";
    for (int i = 0; i < Edge[u].size(); i++) {
        if (visited[Edge[u][i]] == 0) {
            DFS(Edge[u][i]);
        }
    }
}
```

**迭代模板（栈实现）**：
```cpp
void DFS(int u) {
    stack<int> s;
    s.push(u);
    visited[u] = 1;
    while (!s.empty()) {
        int curr = s.top();
        s.pop();
        std::cout << curr << " ";
        for (int neighbor : Edge[curr]) {
            if (visited[neighbor] == 0) {
                visited[neighbor] = 1;
                s.push(neighbor);
            }
        }
    }
}
```

### 5.2 BFS（广度优先搜索）

**模板**：
```cpp
void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        std::cout << "V" << curr << " ";
        for (int i = 0; i < Edge[curr].size(); i++) {
            if (visited[Edge[curr][i]] == 0) {
                visited[Edge[curr][i]] = 1;
                q.push(Edge[curr][i]);
            }
        }
    }
}
```

---

## 6. 时间复杂度对比

| 操作 | 树 | 图 |
|-----|-----|-----|
| **遍历** | O(n) | O(V + E) |
| **搜索** | O(log n) ~ O(n) | O(V + E) |
| **插入** | O(log n) ~ O(n) | O(1) ~ O(V) |
| **删除** | O(log n) ~ O(n) | O(E) |

> 注：树的操作复杂度取决于树的高度，平衡树为O(log n)，退化为链表时为O(n)

---

## 7. 典型应用场景

### 7.1 树的应用

| 场景 | 使用类型 | 原因 |
|-----|---------|------|
| 数据查找 | BST、平衡树 | O(log n) 查找效率 |
| 优先级队列 | 堆 | O(1) 获取最大/最小值 |
| 文件系统 | 多叉树 | 层次结构天然适合 |
| 表达式求值 | 二叉树 | 前中后序对应不同表达式 |

### 7.2 图的应用

| 场景 | 使用类型 | 原因 |
|-----|---------|------|
| 社交网络 | 图 | 多对多关系 |
| 地图导航 | 加权图 | 最短路径问题 |
| 爬虫 | 有向图 | 网页链接关系 |
| 依赖关系 | DAG | 拓扑排序 |

---

## 8. LeetCode高频题型

### 8.1 树的高频题型

| 题型 | 题目示例 | 核心思路 |
|-----|---------|---------|
| **遍历** | 144/94/145 前中后序 | 递归/栈 |
| **层序** | 102 层序遍历 | BFS + 队列 |
| **路径** | 112 路径总和 | DFS + 回溯 |
| **公共祖先** | 236 二叉树最近公共祖先 | 递归 |
| **重构树** | 105/106 从序列重构 | 中序+前/后序 |

### 8.2 图的高频题型

| 题型 | 题目示例 | 核心思路 |
|-----|---------|---------|
| **岛屿问题** | 200 岛屿数量 | DFS/BFS flood fill |
| **染色问题** | 785 判断二分图 | BFS/DFS + 三色标记 |
| **拓扑排序** | 207 课程表 | BFS/DFS |
| **最短路径** | 743 网络延迟时间 | Dijkstra/Floyd |
| **连通分量** | 547 省份数量 | DFS/BFS |

### 8.3 岛屿问题通用解法

```cpp
// 模板：DFS flood fill
int dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        return 0;
    grid[i][j] = '0';  // 标记已访问
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
    return 1;
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            count += dfs(grid, i, j);
    return count;
}
```

---

## 9. 关键区别总结

```
树 = 特殊化的图（无环、层次结构）
树 ≠ 图（无环路、有向、无多重边）
```

| 特征 | 树 | 图 |
|-----|-----|-----|
| 边数 | n-1条边 | 任意 |
| 连通性 | 连通且无环 | 可能不连通 |
| 路径唯一性 | 唯一 | 可能多条 |
| 方向 | 通常有向（父子） | 可有可无 |

---

## 10. 代码模板速查

### BST插入/搜索/删除
```cpp
// 插入：比根小往左，比根大往右
void insert(TreeNode*& root, int val) {
    if (!root) { root = new TreeNode(val); return; }
    if (val < root->val) insert(root->lchild, val);
    else insert(root->rchild, val);
}

// 搜索
TreeNode* search(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    return val < root->val ? search(root->lchild, val) : search(root->rchild, val);
}
```

### 图的DFS/BFS
```cpp
// DFS（递归）
void dfs(int u) {
    visited[u] = 1;
    for (int v : Edge[u])
        if (!visited[v]) dfs(v);
}

// BFS（队列）
void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int v : Edge[curr])
            if (!visited[v]) { visited[v] = 1; q.push(v); }
    }
}
```
