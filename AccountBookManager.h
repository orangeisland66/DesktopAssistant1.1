#pragma once
#include"Account.h"

using namespace std;

//账单管理类，功能与函数名一致，不再赘述
class AccountBookManager
{
public:
	AccountBookManager();
	void write();
	void show();
	void search(int*, int*);
	void searchByDate();
	void searchByYear();
	bool accountRegister(string& s,double& money,int& choice);
	void operator()();
	bool transform(string YMD, int* Y_M_D);
	void delete_();
	bool isEmpty();

private:
	multiset<Account,MyCompare<Account>>accountArray;
	double inSum;
	double outSum;
};
void myPrintIn(const Account& ac);
void myPrintOut(const Account& ac);
