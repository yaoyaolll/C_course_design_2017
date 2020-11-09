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

void minus1(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='-';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(327,373,list[0].count,c);
			}
			if(i==0&&*flag==1)          //第一类第二张
			{
				transform2(327,373,list[6].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(327,373,list[8].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(327,373,list[14].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(327,373,list[20].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(327,373,list[26].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(327,373,list[32].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(327,373,list[38].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(327,373,list[44].count,c);
			}
			if(i==6)                   //第七张
			{
				transform2(327,373,list[50].count,c);
			}
		}
void add1(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='+';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(327,373,list[0].count,c);
			}
			if(i==0&&*flag==1)          //第一类第二张
			{
				transform2(327,373,list[6].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(327,373,list[8].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(327,373,list[14].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(327,373,list[20].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(327,373,list[26].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(327,373,list[32].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(327,373,list[38].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(327,373,list[44].count,c);
			}
			if(i==6)                   //第七张
			{
				transform2(327,373,list[50].count,c);
			}
		}
void minus2(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='-';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(628,373,list[1].count,c);
			}
			if(i==0&&*flag==1)          //第一类第二张
			{
				transform2(628,373,list[7].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(628,373,list[9].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(628,373,list[15].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(628,373,list[21].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(628,373,list[27].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(628,373,list[33].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(628,373,list[39].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(628,373,list[45].count,c);
			}
			if(i==6)                   //第七张
			{
				transform2(628,373,list[51].count,c);
			}
		}
void add2(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='+';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				
				transform2(628,373,list[1].count,c);
			}
			if(i==0&&*flag==1)          //第一类第二张
			{
				transform2(628,373,list[7].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(628,373,list[9].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(628,373,list[15].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(628,373,list[21].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(628,373,list[27].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(628,373,list[33].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(628,373,list[39].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(628,373,list[45].count,c);
			}
			if(i==6)                   //第七张
			{
				transform2(628,373,list[51].count,c);
			}
		}
void minus3(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='-';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(932,373,list[2].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(932,373,list[10].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(932,373,list[16].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(932,373,list[22].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(932,373,list[28].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(932,373,list[34].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(932,373,list[40].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(932,373,list[46].count,c);
			}
			if(i==6)                   //第七张
			{
				transform2(932,373,list[52].count,c);
			}
		}
void add3(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='+';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(932,373,list[2].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(932,373,list[10].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(932,373,list[16].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(932,373,list[22].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(932,373,list[28].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(932,373,list[34].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(932,373,list[40].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(932,373,list[46].count,c);
			}
			if(i==6)                   //第七张
			{
				transform2(932,373,list[52].count,c);
			}
		}
void minus4(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='-';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(327,724,list[3].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(327,724,list[11].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(327,724,list[17].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(327,724,list[23].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(327,724,list[29].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(327,724,list[35].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(327,724,list[41].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(327,724,list[47].count,c);
			}
			if(i==6)                   //第七张
			{
				transform2(327,724,list[53].count,c);
			}
		}
void add4(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='+';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(327,724,list[3].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(327,724,list[11].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(327,724,list[17].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(327,724,list[23].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(327,724,list[29].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(327,724,list[35].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(327,724,list[41].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(327,724,list[47].count,c);
			}
			if(i==6)                   //第七张
			{
				transform2(327,724,list[53].count,c);
			}
		}
void minus5(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='-';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(628,724,list[4].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(628,724,list[12].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(628,724,list[18].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(628,724,list[24].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(628,724,list[30].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(628,724,list[36].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(628,724,list[42].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(628,724,list[48].count,c);
			}
			if(i==6)                   //第七张
			{
				transform2(628,724,list[54].count,c);
			}
		}
void add5(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='+';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(628,724,list[4].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(628,724,list[12].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(628,724,list[18].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(628,724,list[24].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(628,724,list[30].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(628,724,list[36].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(628,724,list[42].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(628,724,list[48].count,c);
			}
			if(i==6)                   //第七张
			{
				transform2(628,724,list[54].count,c);
			}
		}
void minus6(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='-';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(932,724,list[5].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(932,724,list[13].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(932,724,list[19].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(932,724,list[25].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(932,724,list[31].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(932,724,list[37].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(932,724,list[43].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(932,724,list[49].count,c);
			}
		}
void add6(struct caipin *list,int *fen,int *flag)
{
	int i;
			char c='+';
			for(i=0;i<7;i++)
			{
			  if(fen[i]==1)
			  {
				break;
			  }
			}
			if(i==0&&*flag==0)          //第一类第一张
			{
				transform2(932,724,list[5].count,c);
			}
			if(i==1&&*flag==0)          //第二类第一张
			{
				transform2(932,724,list[13].count,c);
			}
			if(i==1&&*flag==2)          //第二类第二张
			{
				transform2(932,724,list[19].count,c);
			}
			if(i==2)                   //第三类
			{
				transform2(932,724,list[25].count,c);
			}
			if(i==3)                   //第四类
			{
				transform2(932,724,list[31].count,c);
			}		
            if(i==4&&*flag==0)          //第五类第一张
			{
				transform2(932,724,list[37].count,c);
			}
            if(i==4&&*flag==3)          //第五类第二张
			{
				transform2(932,724,list[43].count,c);
			}			
			if(i==5)                   //第六张
			{
				transform2(932,724,list[49].count,c);
			}
		}	