#include<iostream>
#include<vector>

//Animal类
class Animal {
public:
	//虚函数speak
	virtual void speak()
	{
		std::cout << "Animal在说话" << std::endl;
	}

	//虚析构函数
	virtual ~Animal()
	{
		std::cout << "Animal的析构函数" << std::endl;
	}
};

//Cat类（Animal的派生类）
class Cat :public Animal {
public:
	//因为该案例不涉及成员变量以及深浅拷贝问题，故不再实现构造函数
	
	//重写speak函数
	virtual void speak() override//override：编译器替你检查重写的虚函数命名，返回值等是否正确
	{
		std::cout << "小猫在说话" << std::endl;
	}

	//析构函数
	~Cat()
	{
		std::cout << "Cat的析构函数" << std::endl;
	}
};

//Dog类（Animal的派生类）
class Dog :public Animal {
public:
	//因为该案例不涉及成员变量以及深浅拷贝问题，故不再实现构造函数

	//重写speak函数
	virtual void speak() override
	{
		std::cout << "小狗在说话" << std::endl;
	}

	//析构函数
	~Dog()
	{
		std::cout << "Dog的析构函数" << std::endl;
	}
};

void test()
{
	//创建Animal*的vector容器
	std::vector<Animal*> animals;

	//入栈，体现多态
	animals.push_back(new Cat);
	animals.push_back(new Dog);

	//分别调用speak函数，并delete
	for (int i = 0; i < animals.size(); i++)
	{
		animals[i]->speak();
		delete animals[i];
	}

	//清空容器
	animals.clear();
}

int main()
{
	test();
	return 0;
}