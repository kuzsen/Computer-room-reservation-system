#pragma once
#include "Identity.h"
#include<vector>
#include"ComputerRoom.h"

class Student : public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	
	//�в�������
	Student(int id, string name, string password);

	//�����˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ���ҵ�ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_studentId;

	//������ԤԼʱ��ѧ�����Կ�����������Ϣ�����������Ҫ��ѧ����ȡ����������Ϣ
	//��student.h������µĳ�Ա������
	//��������
	vector<ComputerRoom> vCom;

};

