#include "system.h"
extern int flag;
string numstu, namestu, codestu;
void System::mainmenu()
{
	
	cout << "*************************************" << endl;
	cout << "1.学生" << endl;
	cout << "2.教师" << endl;
	cout << "3.管理员" << endl;
	cout << "0.退出" << endl;
	cout << "*************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "请输入你的选择：" << endl;
	
	
	
		
}

void System::stusystem()
{
	int flagstu = 5;
	Student s(numstu,namestu,codestu); 
	s.Stumenu();
	cin >> flagstu;
	if (flagstu == 1)
	{
		s.applyorder();
		system("pause");
	}
	else if (flagstu == 2)
	{
		s.showownorder();
		system("pause");
	}
	else if (flagstu == 3)
	{
		s.showallorder();
		system("pause");
	}

	else if (flagstu == 4)
	{
		s.cancelorder();
		system("pause");
	}


	else if (flagstu == 0)
	{
		flag = 5;
		system("pause");
	}
	else
	{
		cout << "输入错误，请重新输入" << endl;
		system("pause");
		system("cls");
		s.Stumenu();
	}
	
}

void System::teachersystem()
{
	int flagteacher = 5;
	Teacher t;
	t.teachermenu();
	cin >> flagteacher;
	if (flagteacher == 1)
	{
		t.showallorder();
		system("pause");
	}
	else if (flagteacher == 2)
	{
		t.verifyorder();
		system("pause");
	}
	else if (flagteacher == 0)
	{
		flag = 5;
		system("pause");
	}
	else
	{
		cout << "输入错误，请重新输入" << endl;
		system("pause");
		system("cls");
		t.teachermenu();
	}

}

void System::adminsystem()
{
	int flagadmin=5;
	Admin a;
	a.Adminmenu();
	cin >> flagadmin;
	if (flagadmin == 1)
	{
		a.Addnumber();
		system("pause");
	}
	else if (flagadmin == 2)
	{
		a.shownumber();
		system("pause");
	}
	else if (flagadmin == 3)
	{
		a.showcomputerroom();
		system("pause");
	}

	else if (flagadmin == 4)
	{
		a.clearorder();
		system("pause");
	}
	else if (flagadmin == 5)
	{
		a.showallorder();
		system("pause");
	}

	else if (flagadmin == 0)
	{
		flag = 5;
		system("pause");
	}
	else
	{
		cout << "输入错误，请重新输入" << endl;
		system("pause");
		system("cls");
		a.Adminmenu();
	}
}


bool System::load(string file,int a)
{
	ifstream ifs;
	string num1, name1, code1;
	ifs.open(file, ios::in);
	if (ifs.is_open() != true)
	{
		cout << "文件打开失败！" << endl;
		return 0;
	}
	if (a == 1)
	{
		
		cout << "请输入学号：" << endl;
		cin >> num1;
		cout << "请输入姓名：" << endl;
		cin >> name1;
		cout << "请输入密码：" << endl;
		cin >> code1;
		while (ifs >> numstu && ifs >> namestu && ifs >> codestu)
		{
			//cout << numstu << " " << namestu << " " << codestu << endl;
			if (numstu == num1 && namestu == name1 && codestu == code1)
			{
				cout << "学生身份验证成功"<<endl;
				system("pause");
				return 1;
			}

		}
	}
	if (a==2)
	{
		string numteacher, nameteacher, codeteacher;
		cout << "请输入职工号：" << endl;
		cin >> num1;
		cout << "请输入姓名：" << endl;
		cin >> name1;
		cout << "请输入密码：" << endl;
		cin >> code1;
		while (ifs >> numteacher && ifs >> nameteacher && ifs >> codeteacher)
		{
			//cout << numteacher << " " << nameteacher << " " << codeteacher << endl;
			if (numteacher == num1 && nameteacher == name1 && codeteacher == code1)
			{
				cout << "教师身份验证成功" << endl;
				system("pause");
				return 1;
			}

		}
	}
	if (a == 3)
	{
		string nameadmin, codeadmin;
		cout << "请输入姓名：" << endl;
		cin >> name1;
		cout << "请输入密码：" << endl;
		cin >> code1;
		while (ifs >> nameadmin && ifs >> codeadmin)
		{
			//cout << nameadmin << " " << codeadmin << endl;
			if (nameadmin == name1 && codeadmin == code1)
			{
				cout << "管理员身份验证成功" << endl;
				system("pause");
				return 1;
			}

		}
	}

	cout << "身份验证失败" << endl;
	system("pause");
	return 0;


}


void System::createfile()
{
	ofstream ofs;
	ofs.open("stu.txt", ios::out|ios::app);
	ofs.close();
	ofs.open("teacher.txt", ios::out|ios::app);
	ofs.close();
	ofs.open("admin.txt", ios::out| ios::app);
	ofs.close();
	ofs.open("computerroom.txt", ios::out | ios::trunc);
	ofs << "1 20" << endl;
	ofs << "2 50" << endl;
	ofs << "3 100" << endl;
	ofs.close();
	ofs.open("order.txt", ios::out| ios::app);
	ofs.close();

}