#include "Subject.h"
//构造函数
Subject::Subject(string subjectName, string teacher, string string_weekday, string sections, bool have_ddl,
				int year, int month, int day, bool have_reminder) :
	subjectName(subjectName), teacher(teacher), string_weekday(string_weekday), sections(sections), butn(subjectName,RGB(252,140,35)),
	have_ddl(have_ddl), year(year), month(month), day(day), have_reminder(have_reminder)
{
	setHourAndMinute();
	setweekday();
	butn.set(setButton_x(), setButton_y(), setButtonWidth(), setButtonHeight());
}
//设置科目按钮高度
int Subject::setButtonHeight()
{
	return (int)(81 * (endSection - startSection + 1) / 1.75);
}
//设置科目按钮宽度
int Subject::setButtonWidth()
{
	return (int)(78 / 1.75);
}
//设置科目按钮横坐标
int Subject::setButton_x()
{
	return (int)(62 + 78 * int_weekday) / 1.75;

}
//设置科目按钮纵坐标
int Subject::setButton_y()
{
	return (int)(71 + 81 * (startSection - 1)) / 1.75;
}
//设置是否有课程提醒
bool Subject::set_have_reminder(bool have_reminder)
{
	if (this->have_reminder == have_reminder)return false;//如果已经设置，返回false
	this->have_reminder = have_reminder;
	return true;
}
//设置科目时间
void Subject::setHourAndMinute()
{
	int size = (int)sections.size();
	int hyphen = 0;
	for (int i = 0; i < size; i++)
	{
		if (sections[i] == '-')hyphen = i;
	}
	stringstream ss;
	//读取课程开始的节数
	ss << sections.substr(0, hyphen);
	ss >> startSection;
	ss.str("");//清空buffer
	ss.clear();//初始化流状态
	//读取课程结束的节数
	ss << sections.substr(hyphen + 1, size - hyphen - 1);
	ss >> endSection;
	//将节数转换为上课时间
	if (startSection == 1) { startHour = 8; startMinute = 0; startHourAndMinute = "8:00"; }
	if (startSection == 2) { startHour = 8; startMinute = 50; startHourAndMinute = "8:50"; }
	if (startSection == 3) { startHour = 9; startMinute = 50; startHourAndMinute = "9:50"; }
	if (startSection == 4) { startHour = 10; startMinute = 40; startHourAndMinute = "10:40"; }
	if (startSection == 5) { startHour = 11; startMinute = 30; startHourAndMinute = "11:30"; }
	if (startSection == 6) { startHour = 14; startMinute = 5; startHourAndMinute = "14:05"; }
	if (startSection == 7) { startHour = 14; startMinute = 55; startHourAndMinute = "14:55"; }
	if (startSection == 8) { startHour = 15; startMinute = 45; startHourAndMinute = "15:45"; }
	if (startSection == 9) { startHour = 16; startMinute = 40; startHourAndMinute = "16:40"; }
	if (startSection == 10) { startHour = 17; startMinute = 30; startHourAndMinute = "17:30"; }
	if (startSection == 11) { startHour = 18; startMinute = 30; startHourAndMinute = "18:30"; }
	if (startSection == 12) { startHour = 19; startMinute = 20; startHourAndMinute = "19:20"; }
	if (startSection == 13) { startHour = 20; startMinute = 10; startHourAndMinute = "20:10"; }
	if (endSection == 1) { endHour = 8; endMinute = 45; endHourAndMinute = "8:45"; }
	if (endSection == 2) { endHour = 9; endMinute = 35; endHourAndMinute = "9:35"; }
	if (endSection == 3) { endHour = 10; endMinute = 35; endHourAndMinute = "10:35"; }
	if (endSection == 4) { endHour = 11; endMinute = 25; endHourAndMinute = "11:25"; }
	if (endSection == 5) { endHour = 12; endMinute = 15; endHourAndMinute = "12:15"; }
	if (endSection == 6) { endHour = 14; endMinute = 50; endHourAndMinute = "14:50"; }
	if (endSection == 7) { endHour = 15; endMinute = 40; endHourAndMinute = "15:40"; }
	if (endSection == 8) { endHour = 16; endMinute = 30; endHourAndMinute = "16:30"; }
	if (endSection == 9) { endHour = 17; endMinute = 25; endHourAndMinute = "17:25"; }
	if (endSection == 10) { endHour = 18; endMinute = 15; endHourAndMinute = "18:15"; }
	if (endSection == 11) { endHour = 19; endMinute = 15; endHourAndMinute = "19:15"; }
	if (endSection == 12) { endHour = 20; endMinute = 5; endHourAndMinute = "20:05"; }
	if (endSection == 13) { endHour = 20; endMinute = 55; endHourAndMinute = "20:55"; }
}
//设置int型星期
void Subject::setweekday()
{
	int size = (int)string_weekday.size();
	for (int i = 0; i < size; i += 2)
	{
		if (string_weekday.substr(i, 2) == "一")
		{
			int_weekday = 1;
			break;
		}
		if (string_weekday.substr(i, 2) == "二")
		{
			int_weekday = 2;
			break;
		}
		if (string_weekday.substr(i, 2) == "三")
		{
			int_weekday = 3;
			break;
		}
		if (string_weekday.substr(i, 2) == "四")
		{
			int_weekday = 4;
			break;
		}
		if (string_weekday.substr(i, 2) == "五")
		{
			int_weekday = 5;
			break;
		}
		if (string_weekday.substr(i, 2) == "六")
		{
			int_weekday = 6;
			break;
		}
		if (string_weekday.substr(i, 2) == "日" || string_weekday.substr(i, 2) == "天")
		{
			int_weekday = 0;
			break;
		}
	}
}
//设置ddl
bool Subject::set_ddl(int year,int month,int day)
{
	if (have_ddl == true)return false;
	this->year = year;
	this->month = month;
	this->day = day;
	have_ddl = true;
	return true;
}
//删除ddl
bool Subject::delete_ddl()
{
	if (have_ddl == false)return false;
	year = 0;
	month = 0;
	day = 0;
	have_ddl = false;
	return true;
}
//输出课程信息
void Subject::outtextInfo()
{
	settextcolor(BLACK);
	settextstyle(40, 0, ("微软雅黑"));
	string s1, s2, s3;
	s1 = "课程名：" + subjectName;
	s2 = "任课老师：" + teacher;
	s3 = "上课时间：" + string_weekday + "  " + startHourAndMinute + "~" + endHourAndMinute;

	outtextxy(0, 0, s1.c_str());
	outtextxy(0, 40, s2.c_str());
	outtextxy(0, 80, s3.c_str());
	settextcolor(WHITE);
	settextstyle(17, 0, ("微软雅黑"));
}
//是否已经设置ddl
bool Subject::is_ddl()
{
	return have_ddl;
}
//是否已经设置课程提醒
bool Subject::is_reminder()
{
	return have_reminder;
}
//获取课程开始上课小时
int Subject::getStartHour()
{
	return startHour;
}
//获取课程开始上课分钟
int Subject::getStartMinute()
{
	return startMinute;
}
//获取课程在星期几上课
int Subject::getWeekday()
{
	return int_weekday;
}
//获取ddl的年
int Subject::getYear()
{
	return year;
}
//获取ddl的月
int Subject::getMonth()
{
	return month;
}
//获取ddl的日
int Subject::getDay()
{
	return day;
}
//获取科目名称
string Subject::getSubjectName()
{
	return subjectName;
}
//获取按钮
PushButton Subject::getButn()const
{
	return butn;
}
//重载<号
bool operator<(const Subject& sbj1, const Subject& sbj2)
{
	if (sbj1.int_weekday < sbj2.int_weekday)return true;
	if (sbj1.int_weekday < sbj2.int_weekday && sbj1.startHour < sbj2.startHour)return true;
	if (sbj1.int_weekday < sbj2.int_weekday && sbj1.startHour == sbj2.startHour && sbj1.startMinute < sbj2.startMinute)return true;
	return false;
}
//重载<<
ofstream& operator<<(ofstream& ofs, const Subject& sbj)
{
	ofs << sbj.subjectName << " " << sbj.teacher << " " << sbj.string_weekday << " " << sbj.sections << " " << sbj.have_ddl<<" ";
	if (sbj.have_ddl == true)ofs << sbj.year << " " << sbj.month << " " << sbj.day << " " << sbj.have_reminder << endl;
	else ofs << sbj.have_reminder << endl;
	return ofs;
}
