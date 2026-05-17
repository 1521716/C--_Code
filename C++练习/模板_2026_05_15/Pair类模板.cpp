#include<iostream>

template<class K,class V>
class Pair
{
public:
	//有参构造函数
	Pair(K key, V value)
	{
		m_Key = key;
		m_Value = value;
	}
	//operator=
	Pair& operator=(const Pair& pair)
	{
		this->m_Key = pair.m_Key;
		this->m_Value = pair.m_Value;
		return *this;
	}

	//获取Key
	K getKey() const
	{
		return this->m_Key;
	}

	//获取Value
	V getValue() const
	{
		return this->m_Value;
	}
	//因为不涉及深拷贝问题，所以析构函数、拷贝构造函数使用编译器提供的即可
private:
	K m_Key;
	V m_Value;
};

int main()
{
	Pair<int, int> p1(1, 10);
	std::cout << "p1的Key为：" << p1.getKey() << " Value为：" << p1.getValue() << std::endl;
	Pair<int, int> p2(p1);
	std::cout << "p2的Key为：" << p2.getKey() << " Value为：" << p2.getValue() << std::endl;
	Pair<int, int> p3 = p1;
	std::cout << "p3的Key为：" << p3.getKey() << " Value为：" << p3.getValue() << std::endl;
	return 0;
}