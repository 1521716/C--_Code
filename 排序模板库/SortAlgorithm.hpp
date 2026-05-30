#include<vector>
#include<algorithm>
#include<cstdlib>

/*
 * ===================================================
 * 排序算法库 (Sorting Algorithm Library)
 * ===================================================
 *
 * 本库实现了三种经典的比较排序算法：
 *
 * 1. 快速排序 (Quick Sort)
 *    - 平均时间复杂度：O(n log n)
 *    - 最坏时间复杂度：O(n²) (可通过随机化基准或三数取中避免)
 *    - 空间复杂度：O(log n) (递归栈深度)
 *    - 稳定性：不稳定
 *    - 适用场景：
 *        • 一般情况下的通用排序，实际运行速度通常最快
 *        • 对内存缓存友好，适合大数据量
 *        • 不要求稳定性的场合
 *    - 注意事项：
 *        • 最坏情况发生在已排序或大量重复元素，需配合随机化或三路划分
 *        • 递归过深可能导致栈溢出，可改用 Introsort 策略（转堆排序）
 *
 * 2. 归并排序 (Merge Sort)
 *    - 平均/最坏/最好时间复杂度：O(n log n)
 *    - 空间复杂度：O(n) (需要辅助数组)
 *    - 稳定性：稳定
 *    - 适用场景：
 *        • 要求稳定排序的场合（如按成绩排序，保持原有顺序）
 *        • 外部排序 (外存数据量大无法一次装入内存)
 *        • 对链表进行排序 (可达到 O(1) 额外空间)
 *        • 最坏情况也保证 O(n log n)，适合对时间复杂度有严格保证的场景
 *
 * 3. 堆排序 (Heap Sort)
 *    - 平均/最坏/最好时间复杂度：O(n log n)
 *    - 空间复杂度：O(1)
 *    - 稳定性：不稳定
 *    - 适用场景：
 *        • 要求原地排序且不能出现最坏 O(n²) 的情况
 *        • 内存极度受限的嵌入式或实时系统
 *        • 实现优先队列的核心操作
 *    - 缺点：
 *        • 常数因子较大，实际速度通常慢于快排
 *        • 访存不连续，缓存不友好
 *
 * 推荐使用指南：
 *   - 大多数情况下优先使用快速排序（或 std::sort 的 Introsort）
 *   - 需要稳定性时使用归并排序（或 std::stable_sort）
 *   - 内存极紧且不能接受最坏退化时使用堆排序
 * ===================================================
 */

//快速排序辅助函数
template <typename T>
int partition(std::vector<T>& arr, int left, int right)
{
	//维护小于pivot区间
	int low = left - 1;
	//取随机值，避免O(n2)
	std::swap(arr[right], arr[left + rand() % (right - left + 1)]);
	//基准值
	T pivot = arr[right];

	//开始遍历排序，小于pivot就移动到左区间
	for (int i = left; i < right; i++)
	{
		if (arr[i] < pivot)
			std::swap(arr[++low], arr[i]);
	}
	//将基准值放到最终位置
	std::swap(arr[++low], arr[right]);

	//返回本次确定的位置
	return low;
}

//快速排序
template <typename T>
void quickSort(std::vector<T>& arr, int left, int right)
{
	//如果区间小于2，则已经有序
	if (left >= right)	return;

	//选择本次要确定的位置
	int pivot = partition<T>(arr, left, right);
	//递归左半区
	quickSort<T>(arr, left, pivot - 1);
	//递归右半区
	quickSort<T>(arr, pivot + 1, right);
}

//归并排序辅助函数
template <typename T>
void merge(std::vector<T>& arr, std::vector<T>& tempArr, int left, int mid, int right)
{
	//辅助变量
	int pos = left;
	int l_pos = left;
	int r_pos = mid + 1;

	//排序
	while (l_pos <= mid && r_pos <= right)
	{
		if (arr[l_pos] <= arr[r_pos])
			tempArr[pos++] = arr[l_pos++];
		else
			tempArr[pos++] = arr[r_pos++];
	}

	//将剩余数据存入
	while (l_pos <= mid)
		tempArr[pos++] = arr[l_pos++];
	while (r_pos <= right)
		tempArr[pos++] = arr[r_pos++];

	//更新排序后的arr
	for (int i = left; i <= right; i++)
		arr[i] = tempArr[i];
}

//归并排序
template <typename T>
void mergeSort(std::vector<T>& arr, int n)
{
	//如果数组长度小于2，则已经有序
	if (n <= 1) return;

	//开辟辅助数组
	std::vector<T> tempArr(n);

	//先从小区间开始归并，慢慢增大，直到并成一个区间
	for (int size = 1; size < n; size *= 2)
	{
		for (int left = 0; left < n; left += size * 2)
		{
			int mid = left + size - 1;
			int right = std::min(left + size * 2 - 1, n - 1);

			//右区间不为空才合并
			if (mid < right)
				merge(arr, tempArr, left, mid, right);
		}
	}
	
}

//堆排序辅助函数
template <typename T>
void sink(std::vector<T>& arr, int index, int n)
{
	int child = index * 2 + 1;
	while (child < n)
	{
		if (child < n - 1 && arr[child] < arr[child + 1])
			child++;
		if (arr[child] > arr[index])
		{
			std::swap(arr[child], arr[index]);
			index = child;
			child = index * 2 + 1;
		}
		else
			break;
	}
}

//堆排序
template <typename T>
void heapSort(std::vector<T>& arr,int n)
{
	//如果数组长度小于2，则已经有序
	if (n <= 1)	return;

	for (int index = n / 2 - 1; index >= 0; index--)
	{
		sink(arr, index, n);
	}

	for (int tail = n - 1; tail > 0; tail--)
	{
		std::swap(arr[tail], arr[0]);
		sink(arr, 0, tail);
	}

}