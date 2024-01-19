#include "MyWindow.h"

MyWindow::MyWindow()
{
}
//有参构造，设置窗口基本属性
MyWindow::MyWindow(int w, int h, int flag)
{
	m_handle = ::initgraph(w, h, flag);			//初始化（显示）窗口
	MoveWindow(m_handle, 400, 200, w, h, TRUE);	//移动窗口至
	settextstyle(20, 0, ("黑体"));				//设置默认字体
}

void MyWindow::setWindowTitle(const string& title)
{
	::SetWindowText(m_handle, title.c_str());	//改变窗口标题
}
//清空缓冲
int MyWindow::exec()
{
	return getchar();
}
//获取窗口宽度
int MyWindow::width()
{
	return ::getwidth();
}
//获取窗口高度
int MyWindow::height()
{
	return ::getwidth();
}
//清空窗口（清空显示的所有内容）
void MyWindow::clear()
{
	::cleardevice();
}
//开始绘画
void MyWindow::beginDraw()
{
	::BeginBatchDraw();
}
//继续绘画
void MyWindow::flushDraw()
{
	::FlushBatchDraw();
}
//结束绘画
void MyWindow::endDraw()
{
	::EndBatchDraw();
}
//获取窗口句柄
HWND MyWindow::getHWND()
{
	return m_handle;
}

HWND MyWindow::m_handle;
ExMessage MyWindow::m_msg;

//说明：由于无需创建对象成员变量和函数均为static类型