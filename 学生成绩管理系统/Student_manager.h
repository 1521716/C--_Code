#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Student.h"
#include<fstream>
#include<iomanip>
#include<algorithm>

//清屏函数
void clear();

//读取文件数据并录入容器
void loadFromFile(std::vector<Student>& s, const std::string& filename);

//打印菜单
void menu();

//1-录入
void inputStudentData(std::vector<Student>& s);

//2-删除(清空）
void removeStudentData(std::vector<Student>& s);

//3-修改
void changeStudentData(std::vector<Student>& s);

//4-显示
void outputStudentData(const std::vector<Student>& s);

//5-查找
void searchStudentData(const std::vector<Student>& s);

//6-排序
bool idLessSort(const Student& s1, const Student& s2);
bool scoreGreaterSort(const Student& s1, const Student& s2);
void sortStudentData(std::vector<Student>& s);


//将容器数据录入文件
void saveToFile(const std::vector<Student>& s, const std::string& filename);