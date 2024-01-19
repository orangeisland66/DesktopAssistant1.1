#include"AccountBookManager.h"
#include"SystemTime.h"
#define FILENAME "./txts/AccountBook.txt"
//�������
void myPrintIn(const Account& ac)
{
	if (ac.getInorOut())cout << ac;
}
//���֧��
void myPrintOut(const Account& ac)
{
	if (!ac.getInorOut())cout << ac;
}
//���캯��
AccountBookManager::AccountBookManager():inSum(0),outSum(0){
	//��ʼ���ļ�
	system("cls");
	cout << "���ڳ�ʼ������\n";
	Sleep(1000);
	cout << "���ڶ�ȡ�ļ�����\n";
	Sleep(1000);
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int year, month, day;
	double money;
	bool InorOut;
	if (!ifs.is_open())
	{
		printf("�ļ�δ������\n");
		ifs.close();
		Sleep(1000);
		system("cls");
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		printf("�ļ�Ϊ�գ�\n");
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
	cout << "��ʼ���ɹ���";
	Sleep(1000);
}
//����ѡ�����
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
		case 6:goto flag; break;//��֤�Ժ�����goto����ʦԭ����~
		default:break;
		}
		Pause_and_Cls();
	}
flag:
	system("cls");
	return;
}

//д�빦��ʵ��
void AccountBookManager::write()
{

	string dateInput;
	double money;
	cout << "��������Ҫ��¼�����ͣ�\n";
	cout << "1��֧�� 2�����룺\n";

	int choice;
	if ((choice = cinCheck<int>(1, 2)) == 0)return;//�������������Ϸ���
	if (choice == 1)
	{
		cout << "������֧�������ڣ�����/��/�գ�\n";
		while (cin >> dateInput && !cinCheck<bool>(4, 0, dateInput))cout << "��ʽ�������������룡\n";//����Ϸ���
		cout << "������֧����\n";
		if ((money = cinCheck<double>(2)) == 0)return;
		if (!accountRegister(dateInput, money, choice))//����Ϸ���
		{
			cout << "���ڲ��Ϸ������ڷ���������\n";
			return;
			Sleep(1000);
		}
	}
	if (choice == 2)
	{

		cout << "����������������ڣ�����/��/�գ�\n";
		while (cin >> dateInput && !cinCheck<bool>(4, 0, dateInput))cout<<"��ʽ�������������룡\n";
		cout << "�����������\n";
		if ((money = cinCheck<double>(2)) == 0)return;
		if (!accountRegister(dateInput, money, choice))
		{
			cout << "���ڲ��Ϸ������ڷ���������\n";
			Sleep(1000);
			return;
		}
	}

	cout << "��ӳɹ���\n";
}
//��ʾ����ʵ��
void AccountBookManager::show()
{
	if (isEmpty())return;
	cout << "1����ʾ֧��" << endl;
	cout << "2����ʾ����" << endl;
	cout << "3����ʾȫ��" << endl;
	int choice;
	if ((choice = cinCheck<int>(1, 3)) == 0)return;
	system("cls");
	switch (choice)
	{
	case 1:
	{
		cout << endl << "��֧����" << outSum << endl << endl;
		for_each(accountArray.begin(), accountArray.end(), myPrintOut);
		break;
	}
	case 2:
	{
		cout << endl << "�����룺" << inSum << endl << endl;
		for_each(accountArray.begin(), accountArray.end(), myPrintIn);
		break;
	}
	case 3:
	{
		cout << endl << "�����룺" << inSum << " ��֧����" << outSum << endl << endl;
		for_each(accountArray.begin(), accountArray.end(), MyPrint<Account>);
		break;
	}
	default:cout << "������Ч��" << endl; break;
	}
}

//ͨ����ʼ��ֹʱ���ѯ
void AccountBookManager::searchByDate()
{
	if (isEmpty())return;//û���˵�ֱ�ӷ���
	int Year_Month_Date1[3], Year_Month_Date2[3];
	string s1, s2;
	cout << "��������ʼ��ѯ���ڣ�(��/��/��)\n";
	while (cin >> s1 && !cinCheck<bool>(4, 0, s1))cout << "��ʽ�������������룡\n";
	cout << "�����������ѯ���ڣ�(��/��/��)\n";
	while (cin >> s2 && !cinCheck<bool>(4, 0, s2))cout << "��ʽ�������������룡\n";

	if (!transform(s1, Year_Month_Date1) || !transform(s2, Year_Month_Date2))//ת��ʧ��
	{
		cout << "���ڲ��Ϸ������ڷ��������棡\n";
		Sleep(1000);
		return;
	}
	search(Year_Month_Date1, Year_Month_Date2);
}


