#include "OrderFile.h"

OrderFile :: OrderFile()
{
	ifstream ifs;
	ifs.open(order_file, ios::in);//��ԤԼ�ļ���ͳ�����е�ԤԼ��Ϣ
	string date;//����
	string interval;//ʱ���
	string stuId;//ѧ�����
	string stuName;//ѧ������
	string roomId;//�������
	string status;//ԤԼ״̬

	this->orderNum = 0;//��¼����

	while (ifs >> date && ifs >> interval && ifs >> stuId
		&& ifs >> stuName && ifs >> roomId && ifs >> status) {
		//����
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;
		//cout << endl;
		string key;//С������key����ʾ  ��Ϣ�����ƣ����� data��interval
		string value;//С������vaule����ʾ ��Ϣ��ֵ������ ��������ӦkeyΪstuName��
		map<string, string> m;//С��������ʾһ��ԤԼ��¼��������Ϣ

		//��ȡʱ��Σ���ʱ��ԤԼ�ļ�order_file�ж�ȡ����һ��ԤԼ��¼�У�string data = "data:1"
		int pos = date.find(":"); // data[4] = ":"
		if (pos != -1) {
			key = date.substr(0, pos);//substr�ĵ�һ������0��ʾ��ȡ�ַ�������ʼ�±꣬�ڶ�������pos ��ʾ��ȡ�ַ������ȣ���ʱ��key = data��
			value = date.substr(pos + 1, date.size() - pos - 1);//��':'����һ���ַ���ʼ��ȡʣ�µ��ַ�����ʱ��val = 1����ʾ��һ��
			m.insert(make_pair(key, value));//��һ��ԤԼ��¼�еĲ�����Ϣ{data��1}������С������
		}
		//��ȡ���
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��ȡѧ��
		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��ȡ����
		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��ȡ������
		pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//��ȡ״̬
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		//��Сmap�������뵽���map������
		this->m_orderData.insert(make_pair(this->orderNum, m));// m_orderData��key��Ӧ��vaule�ǵ�key+1��ԤԼ��Ϣ
		this->orderNum++;//��ȡ��ԤԼ��¼��һ
	}
	ifs.close();
	/*cout << "�������map����" << endl;
	for (map<int, map<string, string>>::iterator it = m_orderData.begin();
		it != m_orderData.end(); it++) {
		cout << "��"<< it->first + 1<<"��ԤԼ��ϢΪ��"<< " value = " << endl;
		for (map<string, string>::iterator mit = (*it).second.begin();
			mit != (*it).second.end(); mit++) {
			cout << " key = " << mit->first << " value = " << mit->second << " ";
		}
		cout << endl; 
	}*/
}

void OrderFile :: updateOrder ()
{
	if (this->orderNum == 0)
	{
		return;
	}
	ofstream ofs(order_file, ios::out | ios::trunc);//�Ƚ�ԤԼ�ļ����
	for (int i = 0; i < this->orderNum; i++) {//���½�ԤԼ��¼��д������ԤԼ�ļ��У���ɸ��²���
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}
