#include"AccountBookManager.h"
#include"SystemTime.h"
#define FILENAME "./txts/AccountBook.txt"
//输出收入
void myPrintIn(const Account& ac)
{
	if (ac.getInorOut())cout << ac;
}
//输出支出
void myPrintOut(const Account& ac)
{
	if (!ac.getInorOut())cout << ac;
}
//构造函数
AccountBookManager::AccountBookManager():inSum(0),outSum(0){
	//初始化文件
	system("cls");
	cout << "正在初始化……\n";
	Sleep(1000);
	cout << "正在读取文件……\n";
	Sleep(1000);
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int year, month, day;
	double money;
	bool InorOut;
	if (!ifs.is_open())
	{
		printf("文件未创建！\n");
		ifs.close();
		Sleep(1000);
		system("cls");
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		printf("文件为空！\n");
		ifs.close();
		Sleep(1000);
		system("cls");
		return;
	}
	ifs.putback(ch);
	while (ifs >> year && ifs >> month && ifs >> day && ifs >> money && ifs >> InorOut)
	{
		Account ac(year, month, day, money, InorOut);
		accountArray.insert(ac);
		if (InorOut)inSum += money;
		else outSum += money;
	}
	ifs.close();
	cout << "初始化成功！";
	Sleep(1000);
}
//操作选择界面
void AccountBookManager::operator()()
{
	int choice;

	while (1)
	{
		MenuManager(1)();
		while ((choice = cinCheck<int>(3, 6)) == 0)continue;
		system("cls");
		switch (choice)
		{
		case 1:write(); break;
		case 2:show(); break;
		case 3:searchByDate(); break;
		case 4:searchByYear(); break;
		case 5:delete_(); break;
		case 6:goto flag; break;//保证以后少用goto，老师原谅我~
		default:break;
		}
		Pause_and_Cls();
	}
flag:
	system("cls");
	return;
}

//写入功能实现
void AccountBookManager::write()
{

	string dateInput;
	double money;
	cout << "请输入想要记录的类型：\n";
	cout << "1、支出 2、收入：\n";

	int choice;
	if ((choice = cinCheck<int>(1, 2)) == 0)return;//输入操作，检验合法性
	if (choice == 1)
	{
		cout << "请输入支出的日期：（年/月/日）\n";
		while (cin >> dateInput && !cinCheck<bool>(4, 0, dateInput))cout << "格式错误，请重新输入！\n";//检验合法性
		cout << "请输入支出金额：\n";
		if ((money = cinCheck<double>(2)) == 0)return;
		if (!accountRegister(dateInput, money, choice))//检验合法性
		{
			cout << "日期不合法，正在返回主界面\n";
			return;
			Sleep(1000);
		}
	}
	if (choice == 2)
	{

		cout << "请输入获得收入的日期：（年/月/日）\n";
		while (cin >> dateInput && !cinCheck<bool>(4, 0, dateInput))cout<<"格式错误！请重新输入！\n";
		cout << "请输入收入金额：\n";
		if ((money = cinCheck<double>(2)) == 0)return;
		if (!accountRegister(dateInput, money, choice))
		{
			cout << "日期不合法，正在返回主界面\n";
			Sleep(1000);
			return;
		}
	}

	cout << "添加成功！\n";
}
//显示功能实现
void AccountBookManager::show()
{
	if (isEmpty())return;
	cout << "1、显示支出" << endl;
	cout << "2、显示收入" << endl;
	cout << "3、显示全部" << endl;
	int choice;
	if ((choice = cinCheck<int>(1, 3)) == 0)return;
	system("cls");
	switch (choice)
	{
	case 1:
	{
		cout << endl << "总支出：" << outSum << endl << endl;
		for_each(accountArray.begin(), accountArray.end(), myPrintOut);
		break;
	}
	case 2:
	{
		cout << endl << "总收入：" << inSum << endl << endl;
		for_each(accountArray.begin(), accountArray.end(), myPrintIn);
		break;
	}
	case 3:
	{
		cout << endl << "总收入：" << inSum << " 总支出：" << outSum << endl << endl;
		for_each(accountArray.begin(), accountArray.end(), MyPrint<Account>);
		break;
	}
	default:cout << "输入无效！" << endl; break;
	}
}

//通过起始终止时间查询
void AccountBookManager::searchByDate()
{
	if (isEmpty())return;//没有账单直接返回
	int Year_Month_Date1[3], Year_Month_Date2[3];
	string s1, s2;
	cout << "请输入起始查询日期：(年/月/日)\n";
	while (cin >> s1 && !cinCheck<bool>(4, 0, s1))cout << "格式错误，请重新输入！\n";
	cout << "请输入结束查询日期：(年/月/日)\n";
	while (cin >> s2 && !cinCheck<bool>(4, 0, s2))cout << "格式错误，请重新输入！\n";

	if (!transform(s1, Year_Month_Date1) || !transform(s2, Year_Month_Date2))//转换失败
	{
		cout << "日期不合法，正在返回主界面！\n";
		Sleep(1000);
		return;
	}
	search(Year_Month_Date1, Year_Month_Date2);
}


//通过年份查询
void AccountBookManager::searchByYear()
{
	cout << "请输入需要查询的年份：\n";
	string yearToSearch;
	int Year_Month_Date1[3], Year_Month_Date2[3];
	while (cin >> yearToSearch && !cinCheck<bool>(4, 0, yearToSearch + "/1/1"))cout << "格式错误，请重新输入！\n";
	transform(yearToSearch + "/1/1", Year_Month_Date1);
	Year_Month_Date2[0] = Year_Month_Date1[0] + 1;
	Year_Month_Date2[1] = 1;
	Year_Month_Date2[2] = 1;
	search(Year_Month_Date1, Year_Month_Date2);
}


