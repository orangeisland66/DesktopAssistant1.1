#pragma once
#include"header.h"

//自定义系统时间类
class SystemTime
{
public:
    static void getSystemTime();//获取系统时间
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
    static time_t t;                //用于获取时间信息
    static tm tm_info[50];          //存储时间信息，类型为tm*
    static int year, month, day, dayOfWeek, hour, minute, second;//用整型存储时间便于计算
};

