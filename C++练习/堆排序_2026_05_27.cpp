#include<iostream>
#include<vector>
#include<algorithm>


/*
                                                   三种O(n logn)排序横向对比                             
算法             平均时间              最坏时间             最好时间             空间复杂度            稳定性              使用场景

快速排序          nlogn                n2                   nlogn                  logn                不稳定               通用，实际最快

归并排序          nlogn                nlogn                nlogn                   n                   稳定                需要稳定排序/外部排序
 
堆排序            nlogn                nlogn                nlogn                   1                   不稳定              内存极受限，只需top K

*/


//辅助建堆函数(n为数组大小，i为要建堆的子树的根)
void heapify(std::vector<int>& arr, int n, int i) {
	while (true) {
		int child = i * 2 + 1;
		if (child >= n) break;
		if (child + 1 < n && arr[child] < arr[child + 1])
			child++;
		if (arr[child] <= arr[i]) break;
		std::swap(arr[child], arr[i]);
		i = child;  
	}
}

//堆排序
void heapSort(std::vector<int>& arr)
{
	
	int size = arr.size();
	if (size < 2)	return;
	//建堆
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(arr, size, i);
	}

	//排序
	for (int i = size - 1; i > 0; i--)
	{
		std::swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}

}


//打印数组
void printArr(const std::vector<int>& arr)
{
	for (const auto& val : arr)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> arr({ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 });

	printArr(arr);

	heapSort(arr);

	printArr(arr);

	return 0;
}