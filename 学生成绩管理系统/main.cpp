#define _CRT_SECURE_NO_WARNINGS
#include"Student_manager.h"
#include"Student.h"
#include<vector>

int main()
{
	//初始化容器
	std::vector<Student> s;

	//读取文件数据并录入容器
	loadFromFile(s,"Students.txt");

	int input = 0;

	do {
		//打印菜单
		menu();
		std::cin >> input;
		switch (input)
		{
		case 1:
			inputStudentData(s);
			clear();
			break;
		case 2:
			removeStudentData(s);
			clear();
			break;
		case 3:
			changeStudentData(s);
			clear();
			break;
		case 4:
			outputStudentData(s);
			clear();
			break;
		case 5:
			searchStudentData(s);
			clear();
			break;
		case 6:
			sortStudentData(s);
			clear();
			break;
		case 0:
			printf("程序使用结束，再见！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
		}
	} while (input);
	//将容器数据录入文件
	saveToFile(s, "Students.txt");
	return 0;
}