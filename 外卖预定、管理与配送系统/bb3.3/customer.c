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

/*�洢�����˺�����*/
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
	int zflag;                                           //����������˺������Ƿ���ȷ
	MOUSE M;
	char account[20];                      //���˺�������
	User Cus={"","",0,392,0,392};
	Putbmp64k(0,0,"img\\yhdl.bmp");
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);          //��ʼ�����                     
		if(MouseBarLeft(350,354,674,405)==1)      //�˺ſ�
		{
			inputzh(392,674,374,&Cus);
		}
		if(MouseBarLeft(350,424,674,478)==1)      //�����
		{
			inputmm(392,674,444,&Cus);
		}
		if(MouseBarLeft(352,496,671,547)==1)      //��½
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
		if(MouseBarLeft(350,567,671,616)==1)      //ע��
		{
			Register(&Cus);
		}
	}
}

/*�û���¼����*/
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
	fseek(fp,0,SEEK_END);      //�ļ�ָ��ָ���ļ�β��SEEK_END=2        
	offset=ftell(fp);          //�ļ�ͷ���ļ�β��ƫ����    
	count=offset/LEN1;          //�Ѿ�ע�������
	rewind(fp);                //fpָ���ļ�ͷ     
	for(i=0;i<count;i++)       //�Ա�
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
			flag=0;                               //�˺���ȷ���������
			printhz16(690,510,"�������",0);
			delay(500);
		    Putbmp64k(690,510,"img\\bk2.bmp");
		}
	}
	if(i==count&&flag==1)                                  //�˺�δ��������
	{
		fclose(fp);
		printASC("hadn't been registered.",690,510,1,1,0xfc0303);
		delay(500);
		Putbmp64k(690,510,"img\\bk2.bmp");
	}
}

/*�û�ע��*/
void Register(User *Cus)
{
	FILE *fp=NULL;
	char *s;
	struct time_config Time={"",""};
	if((strcmp(Cus->Account,"")!=0)&&(strcmp(Cus->Password,"")!=0))     //�˺ź����붼���벻Ϊ��ֵ
			{   
				if(Register_check(Cus)==1)               //�û���δ��ע��
				{
					if((fp=fopen("user.txt","r+"))==NULL)
	                {
		                printf("can not open the file(user.txt).");
		                getch();
		                exit(0);
	                }
					fseek(fp,0,SEEK_END);       //�ļ�ָ��ָ���ļ�β
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
					
					printhz16(450,700,"ע��ɹ�",0xfc0303);
		            delay(500);
					Putbmp64k(450,700,"img\\bk4.bmp");
				}
				else                                      //�û����ѱ�ע��
				{
					printhz16(450,700,"�û����ѱ�ע��",0xfc0303);
					delay(500);
					Putbmp64k(450,700,"img\\bk4.bmp");
				}
			}
}


/*�û�ע�ắ���˻�����У�Լ��洢*/
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
	fseek(fp,0,SEEK_END);       //�ļ�ָ��ָ���ļ�β
	offset=ftell(fp);           //�ļ�ͷ���ļ�β��ƫ����
	rewind(fp);                 //fpָ���ļ�ͷ
	count=offset/LEN1;           //�Ѿ�ע�������
	for(i=0;i<count;i++)        //����û����Ƿ��ظ�
	{
		fread(&info[i],LEN1,1,fp);
		if(strcmp(info[i].Account,Cus->Account)==0)
		{
			break;              //��������ͬ�û���ʱ���˳�ѭ��
		}
	}
	fclose(fp);             //�ر�fp
	if(i==count)            //�û���δ��ע��
	{
		out=1;
	}
	else                    //�û����ѱ�ע��
	{
		out=0;
	}
	return out;             //����outֵ
}
/*��ȡϵͳʱ�䣬����Ϊ����*/
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