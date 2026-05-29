#include<iostream>
#include<vector>
#include<algorithm>

void printArr(const std::vector<int>& arr)
{
	for (const auto& val : arr)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

void test_sort()
{

	/*
	sort排序复杂度为O(nlogn),通常是introsort（快排+堆排+插入混合）

	一上来先使用快速排序，当层数超过某一限度使用堆排，当剩余元素很少或者已经基本有序，使用插入排序

	不稳定，因为快排、堆排不稳定
	
	*/

	std::vector<int> arr({ 3,1,4,1,5,9,2,6,5,3,5 });

	printArr(arr);

	//默认升序排列
	//std::sort(arr.begin(), arr.end());

	std::sort(arr.begin(), arr.end(), std::greater<int>());

	printArr(arr);
}

class  Student {
public:
	//重载逻辑运算符，以便比较
	bool operator< (const Student& s ) const
	{
		return this->Score < s.Score;
	}
	//有参构造
	Student(int id, int score):Id(id),Score(score){}
public:
	int Id = 0;
	int Score = 0;
};

void test_stable_sort()
{
	/*
	stable_sort排序复杂度为O(nlogn),通常是归并排序

	稳定，因为归并排序稳定

	*/
	//稳定的排序
	std::vector<Student> arr;
	arr.push_back(Student(1001, 78));
	arr.push_back(Student(1002, 82));
	arr.push_back(Student(1003, 67));
	arr.push_back(Student(1004, 67));
	arr.push_back(Student(1005, 56));

	for ( auto it = arr.begin(); it != arr.end(); it++)
	{
		std::cout << it->Id << "     " << it->Score << std::endl;
	}
	std::cout << std::endl;

	std::stable_sort(arr.begin(), arr.end(),std::less<Student>());

	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		std::cout << it->Id << "     " << it->Score << std::endl;
	}

}

void test_partial_sort()
{
	/*
	partial_sort排序复杂度为O(nlogk),通常是堆排

	只保证前K个元素是最大（小），其余位置顺序随机

	不稳定

	*/
	std::vector<int> arr({ 3,1,4,1,5,9,2,6,5,3,5 });

	printArr(arr);
	//默认是“升序”
	//std::partial_sort(arr.begin(), arr.begin() + 3, arr.end());

	std::partial_sort(arr.begin(), arr.begin() + 3, arr.end(), std::greater<int>());

	printArr(arr);
}
int main()
{
	

	//test_sort
	//test_sort();

	//test_stable_sort
	//test_stable_sort();

	//test_partial_sort
	test_partial_sort();
	return 0;
}