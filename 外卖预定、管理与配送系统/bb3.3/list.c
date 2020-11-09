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

/*列表*/
void list(struct caipin *wjcf,int *aflag)
{
	MOUSE M;
	int i,j,sum=0;
	char str[5];
	char str1[]="cai\\\\cmxx.bmp";
	char str2[]="price\\\\xx.bmp";
	char str3[]="numb\\\\nxx.bmp";
	
	if(sum!=0)
	{
	   for(i=0;i<55;i++)
      {
		if(wjcf[i].count[0]!='0')
		{
			sum+=atoi(wjcf[i].price)*atoi(wjcf[i].count);
		}
	  }
     	Putbmp64k(0,0,"numb\\js.bmp");
		for(i=0,j=0;i<55;i++)
		{
			if(wjcf[i].count[0]!='0')
			{
				j++;
				if(j==19)
				{
					Putbmp64k(973,374,"img\\xyj.bmp");
					break;
				}
				if(i<9)
				{
					i+=1;
					itoa(i,str,10);
					str1[7]='0';
					str1[8]=str[0];
				}
				else
				{
					i+=1;
					itoa(i,str,10);
					str1[7]=str[0];
					str1[8]=str[1];
				}
				i-=1;
				change(str2,wjcf[i].price);
				change(str3,wjcf[i].count);
				Putbmp64k(100,155+30*(j-1),str1);
				Putbmp64k(478,153+30*(j-1),str2);
				Putbmp64k(873,151+30*(j-1),str3);
			}
	    }
	  while(1)
	  {
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(983,384,1013,414)==1)
		{
			Putbmp64k(0,0,"numb\\js2.bmp");
		    for(;i<55;i++)
			{
			  if(wjcf[i].count[0]!='0')
			  {
				j++;
				  if(j==37)
				{
					Putbmp64k(973,374,"img\\xyj.bmp");
					break;
				}
				i+=1;
				itoa(i,str,10);
				str1[7]=str[0];
				str1[8]=str[1];
				i-=1;
				change(str2,wjcf[i].price);
				change(str3,wjcf[i].count);
				Putbmp64k(100,155+30*(j-20),str1);
				Putbmp64k(478,153+30*(j-20),str2);
				Putbmp64k(873,151+30*(j-20),str3);
				//sum+=atoi(wjcf[i].price)*atoi(wjcf[i].count);
			  }
			}
			//printASC32_16(string1,847,705,1);
		}
		if(MouseBarLeft(17,24,135,51)==1)                //上一级
		{
			*aflag=1;
			break;
		}
		if(MouseBarLeft(17,381,47,411)==1)               //上一页
		{
			Putbmp64k(0,0,"numb\\js.bmp");
	        for(i=0,j=0;i<55;i++)
		    {
			
			if(wjcf[i].count[0]!='0')
			{
				j++;
				if(j==19)
				{
					Putbmp64k(973,374,"img\\xyj.bmp");
					break;
				}
				if(i<9)
				{
					i+=1;
					itoa(i,str,10);
					str1[7]='0';
					str1[8]=str[0];
				}
				else
				{
					i+=1;
					itoa(i,str,10);
					str1[7]=str[0];
					str1[8]=str[1];
				}
				i-=1;
				change(str2,wjcf[i].price);
				change(str3,wjcf[i].count);
				Putbmp64k(100,155+30*(j-1),str1);
				Putbmp64k(478,153+30*(j-1),str2);
				Putbmp64k(873,151+30*(j-1),str3);
		    }
			//Putbmp64k(847,702,"img\\bk3.bmp");
		    //printASC32_16(string1,847,705,1);
		    }
		}
		if(MouseBarLeft(929,18,1001,57)==1)                        //退出
		{
			exit(0);
		}			
		if(MouseBarLeft(900,707,1024,768)==1)                      //确认
		{
			*aflag=4;
			break;
		}
	}
    }
	else
		{
			*aflag=1;
		}
}

