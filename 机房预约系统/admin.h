#pragma once
#include<iostream>
#include "computerroom.h"
#include "orderfile.h"
using namespace std;


class Admin
{
public:
	string m_Name, m_Code;//ĞÕÃû,µÇÂ¼ÃÜÂë
	Admin();
	Admin(string name, string code);
	void Adminmenu();
	void Addnumber();
	void shownumber();
	void showcomputerroom();
	void clearorder();
	void showallorder();



};