/*
Function List：
	1.unsigned int Getpixel64k(int x, int y);
		取点颜色函数，仅适用于0x117模式！
		
	2.int MouseInit(void);
		鼠标复位
	
	3.void MouseRange(int x1, int y1, int x2, int y2);
		设置鼠标移动范围
		
	4.int MouseXYB(MOUSE * mouse);
		读取当前鼠标状态，存入指定结构体
		
	5.int MouseBarLeft(int x1, int y1, int x2, int y2);
		判断鼠标左键是否在指定区域内按下
		
	6.void MouseStoreBk(int x, int y);
		储存被鼠标覆盖区域的显存内容
		
	7.void MousePutBk(int x, int y);
		恢复被鼠标覆盖区域的显存内容
		
	8.void MouseReset(void);
		重置鼠标状态，范围为全屏
		
	9.void MouseDraw(MOUSE mouse);
		画鼠标光标函数		

History：		对本文件的修改请及时按如下格式记录在下面（每个修改单独列出）！
	Example：	Date：
				Author：
				Version：
				Modification：
**********************************************************/

#include"mouse.h"

/*鼠标形状全局变量数组，0表示鼠标外界，1表示鼠标边界，2表示鼠标内部*/
int const mouse_shape[16][10] =
{
	{1,1,0,0,0,0,0,0,0,0},
    {1,2,1,0,0,0,0,0,0,0},
    {1,2,2,1,0,0,0,0,0,0},
    {1,2,2,2,1,0,0,0,0,0},
    {1,2,2,2,2,1,0,0,0,0},
    {1,2,2,2,2,2,1,0,0,0},
    {1,2,2,2,2,2,2,1,0,0},
    {1,2,2,2,2,2,2,2,1,0},
    {1,2,2,2,2,2,2,2,2,1},
    {1,2,2,2,2,2,2,1,1,0},
    {1,2,2,2,2,2,1,0,0,0},
    {1,2,1,1,1,2,2,1,0,0},
    {1,1,0,0,1,2,2,1,0,0},
    {0,0,0,0,0,1,2,2,1,0},
    {0,0,0,0,0,1,2,2,1,0},
    {0,0,0,0,0,0,1,1,1,0}
};

/*鼠标遮挡的背景缓存数组，全局变量，bk是background的缩写*/
int mouse_bk[16][10];

/**********************************************************
Function：		Getpixel64k

Description：	取点颜色函数，仅适用于0x117模式！

Calls：			Selectpage
				
Called By：		MouseStoreBk

Input：			int x	像素横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y	像素纵坐标，从上到下增加，0为最小值（屏幕参考系）

Output：		None

Return：		unsigned int	对应坐标点在显存里面的颜色
				
Others：		None
**********************************************************/
unsigned int Getpixel64k(int x, int y)
{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned int far * const video_buffer = (unsigned char far *)0xa0000000L;
	
	/*要切换的页面号*/
	unsigned char new_page;
	
	/*对应显存地址偏移量*/
	unsigned long int page;
	
	/*判断点是否在屏幕范围内，不在就退出*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return 0;
	}
	
	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 15;	/*32k个点一换页，除以32k的替代算法*/
	Selectpage(new_page);
	
	/*返回颜色*/
	return video_buffer[page];	
}

/**********************************************************
Function：		 MouseInit

Description：	鼠标复位

Calls：			int86
				
Called By：		MouseReset

Input：			None

Output：		鼠标复位

Return：		unsigned int	函数执行结果，
								0x0000	不支持
								0xffff	支持
				
Others：		None
**********************************************************/
int MouseInit(void)
{
	/*****************************************************
	在dos.h中REGS的定义如下：
	struct WORDREGS
	{
		unsigned int ax, bx, cx, dx, si, di, cflag, flags;
	};
	
	struct BYTEREGS
	{
		unsigned char al, ah, bl, bh, cl, ch, dl, dh;
	};
	
	union REGS
	{
		struct WORDREGS x;
		struct BYTEREGS h;
	};
	这样al对应ax的低八位，ah对应ax的高八位，以此类推。
	调用时需要查表决定各入口参数取值,获取返回值表示的信息。
	*****************************************************/
	union REGS mouse;
	
	/*设置鼠标的功能号*/
	mouse.x.ax = 0;
	int86(0x33, &mouse, &mouse);
	return mouse.x.ax;
}

/**********************************************************
Function：		 MouseRange

Description：	设置鼠标移动范围

Calls：			int86
				
Called By：		MouseReset

Input：			int x1		移动范围左上角横坐标
				int y1		移动范围左上角纵坐标
				int x2		移动范围右下角横坐标
				int y2		移动范围右下角纵坐标

Output：		None
Return：		None
				
Others：		None
**********************************************************/
void MouseRange(int x1, int y1, int x2, int y2)
{
	/*REGS联合体见上*/
	union REGS mouse;
	
	/*设置横坐标范围*/
	mouse.x.ax = 7;
	mouse.x.cx = x1;
	mouse.x.dx = x2;
	int86(0x33, &mouse, &mouse);
	
	/*设置纵坐标范围*/
	mouse.x.ax = 8;
	mouse.x.cx = y1;
	mouse.x.dx = y2;
	int86(0x33, &mouse, &mouse);
}

