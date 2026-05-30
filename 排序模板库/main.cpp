#include"SortAlgorithm.hpp"
#include<iostream>
#include<string>

//打印函数
template <typename T>
void printfArr(const std::vector<T>& arr)
{
	for (const auto& val : arr)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

//快速排序测试函数
void test_quicksort_int()
{
	std::vector<int> arr_int({ 3,1,4,1,5,9,2,6,5,3,5 });

	printfArr<int>(arr_int);

	quickSort<int>(arr_int, 0, arr_int.size() - 1);

	printfArr<int>(arr_int);
}
void test_quicksort_double()
{
	std::vector<double> arr_double({ 3.3,1.2,4.5,1.3,5.1,9.6,2.8,6.4,5.1,3.2,5.2 });

	printfArr<double>(arr_double);

	quickSort<double>(arr_double, 0, arr_double.size() - 1);

	printfArr<double>(arr_double);
}
void test_quicksort_string()
{
	std::vector<std::string> arr_string({ "c","a","a","e","i","b","f","e","c","e" });

	printfArr<std::string>(arr_string);

	quickSort<std::string>(arr_string, 0, arr_string.size() - 1);

	printfArr<std::string>(arr_string);
}

//归并排序测试函数
void test_mergesort_int()
{
	std::vector<int> arr_int({ 3,1,4,1,5,9,2,6,5,3,5 });

	printfArr<int>(arr_int);

	mergeSort<int>(arr_int, arr_int.size());

	printfArr<int>(arr_int);
}
void test_mergesort_double()
{
	std::vector<double> arr_double({ 3.3,1.2,4.5,1.3,5.1,9.6,2.8,6.4,5.1,3.2,5.2 });

	printfArr<double>(arr_double);

	mergeSort<double>(arr_double, arr_double.size());

	printfArr<double>(arr_double);
}
void test_mergesort_string()
{
	std::vector<std::string> arr_string({ "c","a","a","e","i","b","f","e","c","e" });

	printfArr<std::string>(arr_string);

	mergeSort<std::string>(arr_string, arr_string.size());

	printfArr<std::string>(arr_string);
}

//堆排序测试函数
void test_heapsort_int()
{
	std::vector<int> arr_int({ 3,1,4,1,5,9,2,6,5,3,5 });

	printfArr<int>(arr_int);

	heapSort<int>(arr_int, arr_int.size());

	printfArr<int>(arr_int);
}
void test_heapsort_double()
{
	std::vector<double> arr_double({ 3.3,1.2,4.5,1.3,5.1,9.6,2.8,6.4,5.1,3.2,5.2 });

	printfArr<double>(arr_double);

	heapSort<double>(arr_double, arr_double.size());

	printfArr<double>(arr_double);
}
void test_heapsort_string()
{
	std::vector<std::string> arr_string({ "c","a","a","e","i","b","f","e","c","e" });

	printfArr<std::string>(arr_string);

	heapSort<std::string>(arr_string, arr_string.size());

	printfArr<std::string>(arr_string);
}
int main()
{
	//快速排序测试函数
	//test_quicksort_int();
	//test_quicksort_double();
	//test_quicksort_string();

	//归并排序测试函数
	//test_mergesort_int();
	//test_mergesort_double();
	//test_mergesort_string();

	//堆排序测试函数
	//test_heapsort_int();
	//test_heapsort_double();
	//test_heapsort_string();
	return 0;
}