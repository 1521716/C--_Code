/*
 * 哈希表开链法模板
 * 
 * 适用场景：
 *   - 快速查找/插入/删除
 *   - 字典/映射数据结构
 *   - 缓存实现
 *   - 去重问题
 * 
 * 注意事项：
 *   1. 负载因子 = n/m（元素数/桶数），过大时需扩容/重哈希
 *   2. 哈希函数需尽量均匀分布，减少冲突
 *   3. 链表操作：插入/删除O(1)，查找O(k)，k为链表平均长度
 *   4. 本模板使用 vector<list> 实现
 *   5. key比较：需遍历链表找到对应节点
 *   6. 存储类型为 pair<K, V>，key唯一，value可更新
 */

//============= 哈希表开链法模板 =============
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

#define CAPACITY 10

template<class K, class V>
class HashTable {
public:
    // 构造函数：初始化桶
    HashTable() {
        buckets.resize(CAPACITY);
    }
    
    // 插入/更新
    void insert(const K& key, const V& value) {
        int index = getIndex(key);
        
        // 遍历链表查找key是否已存在
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value;              // 存在则更新value
                return;
            }
        }
        // 不存在则插入新节点
        buckets[index].push_back({key, value});
        m_size++;
    }
    
    // 查找
    bool search(const K& key, V& value) const {
        int index = getIndex(key);
        
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }
    
    // 删除
    bool remove(const K& key) {
        int index = getIndex(key);
        
        for (auto it = buckets[index].begin(); it != buckets[index].end(); it++) {
            if (it->first == key) {
                buckets[index].erase(it);
                m_size--;
                return true;
            }
        }
        return false;
    }
    
    int size() const {
        return m_size;
    }

private:
    // 获取哈希索引（适用于int类型）
    int getIndex(int key) const {
        return key % CAPACITY;
    }
    
    // 获取哈希索引（适用于string类型）
    int getIndex(const std::string& key) const {
        int index = 0;
        for (char c : key) {
            index = index * 31 + c;
        }
        return index % CAPACITY;
    }
    
private:
    std::vector<std::list<std::pair<K, V>>> buckets;
    int m_size = 0;
};


//============= 测试示例 =============
void testHashTable() {
    // int类型key
    HashTable<int, int> intHash;
    intHash.insert(1, 10);
    intHash.insert(2, 20);
    intHash.insert(3, 30);
    
    int value;
    if (intHash.search(2, value))
        std::cout << "key=2, value=" << value << std::endl;
    
    // string类型key
    HashTable<std::string, int> strHash;
    strHash.insert("Alice", 85);
    strHash.insert("Bob", 92);
    
    if (strHash.search("Bob", value))
        std::cout << "Bob's score: " << value << std::endl;
}
