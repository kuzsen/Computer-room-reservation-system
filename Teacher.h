#pragma once
#include"Identity.h"

#include <iostream>
using namespace std;

class Teacher : public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int id, string name, string password);
	//��ʦ��������
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ����������ʦ���ѧ����ԤԼ������ʵ��������ԤԼ
	void validOrder();
	//��ʦְ����
	int m_teacherId;
};