//ͨ����ݲ�ѯ
void AccountBookManager::searchByYear()
{
	cout << "��������Ҫ��ѯ����ݣ�\n";
	string yearToSearch;
	int Year_Month_Date1[3], Year_Month_Date2[3];
	while (cin >> yearToSearch && !cinCheck<bool>(4, 0, yearToSearch + "/1/1"))cout << "��ʽ�������������룡\n";
	transform(yearToSearch + "/1/1", Year_Month_Date1);
	Year_Month_Date2[0] = Year_Month_Date1[0] + 1;
	Year_Month_Date2[1] = 1;
	Year_Month_Date2[2] = 1;
	search(Year_Month_Date1, Year_Month_Date2);
}


//���ֲ�ѯ�����Ĳ�ѯ����
void AccountBookManager::search(int* Year_Month_Date1, int* Year_Month_Date2)
{
	const Account ac1(Year_Month_Date1[0], Year_Month_Date1[1], Year_Month_Date1[2], 0, 0);
	const Account ac2(Year_Month_Date2[0], Year_Month_Date2[1], Year_Month_Date2[2], 0, 0);
	//�жϽ�����ѯ�����Ƿ�������ʼ��ѯ����
	if (ac2 < ac1)
	{
		cout << "������ѯ����������ʼ��ѯ���ڣ���ѯʧ�ܣ�\n";
		return;
	}

	//����Ϊ��ѯ����
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
		cout << "δ��ѯ����Ӧ�˵���\n";
		return;
	}

	//ͳ��������֧�����
	double InSum = 0, OutSum = 0;
	for (multiset<Account>::iterator it = front; it != back; it++)
	{
		if ((*it).getInorOut())InSum += (*it).getMoney();
		else OutSum += (*it).getMoney();
	}
	cout << endl << "�����룺" << InSum << "��֧����" << OutSum << endl << endl;
	for_each(front, back, MyPrint<Account>);//��ӡ���
}
//��string�������ת��Ϊint���鲢�ж��Ƿ�ת���ɹ�
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

	//����������֧��ʱ�������������ʱ��
	SystemTime::getSystemTime();//��ȡϵͳʱ��
	if (Y_M_D[0] > SystemTime::getYear())return false;
	if ((Y_M_D[0] == SystemTime::getYear()) && (Y_M_D[1] > SystemTime::getMonth()))return false;
	if ((Y_M_D[0] == SystemTime::getYear()) && (Y_M_D[1] == SystemTime::getMonth()) && (Y_M_D[2] > SystemTime::getDay()))return false;
	//�ж����������Ƿ�Ϸ��������2023/13/32������
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((Y_M_D[0] % 4 == 0 && Y_M_D[0] % 100 != 0) || (Y_M_D[0] % 400 == 0)) {//���������
		month[1] = 29;
		if (Y_M_D[2] > 0 && Y_M_D[2] <= month[Y_M_D[1] - 1] && Y_M_D[1] > 0 && Y_M_D[1] <= 12) return true;
		else return false;
	}
	else {
		if (0 < Y_M_D[2] && Y_M_D[2] <= month[Y_M_D[1] - 1] && 0 < Y_M_D[1] && 12 >= Y_M_D[1]) return true;
		else return false;
	}
}
//����һ���˵�������
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

//ɾ��ĳ�˵�
void AccountBookManager::delete_()
{
	if (isEmpty())return;
	cout << endl << "�����룺" << inSum << " ��֧����" << outSum << endl << endl;
	int i = 0;
	for (multiset<Account>::iterator it= accountArray.begin(); it != accountArray.end(); it++)
	{
		i++;
		cout << i << " " << (*it);
	}
	cout << "��������Ҫɾ�����������֧����¼��(��0ȡ��ɾ����\n";
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
	cout << "ɾ���ɹ���" << endl;
}


//�ж��˵��Ƿ�Ϊ��
bool AccountBookManager::isEmpty()
{
	if (accountArray.empty())
	{
		cout << "��ǰ��¼Ϊ�գ�����¼����֧��¼��\n";
		return true;
	}
	return false;
}
