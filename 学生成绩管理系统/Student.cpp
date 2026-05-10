#include"Student.h"

	//默认构造函数
	Student::Student():m_ID(),m_Name(),m_Score(0.0)
	{

	}

	//有参构造函数
	Student::Student(const std::string& id, const std::string& name, double score):m_ID(id),m_Name(name),m_Score(score)
	{
	
	}

	//拷贝构造函数
	Student::Student(const Student& s):m_ID(s.m_ID),m_Name(s.m_Name),m_Score(s.m_Score)
	{
		
	}

	//一些基本函数
	const std::string& Student::getID() const
	{
		return m_ID;
	}

	const std::string& Student::getName() const
	{
		return m_Name;
	}

	double Student::getScore() const
	{
		return m_Score;
	}

	Student& Student::setID(const std::string& id)
	{
		m_ID = id;
		return *this;
	}

	Student& Student::setName(const std::string& name)
	{
		m_Name = name;
		return *this;
	}

	Student& Student::setScore(double score)
	{
		m_Score = score;
		return *this;
	}
