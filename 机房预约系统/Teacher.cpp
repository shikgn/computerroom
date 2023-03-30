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
	cout << "1.查看所有预约" << endl;
	cout << "2.审核预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "*************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "请输入你的选择：" << endl;

}

void Teacher::showallorder()
{
	Orderfile ord;
	cout << "所有的预约如下所示" << endl;
	for (int i = 0; i < ord.m_Size; i++)
	{

		cout << i + 1 << "、";
		cout << "预约日期：周" << ord.m_Orderdata[i]["data"] << " ";
		if (ord.m_Orderdata[i]["interval"] == "1")
		{
			cout << "时间段：上午" << " ";
		}
		else
			cout << "时间段：下午" << " ";
		cout << "学号：" << ord.m_Orderdata[i]["m_Num"] << " ";
		cout << "姓名：" << ord.m_Orderdata[i]["m_Name"] << " ";
		cout << "机房号：" << ord.m_Orderdata[i]["roomid"] << " ";
		if (ord.m_Orderdata[i]["status"] == "-1")
		{
			cout << "状态：预约取消" << endl;
		}
		if (ord.m_Orderdata[i]["status"] == "0")
		{
			cout << "状态：审核不通过" << endl;
		}
		if (ord.m_Orderdata[i]["status"] == "1")
		{
			cout << "状态：审核中" << endl;
		}
		if (ord.m_Orderdata[i]["status"] == "2")
		{
			cout << "状态：预约成功" << endl;
		}



	}




}

void Teacher::verifyorder()
{
	Orderfile ord2;
	map<int, int> m;
	int i, j = 0;
	int select, pass = 0;
	cout << "您需要审核的预约如下所示：" << endl;
	for (i = 0; i < ord2.m_Size; i++)
	{
		if (ord2.m_Orderdata[i]["status"] == "1")
		{
			cout << j + 1 << "、";
			cout << "预约日期：周" << ord2.m_Orderdata[i]["data"] << " ";
			if (ord2.m_Orderdata[i]["interval"] == "1")
			{
				cout << "时间段：上午" << " ";
			}
			else
				cout << "时间段：下午" << " ";
			cout << "学号：" << ord2.m_Orderdata[i]["m_Num"] << " ";
			cout << "姓名：" << ord2.m_Orderdata[i]["m_Name"] << " ";
			cout << "机房号：" << ord2.m_Orderdata[i]["roomid"] << " ";
			if (ord2.m_Orderdata[i]["status"] == "-1")
			{
				cout << "状态：预约取消" << endl;
			}
			if (ord2.m_Orderdata[i]["status"] == "0")
			{
				cout << "状态：审核不通过" << endl;
			}
			if (ord2.m_Orderdata[i]["status"] == "1")
			{
				cout << "状态：审核中" << endl;
			}
			if (ord2.m_Orderdata[i]["status"] == "2")
			{
				cout << "状态：预约成功" << endl;
			}
			m.insert(make_pair(j + 1, i));
			j++;
		}


	}

	if (j == 0 && i == ord2.m_Size)
	{
		cout << "当前没有您需要审核的记录" << endl;
		return;
	}
	cout << endl;
	cout << "请输入您想要审核的记录编号" << endl;
	cin >> select;
	while (!(select>0&&select<j+1))
	{
		cout << "输入错误，请重新输入" << endl;
		cin >> select;
	}
	cout << "请输入您的选择：" << endl;
	cout << "1、通过" << endl;
	cout << "2、不通过" << endl;
	cin >> pass;
	while (!(pass == 1||pass == 2))
	{
		cout << "输入错误，请重新输入" << endl;
		cin >> pass;
	}
	if (pass == 1)
	{
		ord2.m_Orderdata[m[select]]["status"] = '2';
		cout << "审核完毕" << endl;
		ord2.updateorder();
	}
	if (pass ==2)
	{
		ord2.m_Orderdata[m[select]]["status"] = '0';
		cout << "审核完毕" << endl;
		ord2.updateorder();
	}
	
}