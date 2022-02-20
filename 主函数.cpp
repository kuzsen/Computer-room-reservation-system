#include<iostream>
#include<string>
using namespace std;
#include"GolbalFile.h"
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include<fstream>//C++�ļ������������ͷ�ļ�<fstream>�а��������ļ���������ࡪ��ifstream/ofstream/fstream���ֱ�����Ӧ��iostream�е�����������

//ȫ�ֺ��������������Ա�����Ӳ˵�����
//****ע�⣬һ��Ҫ����ȫ�ֵ�¼����LoginIn�����棬��ΪLoginIn�л���øú���
//****�������ʾ       "managerMenu":�Ҳ�����ʶ��
//*****������дһ���������������£�����  ����ʵ��  �Ϳ����������
//void managerMenu(Identity*& father);//��������


//ȫ�ֺ�����������ѧ�������Ӳ˵�����
void studentMenu(Identity*& father) 
{
	while (true)
	{
		//����ѧ���Ӳ˵�,�����еĴ��麯����ѧ��������ʵ��
		father->operMenu();
		//������ָ��father ǿ��ת��Ϊѧ������ָ��stu �����ڵ��������е����������ӿ�
		Student* stu = (Student*)father;
		//����ѧ����ѡ��
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2)
		{
			cout << "�鿴�ҵ�ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
		}
		else
		{
			delete father;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;			
		}
	}
}

//ȫ�ֺ�������������ʦ�����Ӳ˵�����
void teachrMenu(Identity*& father)
{
	while (true) {
		//��ʦ�˵�
		father->operMenu();

		Teacher* tea = (Teacher*)father;
		int select = 0;//������ʦ��ѡ��
		cin >> select;
		if (select == 1) {
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2) {
			//���ԤԼ
			tea->validOrder();
		}
		else {
			delete father;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void managerMenu(Identity*& father)//����father������Ϊ����ָ��
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		father->operMenu();
		//������ָ��father ǿ��ת��Ϊ����ָ��man �����ڵ��������е����������ӿ�
		Manager* man = (Manager*)father;

		int select = 0;
		//���ܹ���Ա��ѡ��
		cin >> select;
		if (select == 1)
		{
			cout << "����˺�" << endl;//��ѧ�����ʦ����µ��˺�
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "�鿴������Ϣ" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else //��ȥ1/2/3/4
		{
			delete father;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//��¼ȫ�ֺ���
void LoginIn(string filename,int type)//fileName �� �������ļ�����type �� ��¼�����(1����ѧ���� 2������ʦ�� 3�������Ա)
{
	Identity* Father = nullptr;//����ָ��   ����ָ���������

	//���ļ�              https://blog.csdn.net/weixin_42831199/article/details/82047874
	ifstream ifs;//����һ�����ļ��������ڽ��ļ��е��������뵽�ڴ���
	ifs.open(filename, ios::in);//�Զ���ķ�ʽ��ͬһĿ¼���ļ���Ϊ��filename�����ļ�
	//ifs.open("D:\\Users\\a'd'mia\\source\\repos\\lzs925\\����ԤԼϵͳ\\student.txt");
	//�ж�Ҫ�����ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	//���ļ����ڣ�׼�������û�����ĵ�¼��Ϣ
	int id = 0;
	string name;
	string password;

	if (type == 1)//ѧ����ݣ���Ҫ����ѧ��
	{
		cout << "����������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ��ݣ���Ҫ������ʦְ����
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> password;

	if (type == 1)//ѧ�������֤
	{
		//���մ��ļ��ж����ѧ����Ϣ
		int fid;//���ļ��ж�ȡ��id��
		string fname;//���ļ��ж�ȡ��name
		string fpasssword;//���ļ��ж�ȡ��password

		while (ifs >> fid && ifs >> fname && ifs >> fpasssword)
		{
			//cout<<fid<<fname<<fpasssword<<endl;//��֤�Ƿ���ļ��ж�ȡ�ɹ�
			if (fid == id && fname == name && fpasssword == password)//���û��������Ϣ���Ա�
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");//����

				Father = new Student(id, name, password);  //����ָ��ָ���������
				//����ѧ��¼����Ӳ˵�
				studentMenu(Father);
				return;
			}
		}

	}
	else if (type == 2)//��ʦ�����֤
	{
		//���մ��ļ��ж������ʦ��Ϣ
		int fid;//���ļ��ж�ȡ��id�š���ְ����
		string fname;//���ļ��ж�ȡ��name
		string fpasssword;//���ļ��ж�ȡ��password

		while (ifs >> fid && ifs >> fname && ifs >> fpasssword)
		{
			//cout<<fid<<fname<<fpasssword<<endl;//��֤�Ƿ���ļ��ж�ȡ�ɹ�
			if (fid == id && fname == name && fpasssword == password)//���û��������Ϣ���Ա�
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");//����

				Father = new Teacher(id, name, password);  //����ָ��ָ���������
				//������ʦ��ݵ��Ӳ˵�
				teachrMenu(Father);
				return;
			}
		}
	}
	else if(type == 3)//����Ա�����֤
	{
		//���մ��ļ��ж���Ĺ���Ա��Ϣ
		//int fid;//���ļ��ж�ȡ��id��
		string fname;//���ļ��ж�ȡ��name
		string fpasssword;//���ļ��ж�ȡ��password

		while (ifs >> fname && ifs >> fpasssword)
		{
			//cout<<fname<<fpasssword<<endl;//��֤�Ƿ���ļ��ж�ȡ�ɹ�
			if (fname == name && fpasssword == password)//���û��������Ϣ���Ա�
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");//����

				Father = new Manager(name, password);  //����ָ��ָ���������,��ʱ����Manager���вι��캯�������ɳ�ʼ��ѧ������ʦ��Ϣ����
				//�������Ա��ݵ��Ӳ˵�
				managerMenu(Father);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select = 0;
	while (true) {

		cout << endl << "�������������" << endl;//         \t��ʾ��4��\n��ʾ����
		cout << "\t\t  ---------------------------------\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            1.ѧ������          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            2.��    ʦ          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            3.�� �� Ա          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            0.��    ��          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t  ---------------------------------\n";
		cout << "����������ѡ��";

		cin >> select;//�����û�ѡ��

		switch (select)
		{
		case 1://ѡ��ѧ�����
			LoginIn(student_file, select);
			break;
		case 2://ѡ����ʦ���
			LoginIn(teacher_file, select);
			break;
		case 3://ѡ�����Ա���
			LoginIn(manager_file, select);
			break;
		case 0://�˳�ϵͳ
			cout << "���˳�����ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	
	}
	
	system("pause");
	system("cls");
	return 0;
}
