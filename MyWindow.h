#pragma once
#include"header.h"
#include"MenuManager.h"
#include<graphics.h>

//自定义窗口类
class MyWindow
{
public:
	MyWindow();
	MyWindow(int w, int h, int flag);				//设置窗口长宽，窗口模式
	static void setWindowTitle(const string& title);//设置窗口标题
	static int exec();								//清理输入流
	static int width();
	static int height();
	static void clear();
	static void flushDraw();						//继续绘画
	static void beginDraw();						//开始绘画
	static void endDraw();							//停止绘画（以上两个功能主要为了防止闪烁）
	static HWND getHWND();							//获取窗口句柄

	inline static bool hasMsg() { return ::peekmessage(&m_msg, EM_MOUSE | EM_KEY); }//鼠标或键盘是否有消息
	inline static const EASYXMSG& getMsg() { return m_msg; };						//获取鼠标或键盘消息
private:
	static HWND m_handle;							//创建窗口句柄
	static ExMessage m_msg;							//消息
};


