#pragma once
#include<iostream>
#include "computerroom.h"
#include "orderfile.h"
using namespace std;


class Teacher
{
public:
	string m_Num, m_Name, m_Code;//ְ����,����,��¼����
	Teacher();
	Teacher(string num, string name, string code);
	void teachermenu();
	void showallorder();
	void verifyorder();


};