#include "admin.h"


Admin::Admin()
{



}

Admin::Admin(string name, string code)
{
	m_Name = name;
	m_Code = code;

}

void Admin::Adminmenu()
{
	cout << "*************************************" << endl;
	cout << "1.����˺�" << endl;
	cout << "2.�鿴�˺�" << endl;
	cout << "3.�鿴����" << endl;
	cout << "4.���ԤԼ" << endl;
	cout << "5.�鿴����ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
	cout << "*************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "���������ѡ��" << endl;
}

void Admin::Addnumber()
{
	int a=0;
	ofstream ofs;
	string num1, name1, code1;
	cout << "��ѡ�����±�Ž�������˺�" << endl;
	cout << "1�����ѧ���˺�" << endl;
	cout << "2����ӽ�ʦ�˺�" << endl;
	cin >> a;
	while (!(a == 1 || a == 2))
	{
		cout << "�����������������" << endl;
		cin >> a;
	}

	if (a == 1)
	{
	
		ofs.open("stu.txt", ios::out | ios::app);
		cout << "������ѧ�ţ�" << endl;
		cin >> num1;
		cout << "������������" << endl;
		cin >> name1;
		cout << "���������룺" << endl;
		cin >> code1;
		ofs << num1 << " " << name1 << " " << code1 << endl;
		cout << "���ѧ���˺����" << endl;
		ofs.close();
	}
	if (a == 2)
	{
		ofs.open("teacher.txt", ios::out | ios::app);
		cout << "������ְ���ţ�" << endl;
		cin >> num1;
		cout << "������������" << endl;
		cin >> name1;
		cout << "���������룺" << endl;
		cin >> code1;
		ofs << num1 << " " << name1 << " " << code1 << endl;
		cout << "��ӽ�ʦ�˺����" << endl;
		ofs.close();
	}

}


void Admin::shownumber()
{
	ifstream ifs;
	int a = 0;
	cout << "��ѡ�����±�Ž��в鿴�˺�" << endl;
	cout << "1���鿴ѧ���˺�" << endl;
	cout << "2���鿴��ʦ�˺�" << endl;
	cin >> a;
	while (!(a == 1 || a == 2))
	{
		cout << "�����������������" << endl;
		cin >> a;
	}

	if (a == 1)
	{
		string numstu, namestu, codestu;
		cout << "ѧ���˺���Ϣ������ʾ" << endl;
		ifs.open("stu.txt", ios::in);
		if (ifs.is_open() != true)
		{
			cout << "�ļ���ʧ�ܣ�" << endl;
			return;
		}
		while (ifs >> numstu && ifs >> namestu && ifs >> codestu)
		{
			cout << "ѧ�ţ�" << numstu << " " << "������" << namestu << " " << "���룺" << codestu << endl;
		}
		ifs.close();
	}
	if (a == 2)
	{
		string numteacher, nameteacher, codeteacher;
		cout << "��ʦ�˺���Ϣ������ʾ" << endl;
		ifs.open("teacher.txt", ios::in);
		if (ifs.is_open() != true)
		{
			cout << "�ļ���ʧ�ܣ�" << endl;
			return;
		}
		while (ifs >> numteacher && ifs >> nameteacher && ifs >> codeteacher)
		{
			cout << "ְ���ţ�" << numteacher << " " << "������" << nameteacher << " " << "���룺" << codeteacher << endl;
		}
		ifs.close();
	}



}


void Admin::showcomputerroom()
{

	string id,nummax;
	ifstream ifs;
	cout << "������Ϣ������ʾ" << endl;
	ifs.open("computerroom.txt", ios::in);
	if (ifs.is_open() != true)
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	while (ifs >> id && ifs >> nummax)
	{
		cout << "������ţ�" << id<< " " << "����������" << nummax << endl;
	}
	ifs.close();

}


void Admin::clearorder()
{
	ofstream ofs;
	ofs.open("order.txt", ios::out | ios::trunc);
	ofs.close();
	cout << "ԤԼ��¼�����" << endl;
}

void Admin::showallorder()
{
	Orderfile ord;
	cout << "���е�ԤԼ������ʾ" << endl;
	for (int i = 0; i < ord.m_Size; i++)
	{

		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << ord.m_Orderdata[i]["data"] << " ";
		if (ord.m_Orderdata[i]["interval"] == "1")
		{
			cout << "ʱ��Σ�����" << " ";
		}
		else
			cout << "ʱ��Σ�����" << " ";
		cout << "ѧ�ţ�" << ord.m_Orderdata[i]["m_Num"] << " ";
		cout << "������" << ord.m_Orderdata[i]["m_Name"] << " ";
		cout << "�����ţ�" << ord.m_Orderdata[i]["roomid"] << " ";
		if (ord.m_Orderdata[i]["status"] == "-1")
		{
			cout << "״̬��ԤԼȡ��" << endl;
		}
		if (ord.m_Orderdata[i]["status"] == "0")
		{
			cout << "״̬����˲�ͨ��" << endl;
		}
		if (ord.m_Orderdata[i]["status"] == "1")
		{
			cout << "״̬�������" << endl;
		}
		if (ord.m_Orderdata[i]["status"] == "2")
		{
			cout << "״̬��ԤԼ�ɹ�" << endl;
		}



	}



}