#ifndef	HEAD_H
#define	HEAD_H

#define	SCR_WIDTH	1024	/*SCREEN_WIDTH的缩写，屏幕宽度像素 */
#define	SCR_HEIGHT	768		/*SCREEN_HEIGHT的缩写，屏幕高度像素 */

#include<dos.h>			/*int86、outportb函数头文件，union REGS的定义文件*/
#include<stdio.h>		/*文件操作函数头文件*/
#include<time.h>		/*time函数头文件，clock_t的定义头文件*/
#include<math.h>		/*abs，fabs，sin，cos函数头文件*/
#include<stdlib.h>		/*rand、srand、exit函数头文件*/
#include<graphics.h>	/*自带画图函数头文件*/
#include<conio.h>		/*getch函数头文件*/
#include<string.h>		/*memmove函数头文件*/
#include<bios.h>		/*bioskey函数头文件*/
#define LEN sizeof(struct caipin)
#define LEN1 sizeof(struct Customer)
#define LEN2 sizeof(struct order)
#define LEN3 sizeof(struct time_config)
struct caipin
{
	char name[5];     //名称编号
    char price[5];    //价格
	char count[5];    //个数，初始时为0
};
struct order
{
	char order_time[20];    //订单时间
	char account[20];       //用户名
	char name[20];         //姓名
	char number[12];       //电话
	char address[2];       //韵苑，紫菘，沁园
	char building[3];      //楼栋
	struct caipin cai[55];//存贮所定菜品
};
struct Customer
{
	char Account[20];
	char Password[20];
};
typedef struct user
{
	char Account[20];
	char Password[20];
	int count1;            //账号字符个数
	int posx1;             //输出横坐标
	int count2;            //密码字符个数
	int posx2;             //输出横坐标
}User;
struct information
{
	char name[20];
	char number[12];
	char building[3];
	int count1;
	int posx1;
	int count2;
	int posx2;
	int count3;
	int posx3;
};
struct time_config
{
	char time1[20];
	char time2[20];
};
#endif