#pragma once
#include"header.h"
#include"MenuManager.h"
#include<graphics.h>

//�Զ��崰����
class MyWindow
{
public:
	MyWindow();
	MyWindow(int w, int h, int flag);				//���ô��ڳ�������ģʽ
	static void setWindowTitle(const string& title);//���ô��ڱ���
	static int exec();								//����������
	static int width();
	static int height();
	static void clear();
	static void flushDraw();						//�����滭
	static void beginDraw();						//��ʼ�滭
	static void endDraw();							//ֹͣ�滭����������������ҪΪ�˷�ֹ��˸��
	static HWND getHWND();							//��ȡ���ھ��

	inline static bool hasMsg() { return ::peekmessage(&m_msg, EM_MOUSE | EM_KEY); }//��������Ƿ�����Ϣ
	inline static const EASYXMSG& getMsg() { return m_msg; };						//��ȡ���������Ϣ
private:
	static HWND m_handle;							//�������ھ��
	static ExMessage m_msg;							//��Ϣ
};


