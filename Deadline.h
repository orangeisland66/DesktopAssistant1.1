#pragma once
#include"header.h"

//��ֹ������
class Deadline
{
public:
	Deadline(string subjectname, int dayRemained);
	friend bool operator<(const Deadline& ddl1, const Deadline& ddl12);//���أ������ڱȽ�
	void deadlineOutput(int cnt)const;

private:
	
	string subjectName;
	int dayRemained;
};

