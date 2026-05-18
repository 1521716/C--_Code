#include<iostream>
#include<vector>


class MaxHeap {

public:
	//构造函数
	//默认构造函数
	MaxHeap()
	{
		//因为本逻辑是从下标1开始，所以在0填充0占位
		heap.push_back(0);
	}
	//插入(在尾部插入，然后上浮)
	void push(int val)
	{
		heap.push_back(val);
		swim(heap.size()-1);
		std::cout << "元素已插入" << std::endl;
	}
	//删除堆顶元素 
	void pop()
	{
		if (heap.size() == 1)
		{
			std::cout << "堆为空，删除失败！" << std::endl;
			return;
		}

		heap[1] = heap.back();
		heap.pop_back();
		sink(1);
		std::cout << "堆顶元素已删除！" << std::endl;
	}
	//获取堆顶元素（最大值）
	int top() const
	{
		if (heap.size() > 1)
			return heap[1];
		else
		{
			std::cout << "堆为空！默认返回0" << std::endl;
			return 0;
		}
	}
	//返回当前元素个数
	int size() const
	{
		return heap.size() - 1;
	}
	//判断堆是否为空
	bool empty() const
	{
		return heap.size() == 1;
	}

private:
	//辅助函数(递归)
	//上浮(当前结点与父结点比较，若大于父节点则交换)
	//void swim(int index)
	//{
	//	if (index == 1)
	//		return;
	//	if (heap[index] > heap[index / 2])
	//	{
	//		int tem = heap[index];
	//		heap[index] = heap[index / 2];
	//		heap[index / 2] = tem;
	//		return swim(index / 2);
	//	}

	//	return;
	//}
	//下沉(当前节点与左右孩子比较，若小于孩子节点，与较大者交换)
	//void sink(int index)
	//{
	//	//n为最大下标
	//	int n = heap.size() - 1;
	//	if (index * 2 <= n)
	//	{
	//		int child = index * 2;
	//		if (child < n && heap[child] < heap[child + 1])
	//			child++;
	//		if (heap[index] >= heap[child])
	//			return;
	//		else 
	//		{
	//			int tem = heap[index];
	//			heap[index] = heap[child];
	//			heap[child] = tem;
	//			return sink(child);
	//		}
	//	}

	//}
	//辅助函数(循环)
	//上浮(当前结点与父结点比较，若大于父节点则交换)
	void swim(int index) {
		while (index > 1 && heap[index] > heap[index / 2]) {
			std::swap(heap[index], heap[index / 2]);
			index /= 2;
		}
	}
	//下沉(当前节点与左右孩子比较，若小于孩子节点，与较大者交换)
	void sink(int index) {
		int n = heap.size() - 1;
		while (index * 2 <= n) {
			int child = index * 2;
			if (child < n && heap[child] < heap[child + 1])
				child++;
			if (heap[index] >= heap[child])
				break;
			std::swap(heap[index], heap[child]);
			index = child;
		}
	}
private:
	std::vector<int> heap;
};

//测试函数
void test()
{
	MaxHeap h;
	std::cout << "当前堆的元素个数为：" << h.size() << std::endl;
	h.push(3);
	h.push(10);
	h.push(5);
	h.push(17);
	h.push(2);
	h.push(8);

	std::cout << "当前堆的元素个数为：" << h.size() << std::endl;

	std::cout << h.top() << " ";
	h.pop();
	std::cout << h.top() << " ";
	h.pop();
	std::cout << h.top() << " ";
	h.pop();
	std::cout << h.top() << " ";
	h.pop();
	std::cout << h.top() << " ";
	h.pop();
	std::cout << h.top() << " ";
	h.pop();

	std::cout << "当前堆的元素个数为：" << h.size() << std::endl;

}


int main()
{
	test();
	return 0;
}