//两种查询方法的查询过程
void AccountBookManager::search(int* Year_Month_Date1, int* Year_Month_Date2)
{
	const Account ac1(Year_Month_Date1[0], Year_Month_Date1[1], Year_Month_Date1[2], 0, 0);
	const Account ac2(Year_Month_Date2[0], Year_Month_Date2[1], Year_Month_Date2[2], 0, 0);
	//判断结束查询日期是否早于起始查询日期
	if (ac2 < ac1)
	{
		cout << "结束查询日期早于起始查询日期！查询失败！\n";
		return;
	}

	//以下为查询过程
	multiset<Account>::iterator front = accountArray.end();
	multiset<Account>::iterator back = accountArray.begin();
	for (multiset<Account>::iterator it = accountArray.begin(); it != accountArray.end(); it++)
	{
		if (*it < ac1)continue;
		front = it;
		break;
	}
	multiset<Account>::iterator end = accountArray.end();
	multiset<Account>::iterator begin = accountArray.begin();
	end--;
	begin--;
	for (multiset<Account>::iterator it = end; it != begin; it--)
	{
		if (ac2 < *it)continue;
		it++;
		back = it;
		break;
	}
	if (front == back)
	{
		cout << "未查询到相应账单！\n";
		return;
	}

	//统计总收入支出金额
	double InSum = 0, OutSum = 0;
	for (multiset<Account>::iterator it = front; it != back; it++)
	{
		if ((*it).getInorOut())InSum += (*it).getMoney();
		else OutSum += (*it).getMoney();
	}
	cout << endl << "总收入：" << InSum << "总支出：" << OutSum << endl << endl;
	for_each(front, back, MyPrint<Account>);//打印输出
}
//将string类型年份转换为int数组并判断是否转换成功
bool AccountBookManager::transform(string YMD,int *Y_M_D)
{
	int size =(int) YMD.size();
	string temp;
	int pos = 0, count = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (YMD[i] == '/')
		{
			temp = YMD.substr(pos, i - pos);
			pos = i + 1;
			stringstream ss;
			ss << temp;
			ss >> Y_M_D[count++];
		}
	}
	temp = YMD.substr(pos);
	stringstream ss;
	ss << temp;
	ss >> Y_M_D[count];

	//输入的收入或支出时间必须早于现在时间
	SystemTime::getSystemTime();//获取系统时间
	if (Y_M_D[0] > SystemTime::getYear())return false;
	if ((Y_M_D[0] == SystemTime::getYear()) && (Y_M_D[1] > SystemTime::getMonth()))return false;
	if ((Y_M_D[0] == SystemTime::getYear()) && (Y_M_D[1] == SystemTime::getMonth()) && (Y_M_D[2] > SystemTime::getDay()))return false;
	//判断输入日期是否合法，如避免2023/13/32被输入
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((Y_M_D[0] % 4 == 0 && Y_M_D[0] % 100 != 0) || (Y_M_D[0] % 400 == 0)) {//如果是闰年
		month[1] = 29;
		if (Y_M_D[2] > 0 && Y_M_D[2] <= month[Y_M_D[1] - 1] && Y_M_D[1] > 0 && Y_M_D[1] <= 12) return true;
		else return false;
	}
	else {
		if (0 < Y_M_D[2] && Y_M_D[2] <= month[Y_M_D[1] - 1] && 0 < Y_M_D[1] && 12 >= Y_M_D[1]) return true;
		else return false;
	}
}
//创建一条账单并保存
bool AccountBookManager::accountRegister(string &s,double &money,int &choice)
{
	int year_month_date[3];
	if (!transform(s, year_month_date))return false;
	const Account ac(year_month_date[0], year_month_date[1], year_month_date[2], money,(bool)(choice-1));
	if ((choice - 1) == 0)outSum += money;
	else inSum += money;
	accountArray.insert(ac);
	ofstream ofs;
	ofs.open(FILENAME, ios::app);
	ofs << ac;
	ofs.close();
	return true;
}

//删除某账单
void AccountBookManager::delete_()
{
	if (isEmpty())return;
	cout << endl << "总收入：" << inSum << " 总支出：" << outSum << endl << endl;
	int i = 0;
	for (multiset<Account>::iterator it= accountArray.begin(); it != accountArray.end(); it++)
	{
		i++;
		cout << i << " " << (*it);
	}
	cout << "请问你想要删除哪条收入或支出记录？(按0取消删除）\n";
	int num;
	if ((num = cinCheck<int>(6, i)) == 0)return;
	int j = 0;
	for (multiset<Account>::iterator it = accountArray.begin(); it != accountArray.end(); it++)
	{
		j++;
		if (j == num)
		{
			if ((*it).getInorOut())inSum -= (*it).getMoney();
			else outSum -= (*it).getMoney();
			accountArray.erase(it);
			break;
		}
	}
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (multiset<Account>::iterator it = accountArray.begin(); it != accountArray.end(); it++)
	{
		ofs << (*it);
	}
	ofs.close();
	cout << "删除成功！" << endl;
}


//判断账单是否为空
bool AccountBookManager::isEmpty()
{
	if (accountArray.empty())
	{
		cout << "当前记录为空，请先录入收支记录！\n";
		return true;
	}
	return false;
}
