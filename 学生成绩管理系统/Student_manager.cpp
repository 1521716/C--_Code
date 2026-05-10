#define _CRT_SECURE_NO_WARNINGS
#include"Student_manager.h"

//读取文件数据并录入容器
void loadFromFile(std::vector<Student>& s, const std::string& filename)
{
	//清空vector容器，防止旧数据干扰
	s.clear();

	//创建流对象
	std::ifstream ifs;

	//打开文件
	ifs.open(filename, std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "文件打开失败！" << std::endl;
		return;
	}

	//用于读取学生个数
	int size = 0;
	ifs >> size;

	//循环读取所有学生
	std::string id = "", name = ""; double score = 0.0;
	for (int i = 0; i < size; i++)
	{
		if (!(ifs >> id >> name >> score))
		{
			std::cout << "数据出错，读取终止！" << std::endl;
			break;
		}
		Student tem(id,name,score);
		s.push_back(tem);
	}

	//关闭文件
	ifs.close();

	std::cout << "数据初始化成功！" << std::endl;
}

//清屏函数
void clear()
{
	system("pause");
	system("cls");
}

//打印菜单
void menu()
{
	std::cout << "*****************************************************************************************" << std::endl;
	std::cout << "*********1-录入   2-删除(清空)   3-修改   4-显示   5-查找   6-排序  0-退出***************" << std::endl;
	std::cout << "*****************************************************************************************" << std::endl;
	std::cout << "请输入你的选择(0-5):";
}

//1-录入
void inputStudentData(std::vector<Student>& s)
{
	//通过循环，录入所需数据
	std::cout<<"请输入新增加的学生个数：";
	int n = 0,sign = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		//更新学生数量
		int sum = s.size();
		//设置辅助变量
		std::string id = "", name = ""; double score = 0.0;

		//输入学号，并判断学号是否已经存在
		do {
			sign = 0;
			std::cout<<"请输入第"<<sum+1<<"个学生的学号：";
			std::cin >> id;
			for(int j = 0;j<sum;j++)
			{
				if (id == s[j].getID())
				{
					std::cout << "该学号已存在，请重新输入！" << std::endl;
					sign = 1;
					break;
				}
			}
		} while (sign);

		//输入姓名
		std::cout << "请输入第" << sum+1 << "个学生的姓名：";
		std::cin >> name;

		//输入成绩，并判断成绩是否合法
		do {
			sign = 0;
			std::cout << "请输入第" << sum+1 << "个学生的成绩：";
			std::cin >> score;
			if (score < 0 || score >100)
			{
				std::cout << "成绩输入不合法，请重新输入！" << std::endl;
				sign = 1;
			}
		} while (sign);
		
		//将该学生加入到容器
		Student tem(id, name, score);
		s.push_back(tem);
	}
}

//2-删除(清空）
void removeStudentData(std::vector<Student>& s)
{

	int select = 0,select1 = 0;;
	do {
		//菜单
		std::cout << "*******************************************************" << std::endl;
		std::cout << "***1-按学号删除    2-按姓名删除      3-清空   0-退出***" << std::endl;
		std::cout << "*******************************************************" << std::endl;
		std::cout << "请输入你的选择:";

		std::string remove_ID = "", remove_name = "";
		std::cin >> select;

		switch (select)
		{
		case 1:
			//按照学号删除
			std::cout << "请输入你要删除的学生的学号：";
			std::cin >> remove_ID;
			for(int i = 0;i<s.size();i++)
			{
				if (s[i].getID() == remove_ID)
				{
					s.erase(s.begin() + i);
					std::cout << "删除成功!" << std::endl;
					return;
				}
			}
			std::cout << "未找到学号为" << remove_ID << "的学生信息" << std::endl;
			break;
		case 2:
			//按照姓名删除
			std::cout << "请输入你要删除的学生姓名：";
			std::cin >> remove_name;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i].getName() == remove_name)
				{
					s.erase(s.begin() + i);
					std::cout << "删除成功!" << std::endl;
					return;
				}
			}
			std::cout << "未找到姓名为" << remove_name << "的学生信息" << std::endl;
			break;
		case 3:
			//询问用户是否清空
			std::cout << "你真的要清空吗？清空后不可恢复！！！" << std::endl;
			std::cout << "*****************************************************" << std::endl;
			std::cout << "****1-仍要清空   0-放弃清空（输入其他值默认放弃）****" << std::endl;
			std::cout << "*****************************************************" << std::endl;

			//用户选择
			std::cout << "请输入你的选择：";
			std::cin >> select1;

			switch (select1)
			{
			case 1:
				
				s.clear();
				std::cout << "已清空！" << std::endl;
				return;
				break;
			case 0:
				std::cout << "已放弃清空。" << std::endl;
				return;
				break;
			default:
				std::cout << "已默认放弃清空。" << std::endl;
				return;
			}
			break;
		case 0:
			std::cout << "删除程序退出！" << std::endl;
			break;
		default:
			std::cout << "选择错误，请重新选择！" << std::endl;
		}
	} while (select);
}

