#pragma once
#include"header.h"

//�Զ���ϵͳʱ����
class SystemTime
{
public:
    static void getSystemTime();//��ȡϵͳʱ��
    static int getYear();
    static int getMonth();
    static int getDay();
    static int getDayOfWeek();
    static int getHour();
    static int getMinute();
    static int getSecond();
    static void showTime();
    static tm* get_tm_info();
private:
    static char cYear_Month_Date[50], cHour_Mniute_Second[50];
    static time_t t;                //���ڻ�ȡʱ����Ϣ
    static tm tm_info[50];          //�洢ʱ����Ϣ������Ϊtm*
    static int year, month, day, dayOfWeek, hour, minute, second;//�����ʹ洢ʱ����ڼ���
};

