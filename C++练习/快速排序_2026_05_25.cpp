#include<iostream>
#include<vector>
#include<algorithm>

class QuickSort {
public:
	//快速排序
	void quickSort(std::vector<int>& arr, int left,int right)
	{
		if (left < right)
		{
			int pivotPos = partition(arr, left, right);
			quickSort(arr, left, pivotPos - 1);
			quickSort(arr, pivotPos + 1, right);
		}
		
	}

	/*
 * 为什么快排不稳定？
 * partition 里交换时，相同元素的相对顺序可能被打乱。
 * 例如 arr = [2a, 2b, 1]，pivot = 1
 * 第一次交换 2a 和 1 → [1, 2b, 2a]，2a 和 2b 的相对顺序变了。
    */
	int partition(std::vector<int>& arr, int left, int right)
	{
		
		//选择最右侧为基准值
		int pivot = arr[right];

		//小于基准值的数组边界
		int low = left - 1;

		for (int high = left; high < right; high++)
		{
			//找到小于基准值的数便将其移动到左侧区域
			if (arr[high] < pivot)
			{
				low = low + 1;
				std::swap(arr[low], arr[high]);
			}
		}

		//遍历结束，将pivot放到最终位置
		low = low + 1;
		std::swap(arr[low], arr[right]);

		return low;

	}
};

void printArr(const std::vector<int>& arr)
{
	for (const auto& val : arr)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

void test()
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(1);
	v.push_back(5);
	v.push_back(9);
	v.push_back(2);
	v.push_back(6);
	v.push_back(5);
	v.push_back(3);
	v.push_back(5);
	printArr(v);

	QuickSort().quickSort(v,0,v.size()-1);

	printArr(v);

}


int main()
{
	test();
	return 0;
}