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
#include "manda.h"

void recai(struct caipin *list,int *fen,int *flag)                       //热菜
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
			show_init1(list);
		}
	    if(i==2)
		{
			Putbmp64k(0,192,"img\\s221.bmp");
			fen[0]=1;
		    Putbmp64k(0,72,"img\\s20.bmp");
		    Putbmp64k(117,72,"img\\s10.bmp");
			show_init1(list);
        }
		if(i==3)
		{
       		Putbmp64k(0,252,"img\\s231.bmp");
			fen[0]=1;
		    Putbmp64k(0,72,"img\\s20.bmp");
		    Putbmp64k(117,72,"img\\s10.bmp");
     		show_init1(list);
		}
		if(i==4)
		{
			Putbmp64k(0,312,"img\\s241.bmp");
			fen[0]=1;
		    Putbmp64k(0,72,"img\\s20.bmp");
		    Putbmp64k(117,72,"img\\s10.bmp");
			show_init1(list);
		}
		if(i==5)
		{	
			Putbmp64k(0,372,"img\\s251.bmp");
			fen[0]=1;
		    Putbmp64k(0,72,"img\\s20.bmp");
		    Putbmp64k(117,72,"img\\s10.bmp");
			show_init1(list);
	    }
		if(i==6)
		{
			Putbmp64k(0,432,"img\\s261.bmp");
			fen[0]=1;
		    Putbmp64k(0,72,"img\\s20.bmp");
		    Putbmp64k(117,72,"img\\s10.bmp");
			show_init1(list);
        }
}

