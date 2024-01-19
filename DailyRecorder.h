#pragma once
#include"header.h"
#include"PushButton.h"
#include"MyWindow.h"
#include"SystemTime.h"

//生活记录类
class DailyRecorder
{
public:
	DailyRecorder(string title,string content,string address,string time);
	void show();
	friend ofstream& operator<<(ofstream& ofs, DailyRecorder da);
	~DailyRecorder();
private:
	string title, content, address, time;
	IMAGE *image;
};

