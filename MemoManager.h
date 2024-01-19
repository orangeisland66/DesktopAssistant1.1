#pragma once
#include"header.h"
#include"PushButton.h"
#include"Subject.h"
#include"MyWindow.h"
#include"SystemTime.h"
#include"Deadline.h"

//备忘录管理类，没有注释的函数函数名与功能基本对应
class MemoManager
{
public:
	MemoManager();
	void operator()();
	void fileInit();
	bool transform1(string YMD,int *Y_M_D);			//将string类型的日期转化成年月日数组存储
	string transform2(vector<int>& v);				//将时间转化为字符串便于输出至屏幕
	int schedulePage();
	void reminder_and_ddlShow();
	int selectMenu(int i);
	void show_btns(vector<PushButton>& v);
	int addSubject();
	int deleteSubject(int i);
	int add_ddl(int i);
	int delete_ddl(int i);
	int addReminder(int i);
	int deleteReminder(int i);
	bool isEsc();									//按下返回键
	void setPos(vector<PushButton>& v);				//设置按钮位置
	void drawBackground(int mode);
	int menueventLoop(vector<PushButton> &v);		//事件循环
	int showSubjectInfo(int i);
	void sortAndBtnsPushBack();						//根据一周的时间顺序给科目排序，便于后续操作与计算
	int calculateDay(int year, int month, int day);	//计算天数之差
	void save();
	void showEsc();
	~MemoManager();
 private:
	vector<PushButton>menu_btns;
	vector<PushButton>schedule_btns;
	vector<PushButton>select_btns;
	vector<Subject>subjectArray;
	ExMessage msg;
	IMAGE *menu;
	IMAGE *schedule;
	vector<PushButton>addButton;

};

