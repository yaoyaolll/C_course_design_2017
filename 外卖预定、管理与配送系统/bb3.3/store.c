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
#include "caipin.h"
#include "manda.h"

void store(struct caipin *wjcf,int *aflag)
{
	struct caipin *list=wjcf;         
	MOUSE M;
	int fen[7]={1};
	int i;
	int flag=0;
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(0,72,117,130)==1)                 //热菜
     	{
			recai(list,fen,&flag);
		}
		if(MouseBarLeft(0,132,117,190)==1)                //盖浇饭
		{
			gaijiaofan(list,fen,&flag);
		}
		if(MouseBarLeft(0,192,117,250)==1)                //干锅类
		{
			ganguolei(list,fen,&flag);
		}
		if(MouseBarLeft(0,252,117,310)==1)                //凉菜
		{
			liangcai(list,fen,&flag);
		}
		if(MouseBarLeft(0,312,117,370)==1)                //家常小炒
		{
			xiaocao(list,fen,&flag);
		}
		if(MouseBarLeft(0,372,117,430)==1)                //主食
		{
			zhuxhi(list,fen,&flag);
		}
		if(MouseBarLeft(0,432,117,490)==1)                //饮料
		{
			yinliao(list,fen,&flag);
		}
		if(MouseBarLeft(294,375,328,406)==1)     //1(-)
		{
			minus1(list,fen,&flag);
		}
		if(MouseBarLeft(357,374,390,407)==1)     //1(+)
		{
		    add1(list,fen,&flag);	
		}
		if(MouseBarLeft(596,375,627,406)==1)     //2(-)
		{
			minus2(list,fen,&flag);
		}
		if(MouseBarLeft(662,374,696,407)==1)     //2(+)
		{
			add2(list,fen,&flag);
		}
		if(MouseBarLeft(896,375,930,406)==1)     //3(-)
		{
			minus3(list,fen,&flag);
		}
		if(MouseBarLeft(966,374,1000,407)==1)    //3(+)
		{
			add3(list,fen,&flag);
		}
		if(MouseBarLeft(294,722,328,755)==1)     //4(-)
		{
			minus4(list,fen,&flag);
		}
		if(MouseBarLeft(357,722,390,755)==1)     //4(+)
		{
			add4(list,fen,&flag);
		}
		if(MouseBarLeft(596,722,627,755)==1)     //5(-)
		{
			minus5(list,fen,&flag);
		}
		if(MouseBarLeft(662,722,696,755)==1)     //5(+)
		{
			add5(list,fen,&flag);
		}
		if(MouseBarLeft(896,722,930,755)==1)     //6(-)
		{
			minus6(list,fen,&flag);
		}
		if(MouseBarLeft(966,722,1000,755)==1)    //6(+)
		{
			add6(list,fen,&flag);
		}
		if(MouseBarLeft(933,24,995,57)==1)                //退出
		{
			exit(0);
		}
		if(MouseBarLeft(0,707,117,768)==1)                //结算
		{
			for(i=0;i<55;i++)
			{
				if(strcmp(list[i].count,"0")!=0)
				{
					break;
				}
			}
			if(i!=55)
			{
			    *aflag=2;
			    break;
			}
		}	
		if(MouseBarLeft(17,24,135,51)==1)                //上一级
		{
			Putbmp64k(0,0,"img\\dl1.bmp");
			*aflag=3;
			break;
		}
		if(MouseBarLeft(995,417,1019,443)==1)            //下一页
		{
			nextpage1(list,fen,&flag);
		}
		if(MouseBarLeft(123,417,151,443)==1)             //上一页
		{
			lastpage1(list,fen,&flag);
		}
	}
}	
void nextpage1(struct caipin *list,int *fen,int *flag)
{
	int i;
	for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag!=1)                                //flag防止重新贴图
			{
				Putbmp64k(117,72,"img\\s101.bmp");
				show_init2(list);
				*flag=1;
			}
			if(i==1&&*flag!=2)
			{
				Putbmp64k(117,72,"img\\s111.bmp");
				show_init4(list);
			    *flag=2;
			}
			if(i==4&&*flag!=3)
			{
				Putbmp64k(117,72,"img\\s141.bmp");
				show_init8(list);
				*flag=3;
			}
}
void lastpage1(struct caipin *list,int *fen,int *flag)
{
	int i;
	for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==1)
			{
     	        Putbmp64k(117,72,"img\\s10.bmp");
				show_init1(list);
				*flag=0;
	        }
			if(i==1&&*flag==2)
			{
     	        Putbmp64k(117,72,"img\\s11.bmp");
				show_init3(list);
				*flag=0;
	        }
			if(i==4&&*flag==3)
			{
     	        Putbmp64k(117,72,"img\\s14.bmp");
				show_init7(list);
				*flag=0;
	        }
}
/*修改数量并将数量修改后的图片贴出来*/
void transform2(int x,int y,char *s,char c)
{
	char letter[]="numb\\\\nxx.bmp";
	int a;
	a=atoi(s);
	if(c=='-')
	{
		if(a>0)
		{
			a=a-1;
			itoa(a,s,10);
			if(s[1]=='\0')     //个位数
			{
				letter[7]='0';
				letter[8]=s[0];
				delay(200);      //由于鼠标点击太快，无法实现一个一个加减，所以设置一个延时函数0.2s
				Putbmp64k(x,y,letter);
			}
			else
			{
				letter[7]=s[0];
				letter[8]=s[1];
				delay(200);
				Putbmp64k(x,y,letter);
			}
		}
	}
	else
	{
		if((a+1)<100)
		{
			a=a+1;
			itoa(a,s,10);
			if(s[1]=='\0')     //个位数
			{
				letter[7]='0';
				letter[8]=s[0];
				delay(200);
				Putbmp64k(x,y,letter);
			}
			else
			{
				letter[7]=s[0];
				letter[8]=s[1];
				delay(200);            
				Putbmp64k(x,y,letter);
			}
		}
	}
}
/*用于结算，与transform2的区别在于a>1。*/
void transform3(int x,int y,char *s,char c)                  
{
	char letter[]="numb\\\\nxx.bmp";
	int a;
	a=atoi(s);
	if(c=='-')
	{
		if(a>1)
		{
			a=a-1;
			itoa(a,s,10);
			if(s[1]=='\0')     //个位数
			{
				letter[7]='0';
				letter[8]=s[0];
				delay(200);      //由于鼠标点击太快，无法实现一个一个加减，所以设置一个延时函数0.2s
				Putbmp64k(x,y,letter);
			}
			else
			{
				letter[7]=s[0];
				letter[8]=s[1];
				delay(200);
				Putbmp64k(x,y,letter);
			}
		}
	}
	else
	{
		if((a+1)<100)
		{
			a=a+1;
			itoa(a,s,10);
			if(s[1]=='\0')     //个位数
			{
				letter[7]='0';
				letter[8]=s[0];
				delay(200);
				Putbmp64k(x,y,letter);
			}
			else
			{
				letter[7]=s[0];
				letter[8]=s[1];
				delay(200);            
				Putbmp64k(x,y,letter);
			}
		}
	}
}
