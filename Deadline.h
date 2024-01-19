#pragma once
#include"header.h"

//截止日期类
class Deadline
{
public:
	Deadline(string subjectname, int dayRemained);
	friend bool operator<(const Deadline& ddl1, const Deadline& ddl12);//重载＜，便于比较
	void deadlineOutput(int cnt)const;

private:
	
	string subjectName;
	int dayRemained;
};

