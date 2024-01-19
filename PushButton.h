#pragma once
#include "BasicWidget.h"

//��ť��
class PushButton :
    public BasicWidget
{
public:
    PushButton(const string& text = "Button", COLORREF color1 = RGB(105, 175, 240), int x = 0, int y = 0, int w = 100, int h = 30);
    void show(int mode)override;                         //����ģʽ��ʾ��ť
    bool isIn();                                         //�ж�����Ƿ��ڰ�ť��
    bool isClicked();                                    //�ж�����Ƿ񱻵��  
    void eventLoop(const ExMessage& msg,int mode);       //�¼�ѭ�����ж�����Ƿ��ڰ�ť�ϡ�
    void set_m_text(string textToModify);                //���ð�ť����
    string get_m_text();                                 //��ȡ��ť����
private:
    string m_text;                                       //��ť����
    ExMessage m_msg;                                     //���״̬
    COLORREF color1, color2=WHITE;                       //����ڰ�ť�ϺͲ��ڰ�ť�ϵİ�ť��ɫ
    COLORREF save;                                       //���ڼ�¼��ť��ʷ��ɫ
};

