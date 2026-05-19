#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

#define CAPACITY 10

template<class K,class V>
class HashTable {

public:
	
	HashTable()
	{
		buckets.resize(CAPACITY);
		m_size = 0;
	}

	void insert(const K& key, const V& value)
	{
		int index = getIndex(key);

		// 遍历链表查找key是否已存在
		for(auto it = buckets[index].begin();it!= buckets[index].end();it++)
		{
			if (it->first == key)
			{
				it->second = value;  // 找到了就更新value
				return;
			}
		}
		// 没找到才插入
		buckets[index].push_back({ key, value });
		m_size++;
	}
	//查找
	bool search(const K& key, V& value) 
	{
		int index = getIndex(key);
		
		for (auto it = buckets[index].begin(); it != buckets[index].end(); it++)
		{
			if (it->first == key)
			{
				value = it->second;
				return true;
			}
		}
		
		return false;
	}
	//删除
	bool remove(const K& key)
	{
		int index = getIndex(key);
		
		for (auto it = buckets[index].begin(); it != buckets[index].end(); it++)
		{
			if (it->first == key)
			{
				buckets[index].erase(it);
				m_size--;
				return true;
			}
		}
		return false;
	}
	//当前哈希表内元素个数
	int size() const
	{
		return m_size;
	}

private:
	int getIndex(const K& key) {
		return std::hash<K>{}(key) % CAPACITY;
	}
private:
	std::vector < std::list<std::pair<K, V>>> buckets;
	int m_size = 0;
        
};

/*void testInt()
{
	HashTable<int,int> hash;
	int value = 0;
	hash.insert(1, 10);
	hash.insert(2, 20);
	hash.insert(3, 30);
	
	if (hash.search(2, value))
		std::cout << value << std::endl;
	else
		std::cout << "无该key" << std::endl;
	if (hash.remove(2))
		std::cout << "删除成功" << std::endl;
	else
		std::cout << "无key值，删除失败" << std::endl;
	if (hash.search(2, value))
		std::cout << value << std::endl;
	else
		std::cout << "无该key" << std::endl;
	if (hash.search(1, value))
		std::cout << value << std::endl;
	else
		std::cout << "无该key" << std::endl;
	hash.insert(1, 100);
	if (hash.search(1, value))
		std::cout << value << std::endl;
	else
		std::cout << "无该key" << std::endl;


}*/

void testString()
{
	HashTable<std::string, int> hash;
	int value = 0;
	hash.insert("Alice", 85);
	hash.insert("Bob", 92);
	hash.insert("Charlie", 78);

	if (hash.search("Bob", value))
		std::cout << value << std::endl;
	else
		std::cout << "无该key" << std::endl;
	if (hash.remove("Bob"))
		std::cout << "删除成功" << std::endl;
	else
		std::cout << "无key值，删除失败" << std::endl;
	if (hash.search("Bob", value))
		std::cout << value << std::endl;
	else
		std::cout << "无该key" << std::endl;
	if (hash.search("Alice", value))
		std::cout << value << std::endl;
	else
		std::cout << "无该key" << std::endl;
	hash.insert("Alice", 95);
	if (hash.search("Alice", value))
		std::cout << value << std::endl;
	else
		std::cout << "无该key" << std::endl;


}

int main()
{
	//testInt();
	testString();
	return 0;
}