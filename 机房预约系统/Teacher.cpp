#include "teacher.h"


Teacher::Teacher()
{



}

Teacher::Teacher(string num, string name, string code)
{
	m_Num = num;
	m_Name = name;
	m_Code = code;

}

void Teacher::teachermenu()
{
	cout << "*************************************" << endl;
	cout << "1.�鿴����ԤԼ" << endl;
	cout << "2.���ԤԼ" << endl;
	cout << "0.ע����¼" << endl;
	cout << "*************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "���������ѡ��" << endl;

}

void Teacher::showallorder()
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

void Teacher::verifyorder()
{
	Orderfile ord2;
	map<int, int> m;
	int i, j = 0;
	int select, pass = 0;
	cout << "����Ҫ��˵�ԤԼ������ʾ��" << endl;
	for (i = 0; i < ord2.m_Size; i++)
	{
		if (ord2.m_Orderdata[i]["status"] == "1")
		{
			cout << j + 1 << "��";
			cout << "ԤԼ���ڣ���" << ord2.m_Orderdata[i]["data"] << " ";
			if (ord2.m_Orderdata[i]["interval"] == "1")
			{
				cout << "ʱ��Σ�����" << " ";
			}
			else
				cout << "ʱ��Σ�����" << " ";
			cout << "ѧ�ţ�" << ord2.m_Orderdata[i]["m_Num"] << " ";
			cout << "������" << ord2.m_Orderdata[i]["m_Name"] << " ";
			cout << "�����ţ�" << ord2.m_Orderdata[i]["roomid"] << " ";
			if (ord2.m_Orderdata[i]["status"] == "-1")
			{
				cout << "״̬��ԤԼȡ��" << endl;
			}
			if (ord2.m_Orderdata[i]["status"] == "0")
			{
				cout << "״̬����˲�ͨ��" << endl;
			}
			if (ord2.m_Orderdata[i]["status"] == "1")
			{
				cout << "״̬�������" << endl;
			}
			if (ord2.m_Orderdata[i]["status"] == "2")
			{
				cout << "״̬��ԤԼ�ɹ�" << endl;
			}
			m.insert(make_pair(j + 1, i));
			j++;
		}


	}

	if (j == 0 && i == ord2.m_Size)
	{
		cout << "��ǰû������Ҫ��˵ļ�¼" << endl;
		return;
	}
	cout << endl;
	cout << "����������Ҫ��˵ļ�¼���" << endl;
	cin >> select;
	while (!(select>0&&select<j+1))
	{
		cout << "�����������������" << endl;
		cin >> select;
	}
	cout << "����������ѡ��" << endl;
	cout << "1��ͨ��" << endl;
	cout << "2����ͨ��" << endl;
	cin >> pass;
	while (!(pass == 1||pass == 2))
	{
		cout << "�����������������" << endl;
		cin >> pass;
	}
	if (pass == 1)
	{
		ord2.m_Orderdata[m[select]]["status"] = '2';
		cout << "������" << endl;
		ord2.updateorder();
	}
	if (pass ==2)
	{
		ord2.m_Orderdata[m[select]]["status"] = '0';
		cout << "������" << endl;
		ord2.updateorder();
	}
	
}