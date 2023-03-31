#include "student.h"



Student::Student(string num, string name, string code)
{
	m_Num = num;
	m_Name = name;
	m_Code = code;

}


Student::Student()
{





}



void Student::Stumenu()
{
	cout << "*************************************" << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看自身的预约" << endl;
	cout << "3.查看所有预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "*************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "请输入你的选择：" << endl;


}

void Student::applyorder()//申请预约
{
	int data = 0;//预约日期1-5分别为周一到周五
	int interval = 0;//时间段1代表上午，2代表下午
	int roomid = 0;//机房号
	int status = 1;//0代表审核不通过，1代表审核中，2代表审核成功，-1代表取消预约
	int roomid1 = 0;//读出的机房号
	int nummax = 0;//读出的机房容量

	cout << "预约的时间段为周一到周五" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	cout << "请选择预约的日期：" << endl;
	cin >> data;
	while (data < 1 || data>5)
	{
		cout << "输入错误，请重新输入!" << endl;
		cin >> data;
	}
	cout << "预约的时间段为上午或者下午" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	cout << "请输入预约的时间段：" << endl;

	cin >> interval;
	while (interval <  1 || interval > 2)
	{
		cout << "输入错误，请重新输入!" << endl;
		cin >> interval;
	}
	vector<Computerroom> v;
	ifstream ifs;
	ifs.open("computerroom.txt", ios::in);
	if (ifs.is_open() != true)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	while (ifs >> roomid1 && ifs >> nummax)
	{
		Computerroom c(roomid1, nummax);
		v.push_back(c);
	}
	ifs.close();
	cout << "可预约机房号为机房1到机房3" << endl;
	cout << "1.机房一的容量为：" << v[0].m_Nummax << endl;
	cout << "2.机房二的容量为：" << v[1].m_Nummax << endl;
	cout << "3.机房三的容量为：" << v[2].m_Nummax << endl;
	cout << "请输入要预约的机房号：" << endl;
	cin >> roomid;
	while (roomid<1||roomid>3)
	{
		cout << "输入错误，请重新输入!" << endl;
		cin >> roomid;
	}

	ofstream ofs;
	ofs.open("order.txt", ios::out | ios::app);
	ofs << "data:" << data << " " << "interval:" << interval << " " << "m_Num:" << m_Num << " " << "m_Name:" << m_Name << " " << "roomid:" << roomid << " " << "status:" << status << endl;
	ofs.close();
	cout << "预约成功，请等待审核！" << endl;

}
void Student::showownorder()//查看自己的预约
{
	Orderfile ord;
	int i = 0, j = 0;
	//以下这行必须写在for循环的外面，因为写在里面每次都会初始化，这样输出的一直是第一行的内容
	//map<int, map<string, string>>::iterator it = ord.m_Orderdata.begin();//第一种方式查找value
	cout << "您的预约如下所示" << endl;
	for (i = 0; i < ord.m_Size; i++)
	{

		//map<string, string>::iterator it1 = it->second.begin();//第一种方式查找value
		if (m_Num == ord.m_Orderdata[i]["m_Num"])//第二种方式，通过[]查找map<int, map<string, string>>中的map<string,string>中的value
		{

			//	//第一种方法
			//	cout << j + 1 << "、";
			//	cout << "预约日期：周" << (it1++)->second<<" ";
			//	if ((it1++)->second == "1")
			//	{
			//		cout << "时间段：上午" << " ";
			//	}
			//	else
			//		cout << "时间段：下午" << " ";
			//	cout << "学号：" << (it1++)->second << " ";
			//	cout << "姓名：" << (it1++)->second << " ";
			//	cout << "机房号：" << (it1++)->second << " ";
			//	if ((it1)->second == "-1")
			//	{
			//		cout << "状态：预约取消" << endl;
			//	}
			//	if (it1->second == "0")
			//	{
			//		cout << "状态：审核不通过" << endl;
			//	}
			//	if (it1->second == "1")
			//	{
			//		cout << "状态：审核中" << endl;
			//	}
			//	if (it1->second == "2")
			//	{
			//		cout << "状态：预约成功" << endl;
			//	}

				//第二种方法
			cout << j + 1 << "、";
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

			j++;
		}
		//it++;


	}
	if (j == 0 && i == ord.m_Size)
	{
		cout << "当前没有您的预约记录" << endl;
	}

}



void Student::showallorder()//查看所有的预约
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


void Student::cancelorder()//取消预约
{
	Orderfile ord1;
	int i = 0, j = 0;
	int cancel = -5;
	map<int, int> m;
	
	cout << "您可取消的预约如下所示：" << endl;
	for (i = 0; i < ord1.m_Size; i++)
	{
		if (m_Num == ord1.m_Orderdata[i]["m_Num"] && (ord1.m_Orderdata[i]["status"] == "1" || ord1.m_Orderdata[i]["status"] == "2"))
		{
			cout << j + 1 << "、";
			cout << "预约日期：周" << ord1.m_Orderdata[i]["data"] << " ";
			if (ord1.m_Orderdata[i]["interval"] == "1")
			{
				cout << "时间段：上午" << " ";
			}
			else
				cout << "时间段：下午" << " ";
			cout << "学号：" << ord1.m_Orderdata[i]["m_Num"] << " ";
			cout << "姓名：" << ord1.m_Orderdata[i]["m_Name"] << " ";
			cout << "机房号：" << ord1.m_Orderdata[i]["roomid"] << " ";
			if (ord1.m_Orderdata[i]["status"] == "-1")
			{
				cout << "状态：预约取消" << endl;
			}
			if (ord1.m_Orderdata[i]["status"] == "0")
			{
				cout << "状态：审核不通过" << endl;
			}
			if (ord1.m_Orderdata[i]["status"] == "1")
			{
				cout << "状态：审核中" << endl;
			}
			if (ord1.m_Orderdata[i]["status"] == "2")
			{
				cout << "状态：预约成功" << endl;
			}
			m.insert(make_pair(j + 1, i));
			j++;
		}


	}

	if (j == 0 && i == ord1.m_Size)
	{
		cout << "当前没有您的预约记录" << endl;
	}
	cout << endl;
	cout << "请选择您要取消的预约编号，按0可以返回：" << endl;
	cout << "请输入您的选择：" << endl;
	cin >> cancel;
	while (cancel<0 || cancel>j+1)
	{
		cout << "输入错误，请重新输入！";
	    cin >> cancel;

	}
	if (cancel == 0)
	{
		return;
	}
	else
	{
		ord1.m_Orderdata[m[cancel]]["status"] = "-1";
		cout << "已取消预约" << endl;
	}
	ord1.updateorder();

}