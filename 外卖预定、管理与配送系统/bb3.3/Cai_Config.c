#include "head.h"
#include "SVGAmode.h"
#include "input.h"
#include "mouse.h"
#include "manager.h"
#include "show_price.h"
#include "Cai_Config.h"
#include "reprice.h"

void Recai1(int *flag,int *fen,struct caipin *list)
{
	int i;
	*flag=0;
	for(i=0;i<7;i++)
	{
	if(fen[i]==1)
	{
		fen[i]=0;
		break;
	}
	}
	if(i==0)
	{
		fen[0]=1;
	}
	if(i==1)
	{
		Putbmp64k(0,132,"img\\s211.bmp");
		fen[0]=1;
		Putbmp64k(0,72,"img\\s20.bmp");
		Putbmp64k(117,72,"img\\s10.bmp"); 				
		show_price1(list);
	}
	if(i==2)
	{
		Putbmp64k(0,192,"img\\s221.bmp");
		fen[0]=1;
		Putbmp64k(0,72,"img\\s20.bmp");
		Putbmp64k(117,72,"img\\s10.bmp");
		show_price1(list);
	}
	if(i==3)
	{
		Putbmp64k(0,252,"img\\s231.bmp");
		fen[0]=1;
		Putbmp64k(0,72,"img\\s20.bmp");
		Putbmp64k(117,72,"img\\s10.bmp");
		show_price1(list);
	}
	if(i==4)
	{
		Putbmp64k(0,312,"img\\s241.bmp");
		fen[0]=1;
		Putbmp64k(0,72,"img\\s20.bmp");
		Putbmp64k(117,72,"img\\s10.bmp");
		show_price1(list);
	}
	if(i==5)
	{	
		Putbmp64k(0,372,"img\\s251.bmp");
		fen[0]=1;
		Putbmp64k(0,72,"img\\s20.bmp");
		Putbmp64k(117,72,"img\\s10.bmp");
		show_price1(list);
	}
	if(i==6)
	{
		Putbmp64k(0,432,"img\\s261.bmp");
		fen[0]=1;
		Putbmp64k(0,72,"img\\s20.bmp");
		Putbmp64k(117,72,"img\\s10.bmp");
		show_price1(list);
	}
}

void Gaijiaofan(int *flag,int *fen,struct caipin *list)
{
	int i;
	*flag=0;
	for(i=0;i<7;i++)
	{
	if(fen[i]==1)
	{
		fen[i]=0;
		break;
	}
	}
	if(i==0)
	{
		Putbmp64k(0,72,"img\\s201.bmp");
		fen[1]=1;
		Putbmp64k(0,132,"img\\s21.bmp");
		Putbmp64k(117,72,"img\\s11.bmp");
		show_price3(list);
	}
	if(i==1)
	{
		fen[1]=1;
	}
	if(i==2)
	{
		Putbmp64k(0,192,"img\\s221.bmp");
		fen[1]=1;
		Putbmp64k(0,132,"img\\s21.bmp");
		Putbmp64k(117,72,"img\\s11.bmp");
		show_price3(list);
	}
	if(i==3)
	{
		Putbmp64k(0,252,"img\\s231.bmp");
		fen[1]=1;
		Putbmp64k(0,132,"img\\s21.bmp");
		Putbmp64k(117,72,"img\\s11.bmp");
		show_price3(list);
	}
	if(i==4)
	{
		Putbmp64k(0,312,"img\\s241.bmp");
		fen[1]=1;
		Putbmp64k(0,132,"img\\s21.bmp");
		Putbmp64k(117,72,"img\\s11.bmp");
		show_price3(list);
	}
	if(i==5)
	{	
		Putbmp64k(0,372,"img\\s251.bmp");
		fen[1]=1;
		Putbmp64k(0,132,"img\\s21.bmp");
		Putbmp64k(117,72,"img\\s11.bmp");
		show_price3(list);
	}
	if(i==6)
	{
		Putbmp64k(0,432,"img\\s261.bmp");
		fen[1]=1;
		Putbmp64k(0,132,"img\\s21.bmp");
		Putbmp64k(117,72,"img\\s11.bmp");
		show_price3(list);
	}
}