//3-修改
void changeStudentData(std::vector<Student>& s)

{
	int select = 0;

	do {
		//菜单
		std::cout << "**********************************************" << std::endl;
		std::cout << "*****1-按学号修改   2-按姓名修改   0-退出*****" << std::endl;
		std::cout << "**********************************************" << std::endl;
		std::cout << "请输入你的选择:";

		//选择
		int sign = 0,sign1 = 0;
		std::cin >> select;
		switch (select)
		{
		case 1:

			do {
				sign = 0;
				//输入修改的学生学号
				std::cout << "请输入要修改的学生的学号：";
				std::string change_ID = "";
				std::cin >> change_ID;

				//通过循环遍历容器，查找位置
				for (int i = 0; i < s.size(); i++)
				{
					//如果找到，开始修改
					if (s[i].getID() == change_ID)
					{
						std::cout << "要修改学生信息已找到！" << std::endl;

						//创建辅助变量
						std::string id = "", name = ""; double score = 0.0;
						
						//输入学号，并判断学号是否已经存在
						do {
							sign1 = 0;
							std::cout << "请输入新学号：";
							std::cin >> id;
							for(int j = 0;j<s.size();j++)
							{
								if (s[j].getID() == id && j != i)
								{
									std::cout << "该学号已存在，请重新输入！" << std::endl;
									sign1 = 1;
									break;
								}
							}
						} while (sign1);

						//输入姓名
						std::cout << "请输入新姓名：";
						std::cin >> name;
						
						//输入成绩，并判断成绩是否合法
						do {
							sign1 = 0;
							std::cout << "请输入新成绩：";
							std::cin >> score;
							if (score < 0 || score >100)
							{
								std::cout << "成绩输入不合法，请重新输入！" << std::endl;
								sign1 = 1;
							}
						} while (sign1);

						//修改数据
						s[i].setID(id); s[i].setName(name); s[i].setScore(score);
						
						std::cout << "修改成功！" << std::endl;
						return;
					}
				}

				//跳出循环，说明未找到
				std::cout << "要修改的学生信息未找到！请重新输入！" << std::endl;
				sign = 1;
			} while (sign);
			break;
		case 2:
			do {
				sign = 0;
				//输入修改的学生姓名
				std::cout << "请输入要修改的学生的姓名：";
				std::string change_name = "";
				std::cin >> change_name;

				//通过循环遍历链表，查找节点
				for (int i = 0; i < s.size(); i++)
				{
					//如果找到，开始修改
					if (change_name == s[i].getName())
					{
						std::cout << "要修改学生信息已找到！" << std::endl;
						
						//创建辅助变量
						std::string id = "", name = ""; double score = 0.0;

						//输入学号，并判断学号是否已经存在
						do {
							sign1 = 0;
							std::cout << "请输入新学号：";
							std::cin >> id;
							for (int j = 0; j < s.size(); j++)
							{
								if (s[j].getID() == id && j != i)
								{
									std::cout << "该学号已存在，请重新输入！" << std::endl;
									sign1 = 1;
									break;
								}
							}
						} while (sign1);

						//输入姓名
						std::cout << "请输入新姓名：";
						std::cin >> name;

						//输入成绩，并判断成绩是否合法
						do {
							sign1 = 0;
							std::cout << "请输入新成绩：";
							std::cin >> score;
							if (score < 0 || score >100)
							{
								std::cout << "成绩输入不合法，请重新输入！" << std::endl;
								sign1 = 1;
							}
						} while (sign1);

						//修改数据
						s[i].setID(id); s[i].setName(name); s[i].setScore(score);

						std::cout << "修改成功！" << std::endl;
						return;
					}
				}

				//跳出循环，说明未找到
				std::cout << "要修改的学生信息未找到！请重新输入！" << std::endl;
				sign = 1;
			} while (sign);
			break;
		case 0:
			std::cout << "修改程序使用结束！" << std::endl;
			break;
		default:
			std::cout << "选择错误，请重新输入！" << std::endl;
		}
	} while (select);
}


