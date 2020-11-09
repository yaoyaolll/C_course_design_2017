#include "head.h"
#include "SVGAmode.h"
#include "input.h"
#include "mouse.h"
#include "manager.h"
#include "show_price.h"
#include "Cai_Config.h"
#include "reprice.h"

void price1(int *flag,int *fen,struct caipin *list,char c)
{
	int i;
	for(i=0;i<7;i++)
	{
	  if(fen[i]==1)
	  {
		break;
	  }
	}
	if(i==0&&(*flag)==0)          //第一类第一张
	{
		transform(139,373,list[0].price,c);
	}
	if(i==0&&(*flag)==1)          //第一类第二张
	{
		transform(139,373,list[6].price,c);
	}
	if(i==1&&(*flag)==0)          //第二类第一张
	{
		transform(139,373,list[8].price,c);
	}
	if(i==1&&(*flag)==2)          //第二类第二张
	{
		transform(139,373,list[14].price,c);
	}
	if(i==2)                   //第三类
	{
		transform(139,373,list[20].price,c);
	}
	if(i==3)                   //第四类
	{
		transform(139,373,list[26].price,c);
	}		
	if(i==4&&(*flag)==0)          //第五类第一张
	{
		transform(139,373,list[32].price,c);
	}
	if(i==4&&(*flag)==3)          //第五类第二张
	{
		transform(139,373,list[38].price,c);
	}			
	if(i==5)                   //第六类
	{
		transform(139,373,list[44].price,c);
	}
	if(i==6)                   //第七类
	{
		transform(139,373,list[50].price,c);
	}
}

void price2(int *flag,int *fen,struct caipin *list,char c)
{
	int i;
	for(i=0;i<7;i++)
	{
	  if(fen[i]==1)
	  {
		break;
	  }
	}
	if(i==0&&(*flag)==0)          //第一类第一张
	{
		transform(442,373,list[1].price,c);
	}
	if(i==0&&(*flag)==1)          //第一类第二张
	{
		transform(442,373,list[7].price,c);
	}
	if(i==1&&(*flag)==0)          //第二类第一张
	{
		transform(442,373,list[9].price,c);
	}
	if(i==1&&(*flag)==2)          //第二类第二张
	{
		transform(442,373,list[15].price,c);
	}
	if(i==2)                   //第三类
	{
		transform(442,373,list[21].price,c);
	}
	if(i==3)                   //第四类
	{
		transform(442,373,list[27].price,c);
	}		
	if(i==4&&(*flag)==0)          //第五类第一张
	{
		transform(442,373,list[33].price,c);
	}
	if(i==4&&(*flag)==3)          //第五类第二张
	{
		transform(442,373,list[39].price,c);
	}			
	if(i==5)                   //第六张
	{
		transform(442,373,list[45].price,c);
	}
	if(i==6)                   //第七张
	{
		transform(442,373,list[51].price,c);
	}
}

void price3(int *flag,int *fen,struct caipin *list,char c)
{
	int i;
	for(i=0;i<7;i++)
	{
	  if(fen[i]==1)
	  {
		break;
	  }
	}
	if(i==0&&(*flag)==0)          //第一类第一张
	{
		transform(751,373,list[2].price,c);
	}
	if(i==1&&(*flag)==0)          //第二类第一张
	{
		transform(751,373,list[10].price,c);
	}
	if(i==1&&(*flag)==2)          //第二类第二张
	{
		transform(751,373,list[16].price,c);
	}
	if(i==2)                   //第三类
	{
		transform(751,373,list[22].price,c);
	}
	if(i==3)                   //第四类
	{
		transform(751,373,list[28].price,c);
	}		
	if(i==4&&(*flag)==0)          //第五类第一张
	{
		transform(751,373,list[34].price,c);
	}
	if(i==4&&(*flag)==3)          //第五类第二张
	{
		transform(751,373,list[40].price,c);
	}			
	if(i==5)                   //第六张
	{
		transform(751,373,list[46].price,c);
	}
	if(i==6)                   //第七张
	{
		transform(751,373,list[52].price,c);
	}
}

