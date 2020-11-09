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
/*付款及检查是否符合条件*/
void pay_check(struct information *info,struct caipin *wjcf,int *m,int *n,int *bflag,char *account)
{
	int i,j,k;
	char string[2];
	int cflag=0;
	FILE *fp;
	struct order Order={"","","","","","",""};
    char *s;
	for(i=0;i<3;i++)     //i为韵苑，沁苑，紫菘
	{
		if(m[i]==1)
			break;
	}
	for(j=0;j<3;j++)     //j为支付方式
	{
		if(n[j]==1)
			break;
	}
	string[0]=i+'0';     //将i变为字符型存入数组
	string[1]='\0';
	if(strcmp(info->name,"")!=0&&info->count2==11&&info->count3>0)
	{
		if((i==0&&(atoi(info->building)<28))||(i==1&&(atoi(info->building)<14)&&(atoi(info->building)>8))||(i==2&&(atoi(info->building)<14)))
		{
			time_out(s);
			strcpy(Order.order_time,s);
			strcpy(Order.account,account);
			strcpy(Order.name,info->name);
			strcpy(Order.number,info->number);
			strcpy(Order.building,info->building);
			strcpy(Order.address,string);
			for(k=0;k<55;k++)
			{
				Order.cai[k]=wjcf[k];
			}
			if(j==0)
			{
				if((fp=fopen("ord.txt","r+"))==NULL)
				{
					printf("can not open the file(order.txt).");
					getch();
					exit(0);
				}
				fseek(fp,0,SEEK_END);
				fwrite(&Order,LEN2,1,fp);
				fclose(fp);
				end();	
				tuic(&cflag);
			}
		    if(j==1)
			{
				zfb(&cflag,&Order);
			}
			if(j==2)
			{
				wx(&cflag,&Order);
			}
			if(cflag==1)
			{
				*bflag=1;
			}
			if(cflag==2)
			{
				*bflag=2;
			}
		}
		else
		{
			printhz16(622,649,"信息填写错误，请修改！",0);
			delay(500);
			Putbmp64k(622,649,"img\\bk9.bmp");
		}
	}
	else
	{
		printhz16(622,649,"信息填写错误，请修改！",0);
		delay(500);
		Putbmp64k(622,649,"img\\bk9.bmp");
	}
}
/*支付宝*/
void zfb(int *cflag,struct order *Order)
{
	MOUSE M;
	FILE *fp;
	char *s;
	int dflag;
	Putbmp64k(0,0,"img\\zfb.bmp");
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(876,709,1000,742)==1)   //确认
		{
			time_out(s);	
            strcpy(Order->order_time,s);
			if((fp=fopen("ord.txt","r+"))==NULL)
			{
				printf("can not open the file(order.txt).");
				getch();
				exit(0);
			}
			fseek(fp,0,SEEK_END);
			fwrite(Order,LEN2,1,fp);
			fclose(fp);
			end();
			tuic(&dflag);
			if(dflag==2)
			{
				*cflag=2;
				break;
			}
		}
		if(MouseBarLeft(0,0,117,54)==1)         //返回
		{
			*cflag=1;
			break;
		}
	}
}
/*微信*/
void wx(int *cflag,struct order *Order)
{
	MOUSE M;
	int dflag;
	FILE *fp;
	char *s;
	Putbmp64k(0,0,"img\\wx.bmp");
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(876,709,1000,742)==1)   //确认
		{
			time_out(s);	
			strcpy(Order->order_time,s);
			if((fp=fopen("ord.txt","r+"))==NULL)
			{
				printf("can not open the file(order.txt).");
				getch();
				exit(0);
			}
			fseek(fp,0,SEEK_END);
			fwrite(Order,LEN2,1,fp);
			fclose(fp);
			end();
			tuic(&dflag);
			if(dflag==2)
			{
				*cflag=2;
				break;
			}
		}
		if(MouseBarLeft(0,0,117,54)==1)         //返回
		{
			*cflag=1;
			break;
		}
	}
}