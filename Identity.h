#pragma once
#include <iostream>
#include<string>
using namespace std;

//��ݻ��ࡪ����������಻�ܹ���ʵ�����ģ�ֻ�ܱ��̳У�https://blog.csdn.net/FX677588/article/details/77727110
class Identity {
public:
	//�����˵� ���麯��������������������������������������������������ֻ�ṩ���������ṩʵ�֣�ʵ��������ȥ��ɡ�
	//ÿ�����඼���Լ������Ĳ����˵�
	virtual void operMenu() = 0;

	string m_Name;//����
	string m_Password;//����
};
