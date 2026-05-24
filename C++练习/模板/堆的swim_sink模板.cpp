/*
 * 堆的swim/sink模板
 * 
 * 适用场景：
 *   - 优先队列实现
 *   - top-k 问题
 *   - 合并有序文件
 *   - 哈夫曼编码
 *   - 调度算法（优先级任务）
 * 
 * 注意事项：
 *   1. 堆从下标1开始存储（下标0留空），简化父子关系计算
 *   2. swim：插入时使用，自底向上恢复堆性质
 *   3. sink：删除堆顶/构建堆时使用，自顶向下恢复堆性质
 *   4. 大根堆：父节点 > 子节点
 *   5. 小根堆：父节点 < 子节点
 *   6. 推荐使用循环版本，避免递归栈溢出
 *   7. 本模板使用 vector 存储，无需手动管理内存
 */

//============= 最大堆模板 =============
#include<iostream>
#include<vector>
#include<algorithm>

template<class T>
class MaxHeap {
public:
    MaxHeap() {
        heap.push_back(0);                        // 下标0留空
    }
    
    // 插入（尾部插入 + swim上浮）
    void push(const T& val) {
        heap.push_back(val);
        swim(heap.size() - 1);
    }
    
    // 删除堆顶（末尾替换 + sink下沉）
    void pop() {
        if (heap.size() == 1) return;
        heap[1] = heap.back();
        heap.pop_back();
        sink(1);
    }
    
    // 获取堆顶
    T top() const {
        return heap.size() > 1 ? heap[1] : T();
    }
    
    bool empty() const {
        return heap.size() == 1;
    }
    
    int size() const {
        return heap.size() - 1;
    }

private:
    // 上浮（循环版本） - 插入时恢复堆性质
    void swim(int index) {
        while (index > 1 && heap[index] > heap[index / 2]) {
            std::swap(heap[index], heap[index / 2]);
            index /= 2;
        }
    }
    
    // 下沉（循环版本） - 删除/构建堆时恢复堆性质
    void sink(int index) {
        int n = heap.size() - 1;
        while (index * 2 <= n) {                  // 有左孩子就继续
            int child = index * 2;
            // 选择较大的孩子
            if (child < n && heap[child] < heap[child + 1])
                child++;
            // 若当前节点 >= 较大孩子，停止下沉
            if (heap[index] >= heap[child])
                break;
            std::swap(heap[index], heap[child]);
            index = child;
        }
    }
    
private:
    std::vector<T> heap;
};


//============= 递归版本（参考） =============
/*
void swim(int index) {
    if (index == 1) return;
    if (heap[index] > heap[index / 2]) {
        std::swap(heap[index], heap[index / 2]);
        swim(index / 2);
    }
}

void sink(int index) {
    int n = heap.size() - 1;
    if (index * 2 <= n) {
        int child = index * 2;
        if (child < n && heap[child] < heap[child + 1])
            child++;
        if (heap[index] >= heap[child])
            return;
        std::swap(heap[index], heap[child]);
        sink(child);
    }
}
*/


//============= 测试示例 =============
void testMaxHeap() {
    MaxHeap<int> h;
    h.push(3);
    h.push(10);
    h.push(5);
    h.push(17);
    h.push(2);
    h.push(8);
    
    // 输出: 17 10 8 3 2 5
    while (!h.empty()) {
        std::cout << h.top() << " ";
        h.pop();
    }
}
