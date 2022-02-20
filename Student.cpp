#include "Student.h"
#include "GolbalFile.h"
#include "OrderFile.h"
#include<cstdlib>//�ڴ������Ϊ�˽��Student.cpp��system("pause");system("cls");  ��ʾsystem����ȷ����
//��C�����stdlib.h����c++�����cstdlib�������װ����ຯ����

Student::Student()
{

}

Student :: Student(int id, string name, string password)//Student����вι��캯����
{
	//��ʼ��ѧ����Ϣ
	this->m_studentId = id;
	this->m_Name = name;
	this->m_Password = password;
	//��ȡ������Ϣ
	ifstream ifs;
	ifs.open(computer_file, ios::in);

	ComputerRoom cr;
	while (ifs >> cr.CR_id && ifs >> cr.CR_max)
	{
		this->vCom.push_back(cr);
	}
	ifs.close();
}

void Student :: operMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼" << endl;
	cout << "\t\t  ---------------------------------\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            1.����ԤԼ          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            2.�鿴�ҵ�ԤԼ      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            3.�鿴����ԤԼ      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            4.ȡ��ԤԼ          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            0.ע����¼          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ---------------------------------\n";
	cout << "���������Ĳ�����";
}
void Student :: applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date = 0;//�ܼ�
	int interval = 0;//����or���磬ʱ���
	int room = 0;//���������
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "������������������";
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].CR_max << endl;
	cout << "2�Ż���������" << vCom[1].CR_max << endl;
	cout << "3�Ż���������" << vCom[2].CR_max << endl;

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs(order_file, ios::app);//����ѧ���ĸ�����Ϣ�Լ�ԤԼ��Ϣ��д��ԤԼ�ļ��м�¼����
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_studentId << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;//��ʾԤԼ��״̬��1 = �����

	ofs.close();
	system("pause");
	system("cls");
}

void Student :: showMyOrder()
{
	/*
	��ʾԤԼ��¼ʱ����Ҫ���ļ��л�ȡ�����м�¼��������ʾ������ԤԼ�����������¼�Լ�����
	��ͷ�ļ��Լ�Դ�ļ��·ֱ𴴽�OrderFile.h��OrderFile.cpp�ļ�
	*/

	OrderFile of;//����ԤԼ�ļ��Ķ��󣬵����˹��캯�����Ѿ���order_file�е���Ϣ���뵽m_orderData�������ж�ԤԼ�ļ�order_file���ж�д�����£���ȡԤԼ�����Ȳ���
	if (of.orderNum == 0) {
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	int orderMyself = 0;//��������ԤԼ��¼,��������ԤԼ�ļ��Ĵ�������vMyself.size() == 0����û�и�ѧ����ԤԼ��¼
	for (int i = 0; i < of.orderNum; i++) {
		//string ת int
		//string ���� .c_str() ת const char*
		//���� atoi(const char*) ת int
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_studentId) {
			orderMyself++;//��⵽����ԤԼ��¼��һ
			cout << "ԤԼ����: ��" << of.m_orderData[i]["date"];
			cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " �����ţ�" << of.m_orderData[i]["roomId"];
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

	}
	if (orderMyself == 0) {
		cout << "ԤԼ�ļ���û������ԤԼ��¼!" << endl;
	}
	system("pause");
	system("cls");

}


void  Student :: showAllOrder()
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

void  Student :: cancelOrder()
{ 
	OrderFile of;
	if (of.orderNum == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л���ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v;//������������  ����л���ԤԼ�ɹ�  �ļ�¼
	int index = 1;//v�еĵ�index����¼
	for (int i = 0; i < of.orderNum; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_studentId) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);//����⵽�ġ���������������  ����л���ԤԼ�ɹ�  �ļ�¼�����������뵽������
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
				cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderData[i]["roomId"];
				string status = " ״̬��";
				if (of.m_orderData[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	if (v.size() == 0) {
		cout << "ԤԼ�ļ���û��������ȡ���ļ�¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л���ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	cout << "�������������С�����л���ԤԼ�ɹ��� �ļ�¼����v�У���Ҫȡ���ĵ�select����¼��0������" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();//״̬�ı����������ԤԼ�ļ�
				cout << "��ȡ��ԤԼ" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		cout << "������������������" << endl;
	}
}
