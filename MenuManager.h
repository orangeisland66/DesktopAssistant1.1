#pragma once
#include"header.h"

//菜单显示类
void ShowMainMenu();
void ShowAccountBookMenu();
void ShowStudyRecorderMenu();
void ShowPasswordRecorderMenu();
void Pause_and_Cls();

class MenuManager
{
public:
	MenuManager(int mode);
	void Refresh(void (*p)());//使用函数指针调用不同的菜单显示
	void operator()();
private:
	int mode;
};

