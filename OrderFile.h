#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "GolbalFile.h"

class OrderFile {
public:
	//���캯��
	OrderFile();//���캯���л�ȡ������Ϣ�������������m_orderData��

	//����ԤԼ��¼
	void updateOrder();

	//��¼������ key = ��¼������ - 1, value = ÿ����¼����ļ�ֵ����Ϣ������{{data, 1},{interval, 2}, .....}
	map<int, map<string, string>> m_orderData;//// m_orderData��key��Ӧ��vaule�ǵ�key+1��ԤԼ��Ϣ

	//ԤԼ��¼����0��1��2����������orderNum - 1 ����orderNum��ԤԼ��¼
	int orderNum;
};


