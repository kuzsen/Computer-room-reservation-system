#pragma once
#include"Identity.h"
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"ComputerRoom.h"

class Manager : public Identity
{
public:
	
	Manager();//Ĭ�Ϲ���

	Manager(string name, string password);	//�вι���
	
	virtual void operMenu();//����Ա�������棬������ʵ�ִ��麯����ʵ�֣��ģ�ͷ�ļ���������Manager.cpp�о���ʵ��
	
	void addPerson();//����˺ţ�ѧ��or��ʦ��

	void noPerson();  //ɾ���˺�
	
	void showPerson();//����Աɾ���˺ţ�ѧ��or��ʦ������������������������������δʵ��
	
	void showComputer();//�鿴������Ϣ
	
	void cleanFile();//���ԤԼ��¼

	/*Ҫȥ���ظ����˺ţ�����Ҫ��ѧ���ͽ�ʦ���˺���Ϣ��ȡ�������У����ɼ��
	��manager.h�У�����������������ڴ��ѧ���ͽ�ʦ����Ϣ
	���һ���µĳ�Ա���� void initVector()��ʼ������*/

	void initVector();

	vector<Student>stu;//ѧ������

	vector<Teacher>tea;//��ʦ����

	//���ѧ��or��ʦ��Ϣ�Ƿ����ظ�,//idΪ�����ѧ��orְ���ţ�typeΪ1ѧ��or2��ʦ������ֵtrue=���ظ���false=û���ظ���������Ӹ��˺�
	bool checkRepeat(int id, int type);

	//��ӻ��������������ڱ��������Ϣ
	vector<ComputerRoom>CR;

	
};