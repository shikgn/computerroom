#include "orderfile.h"


Orderfile::Orderfile()
{
	string data;//预约日期1-5分别为周一到周五
	string interval;//时间段1代表上午，2代表下午
	string num;//学号
	string name;//姓名
	string roomid;//机房号
	string status;//-1代表取消预约，0代表审核不通过，1代表审核中，2代表审核成功

	ifstream ifs;
	ifs.open("order.txt", ios::in);
	if (ifs.is_open() != true)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	
	string key;
	string value;
	m_Size = 0;
	while (ifs >> data && ifs >> interval && ifs >> num && ifs >> name && ifs >> roomid && ifs >> status)
	{
		map<string, string> m;//一定要写在while循环的里面，否则最后验证的时候总是会出现读出来的第一行数据
		//以下这行代码是为了确认数据被提取出来
		//cout << data << " " << interval << " " << num << " " << name << " " << roomid << " " << status << " " << endl;
		int pos = data.find(":");
		if (pos != -1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos+1, data.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key =interval.substr(0, pos);
			value = interval.substr(pos+1, interval.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = num.find(":");
		if (pos != -1)
		{
			key = num.substr(0, pos);
			value = num.substr(pos+1, num.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = name.find(":");
		if (pos != -1)
		{
			key = name.substr(0, pos);
			value = name.substr(pos+1, name.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		pos = roomid.find(":");
		if (pos != -1)
		{
			key = roomid.substr(0, pos);
			value = roomid.substr(pos+1, roomid.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos+1, status.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		m_Orderdata.insert(make_pair(m_Size, m));
		m_Size++;
		
	}

	ifs.close();
	
	//以下代码是为了保证提取出的数据正确
	/*for (map<int, map<string, string>>::iterator it = m_orderdata.begin(); it != m_orderdata.end(); it++)
	{
		cout << "key:" << it->first << " " << endl;
		for (map<string, string>::iterator it1 = it->second.begin(); it1 != it->second.end(); it1++)
		{
			cout << it1->first <<" "<< it1->second << " ";
		}
		cout << endl;
	}*/
	

}


void Orderfile::updateorder()
{
	if (m_Size == 0)
	{
		cout << "无预约记录" << endl;
		return;
	}
	ofstream ofs;
	ofs.open("order.txt", ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "data:" << m_Orderdata[i]["data"] << " ";
		ofs << "interval:" << m_Orderdata[i]["interval"] << " ";
		ofs << "m_Num:" << m_Orderdata[i]["m_Num"] << " ";
		ofs << "m_Name:" << m_Orderdata[i]["m_Name"] << " ";
		ofs << "roomid:" << m_Orderdata[i]["roomid"] << " ";
		ofs << "status:" << m_Orderdata[i]["status"] << " "<<endl;

	}
	ofs.close();
}