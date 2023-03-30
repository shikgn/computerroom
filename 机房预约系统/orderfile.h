#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<string>
using namespace std;

class Orderfile
{
public:
	Orderfile();

	int m_Size;//预约的条数

	map<int, map<string, string>> m_Orderdata;

	void updateorder();
};