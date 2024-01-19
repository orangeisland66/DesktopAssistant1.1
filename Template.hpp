#pragma once
#include<iostream>
#include<string>
using namespace std;


//�Զ���ģ�庯��
//1������MyPrint������������<<��ʹ��ͬ�������ݿ������
template<typename T>
void MyPrint(const T& to_print)
{
	cout << to_print;
}

//2������MyCompare������������<��ʹ��ͬ������������֮����ԱȽ�
template<typename T>
class MyCompare
{
public:
	bool operator()(const T& t1, const T& t2)const
	{
		return t1 < t2;
	}
};


//3�����������⣬ʹ�ø��������ܹ��������Ϸ���
template<typename T>
T cinCheck(int mode,int range=0,string s=" ")
{
	if (mode == 1||mode==3)
	{
		int choice = 0;

		while (cin >> choice)
		{
			if (choice <= 0 || choice > range)
			{
				cin.clear();
				while (cin.get() != '\n')continue;
				cout << "������1~" << range << "֮���������" << endl;
				continue;
			}
			break;
		}
		if (cin.fail() && mode == 1)
		{
			cin.clear();
			while (cin.get() != '\n')continue;
			cout << "�����ʽ�������ڷ�����һ���棡\n";
			Sleep(1000);
		}
		else if (cin.fail() && mode == 3)
		{
			cin.clear();
			while (cin.get() != '\n')continue;
			cout << "������1~" << range << "֮���������" << endl;
		}
		else
		{
			cin.clear();
			while (cin.get() != '\n')choice=0;
			if (choice == 0)cout << "������1~" << range << "֮���������" << endl;
		}
		return choice;
	}
	if (mode == 2)
	{
		double money = 0;
		cin >> money;
		if (cin.fail())
		{
			cin.clear();
			while (cin.get() != '\n')continue;
			cout << "�����ʽ�������ڷ�����һ���棡\n";
			Sleep(1000);
		}
		return money;
	}
	if (mode == 4)
	{
		int num = 0;
		for (auto& e : s)
		{
			if (e == '/')num++;
			else if (e < '0' || e>'9')return false;
		}
		if (num == 2)
			return true;
		return false;
	}
	if (mode == 5)
	{
		int num = 0;
		for (auto& e : s)
		{
			if (e == ' ')num++;
		}
		if (num == 3)return true;
		return false;
	}
	if (mode == 6)
	{
		int choice = 0;

		while (cin >> choice)
		{
			if (choice < 0 || choice > range)
			{
				cin.clear();
				while (cin.get() != '\n')continue;
				cout << "������0~" << range << "֮���������" << endl;
				continue;
			}
			break;
		}
		if (cin.fail())
		{
			cin.clear();
			while (cin.get() != '\n')continue;
			cout << "�����ʽ�������ڷ�����һ���棡\n";
			Sleep(1000);
		}
		else if (choice == 0)
		{
			cout << "�Ѿ�ȡ��ɾ��������\n";
		}
		return choice;
	}
	return 0;
}
