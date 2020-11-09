#include "head.h"
#include "mouse.h"
#include "SVGAmode.h"
#include "input.h"
#include "manager.h"
#include "customer.h"
void main()
{
	MOUSE M;
	SetSVGA64k();     //0x117模式，64k色
	Putbmp64k(0,0,"img\\dl0.bmp");
	delay(1000);
	Putbmp64k(0,446,"img\\dl2.bmp");
	MouseInit();
	MouseRange(0,0,1024,768);
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
	    MouseDraw(M);
		delay(20);
	    MousePutBk(M.x, M.y);                                     	  																																																																																																																																																																																																																																																									
		if(MouseBarLeft(154,592,430,651)==1)      //管理员
		{
	      manager();
		}
		if(MouseBarLeft(592,591,869,651)==1)      //用户
		{
		  customer();
        }
	}  	
}