void list1(struct caipin *wjcf,int *aflag)
{
	MOUSE M;
	int i,j,m,n,l,k,flag,sum=0;
	char str[5];
	char str1[]="cai\\\\cmxx.bmp";
	char str2[]="price\\\\xx.bmp";
	char str3[]="numb\\\\nxx.bmp";
	char string[15];
	
	for(i=0;i<55;i++)
	{
		if(wjcf[i].count[0]!='0')
		{
			sum+=atoi(wjcf[i].price)*atoi(wjcf[i].count);
			itoa(sum,string,10);
		}
	}
	if(sum!=0)
	{
		flag=0;
		Putbmp64k(0,0,"numb\\js.bmp");
		printASC32_16(string,210,728,1);
		for(i=0,j=0;i<55;i++)
		{
			if(wjcf[i].count[0]!='0')
			{
				j++;
				if(j==19)
				{
					j-=1;
					Putbmp64k(985,374,"img\\xyj.bmp");
					break;
				}
				if(i<9)
				{
					i+=1;
					itoa(i,str,10);
					str1[7]='0';
					str1[8]=str[0];
				}
				else
				{
					i+=1;
					itoa(i,str,10);
					str1[7]=str[0];
					str1[8]=str[1];
				}
				i-=1;
				change(str2,wjcf[i].price);
				change(str3,wjcf[i].count);
				Putbmp64k(100,155+30*(j-1),str1);
				Putbmp64k(478,153+30*(j-1),str2);
				Putbmp64k(873,151+30*(j-1),str3);
				Putbmp64k(844,153+30*(j-1),"img\\jian.bmp");
				Putbmp64k(904,153+30*(j-1),"img\\jia.bmp");
				Putbmp64k(963,153+30*(j-1),"img\\shanc.bmp");
			}
		}
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(990,384,1024,414)==1)
		{
			flag=1;
			Putbmp64k(0,0,"numb\\js2.bmp");
		    for(j=18;i<55;i++)
			{
			  if(wjcf[i].count[0]!='0')
			  {
				j++;
			    if(j==37)
				{
					j-=1;
					Putbmp64k(985,374,"img\\xyj.bmp");
					break;
				}
				i+=1;
				itoa(i,str,10);
				str1[7]=str[0];
				str1[8]=str[1];
				i-=1;
				change(str2,wjcf[i].price);
				change(str3,wjcf[i].count);
				Putbmp64k(100,155+30*(j-19),str1);
				Putbmp64k(478,153+30*(j-19),str2);
				Putbmp64k(873,151+30*(j-19),str3);
				Putbmp64k(844,153+30*(j-19),"img\\jian.bmp");
				Putbmp64k(904,153+30*(j-19),"img\\jia.bmp");
				Putbmp64k(963,153+30*(j-19),"img\\shanc.bmp");
			  }
			}
			Putbmp64k(208,723,"img\\bk12.bmp");
		    printASC32_16(string,210,728,1);
		}
        m=(M.y-123)/30;
		if(j<19&&M.x>843&&M.x<872&&m>0&&m<=j&&M.but==1&&flag==0)
		{
			for(n=0,l=0;n<m;l++)
			{
				if(wjcf[l].count[0]!='0')
				{
					n+=1;
				}
			}
			l--;
		    transform3(873,123+30*m,wjcf[l].count,'-');	
			for(k=0,sum=0;k<55;k++)
	        {
		        if(wjcf[k].count[0]!='0')
		        {
		           	sum+=atoi(wjcf[k].price)*atoi(wjcf[k].count);
			        itoa(sum,string,10);
		        }
           	}
			Putbmp64k(208,723,"img\\bk12.bmp");
	        printASC32_16(string,210,728,1);
		}
		if(j>18&&M.x>843&&M.x<872&&m>0&&m<=(j-18)&&M.but==1&&flag==1)
		{
			m+=18;
			for(n=0,l=0;n<m;l++)
			{
				if(wjcf[l].count[0]!='0')
				{
					n+=1;
				}
			}
			l--;
			m-=18;
		    transform3(873,123+30*m,wjcf[l].count,'-');
			for(k=0,sum=0;k<55;k++)
	        {
		        if(wjcf[k].count[0]!='0')
		        {
		           	sum+=atoi(wjcf[k].price)*atoi(wjcf[k].count);
			        itoa(sum,string,10);
		        }
           	}
			Putbmp64k(208,723,"img\\bk12.bmp");
	        printASC32_16(string,210,728,1);			
		}
		if(j<19&&M.x>905&&M.x<932&&m>0&&m<=j&&M.but==1&&flag==0)
		{
			for(n=0,l=0;n<m;l++)
			{
				if(wjcf[l].count[0]!='0')
				{
					n+=1;
				}
			}
			l--;
		    transform3(873,123+30*m,wjcf[l].count,'+');	
			for(k=0,sum=0;k<55;k++)
	        {
		        if(wjcf[k].count[0]!='0')
		        {
		           	sum+=atoi(wjcf[k].price)*atoi(wjcf[k].count);
			        itoa(sum,string,10);
		        }
           	}
			Putbmp64k(208,723,"img\\bk12.bmp");
	        printASC32_16(string,210,728,1);
		}
		if(j>18&&M.x>905&&M.x<932&&m>0&&m<=(j-18)&&M.but==1&&flag==1)
		{
			m+=18;
			for(n=0,l=0;n<m;l++)
			{
				if(wjcf[l].count[0]!='0')
				{
					n+=1;
				}
			}
			l--;
			m-=18;
		    transform3(873,123+30*m,wjcf[l].count,'+');	
			for(i=0,sum=0;i<55;i++)
	        {
		        if(wjcf[i].count[0]!='0')
		        {
		           	sum+=atoi(wjcf[i].price)*atoi(wjcf[i].count);
			        itoa(sum,string,10);
		        }
           	}
			Putbmp64k(208,723,"img\\bk12.bmp");
	        printASC32_16(string,210,728,1);
		}
		if(j<19&&M.x>963&&M.x<988&&m>0&&m<=j&&M.but==1&&flag==0)
		{
			for(n=0,l=0;n<m;l++)
			{
				if(wjcf[l].count[0]!='0')
				{
					n+=1;
				}
			}
			l--;
			strcpy(wjcf[l].count,"0");
			break;
		}
		if(j>18&&M.x>963&&M.x<988&&m>0&&m<=(j-18)&&M.but==1&&flag==1)
		{
			m+=18;
			for(n=0,l=0;n<m;l++)
			{
				if(wjcf[l].count[0]!='0')
				{
					n+=1;
				}
			}
			l--;
			strcpy(wjcf[l].count,"0");
			break;
		}
		if(MouseBarLeft(17,24,135,51)==1)                //上一级
		{
			*aflag=1;
			break;
		}
		if(MouseBarLeft(17,381,47,411)==1)               //上一页
		{
			flag=0;
			Putbmp64k(0,0,"numb\\js.bmp");
	       for(i=0,j=0;i<55;i++)
		   {
			if(wjcf[i].count[0]!='0')
			{
				j++;
				if(j==19)
				{
					j-=1;
					Putbmp64k(990,374,"img\\xyj.bmp");
					break;
				}
				if(i<9)
				{
					i+=1;
					itoa(i,str,10);
					str1[7]='0';
					str1[8]=str[0];
				}
				else
				{
					i+=1;
					itoa(i,str,10);
					str1[7]=str[0];
					str1[8]=str[1];
				}
				i-=1;
				change(str2,wjcf[i].price);
				change(str3,wjcf[i].count);
				Putbmp64k(100,155+30*(j-1),str1);
				Putbmp64k(478,153+30*(j-1),str2);
				Putbmp64k(873,151+30*(j-1),str3);
				Putbmp64k(844,153+30*(j-1),"img\\jian.bmp");
				Putbmp64k(904,153+30*(j-1),"img\\jia.bmp");
				Putbmp64k(963,153+30*(j-1),"img\\shanc.bmp");
		      }
		    }
	        Putbmp64k(208,723,"img\\bk12.bmp");
	        printASC32_16(string,210,728,1);		
		}
		if(MouseBarLeft(929,18,1001,57)==1)                        //退出
		{
			exit(0);
		}			
		if(MouseBarLeft(900,707,1024,768)==1)                      //确认
		{
			*aflag=4;
			break;
		}
	}
    }
	else
		{
			*aflag=1;
		}
}
