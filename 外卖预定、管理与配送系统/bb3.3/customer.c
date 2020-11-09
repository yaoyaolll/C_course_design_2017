#include "head.h"
#include "SVGAmode.h"
#include "input.h"
#include "mouse.h"
#include "customer.h"
#include "manager.h"
#include "revise.h"
#include "store.h"
#include "account.h"
#include "list.h"


/* struct Customer
{
	char Account[20];
	char Password[20];
}; */

/*存储输入账号密码*/
/* struct IsCustomer{
	char Account[20];
	char Password[20];
	int count1;            
	int posx1;             
	int count2;         
	int posx2;             
}IsCus; */

void customer(void)
{
	int zflag;                                           //参数，检测账号密码是否正确
	MOUSE M;
	char account[20];                      //将账号名传递
	User Cus={"","",0,392,0,392};
	Putbmp64k(0,0,"img\\yhdl.bmp");
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);          //初始化鼠标                     
		if(MouseBarLeft(350,354,674,405)==1)      //账号框
		{
			inputzh(392,674,374,&Cus);
		}
		if(MouseBarLeft(350,424,674,478)==1)      //密码框
		{
			inputmm(392,674,444,&Cus);
		}
		if(MouseBarLeft(352,496,671,547)==1)      //登陆
		{
			if((strcmp(Cus.Account,"")!=0)&&(strcmp(Cus.Password,"")!=0))
			{
			    Login(&Cus,&zflag);
			    if(zflag==1)
			    {
					strcpy(account,Cus.Account);
				    customer_revise(account);
				    break;
			    }
			}			
		}
		if(MouseBarLeft(350,567,671,616)==1)      //注册
		{
			Register(&Cus);
		}
	}
}

/*用户登录函数*/
void Login(User *Cus,int *zflag)
{
	struct Customer *info=NULL;  
	struct time_config Time={"",""};
	char *s;
	int count=0;                    
	long offset;                  
	FILE *fp;
	int i;
	int flag=1;
	if((fp=fopen("user.txt","r"))==NULL)
	{
		printf("Can not open the file(user.txt).");
		getch();
		exit(0);
	}
	fseek(fp,0,SEEK_END);      //文件指针指向文件尾，SEEK_END=2        
	offset=ftell(fp);          //文件头到文件尾的偏移量    
	count=offset/LEN1;          //已经注册的组数
	rewind(fp);                //fp指向文件头     
	for(i=0;i<count;i++)       //对比
	{
		fread(&info[i],LEN1,1,fp);
		if(strcmp(info[i].Account,Cus->Account)==0)	
		{
			if(strcmp(info[i].Password,Cus->Password)==0)
			{
				fclose(fp);
				time_out(s);
				if((fp=fopen("time.txt","r+"))==NULL)
				{
					printf("error");
					getch();
					exit(0);
				}
				fseek(fp,LEN3*i,0);
				fread(&Time,LEN3,1,fp);
				strcpy(Time.time2,s);
				fseek(fp,LEN3*i,0);
				fwrite(&Time,LEN3,1,fp);
				fclose(fp);
				Putbmp64k(0,0,"img\\store.bmp");
			    *zflag=1;
				break;
			}
			flag=0;                               //账号正确，密码错误
			printhz16(690,510,"密码错误",0);
			delay(500);
		    Putbmp64k(690,510,"img\\bk2.bmp");
		}
	}
	if(i==count&&flag==1)                                  //账号未被检索到
	{
		fclose(fp);
		printASC("hadn't been registered.",690,510,1,1,0xfc0303);
		delay(500);
		Putbmp64k(690,510,"img\\bk2.bmp");
	}
}

/*用户注册*/
void Register(User *Cus)
{
	FILE *fp=NULL;
	char *s;
	struct time_config Time={"",""};
	if((strcmp(Cus->Account,"")!=0)&&(strcmp(Cus->Password,"")!=0))     //账号和密码都必须不为空值
			{   
				if(Register_check(Cus)==1)               //用户名未被注册
				{
					if((fp=fopen("user.txt","r+"))==NULL)
	                {
		                printf("can not open the file(user.txt).");
		                getch();
		                exit(0);
	                }
					fseek(fp,0,SEEK_END);       //文件指针指向文件尾
					fwrite(Cus,LEN1,1,fp);
					fclose(fp);
					
					time_out(s);
					strcpy(Time.time1,s);
					strcpy(Time.time2,s);
					
					if((fp=fopen("time.txt","r+"))==NULL)
					{
						printf("error");
						getch();
						exit(0);
					}
					fseek(fp,0,SEEK_END);
					fwrite(&Time,LEN3,1,fp);
					fclose(fp);
					
					printhz16(450,700,"注册成功",0xfc0303);
		            delay(500);
					Putbmp64k(450,700,"img\\bk4.bmp");
				}
				else                                      //用户名已被注册
				{
					printhz16(450,700,"用户名已被注册",0xfc0303);
					delay(500);
					Putbmp64k(450,700,"img\\bk4.bmp");
				}
			}
}


/*用户注册函数账户密码校对及存储*/
int Register_check(User *Cus)
{
	FILE *fp;
	struct Customer *info=NULL;
	int count=0;
	long offset;
	int i;
	int out;
	if((fp=fopen("user.txt","r+"))==NULL)
	{
		printf("can not open the file(user.txt).");
		getch();
		exit(0);
	}
	fseek(fp,0,SEEK_END);       //文件指针指向文件尾
	offset=ftell(fp);           //文件头到文件尾的偏移量
	rewind(fp);                 //fp指向文件头
	count=offset/LEN1;           //已经注册的组数
	for(i=0;i<count;i++)        //检查用户名是否重复
	{
		fread(&info[i],LEN1,1,fp);
		if(strcmp(info[i].Account,Cus->Account)==0)
		{
			break;              //检索到相同用户名时，退出循环
		}
	}
	fclose(fp);             //关闭fp
	if(i==count)            //用户名未被注册
	{
		out=1;
	}
	else                    //用户名已被注册
	{
		out=0;
	}
	return out;             //返回out值
}
/*读取系统时间，保存为数组*/
void time_out(char *s)
{
    char temp[5]; 	
    time_t timep;  
    struct tm *p;  
	int i;
	int count=0;
    time(&timep);  
    p =localtime(&timep); 

    itoa(1900+p->tm_year,temp,10);
    for(i=0;i<4;i++,count++)
	{
		s[count]=temp[i];
	}		
	s[count++]='-';
	itoa(1+p->tm_mon,temp,10);
	for(i=0;i<strlen(temp);i++,count++)
	{
		s[count]=temp[i];
	}
	s[count++]='-';
	itoa(p->tm_mday,temp,10);
	for(i=0;i<strlen(temp);i++,count++)
	{
		s[count]=temp[i];
	}
	s[count++]=' ';
	itoa(p->tm_hour,temp,10);
	if(strlen(temp)==1)
	{
		s[count++]='0';
		s[count++]=temp[0];
	}
	else
	{
		for(i=0;i<2;i++,count++)
		{
			s[count]=temp[i];
		}
	}
	s[count++]=':';
	itoa(p->tm_min,temp,10);
	if(strlen(temp)==1)
	{
		s[count++]='0';
		s[count++]=temp[0];
	}
	else
	{
		for(i=0;i<2;i++,count++)
		{
			s[count]=temp[i];
		}
	}
	s[count]='\0';
}