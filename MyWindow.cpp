#include "MyWindow.h"

MyWindow::MyWindow()
{
}
//�вι��죬���ô��ڻ�������
MyWindow::MyWindow(int w, int h, int flag)
{
	m_handle = ::initgraph(w, h, flag);			//��ʼ������ʾ������
	MoveWindow(m_handle, 400, 200, w, h, TRUE);	//�ƶ�������
	settextstyle(20, 0, ("����"));				//����Ĭ������
}

void MyWindow::setWindowTitle(const string& title)
{
	::SetWindowText(m_handle, title.c_str());	//�ı䴰�ڱ���
}
//��ջ���
int MyWindow::exec()
{
	return getchar();
}
//��ȡ���ڿ��
int MyWindow::width()
{
	return ::getwidth();
}
//��ȡ���ڸ߶�
int MyWindow::height()
{
	return ::getwidth();
}
//��մ��ڣ������ʾ���������ݣ�
void MyWindow::clear()
{
	::cleardevice();
}
//��ʼ�滭
void MyWindow::beginDraw()
{
	::BeginBatchDraw();
}
//�����滭
void MyWindow::flushDraw()
{
	::FlushBatchDraw();
}
//�����滭
void MyWindow::endDraw()
{
	::EndBatchDraw();
}
//��ȡ���ھ��
HWND MyWindow::getHWND()
{
	return m_handle;
}

HWND MyWindow::m_handle;
ExMessage MyWindow::m_msg;

//˵�����������贴�������Ա�����ͺ�����Ϊstatic����