void price4(int *flag,int *fen,struct caipin *list,char c)
{
	int i;
	for(i=0;i<7;i++)
	{
	  if(fen[i]==1)
	  {
		break;
	  }
	}
	if(i==0&&(*flag)==0)          //第一类第一张
	{
		transform(139,724,list[3].price,c);
	}
	if(i==1&&(*flag)==0)          //第二类第一张
	{
		transform(139,724,list[11].price,c);
	}
	if(i==1&&(*flag)==2)          //第二类第二张
	{
		transform(139,724,list[17].price,c);
	}
	if(i==2)                   //第三类
	{
		transform(139,724,list[23].price,c);
	}
	if(i==3)                   //第四类
	{
		transform(139,724,list[29].price,c);
	}		
	if(i==4&&(*flag)==0)          //第五类第一张
	{
		transform(139,724,list[35].price,c);
	}
	if(i==4&&(*flag)==3)          //第五类第二张
	{
		transform(139,724,list[41].price,c);
	}			
	if(i==5)                   //第六张
	{
		transform(139,724,list[47].price,c);
	}
	if(i==6)                   //第七张
	{
		transform(139,724,list[53].price,c);
	}
}

void price5(int *flag,int *fen,struct caipin *list,char c)
{
	int i;
	for(i=0;i<7;i++)
	{
	  if(fen[i]==1)
	  {
		break;
	  }
	}
	if(i==0&&(*flag)==0)          //第一类第一张
	{
		transform(442,724,list[4].price,c);
	}
	if(i==1&&(*flag)==0)          //第二类第一张
	{
		transform(442,724,list[12].price,c);
	}
	if(i==1&&(*flag)==2)          //第二类第二张
	{
		transform(442,724,list[18].price,c);
	}
	if(i==2)                   //第三类
	{
		transform(442,724,list[24].price,c);
	}
	if(i==3)                   //第四类
	{
		transform(442,724,list[30].price,c);
	}		
	if(i==4&&(*flag)==0)          //第五类第一张
	{
		transform(442,724,list[36].price,c);
	}
	if(i==4&&(*flag)==3)          //第五类第二张
	{
		transform(442,724,list[42].price,c);
	}			
	if(i==5)                   //第六张
	{
		transform(442,724,list[48].price,c);
	}
	if(i==6)                   //第七张
	{
		transform(442,724,list[54].price,c);
	}
}

void price6(int *flag,int *fen,struct caipin *list,char c)
{
	int i;
	for(i=0;i<7;i++)
	{
	  if(fen[i]==1)
	  {
		break;
	  }
	}
	if(i==0&&(*flag)==0)          //第一类第一张
	{
		transform(751,724,list[5].price,c);
	}
	if(i==1&&(*flag)==0)          //第二类第一张
	{
		transform(751,724,list[13].price,c);
	}
	if(i==1&&(*flag)==2)          //第二类第二张
	{
		transform(751,724,list[19].price,c);
	}
	if(i==2)                   //第三类
	{
		transform(751,724,list[25].price,c);
	}
	if(i==3)                   //第四类
	{
		transform(751,724,list[31].price,c);
	}		
	if(i==4&&(*flag)==0)          //第五类第一张
	{
		transform(751,724,list[37].price,c);
	}
	if(i==4&&(*flag)==3)          //第五类第二张
	{
		transform(751,724,list[43].price,c);
	}			
	if(i==5)                   //第六张
	{
		transform(751,724,list[49].price,c);
	}
}
/*修改价格并将价格修改后的图片贴出来*/
void transform(int x,int y,char *s,char c)
{
	char letter[]="price\\\\xx.bmp";
	int a;
	a=atoi(s);
	if(c=='-')
	{
		if((a-1)>0)
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