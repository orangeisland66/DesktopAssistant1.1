#include"Account.h"
//构造函数
Account::Account(int year, int month, int day,double money, bool IO):
	year(year),month(month),day(day),money(money),InorOut(IO){}
//文件输出函数
void Account::print(ofstream &ofs)const
{
	ofs << year << " " << month << " " << day << " ";
	if (InorOut)ofs << " " << money << " " <<InorOut<< endl;
	else ofs << " " << money << " " << InorOut << endl;
}
//打印输出函数
void Account::print()const
{
	cout << year << "年" << month << "月" << day << "日：";
	if (InorOut)cout << "收入" << money << "元" << endl;
	else cout << "支出" << money << "元" << endl;
}
//重载左移运算符
ostream& operator<<(ostream& cout, const Account& ac)
{
	ac.print();
	return cout;
}
//重载左移运算符
ofstream& operator<<(ofstream& ofs, const Account& ac)
{
	ac.print(ofs);
	return ofs;
}

bool  operator<(const Account& ac1, const Account& ac2)
{
	if (ac1.year < ac2.year)return true;
	if (ac1.year == ac2.year && ac1.month < ac2.month)return true;
	if (ac1.year == ac2.year && ac1.month == ac2.month && ac1.day < ac2.day)return true;
	return false;
}

bool Account::getInorOut()const { return InorOut; };

double Account::getMoney()const{ return money; }