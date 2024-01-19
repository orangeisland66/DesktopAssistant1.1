#pragma once
#include"StudyRecorder.h"

//学习记录管理类
class StudyRecorderManager
{
public:
	StudyRecorderManager();
	void write();
	void delete_();
	void show();
	void operator()();
	
private:
	vector<StudyRecorder>StudyRecorderArray;
};