void Ganguo(int *flag,int *fen,struct caipin *list)
{
	int i;
	*flag=0;		
	for(i=0;i<7;i++)
	{
	if(fen[i]==1)
	{
		fen[i]=0;
		break;
	}
	}
	if(i==0)
	{
		Putbmp64k(0,72,"img\\s201.bmp");
		fen[2]=1;
		Putbmp64k(0,192,"img\\s22.bmp");
		Putbmp64k(117,72,"img\\s12.bmp");
		show_price5(list);
	}
	if(i==1)
	{
		Putbmp64k(0,132,"img\\s211.bmp");
		fen[2]=1;
		Putbmp64k(0,192,"img\\s22.bmp");
		Putbmp64k(117,72,"img\\s12.bmp");
		show_price5(list);
	}
	if(i==2)
	{
		fen[2]=1;
	}
	if(i==3)
	{
		Putbmp64k(0,252,"img\\s231.bmp");
		fen[2]=1;
		Putbmp64k(0,192,"img\\s22.bmp");
		Putbmp64k(117,72,"img\\s12.bmp");
		show_price5(list);
	}
	if(i==4)
	{
		Putbmp64k(0,312,"img\\s241.bmp");
		fen[2]=1;
		Putbmp64k(0,192,"img\\s22.bmp");
		Putbmp64k(117,72,"img\\s12.bmp");
		show_price5(list);
	}
	if(i==5)
	{	
		Putbmp64k(0,372,"img\\s251.bmp");
		fen[2]=1;
		Putbmp64k(0,192,"img\\s22.bmp");
		Putbmp64k(117,72,"img\\s12.bmp");
		show_price5(list);
	}
	if(i==6)
	{
		Putbmp64k(0,432,"img\\s261.bmp");
		fen[2]=1;
		Putbmp64k(0,192,"img\\s22.bmp");
		Putbmp64k(117,72,"img\\s12.bmp");
		show_price5(list);
	}
}

void Liangcai(int *flag,int *fen,struct caipin *list)
{
	int i;
	*flag=0;		
	for(i=0;i<7;i++)
	{
	if(fen[i]==1)
	{
		fen[i]=0;
		break;
	}
	}
	if(i==0)
	{
		Putbmp64k(0,72,"img\\s201.bmp");
		fen[3]=1;
		Putbmp64k(0,252,"img\\s23.bmp");
		Putbmp64k(117,72,"img\\s13.bmp");
		show_price6(list);
	}
	if(i==1)
	{
		Putbmp64k(0,132,"img\\s211.bmp");
		fen[3]=1;
		Putbmp64k(0,252,"img\\s23.bmp");
		Putbmp64k(117,72,"img\\s13.bmp");
		show_price6(list);
	}
	if(i==2)
	{
		Putbmp64k(0,192,"img\\s221.bmp");
		fen[3]=1;
		Putbmp64k(0,252,"img\\s23.bmp");
		Putbmp64k(117,72,"img\\s13.bmp");
		show_price6(list);
	}
	if(i==3)
	{
		fen[3]=1;
	}
	if(i==4)
	{
		Putbmp64k(0,312,"img\\s241.bmp");
		fen[3]=1;
		Putbmp64k(0,252,"img\\s23.bmp");
		Putbmp64k(117,72,"img\\s13.bmp");
		show_price6(list);
	}
	if(i==5)
	{	
		Putbmp64k(0,372,"img\\s251.bmp");
		fen[3]=1;
		Putbmp64k(0,252,"img\\s23.bmp");
		Putbmp64k(117,72,"img\\s13.bmp");
		show_price6(list);
	}
	if(i==6)
	{
		Putbmp64k(0,432,"img\\s261.bmp");
		fen[3]=1;
		Putbmp64k(0,252,"img\\s23.bmp");
		Putbmp64k(117,72,"img\\s13.bmp");
		show_price6(list);
	}
}

void Jiachang(int *flag,int *fen,struct caipin *list)
{
	int i;
	*flag=0;
	for(i=0;i<7;i++)
	{
	if(fen[i]==1)
	{
		fen[i]=0;
		break;
	}
	}
	if(i==0)
	{
		Putbmp64k(0,72,"img\\s201.bmp");
		fen[4]=1;
		Putbmp64k(0,312,"img\\s24.bmp");
		Putbmp64k(117,72,"img\\s14.bmp");
		show_price7(list);
	}
	if(i==1)
	{
		Putbmp64k(0,132,"img\\s211.bmp");
		fen[4]=1;
		Putbmp64k(0,312,"img\\s24.bmp");
		Putbmp64k(117,72,"img\\s14.bmp");
		show_price7(list);
	}
	if(i==2)
	{
		Putbmp64k(0,192,"img\\s221.bmp");
		fen[4]=1;
		Putbmp64k(0,312,"img\\s24.bmp");
		Putbmp64k(117,72,"img\\s14.bmp");
		show_price7(list);
	}
	if(i==3)
	{
		Putbmp64k(0,252,"img\\s231.bmp");
		fen[4]=1;
		Putbmp64k(0,312,"img\\s24.bmp");
		Putbmp64k(117,72,"img\\s14.bmp");
		show_price7(list);
	}
	if(i==4)
	{
		fen[4]=1;
	}
	if(i==5)
	{	
		Putbmp64k(0,372,"img\\s251.bmp");
		fen[4]=1;
		Putbmp64k(0,312,"img\\s24.bmp");
		Putbmp64k(117,72,"img\\s14.bmp");
		show_price7(list);
	}
	if(i==6)
	{
		Putbmp64k(0,432,"img\\s261.bmp");
		fen[4]=1;
		Putbmp64k(0,312,"img\\s24.bmp");
		Putbmp64k(117,72,"img\\s14.bmp");
		show_price7(list);
	}
}

