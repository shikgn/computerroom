#include "orderfile.h"


Orderfile::Orderfile()
{
	string data;//ԤԼ����1-5�ֱ�Ϊ��һ������
	string interval;//ʱ���1�������磬2��������
	string num;//ѧ��
	string name;//����
	string roomid;//������
	string status;//-1����ȡ��ԤԼ��0������˲�ͨ����1��������У�2������˳ɹ�

	ifstream ifs;
	ifs.open("order.txt", ios::in);
	if (ifs.is_open() != true)
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	
	string key;
	string value;
	m_Size = 0;
	while (ifs >> data && ifs >> interval && ifs >> num && ifs >> name && ifs >> roomid && ifs >> status)
	{
		map<string, string> m;//һ��Ҫд��whileѭ�������棬���������֤��ʱ�����ǻ���ֶ������ĵ�һ������
		//�������д�����Ϊ��ȷ�����ݱ���ȡ����
		//cout << data << " " << interval << " " << num << " " << name << " " << roomid << " " << status << " " << endl;
		int pos = data.find(":");
		if (pos != -1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos+1, data.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key =interval.substr(0, pos);
			value = interval.substr(pos+1, interval.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = num.find(":");
		if (pos != -1)
		{
			key = num.substr(0, pos);
			value = num.substr(pos+1, num.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = name.find(":");
		if (pos != -1)
		{
			key = name.substr(0, pos);
			value = name.substr(pos+1, name.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = roomid.find(":");
		if (pos != -1)
		{
			key = roomid.substr(0, pos);
			value = roomid.substr(pos+1, roomid.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos+1, status.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		m_Orderdata.insert(make_pair(m_Size, m));
		m_Size++;
		
	}

	ifs.close();
	
	//���´�����Ϊ�˱�֤��ȡ����������ȷ
	/*for (map<int, map<string, string>>::iterator it = m_orderdata.begin(); it != m_orderdata.end(); it++)
	{
		cout << "key:" << it->first << " " << endl;
		for (map<string, string>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++)
		{
			cout << it1->first <<" "<< it1->second << " ";
		}
		cout << endl;
	}*/
	

}


void Orderfile::updateorder()
{
	if (m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		return;
	}
	ofstream ofs;
	ofs.open("order.txt", ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "data:" << m_Orderdata[i]["data"] << " ";
		ofs << "interval:" << m_Orderdata[i]["interval"] << " ";
		ofs << "m_Num:" << m_Orderdata[i]["m_Num"] << " ";
		ofs << "m_Name:" << m_Orderdata[i]["m_Name"] << " ";
		ofs << "roomid:" << m_Orderdata[i]["roomid"] << " ";
		ofs << "status:" << m_Orderdata[i]["status"] << " "<<endl;

	}
	ofs.close();
}