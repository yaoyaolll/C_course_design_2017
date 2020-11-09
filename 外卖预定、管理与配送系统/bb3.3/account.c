#include "head.h"
#include "SVGAmode.h"
#include "input.h"
#include "mouse.h"
#include "customer.h"
#include "manager.h"
#include <stdlib.h>
#include "revise.h"
#include "store.h"
#include "account.h"
#include "list.h"
#include "enter.h"
#include "manda.h"
#include "caipin.h"

/* struct information 
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
}; */
/* struct order
{
	char ordernumber[9];   //八位订单号
	char name[20];         //姓名
	char number[12];       //电话
	char address[2];       //韵苑，沁苑，紫菘 0,1,2
	char building[3];      //楼栋
	struct caipin wjcf[55];//存贮所定菜品
} */
/*结算、填写顾客信息及付款界面*/
void distribution(struct caipin *wjcf,int *aflag,char *account)
{
	MOUSE M;
	struct information info={"","","",0,700,0,700,0,710};
	int address[3]={1,0,0};     
	int pay[3]={0,1,0};                  //置1为选中
	int i,sum=0;
	int bflag=0;
	char string2[15];
	char string1[15];
	
	for(i=0;i<55;i++)
	{
		if(wjcf[i].count[0]!='0')
		{
			sum+=atoi(wjcf[i].price)*atoi(wjcf[i].count);
		}
	}
	Putbmp64k(0,0,"img\\fk.bmp");
	if(sum<100)
	{
		Putbmp64k(357,381,"img\\wu.bmp");
		itoa(sum,string1,10);
        itoa(sum+6,string2,10);
	}
	if(sum>99&&sum<200)
	{
		Putbmp64k(357,381,"img\\100.bmp");
		itoa(sum,string1,10);
        itoa(sum-4,string2,10);
	}
    if(sum>199&&sum<500)
	{
		Putbmp64k(357,381,"img\\200.bmp");
		itoa(sum,string1,10);
        itoa(sum-19,string2,10);
	}
	if(sum>499)
	{
	    Putbmp64k(357,381,"img\\500.bmp");
		itoa(sum,string1,10);
        itoa(sum-64,string2,10);
	}
	printASC32_16(string1,408,179,1);
    printASC32_16(string2,408,449,1);
	Putbmp64k(694,245,"img\\bk6.bmp");   //韵苑
	Putbmp64k(694,290,"img\\bk7.bmp");   //沁苑
	Putbmp64k(694,336,"img\\bk7.bmp");   //紫菘
	
	Putbmp64k(687,455,"img\\bk7.bmp");   //餐到付款
	Putbmp64k(687,514,"img\\bk6.bmp");   //支付宝
	Putbmp64k(687,578,"img\\bk7.bmp");   //微信
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);          //初始化鼠标
		if(MouseBarLeft(691,139,896,174)==1)    //姓名框
		{
			inputinfo(&info,0);
		}
		if(MouseBarLeft(691,195,896,230)==1)    //电话号码框
		{
			inputinfo(&info,1);
		}
		if(MouseBarLeft(701,390,752,425)==1)    //楼栋框
		{
			inputinfo(&info,2);
		}
		if(MouseBarLeft(703,256,726,276)==1)    //韵苑
		{
			for(i=0;i<3;i++)
            {
	            if(address[i]==1)
	                 break;         //得到当前置1的位数
            }
            address[i]=0;
            if(i==0)                //防止重复贴图
            {
	            address[0]=1;
            }
            if(i==1)
            {
	            address[0]=1;
				Putbmp64k(694,290,"img\\bk7.bmp");
				Putbmp64k(694,245,"img\\bk6.bmp");
	
            }
			if(i==2)
			{
				address[0]=1;
				Putbmp64k(694,336,"img\\bk7.bmp");
				Putbmp64k(694,245,"img\\bk6.bmp");
			}
		}
		if(MouseBarLeft(703,300,726,323)==1)    //沁苑
		{
			for(i=0;i<3;i++)
            {
	            if(address[i]==1)
	                 break;         //得到当前置1的位数
            }
            address[i]=0;
            if(i==1)
            {
	            address[1]=1;
            }
            if(i==0)
            {
	            address[1]=1;
				Putbmp64k(694,245,"img\\bk7.bmp");
				Putbmp64k(694,290,"img\\bk6.bmp");
	
            }
			if(i==2)
			{
				address[1]=1;
				Putbmp64k(694,336,"img\\bk7.bmp");
				Putbmp64k(694,290,"img\\bk6.bmp");
			}
		}
		if(MouseBarLeft(703,346,726,368)==1)    //紫菘
		{
			for(i=0;i<3;i++)
            {
	            if(address[i]==1)
	                 break;         //得到当前置1的位数
            }
            address[i]=0;
            if(i==2)
            {
	            address[2]=1;
            }
            if(i==0)
            {
	            address[2]=1;
				Putbmp64k(694,245,"img\\bk7.bmp");
				Putbmp64k(694,336,"img\\bk6.bmp");
	
            }
			if(i==1)
			{
				address[2]=1;
				Putbmp64k(694,290,"img\\bk7.bmp");
				Putbmp64k(694,336,"img\\bk6.bmp");
			}
		}
		if(MouseBarLeft(696,463,720,488)==1)    //餐到付款
		{
			for(i=0;i<3;i++)
			{
				if(pay[i]==1)        
				    break;
			}
			pay[i]=0;
			if(i==0)
			{
				pay[0]=1;
			}
			if(i==1)
			{
				pay[0]=1;
				Putbmp64k(687,514,"img\\bk7.bmp");
				Putbmp64k(687,455,"img\\bk6.bmp");
			}
			if(i==2)
			{
				pay[0]=1;
				Putbmp64k(687,578,"img\\bk7.bmp");
				Putbmp64k(687,455,"img\\bk6.bmp");
			}
		}
		if(MouseBarLeft(696,522,720,547)==1)    //支付宝
		{
			zhifubao(pay);
		}
		if(MouseBarLeft(696,585,720,612)==1)    //微信
		{
			weixin(pay);
		}
		if(MouseBarLeft(908,710,1024,768)==1)    //付款
		{
		    pay_check(&info,wjcf,address,pay,&bflag,account);	
			if(bflag==1)
			{
				*aflag=4;
				break;
			}
			if(bflag==2)
			{
				*aflag=1;
				break;
			}
		}
		if(MouseBarLeft(932,21,1000,59)==1)     //退出
		{
			exit(0);
		}
		if(MouseBarLeft(14,20,142,54)==1)       //上一级
		{
			*aflag=2;
			break;
		}
	}
}
void zhifubao(int *pay)
{
	int i;
	for(i=0;i<3;i++)
			{
				if(pay[i]==1)        
				    break;
			}
			pay[i]=0;
			if(i==1)
			{
				pay[1]=1;
			}
			if(i==0)
			{
				pay[1]=1;
				Putbmp64k(687,455,"img\\bk7.bmp");
				Putbmp64k(687,514,"img\\bk6.bmp");
			}
			if(i==2)
			{
				pay[1]=1;
				Putbmp64k(687,578,"img\\bk7.bmp");
				Putbmp64k(687,514,"img\\bk6.bmp");
			}
}
void weixin(int *pay)
{
	int i;
	for(i=0;i<3;i++)
			{
				if(pay[i]==1)        
				    break;
			}
			pay[i]=0;
			if(i==2)
			{
				pay[2]=1;
			}
			if(i==0)
			{
				pay[2]=1;
				Putbmp64k(687,455,"img\\bk7.bmp");
				Putbmp64k(687,578,"img\\bk6.bmp");
			}
			if(i==1)
			{
				pay[2]=1;
				Putbmp64k(687,514,"img\\bk7.bmp");
				Putbmp64k(687,578,"img\\bk6.bmp");
			}
}
/*退出动画*/
void end(void)
{
	int i;
	Putbmp64k(0,0,"img\\bk5.bmp");
	for(i=0;i<1000;i+=10)
	{
		Putbmp64k(i,273,"img\\dh.bmp");
		Putbmp64k(558+i%3*20,176,"img\\bk10.bmp");
		delay(10);
		if(i%3==2)
		{
			Putbmp64k(558,176,"img\\bk11.bmp");
		}
	}
}
void tuic(int *cflag)
{
	MOUSE M;
	Putbmp64k(262,184,"img\\tuic.bmp");
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(288,451,476,503)==1)  
		{
			*cflag=2;
			break;
		}
		if(MouseBarLeft(547,451,736,503)==1)
		{
			exit(0);
		}
	}
}