void Zhushi(int *flag,int *fen,struct caipin *list)
{
	int i;
	*flag=0;		
	for(i=0;i<7;i++)
	{
	if(fen[i]==1)
	{
		fen[i]=0;
		break;
	}
	}
	if(i==0)
	{
		Putbmp64k(0,72,"img\\s201.bmp");
		fen[5]=1;
		Putbmp64k(0,372,"img\\s25.bmp");
		Putbmp64k(117,72,"img\\s15.bmp");
		show_price9(list);
	}
	if(i==1)
	{
		Putbmp64k(0,132,"img\\s211.bmp");
		fen[5]=1;
		Putbmp64k(0,372,"img\\s25.bmp");
		Putbmp64k(117,72,"img\\s15.bmp");
		show_price9(list);
	}
	if(i==2)
	{
		Putbmp64k(0,192,"img\\s221.bmp");
		fen[5]=1;
		Putbmp64k(0,372,"img\\s25.bmp");
		Putbmp64k(117,72,"img\\s15.bmp");
		show_price9(list);
	}
	if(i==3)
	{
		Putbmp64k(0,252,"img\\s231.bmp");
		fen[5]=1;
		Putbmp64k(0,372,"img\\s25.bmp");
		Putbmp64k(117,72,"img\\s15.bmp");
		show_price9(list);
	}
	if(i==4)
	{
		Putbmp64k(0,312,"img\\s241.bmp");
		fen[5]=1;
		Putbmp64k(0,372,"img\\s25.bmp");
		Putbmp64k(117,72,"img\\s15.bmp");
		show_price9(list);
	}
	if(i==5)
	{
		fen[5]=1;
	}
	if(i==6)
	{
		Putbmp64k(0,432,"img\\s261.bmp");
		fen[5]=1;
		Putbmp64k(0,372,"img\\s25.bmp");
		Putbmp64k(117,72,"img\\s15.bmp");
		show_price9(list);
	}
}

void Yinliao(int *flag,int *fen,struct caipin *list)
{
	int i;
	*flag=0;
	for(i=0;i<7;i++)
	{
	  if(fen[i]==1)
	  {
		fen[i]=0;
		break;
	  }
	}
	if(i==0)
	{
		Putbmp64k(0,72,"img\\s201.bmp");
		fen[6]=1;
		Putbmp64k(0,432,"img\\s26.bmp");
		Putbmp64k(117,72,"img\\s16.bmp");
		show_price10(list);
	}
	if(i==1)
	{
		Putbmp64k(0,132,"img\\s211.bmp");
		fen[6]=1;
		Putbmp64k(0,432,"img\\s26.bmp");
		Putbmp64k(117,72,"img\\s16.bmp");
		show_price10(list);
	}
	if(i==2)
	{
		Putbmp64k(0,192,"img\\s221.bmp");
		fen[6]=1;
		Putbmp64k(0,432,"img\\s26.bmp");
		Putbmp64k(117,72,"img\\s16.bmp");
		show_price10(list);
	}
	if(i==3)
	{
		Putbmp64k(0,252,"img\\s231.bmp");
		fen[6]=1;
		Putbmp64k(0,432,"img\\s26.bmp");
		Putbmp64k(117,72,"img\\s16.bmp");
		show_price10(list);
	}
	if(i==4)
	{
		Putbmp64k(0,312,"img\\s241.bmp");
		fen[6]=1;
		Putbmp64k(0,432,"img\\s26.bmp");
		Putbmp64k(117,72,"img\\s16.bmp");
		show_price10(list);
	}
	if(i==5)
	{	
		Putbmp64k(0,372,"img\\s251.bmp");
		fen[6]=1;
		Putbmp64k(0,432,"img\\s26.bmp");
		Putbmp64k(117,72,"img\\s16.bmp");
		show_price10(list);
	}
	if(i==6)
	{
		fen[6]=1;
	}
}

void Next_Page(int *flag,int *fen,struct caipin *list)
{
	int i;
	for(i=0;i<7;i++)
	{
	  if(fen[i]==1)
	  {
		break;
	  }
	}
	if(i==0&&(*flag)!=1)                                //flag防止重新贴图
	{
		Putbmp64k(117,72,"img\\s101.bmp");
		show_price2(list);
		*flag=1;
	}
	if(i==1&&(*flag)!=2)
	{
		Putbmp64k(117,72,"img\\s111.bmp");
		show_price4(list);
		*flag=2;
	}
	if(i==4&&(*flag)!=3)
	{
		Putbmp64k(117,72,"img\\s141.bmp");
		show_price8(list);
		*flag=3;
	}
}

void Last_Page(int *flag,int *fen,struct caipin *list)
{
	int i;
	for(i=0;i<7;i++)
	{
	  if(fen[i]==1)
	  {
		break;
	  }
	}
	if(i==0&&(*flag)==1)
	{
		Putbmp64k(117,72,"img\\s10.bmp");
		show_price1(list);
		*flag=0;
	}
	if(i==1&&(*flag)==2)
	{
		Putbmp64k(117,72,"img\\s11.bmp");
		show_price3(list);
		*flag=0;
	}
	if(i==4&&(*flag)==3)
	{
		Putbmp64k(117,72,"img\\s14.bmp");
		show_price7(list);
		*flag=0;
	}
}