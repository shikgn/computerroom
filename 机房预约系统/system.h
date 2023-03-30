#pragma once
#include<iostream>
#include<fstream>
#include "student.h"
#include "teacher.h"
#include "admin.h"
using namespace std;

class System
{
public:
	void mainmenu();
	void stusystem();
	void teachersystem();
	void adminsystem();
	bool load(string file,int a);
	void createfile();

};