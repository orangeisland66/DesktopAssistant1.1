#pragma once
#include"header.h"

//�˵���ʾ��
void ShowMainMenu();
void ShowAccountBookMenu();
void ShowStudyRecorderMenu();
void ShowPasswordRecorderMenu();
void Pause_and_Cls();

class MenuManager
{
public:
	MenuManager(int mode);
	void Refresh(void (*p)());//ʹ�ú���ָ����ò�ͬ�Ĳ˵���ʾ
	void operator()();
private:
	int mode;
};

