#pragma once
#include<string>

class Student
{
public:
	//默认构造函数
	Student();

	//有参构造函数
	Student(const std::string& id, const std::string& name, double score);

	//拷贝构造函数
	Student(const Student& s);

	//一些基本函数
	const std::string& getID() const;

	const std::string& getName() const;

	double getScore() const;

	Student& setID(const std::string& id);

	Student& setName(const std::string& name);

	Student& setScore(double score);

private:
	std::string m_ID;
	std::string m_Name;
	double m_Score = 0.0;
};
