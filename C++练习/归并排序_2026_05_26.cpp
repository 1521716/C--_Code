#include<iostream>
#include<vector>

//打印数组
void printArr(const std::vector<int>&arr)
{
	for (const auto& val : arr)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
}
/*
 * 为什么归并排序是"外部排序"的基础？
 * 外部排序 = 数据太大，内存装不下，需要借助磁盘。
 * 归并的思想天然适合分批读写：
 *   1. 把大文件分成若干能装进内存的小块，每块内部排序后写回磁盘。
 *   2. 用类似 merge 函数的方式，从各块中读取最小值，合并成最终有序文件。
 * 因为归并的合并过程本身是顺序读写的，不需要随机访问，适合磁盘 I/O。
 */
//合并
void merge(std::vector<int>& arr, std::vector<int>& tempArr, int left, int mid, int right)
{
	//设置辅助变量
	int l_pos = left;
	int r_pos = mid + 1;
	int pos = left;

	//合并
	while (l_pos <= mid && r_pos <= right)
	{
		if (arr[l_pos] <= arr[r_pos])
			tempArr[pos++] = arr[l_pos++];
		else
			tempArr[pos++] = arr[r_pos++];
	}

	//将剩余元素放入数组
	while (l_pos <= mid)
		tempArr[pos++] = arr[l_pos++];
	while (r_pos <= right)
		tempArr[pos++] = arr[r_pos++];

	//更新arr数组
	for (int i = left; i <= right; i++)
	{
		arr[i] = tempArr[i];
	}
}

//归并排序
void msort(std::vector<int>& arr, std::vector<int>& tempArr, int left, int right)
{
	//如果子数组长度为1，则停止分区
	if (left < right)
	{
		//找到中间点开始分区
		int mid = (left + right) / 2;
		//划分左半区
		msort(arr, tempArr, left, mid);
		//划分右半区
		msort(arr, tempArr, mid + 1, right);
		//开始合并
		merge(arr, tempArr, left, mid, right);

	}
}


//归并排序入口
void merge_sort_rec(std::vector<int>& arr)
{
	//开辟一个辅助容器
	std::vector<int> tempArr(arr.size());
	
	//开始归并
	msort(arr, tempArr, 0, arr.size() - 1);
}


//归并排序（迭代）
void merge_sort_iter(std::vector<int>& arr)
{
	int n = arr.size();
	if (n <= 1)	return;

	//开辟一个辅助空间
	std::vector<int> tempArr(n);



	//归并
	//步长从1开始，到最后数组长度
	for (int size = 1; size < n; size *= 2)
	{
		//分区，每次处理相邻两个区
		for (int left = 0; left < n; left += size * 2)
		{
			int mid = left + size - 1;
			int right = std::min(left + size * 2 - 1, n - 1);

			//左数组肯定非空，右数组涉及一个最小值，导致可能为空，右数组非空才合并
			if (mid < right)
			{
				merge(arr, tempArr, left, mid, right);
			}
		}
	}

}

int main()
{
	std::vector<int> arr{ 3,1,4,1,5,9,2,6,5,3,5 };
	
	printArr(arr);

	//merge_sort_rec(arr);
	merge_sort_iter(arr);

	printArr(arr);
	return 0;
}