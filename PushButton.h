#pragma once
#include "BasicWidget.h"

//按钮类
class PushButton :
    public BasicWidget
{
public:
    PushButton(const string& text = "Button", COLORREF color1 = RGB(105, 175, 240), int x = 0, int y = 0, int w = 100, int h = 30);
    void show(int mode)override;                         //根据模式显示按钮
    bool isIn();                                         //判断鼠标是否在按钮上
    bool isClicked();                                    //判断鼠标是否被点击  
    void eventLoop(const ExMessage& msg,int mode);       //事件循环，判断鼠标是否在按钮上。
    void set_m_text(string textToModify);                //设置按钮名称
    string get_m_text();                                 //获取按钮名称
private:
    string m_text;                                       //按钮标题
    ExMessage m_msg;                                     //鼠标状态
    COLORREF color1, color2=WHITE;                       //鼠标在按钮上和不在按钮上的按钮颜色
    COLORREF save;                                       //用于记录按钮历史颜色
};

