#pragma once
#include"header.h"
#include"PushButton.h"

//科目类
class Subject
{
public:
	Subject(string subjectName, string teacher, string string_weekday, string sections,bool have_dll=false,int year=0,int month=0,int day=0,bool have_reminder=false);
	friend bool  operator<(const Subject& ac1, const Subject& ac2);
	//以下为按钮基本设置
	int setButtonHeight();
	int setButtonWidth();
	int setButton_x();
	int setButton_y();
	//以下为课程基本设置与操作
	bool set_have_reminder(bool);
	void setHourAndMinute();
	void setweekday();
	bool set_ddl(int year,int month,int day);
	bool delete_ddl();
	friend ofstream& operator<<(ofstream&, const Subject&);
	void outtextInfo();
	bool is_ddl();
	bool is_reminder();
	//以下为获取课程信息
	int getStartHour();
	int getStartMinute();
	int getWeekday();
	int getYear();
	int getMonth();
	int getDay();
	string getSubjectName();
	PushButton getButn()const;
private:
	string subjectName;
	string teacher;
	string string_weekday;
	string time;
	string sections;
	int startHour, startMinute, endHour, endMinute;
	string startHourAndMinute, endHourAndMinute;
	int int_weekday;
	int startSection, endSection;
	int year, month, day;
	bool have_ddl, have_reminder;
	PushButton butn;
};

