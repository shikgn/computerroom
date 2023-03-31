#pragma once
#include<iostream>
#include "orderfile.h"
#include "computerroom.h"
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class Student
{
public:
	
	Student();
    Student(string num, string name, string code);
	void Stumenu();//学生管理菜单
	void applyorder();//申请预约
	void showownorder();//查看自己的预约
	void showallorder();//查看所有的预约
	void cancelorder();//取消预约
	
	string m_Num ,m_Name, m_Code;//学号,姓名,登录密码
	
	
};

