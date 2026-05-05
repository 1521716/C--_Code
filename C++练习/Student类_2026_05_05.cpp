#include<iostream>
using namespace std;
#include<string>


//学生类
class Student
{
private:
	string m_Name;
	string m_Num;
	int m_Chinese;
	int m_Math;
	int m_English;

public:
	//无参构造函数
	Student()
	{
		
	}

	//有参构造函数(参数列表初始化)
	Student(string Name,string Num,int Chinese,int Math,int English):m_Name(Name),m_Num(Num),m_Chinese(Chinese),m_Math(Math),m_English(English)
	{
		cout << "Student " << m_Name << " created" << endl;
	}

	//析构函数
	~Student()
	{
		cout << "Student " << m_Name << " destroyed." << endl;
	}

	//一些函数(!!!!!!!!!!!!!!!!!!!!!!只读函数加const修饰!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
	double average() const
	{
		//整数加完之后先显式转换，提高精确度
		return ((double)(m_Chinese + m_Math + m_English)) / 3.0;
	}

	string getName() const
	{
		return m_Name;
	}

	string getNum() const
	{
		return m_Num;
	}

};


int main()
{
	//创建对象
	Student* s1 = new Student("lirui","202500501333",99,98,57);
	const Student s2("test","001", 60, 70, 75);

	//打印平均值
	cout << "Student " << s1->getName() << "`s average is " << s1->average() << endl;
	cout << "Student " << s2.getName() << "`s average is " << s2.average() << endl;

	//销毁
	delete s1;
	return 0;
}