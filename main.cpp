/*

				<<说明>>

一、姓名：陈邱华 班级：计弘 学号：2023302112026
二、大作业选题：第三题：桌面助手
三、代码量：2970（不含注释）
四、具体功能说明：
	共实现五个功能，其中

	记账本、学习记录器、密码记录器在控制台终端上实现
	课程备忘录、生活轨迹记录器用easyx实现

	所以老师您如果想运行请先下载easyx

*/

#include"MenuManager.h"
#include"AccountBookManager.h"
#include"StudyRecorderManager.h"
#include"PasswordRecorderManager.h"
#include"MemoManager.h"
#include"DailyRecorderManager.h"

using namespace std;
void run();




int main()
{
	run();
	return 0;
}






void run()
{
	while (1)
	{
		ShowMainMenu();
		int choice = 0;
		while ((choice = cinCheck<int>(3, 6)) == 0)continue;
		switch (choice)
		{
		//使用仿函数，一个功能一份内存，避免消耗太多内存
		case 1:AccountBookManager()(); break;
		case 2:PasswordRecorderManager()(); break;
		case 3:StudyRecorderManager()(); break;
		case 4:MemoManager()(); break;
		case 5:DailyRecorderManager()(); break;
		case 6:cout << "欢迎下次使用！\n"; exit(0); break;
		default:cout << "输入无效！" << endl;
		}

	}
}
