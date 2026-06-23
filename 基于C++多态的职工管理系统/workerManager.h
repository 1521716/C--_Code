#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#define FILENAME "empFile.txt"

//ְ��������
class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//�˵���ʾ
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//�����ļ�
	void save();

	//����ְ��
	void Add_Emp();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ���ְ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ����Ϣ
	void Show_Emp();

	//ְ���Ƿ����(���ڷ����±꣬�����ڷ���-1)
	int IsExist(int id);

	//ɾ����ְְ��
	void Del_Emp();

	//�޸�ְ����Ϣ
	void Mod_Emp();

	//����ְ����Ϣ
	void Find_Emp();

	//���ձ������
	void Sort_Emp();

	//����ĵ�
	void Clean_File();

	//��������
	~WorkerManager();
};
