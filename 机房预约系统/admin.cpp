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
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.查看机房" << endl;
	cout << "4.清空预约" << endl;
	cout << "5.查看所有预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "*************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "请输入你的选择：" << endl;
}

void Admin::Addnumber()
{
	int a=0;
	ofstream ofs;
	string num1, name1, code1;
	cout << "请选择以下编号进行添加账号" << endl;
	cout << "1、添加学生账号" << endl;
	cout << "2、添加教师账号" << endl;
	cin >> a;
	while (!(a == 1 || a == 2))
	{
		cout << "输入错误，请重新输入" << endl;
		cin >> a;
	}

	if (a == 1)
	{
	
		ofs.open("stu.txt", ios::out | ios::app);
		cout << "请输入学号：" << endl;
		cin >> num1;
		cout << "请输入姓名：" << endl;
		cin >> name1;
		cout << "请输入密码：" << endl;
		cin >> code1;
		ofs << num1 << " " << name1 << " " << code1 << endl;
		cout << "添加学生账号完成" << endl;
		ofs.close();
	}
	if (a == 2)
	{
		ofs.open("teacher.txt", ios::out | ios::app);
		cout << "请输入职工号：" << endl;
		cin >> num1;
		cout << "请输入姓名：" << endl;
		cin >> name1;
		cout << "请输入密码：" << endl;
		cin >> code1;
		ofs << num1 << " " << name1 << " " << code1 << endl;
		cout << "添加教师账号完成" << endl;
		ofs.close();
	}

}


void Admin::shownumber()
{
	ifstream ifs;
	int a = 0;
	cout << "请选择以下编号进行查看账号" << endl;
	cout << "1、查看学生账号" << endl;
	cout << "2、查看教师账号" << endl;
	cin >> a;
	while (!(a == 1 || a == 2))
	{
		cout << "输入错误，请重新输入" << endl;
		cin >> a;
	}

	if (a == 1)
	{
		string numstu, namestu, codestu;
		cout << "学生账号信息如下所示" << endl;
		ifs.open("stu.txt", ios::in);
		if (ifs.is_open() != true)
		{
			cout << "文件打开失败！" << endl;
			return;
		}
		while (ifs >> numstu && ifs >> namestu && ifs >> codestu)
		{
			cout << "学号：" << numstu << " " << "姓名：" << namestu << " " << "密码：" << codestu << endl;
		}
		ifs.close();
	}
	if (a == 2)
	{
		string numteacher, nameteacher, codeteacher;
		cout << "教师账号信息如下所示" << endl;
		ifs.open("teacher.txt", ios::in);
		if (ifs.is_open() != true)
		{
			cout << "文件打开失败！" << endl;
			return;
		}
		while (ifs >> numteacher && ifs >> nameteacher && ifs >> codeteacher)
		{
			cout << "职工号：" << numteacher << " " << "姓名：" << nameteacher << " " << "密码：" << codeteacher << endl;
		}
		ifs.close();
	}



}


void Admin::showcomputerroom()
{

	string id,nummax;
	ifstream ifs;
	cout << "机房信息如下所示" << endl;
	ifs.open("computerroom.txt", ios::in);
	if (ifs.is_open() != true)
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	while (ifs >> id && ifs >> nummax)
	{
		cout << "机房编号：" << id<< " " << "机房容量：" << nummax << endl;
	}
	ifs.close();

}


void Admin::clearorder()
{
	ofstream ofs;
	ofs.open("order.txt", ios::out | ios::trunc);
	ofs.close();
	cout << "预约记录已清空" << endl;
}

void Admin::showallorder()
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