/**********************************************************
Function：		 MouseXYB

Description：	读取当前鼠标状态，存入指定结构体

Calls：			int86

Called By：		MouseBarLeft
				MouseBarRight
				Menu

Input：			MOUSE * mouse	存放鼠标状态结构体的地址

Output：		MOUSE * mouse	存放鼠标状态结构体被更改

Return：		mouse->but		鼠标按钮状态

Others：		None
**********************************************************/
int MouseXYB(MOUSE * mouse)
{
	/*REGS联合体见上*/
	union REGS r;
	r.x.ax = 3;
	int86(0x33, &r, &r);
	mouse->x = r.x.cx;
	mouse->y = r.x.dx;
	mouse->but = r.x.bx;
	return mouse->but;
}

/**********************************************************
Function：		 MouseBarLeft

Description：	判断鼠标左键是否在指定区域内按下

Calls：			MouseXYB

Called By：		Menu

Input：			int x1		移动范围左上角横坐标
				int y1		移动范围左上角纵坐标
				int x2		移动范围右下角横坐标
				int y2		移动范围右下角纵坐标

Output：		None

Return：		1		鼠标左键在指定区域内按下
				0		鼠标左键没在指定区域内按下

Others：		None
**********************************************************/
int MouseBarLeft(int x1, int y1, int x2, int y2)
{
	/*存放鼠标状态的结构体*/
	MOUSE mouse = {0, 0, 0};
	
	/*读取鼠标状态*/
	MouseXYB(&mouse);
	
	/*判断鼠标左键是否在指定区域内按下*/
	if ((mouse.x >= x1)
		&& (mouse.x <= x2)
		&& (mouse.y >= y1)
		&& (mouse.y <= y2)
		&& ((mouse.but & 1) == 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/**********************************************************
Function：		 MouseStoreBk

Description：	储存被鼠标覆盖区域的显存内容
				Bk是background的缩写

Calls：			Getpixel64k

Called By：		MouseReset
				Menu

Input：			int x		鼠标光标横坐标
				int y		鼠标光标纵坐标

Output：		int mouse_bk[16][10]			全局变量储存被鼠标覆盖区域的显存内容
				int const mouse_shape[16][10]	鼠标形状全局变量数组

Return：		None
Others：		None
**********************************************************/
void MouseStoreBk(int x, int y)
{
	int i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (mouse_shape[i][j] == 0)
			{
				continue;
			}
			mouse_bk[i][j] = Getpixel64k(j + x, i + y);
		}
	}
}

/**********************************************************
Function：		 MousePutBk

Description：	恢复被鼠标覆盖区域的显存内容
				Bk是background的缩写

Calls：			Putpixel64k

Called By：		Menu

Input：			int x							鼠标光标横坐标
				int y							鼠标光标纵坐标
				int mouse_bk[16][10]			全局变量储存被鼠标覆盖区域的显存内容
				int const mouse_shape[16][10]	鼠标形状全局变量数组
				
Output：		在屏幕上恢复被鼠标覆盖区域的显存内容

Return：		None
Others：		None
**********************************************************/
void MousePutBk(int x, int y)
{
	int i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (mouse_shape[i][j] == 0)
			{
				continue;
			}
			
			Putpixel64k(j + x, i + y, mouse_bk[i][j]);
		}
	}
}

/**********************************************************
Function：		 MouseReset

Description：	重置鼠标状态，范围为全屏

Calls：			MouseInit
				MouseRange
				MouseStoreBk
				
				printf
				getch
				exit

Called By：		Menu

Input：			None
				
Output：		重置鼠标状态

Return：		None
Others：		None
**********************************************************/
void MouseReset(void)
{
	if (MouseInit() != 0xffff)
	{
		printf("ERROR In MouseInit\n");
		getch();
		exit(1);
	};
	MouseRange(0, 0, SCR_WIDTH - 1, SCR_HEIGHT -1);
	MouseStoreBk(0, 0);
}

/**********************************************************
Function		MouseDraw

Description：	画鼠标光标函数

Calls：			Putpixel64k

Called By：		Menu

Input：			MOUSE mouse						存放鼠标状态的结构体
				int const mouse_shape[16][10]	鼠标形状全局变量数组
				
Output：		在指定坐标处画鼠标光标

Return：		None
Others：		None
**********************************************************/
void MouseDraw(MOUSE mouse)
{
	int i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 10; j++)
		{
			
			if (mouse_shape[i][j] == 0)
			{
				continue;
			}
			else if (mouse_shape[i][j] == 1)
			{
				Putpixel64k(j + mouse.x, i + mouse.y, 0);
			}
			else if (mouse_shape[i][j] == 2)
			{
				Putpixel64k(j + mouse.x, i + mouse.y, 0xffff);
			}
		}
	}
}
/*取鼠标按钮按下状态*/
int Ispress(void)
{
	_AX=3;
	geninterrupt(0x33);
	return _BX;
}
