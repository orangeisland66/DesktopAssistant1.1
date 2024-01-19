#pragma once
#include"header.h"
#include"PushButton.h"
#include"Subject.h"
#include"MyWindow.h"
#include"SystemTime.h"
#include"Deadline.h"

//����¼�����࣬û��ע�͵ĺ����������빦�ܻ�����Ӧ
class MemoManager
{
public:
	MemoManager();
	void operator()();
	void fileInit();
	bool transform1(string YMD,int *Y_M_D);			//��string���͵�����ת��������������洢
	string transform2(vector<int>& v);				//��ʱ��ת��Ϊ�ַ��������������Ļ
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
	bool isEsc();									//���·��ؼ�
	void setPos(vector<PushButton>& v);				//���ð�ťλ��
	void drawBackground(int mode);
	int menueventLoop(vector<PushButton> &v);		//�¼�ѭ��
	int showSubjectInfo(int i);
	void sortAndBtnsPushBack();						//����һ�ܵ�ʱ��˳�����Ŀ���򣬱��ں������������
	int calculateDay(int year, int month, int day);	//��������֮��
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

