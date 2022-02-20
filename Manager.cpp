#include"Manager.h"
#include<fstream>
#include"GolbalFile.h"
#include<algorithm>
//#include"Student.h"
//#include"Teacher.h"
#include"ComputerRoom.h"


Manager::Manager()
{
	
}

Manager::Manager(string name, string password)
{
	this->m_Name = name;//�ڹ���Ա���캯���У���ʼ������Ա��Ϣ��������������
	this->m_Password = password;

	//�ڹ���Ա�вι��캯���У����ó�ʼ��������������ʼ��ѧ������ʦ��Ϣ����
	this->initVector();

	//��ʼ��������Ϣ��//��ÿһ��������Ϣ�ӻ����ļ��ж��������ٵ��뵽����Ա���еĻ�������CR��
	ifstream ifs;
	ifs.open(computer_file, ios::in);
	if (!ifs.is_open())
	{
		cout << "�����ļ���ʧ��" << endl;
	}
	ComputerRoom cr;
	while (ifs >> cr.CR_id && ifs >> cr.CR_max)
	{
		CR.push_back(cr);
	}
}

void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼" << endl;
	cout << "\t\t  ---------------------------------\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            1.����˺�          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            2.�鿴�˺�          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            3.�鿴����          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            4.���ԤԼ          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            0.ע����¼          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ---------------------------------\n";
	cout << "�װ��Ĺ���Ա��������������һ��������";
}

void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string filename;//����˺Ų�������Ҫ���� ��д���� ���ļ���

	ofstream ofs;//�ļ���д����   ��������

	string tip;//��ʾ����Ա���룬��Ҫ��ӵġ�ѧ��ѧ�š�/����ʦְ���š�
	string errortip;//��ʾ����Ա����˺ŵ�id��ѧ��or��ʦ�ļ����Ѿ�������
	int select = 0;
	cin >> select;//���չ���Ա�����ѡ��
	if (select == 1)
	{
		//��ӵ���ѧ���˺�
		filename = student_file;
		tip = "������ѧ��ѧ��";
		errortip = "����ѧ���Ѵ��ڣ�����������";
	}
	if (select == 2)
	{
		//��ӵ�����ʦ�˺�
		filename = teacher_file;
		tip = "��������ʦְ����";
		errortip = "����ְ�����Ѵ��ڣ�����������";
	}

	//����׷�ӵķ�ʽ д�ļ�
	ofs.open(filename, ios::out | ios::app);
	int id;//����Ա��ӵ�id/name/password
	string name;
	string password;

	cout << tip << endl;

	//�ж�����id�Ƿ����ظ�
	while (true)
	{
		cin >> id;
		int ret = checkRepeat(id, select);
		if (ret) //����id���ظ�
		{
			cout << errortip << endl;
		}
		else
			break;
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> password;

	//���ļ����������
	ofs << id << " " << name << " " << password << " " << endl;//ע����ӿո�
	cout << "�˺���ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();//�ر��ļ�

	//bug�������ո���ӵ��˺ţ�ѧ���Ż���ְ���ţ�����û�и��µ������У���3����Ա���棬����ѡ��1����˺�ʱ����Ȼ���ظ�����Ϊѧ��or��ʦ������δ����
	//�����������ÿ��������˺ź����³�ʼ�����������Ѹո���ӵ��˺ţ��ӵ�ѧ��or��ʦ������
	this->initVector();

	return;
}

void Manager::noPerson() //�����
{

}

//��ӡĳһѧ������Ϣ���ڲ鿴�˺�showPerson()�����У�����ô˺���
void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_studentId << " " << " ������" << s.m_Name << " " << " ���룺" << s.m_Password << endl;
}
//��ӡĳһ��ʦ����Ϣ���ڲ鿴�˺�showPerson()�����У�����ô˺���
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_teacherId << " " << "������" << t.m_Name << " " << "���룺" << t.m_Password << endl;
}
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴���е�ѧ��" << endl;
	cout << "2���鿴���е���ʦ" << endl;

	int select = 0;//�����û�ѡ��
	cin >> select;
	if (select == 1)//�鿴ѧ��
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(stu.begin(), stu.end(), printStudent);// // perform function for each element [_First, _Last)
		//����ѧ�������������ӡ��ѧ����Ϣ//for_each��Ҫ�����㷨ͷ�ļ�#include<algorithm>
	}
	else //�鿴��ʦ
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(tea.begin(), tea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	if (CR.size() == 0)
	{
		cout << "�����ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return ;
	}
	cout << "������Ϣ���£�" << endl;
	for (auto i = CR.begin(); i != CR.end(); i++)
	{
		cout << "������ţ�" << i->CR_id << " " << "�û������������" << i->CR_max << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()//��ԤԼ�ļ�order_file���
{
	ofstream ofs;//���� ���ļ��� ��д�롱 �Ĳ�������
	ofs.open(order_file, ios::trunc);  //ios::trunc��������ǰ���ļ������Ƴ���Remove)

	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector() 
{
	//ȷ��ѧ������ʦ���������״̬
	stu.clear();
	tea.clear();
	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(student_file, ios::in);
	if (!ifs.is_open())
	{
		cout << "ѧ����Ϣ�ļ���ȡʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_studentId && ifs >> s.m_Name && ifs >> s.m_Password)
	{
		stu.push_back(s);
	}
	//�����Ƿ��ȡ��  ѧ������stu��
	cout << "��ǰѧ������Ϊ��" << stu.size() << endl;
	//�ر�ѧ���ļ�
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(teacher_file, ios::in);
	if (!ifs.is_open()) 
	{
		cout << "��ʦ��Ϣ�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_teacherId && ifs >>t.m_Name  && ifs >>t.m_Password) 
	{
		tea.push_back(t);
	}
	//����
	cout << "��ǰ��ʦ����Ϊ��" << tea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)//�ж�ѧ������stu�У��Ƿ��Ѿ�����ѧ��Ϊid��ѧ��
	{
		for (auto i = stu.begin(); i != stu.end(); i++)//����ѧ������
		{
			if (i->m_studentId == id)
			{
				cout << "�����ѧ��" << id << "��ѧ���ļ��е��ظ�" << endl;
				return true;
			}
		}
	}
	else//�ж���ʦ����tea�У��Ƿ��Ѿ�����ְ����Ϊid����ʦ
	{
		for (auto i = tea.begin(); i != tea.end(); i++)//������ʦ����
		{
			if (i->m_teacherId== id)
			{
				cout << "�����ְ����" << id << "����ʦ�ļ��е��ظ�" << endl;
				return true;
			}
		}
	}
	return false;
}


