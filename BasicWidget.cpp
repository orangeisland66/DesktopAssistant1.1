#include "BasicWidget.h"
//构造函数
BasicWidget::BasicWidget(int x, int y, int w, int h)
	:m_x(x),m_y(y),m_w(w),m_h(h)
{
}
//获取按钮宽度
int BasicWidget::width()
{
	return m_w;
}
//获取按钮高度
int BasicWidget::height()
{
	return m_h;
}
//设置按钮宽高
void BasicWidget::setFixedSize(int w, int h)
{
	this->m_w = w;
	this->m_h = h;
}
//设置按钮基本参数
void BasicWidget::set(int x, int y, int w, int h)
{
	m_x = x, m_y = y, m_w = w, m_h = h;
}
//获取按钮左上角横坐标
int BasicWidget::x()
{
	return m_x;
}
//获取按钮左上角纵坐标
int BasicWidget::y()
{
	return m_y;
}
//移动按钮至某坐标
void BasicWidget::move(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}
