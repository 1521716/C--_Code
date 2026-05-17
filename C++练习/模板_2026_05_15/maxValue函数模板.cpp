#include<iostream>
#include<string>

template<typename T>
const T& maxValue(const T& a, const T& b) 
{
	return a > b ? a : b;
}

int main()
{
	int a = 10, b = 20;
	std::string c = "cab", d = "dbb";
	std::cout << maxValue<int>(a, b) << std::endl;
	std::cout << maxValue<std::string>(c,d) << std::endl;
	return 0;
}