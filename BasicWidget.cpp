#include "BasicWidget.h"
//���캯��
BasicWidget::BasicWidget(int x, int y, int w, int h)
	:m_x(x),m_y(y),m_w(w),m_h(h)
{
}
//��ȡ��ť���
int BasicWidget::width()
{
	return m_w;
}
//��ȡ��ť�߶�
int BasicWidget::height()
{
	return m_h;
}
//���ð�ť���
void BasicWidget::setFixedSize(int w, int h)
{
	this->m_w = w;
	this->m_h = h;
}
//���ð�ť��������
void BasicWidget::set(int x, int y, int w, int h)
{
	m_x = x, m_y = y, m_w = w, m_h = h;
}
//��ȡ��ť���ϽǺ�����
int BasicWidget::x()
{
	return m_x;
}
//��ȡ��ť���Ͻ�������
int BasicWidget::y()
{
	return m_y;
}
//�ƶ���ť��ĳ����
void BasicWidget::move(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}
