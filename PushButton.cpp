#include "PushButton.h"
//构造函数，继承BasicWidget
PushButton::PushButton(const string& text, COLORREF color, int x, int y, int w, int h) :
	BasicWidget(x, y, w, h), m_text(text), save(color), color1(color),m_msg()
{	
}
//显示按钮
void PushButton::show(int mode)
{
	setfillcolor(color1);
	settextstyle(20, 0, "微软雅黑");
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);
	settextcolor(color2);
	//根据不同模式调整按钮属性
	if (mode == 0)//此模式为课程按钮显示
	{
		if (m_w < m_text.size() * 11 && m_text.size() < 10)
		{
			string text1 = m_text.substr(0, 4);
			string text2 = m_text.substr(4);
			int tx = m_x + (m_w - textwidth(text1.c_str())) / 2;
			int ty = m_y + (m_h - textheight(text1.c_str())) / 2;
			::outtextxy(tx, ty - 7, text1.c_str());
			::outtextxy(tx, ty + 7, text2.c_str());
		}
		else if (m_w < m_text.size() * 11 && m_text.size() >= 10)
		{
			if (m_text.size() < 13)
			{
				string text1 = m_text.substr(0, 6);
				string text2 = m_text.substr(6);
				int tx = m_x + (m_w - textwidth(text1.c_str())) / 2;
				int ty = m_y + (m_h - textheight(text1.c_str())) / 2;
				::outtextxy(tx, ty - 7, text1.c_str());
				::outtextxy(tx, ty + 7, text2.c_str());
			}
			else
			{
				string text1 = m_text.substr(0, 6);
				string text2 = m_text.substr(6, 6);
				string text3 = m_text.substr(12);
				int tx = m_x + (m_w - textwidth(text1.c_str())) / 2;
				int ty = m_y + (m_h - textheight(text1.c_str())) / 2;
				::outtextxy(tx, ty - 14, text1.c_str());
				::outtextxy(tx, ty , text2.c_str());
				::outtextxy(tx, ty + 14, text3.c_str());

			}

		}
		else
		{
			int tx = m_x + (m_w - textwidth(m_text.c_str())) / 2;
			int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;
			::outtextxy(tx, ty, m_text.c_str());

		}
	}
	else//此模式为一般显示
	{
		int tx = m_x + (m_w - textwidth(m_text.c_str())) / 2;
		int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;
		::outtextxy(tx, ty, m_text.c_str());

	}

}
//获取按钮上的文字
string PushButton::get_m_text()
{
	return m_text;
}
//判断鼠标是否在按钮上
bool PushButton::isIn()
{
	if (m_msg.x >= m_x && m_msg.x < m_x + m_w && m_msg.y >= m_y && m_msg.y < m_y + m_h)//根据鼠标坐标判断
	{
		return true;
	}
	return false;
}
//判断按钮是否按下
bool PushButton::isClicked()
{
	if (isIn())
	{
		if (m_msg.message == WM_LBUTTONDOWN)return true;//按下返回真
	}
	return false;
}
//时间循环，并改变按钮颜色
void PushButton::eventLoop(const ExMessage& msg,int mode)
{
	m_msg = msg;
	if (isIn())//如果按钮在上面，按钮变色
	{
		COLORREF temp = color1;
		color1 = LIGHTRED;
		if (temp != color1)show(mode);
	}
	else//否则按钮变回原色（或保持不变）
	{
		COLORREF temp = color1;
		color1 = save;
		if (temp != color1)show(mode);
	}
	
}
//改变按钮上的文字
void PushButton::set_m_text(string textToModify)
{
	m_text = textToModify;
}
