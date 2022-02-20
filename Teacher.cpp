#include"Teacher.h"
#include"OrderFile.h"
#include<vector>

Teacher::Teacher()
{
}

Teacher::Teacher(int id, string name, string password)
{
	//��ʼ������
	this->m_teacherId = id;
	this->m_Name = name;
	this->m_Password = password;

}

void Teacher :: operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t  ---------------------------------\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            1.�鿴����ԤԼ      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            2.���ԤԼ          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            0.ע����¼          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ---------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
}

void  Teacher:: showAllOrder()
{
	OrderFile of;
	if (of.orderNum == 0) {
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.orderNum; i++) {
		cout << i + 1 << "��";

		cout << "ԤԼ����: ��" << of.m_orderData[i]["date"];
		cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["stuName"];
		cout << " ������" << of.m_orderData[i]["roomId"];
		string status = "״̬��";
		//1 ����� 2 ��ԤԼ -1 ԤԼʧ�� 0 ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else {
			status += "ԤԼ��ȡ��";
		}
		cout << " " << status;
		cout << endl;
	}
	system("pause");
	system("cls");
}

void Teacher:: validOrder()
{
	OrderFile of;
	if (of.orderNum == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����ˡ�������״̬=1��ԤԼ��¼���£�" << endl;

	vector<int> v;//����˵�ԤԼ��¼���±�0��1��2��������
	int index = 0;//v�еĵ�1��2��3.������
	for (int i = 0; i < of.orderNum; i++) {
		if (of.m_orderData[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ����ţ�" << of.m_orderData[i]["stuId"];
			cout << " ѧ��������" << of.m_orderData[i]["stuName"];
			cout << " ������ţ�" << of.m_orderData[i]["roomId"];
			string status = "״̬: �����";
			cout << status << endl;
		}
	}
	if (v.size() == 0) {
		cout << "û����Ҫ��˵ļ�¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������Ҫ��˵�ԤԼ��¼, 0����" << endl;
	int select = 0;//�������д���˼�¼�У���ʦѡ����˵ĵ� select ��ԤԼ��¼
	int ret = 0;//������ʦ�Ըü�¼����˽��
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0)
				break;
			else {
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1) {
					//ͨ��
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else {
					//��ͨ��
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();//��ʦ��˺���������ԤԼ�ļ��еļ�¼
				cout << "������" << endl;
				break;
			}
		}
		cout << "������������������!" << endl;
	}
	system("pause");
	system("cls");
}