//4-显示
void outputStudentData(const std::vector<Student>& s)
{
	if (s.size() == 0)
	{
		std::cout << "暂无学生记录！" << std::endl;
		return;
	}
	std::cout << std::left << std::setw(20) << "学号" << std::setw(30) << "姓名" << "成绩" << std::endl;

	for(int i = 0;i<s.size();i++)
	{
		std::cout << std::left << std::setw(20) << s[i].getID() << 
		std::setw(30) << s[i].getName() << s[i].getScore() << std::endl;
	}

}

//5-查找
void searchStudentData(const std::vector<Student>& s)
{
	int select = 0;

	do {
		//菜单
		std::cout << "**********************************************" << std::endl;
		std::cout << "*****1-按学号查找   2-按姓名查找   0-退出*****" << std::endl;
		std::cout << "**********************************************" << std::endl;
		std::cout << "请输入你的选择:";

		//选择
		int sign = 0, sign1 = 1;
		std::cin >> select;
		switch (select)
		{
		case 1:
			do {
				sign = 0;
				//输入查询学号
				std::cout << "请输入你要查询的学号:";
				std::string search_ID = "";
				std::cin >> search_ID;
				std::cout << "查询结果为：" << std::endl;
				//循环遍历查找
				for (int i = 0; i < s.size(); i++)
				{
					//找到便输出
					if (s[i].getID() == search_ID)
					{
						std::cout << std::left << std::setw(20) << "学号" << std::setw(30) << "姓名" << "成绩" << std::endl;
						std::cout << std::left << std::setw(20) << s[i].getID() <<
							std::setw(30) << s[i].getName() << s[i].getScore() << std::endl;
						return;
					}
				}

				std::cout << "未找到你要查询的学生信息，请重新输入！" << std::endl;
				sign = 1;
			} while (sign);
			break;
		case 2:
			do {
				sign = 0;
				//输入查询姓名
				std::cout << "请输入你要查询的姓名:";
				std::string search_name = "";
				std::cin >> search_name;
				std::cout << "查询结果为：" << std::endl;
				//循环遍历查找
				for (int i = 0; i < s.size(); i++)
				{
					//找到便输出
					if (s[i].getName() == search_name)
					{
						std::cout << std::left << std::setw(20) << "学号" << std::setw(30) << "姓名" << "成绩" << std::endl;
						std::cout << std::left << std::setw(20) << s[i].getID() <<
							std::setw(30) << s[i].getName() << s[i].getScore() << std::endl;
						return;
					}
				}
				std::cout << "未找到你要查询的学生信息，请重新输入！" << std::endl;
				sign = 1;
			} while (sign);
			break;
		case 0:
			std::cout << "查找程序使用结束！" << std::endl;
			break;
		default:
			std::cout << "输入选择错误，请重新输入！" << std::endl;
		}
	} while (select);
}

//6-排序
bool idLessSort(const Student& s1, const Student& s2)
{
	if (s1.getID() < s2.getID())
		return true;
	return false;
}

bool scoreGreaterSort(const Student& s1, const Student& s2)
{
	if (s1.getScore() > s2.getScore())
		return true;
	return false;
}
void sortStudentData(std::vector<Student>& s)
{

	int select = 0;
	do {
		//菜单
		std::cout << "*********************************************************" << std::endl;
		std::cout << "*********1-按学号升序    2-按成绩降序    0-退出**********" << std::endl;
		std::cout << "*********************************************************" << std::endl;

		//用户选择
		std::cout << "请选择操作数:";
		std::cin >> select;
		switch (select)
		{
		case 1:

			//按学号升序排序(冒泡)
			std::sort(s.begin(), s.end(), idLessSort);

			std::cout << "按学号升序排序成功！" << std::endl;
			return;
			break;
		case 2:
			//按成绩给数组排序(冒泡)
			std::sort(s.begin(), s.end(), scoreGreaterSort);

			std::cout << "按成绩降序排序成功！" << std::endl;
			return;
			break;
		case 0:
			std::cout << "排序程序结束！" << std::endl;
			break;
		default:
			std::cout << "输入选择错误，请重新选择！" << std::endl;
		}
	} while (select);
}


//将容器数据录入文件
void saveToFile(const std::vector<Student>& s, const std::string& filename)
{
	//获取容器中已有学生个数
	int size = s.size();

	//创建流对象
	std::ofstream ofs;

	//打开文件
	ofs.open(filename, std::ios::out);

	//写入文件
	ofs << size << std::endl;
	//将所有学生数据写入
	for (int i = 0; i < size; i++)
	{
		ofs << s[i].getID() << " " << s[i].getName() << " " << s[i].getScore() << std::endl;
	}

	//关闭文件
	ofs.close();

	std::cout << "数据录入成功！" << std::endl;
}