void gaijiaofan(struct caipin *list,int *fen,int *flag)                  //盖浇饭
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
				show_init3(list);
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
				show_init3(list);
	        }
			if(i==3)
			{
         		Putbmp64k(0,252,"img\\s231.bmp");
				fen[1]=1;
			    Putbmp64k(0,132,"img\\s21.bmp");
			    Putbmp64k(117,72,"img\\s11.bmp");
				show_init3(list);
			}
			if(i==4)
			{
				Putbmp64k(0,312,"img\\s241.bmp");
				fen[1]=1;
			    Putbmp64k(0,132,"img\\s21.bmp");
			    Putbmp64k(117,72,"img\\s11.bmp");
				show_init3(list);
			}
			if(i==5)
			{	
				Putbmp64k(0,372,"img\\s251.bmp");
				fen[1]=1;
			    Putbmp64k(0,132,"img\\s21.bmp");
			    Putbmp64k(117,72,"img\\s11.bmp");
				show_init3(list);
		    }
			if(i==6)
			{
				Putbmp64k(0,432,"img\\s261.bmp");
				fen[1]=1;
			    Putbmp64k(0,132,"img\\s21.bmp");
			    Putbmp64k(117,72,"img\\s11.bmp");
				show_init3(list);
            }
}
void ganguolei(struct caipin *list,int *fen,int *flag)                     //干锅类
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
				show_init5(list);
			}
			if(i==1)
			{
				Putbmp64k(0,132,"img\\s211.bmp");
				fen[2]=1;
			    Putbmp64k(0,192,"img\\s22.bmp");
			    Putbmp64k(117,72,"img\\s12.bmp");
				show_init5(list);
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
				show_init5(list);
			}
			if(i==4)
			{
				Putbmp64k(0,312,"img\\s241.bmp");
				fen[2]=1;
			    Putbmp64k(0,192,"img\\s22.bmp");
			    Putbmp64k(117,72,"img\\s12.bmp");
				show_init5(list);
			}
			if(i==5)
			{	
				Putbmp64k(0,372,"img\\s251.bmp");
				fen[2]=1;
			    Putbmp64k(0,192,"img\\s22.bmp");
			    Putbmp64k(117,72,"img\\s12.bmp");
				show_init5(list);
		    }
			if(i==6)
			{
				Putbmp64k(0,432,"img\\s261.bmp");
				fen[2]=1;
			    Putbmp64k(0,192,"img\\s22.bmp");
			    Putbmp64k(117,72,"img\\s12.bmp");
				show_init5(list);
            }
}
void liangcai(struct caipin *list,int *fen,int *flag)                           //凉菜
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
				show_init6(list);
			}
			if(i==1)
			{
				Putbmp64k(0,132,"img\\s211.bmp");
				fen[3]=1;
			    Putbmp64k(0,252,"img\\s23.bmp");
			    Putbmp64k(117,72,"img\\s13.bmp");
				show_init6(list);
			}
		    if(i==2)
			{
				Putbmp64k(0,192,"img\\s221.bmp");
				fen[3]=1;
			    Putbmp64k(0,252,"img\\s23.bmp");
			    Putbmp64k(117,72,"img\\s13.bmp");
				show_init6(list);
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
				show_init6(list);
			}
			if(i==5)
			{	
				Putbmp64k(0,372,"img\\s251.bmp");
				fen[3]=1;
			    Putbmp64k(0,252,"img\\s23.bmp");
			    Putbmp64k(117,72,"img\\s13.bmp");
				show_init6(list);
		    }
			if(i==6)
			{
				Putbmp64k(0,432,"img\\s261.bmp");
				fen[3]=1;
			    Putbmp64k(0,252,"img\\s23.bmp");
			    Putbmp64k(117,72,"img\\s13.bmp");
				show_init6(list);
            }
}
void xiaocao(struct caipin *list,int *fen,int *flag)                       //家常小炒
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
				show_init7(list);
			}
			if(i==1)
			{
				Putbmp64k(0,132,"img\\s211.bmp");
			    fen[4]=1;
			    Putbmp64k(0,312,"img\\s24.bmp");
		        Putbmp64k(117,72,"img\\s14.bmp");
				show_init7(list);
			}
		    if(i==2)
			{
				Putbmp64k(0,192,"img\\s221.bmp");
				fen[4]=1;
			    Putbmp64k(0,312,"img\\s24.bmp");
		        Putbmp64k(117,72,"img\\s14.bmp");
				show_init7(list);
	        }
			if(i==3)
			{
         		Putbmp64k(0,252,"img\\s231.bmp");
				fen[4]=1;
			    Putbmp64k(0,312,"img\\s24.bmp");
		        Putbmp64k(117,72,"img\\s14.bmp");
				show_init7(list);
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
				show_init7(list);
		    }
			if(i==6)
			{
				Putbmp64k(0,432,"img\\s261.bmp");
				fen[4]=1;
			    Putbmp64k(0,312,"img\\s24.bmp");
		        Putbmp64k(117,72,"img\\s14.bmp");
				show_init7(list);
            }
}
void zhuxhi(struct caipin *list,int *fen,int *flag)                           //主食
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
				show_init9(list);
			}
			if(i==1)
			{
				Putbmp64k(0,132,"img\\s211.bmp");
				fen[5]=1;
			    Putbmp64k(0,372,"img\\s25.bmp");
			    Putbmp64k(117,72,"img\\s15.bmp");
				show_init9(list);
			}
		    if(i==2)
			{
				Putbmp64k(0,192,"img\\s221.bmp");
				fen[5]=1;
			    Putbmp64k(0,372,"img\\s25.bmp");
			    Putbmp64k(117,72,"img\\s15.bmp");
				show_init9(list);
	        }
			if(i==3)
			{
         		Putbmp64k(0,252,"img\\s231.bmp");
				fen[5]=1;
			    Putbmp64k(0,372,"img\\s25.bmp");
			    Putbmp64k(117,72,"img\\s15.bmp");
				show_init9(list);
			}
			if(i==4)
			{
				Putbmp64k(0,312,"img\\s241.bmp");
				fen[5]=1;
			    Putbmp64k(0,372,"img\\s25.bmp");
			    Putbmp64k(117,72,"img\\s15.bmp");
				show_init9(list);
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
				show_init9(list);
            }
}
void yinliao(struct caipin *list,int *fen,int *flag)                              //饮料
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
				show_init10(list);
			}
			if(i==1)
			{
				Putbmp64k(0,132,"img\\s211.bmp");
				fen[6]=1;
			    Putbmp64k(0,432,"img\\s26.bmp");
			    Putbmp64k(117,72,"img\\s16.bmp");
				show_init10(list);
			}
		    if(i==2)
			{
				Putbmp64k(0,192,"img\\s221.bmp");
				fen[6]=1;
			    Putbmp64k(0,432,"img\\s26.bmp");
			    Putbmp64k(117,72,"img\\s16.bmp");
				show_init10(list);
	        }
			if(i==3)
			{
         		Putbmp64k(0,252,"img\\s231.bmp");
				fen[6]=1;
			    Putbmp64k(0,432,"img\\s26.bmp");
			    Putbmp64k(117,72,"img\\s16.bmp");
				show_init10(list);
			}
			if(i==4)
			{
				Putbmp64k(0,312,"img\\s241.bmp");
				fen[6]=1;
			    Putbmp64k(0,432,"img\\s26.bmp");
			    Putbmp64k(117,72,"img\\s16.bmp");
				show_init10(list);
			}
			if(i==5)
			{	
				Putbmp64k(0,372,"img\\s251.bmp");
				fen[6]=1;
			    Putbmp64k(0,432,"img\\s26.bmp");
			    Putbmp64k(117,72,"img\\s16.bmp");
				show_init10(list);
		    }
			if(i==6)
			{ 
				fen[6]=1;
			}
}