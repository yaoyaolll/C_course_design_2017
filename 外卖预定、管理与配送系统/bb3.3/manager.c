#include "head.h"
#include "SVGAmode.h"
#include "input.h"
#include "mouse.h"
#include "manager.h"
#include "show_price.h"
#include "Cai_Config.h"
#include "reprice.h"
#include "list.h"

void manager(void) 
{
	MOUSE M;
	User Adm={"123","123"};     //�˺�����
	User IsAdm={"","",0,399,0,399};   //�����ʼ��      	
	Putbmp64k(0,0,"img\\gly.bmp");
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
	    MouseDraw(M);
		delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(352,355,674,406)==1)     
		{
			inputzh(399,665,375,&IsAdm);
		}
		if(MouseBarLeft(353,425,674,477)==1)     
		{
			inputmm(399,665,445,&IsAdm);
		}
		if(MouseBarLeft(352,497,674,546)==1)
		{
			if((strcmp(IsAdm.Account,"")!=0)&&(strcmp(IsAdm.Password,"")!=0))
			{
			    if(strcmp(Adm.Account,IsAdm.Account)==0)
			    {
				    if(strcmp(Adm.Password,IsAdm.Password)==0)
				    {
					    manager_init();
					    break;
				    }
				    else
				    {
					    printhz16(715,447,"�������",0xfc0303);
					    delay(500);
					    Putbmp64k(715,447,"img\\bk2.bmp");
				    }
			    }
			    else
			    {
				    printhz16(715,447,"�������",0xfc0303);
				    delay(500);
				    Putbmp64k(715,447,"img\\bk2.bmp");
			    }
			}
		}
	}
}
/*ѡ�����Ա���ܽ���*/
void manager_init(void)
{
	MOUSE M;
	int aflag=2;
	Putbmp64k(0,0,"img\\glyxx.bmp");
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
	    MouseDraw(M);
		delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(398,186,704,282)==1&&aflag==2)     //��Ʒ��Ϣ
		{
			manager_revise();
		}
		if(MouseBarLeft(398,483,709,585)==1&&aflag==2)     //������Ϣ
		{
			manager_order(&aflag);
		}
		if(MouseBarLeft(403,335,706,432)==1&&aflag==2)     //�û���Ϣ
		{
			manager_user();
		}
		if(MouseBarLeft(917,14,1013,63)==1&&aflag==2)       //�˳�
		{
			exit(0);
		}
		if(MouseBarLeft(24,14,101,56)==1&&aflag==2)          //ע��
		{
			Putbmp64k(0,0,"img\\dl1.bmp");
			break;
		}
		if(aflag==1)               //ɾ��������Ϣ
		{
			manager_order(&aflag);
		}
	}
}
/*�鿴���޸Ķ�����Ϣ*/
void manager_order(int *aflag)
{
	MOUSE M;
	FILE *fp;
	int count=0;
	int i,j;
	int sum=0;
	int offset;
	struct order Order={"","","","","","",""};
	char str1[]="numb\\\\nxx.bmp";
	char *str2=NULL;
	Putbmp64k(0,0,"img\\yhxx.bmp");
	if((fp=fopen("ord.txt","r"))==NULL)
	{
		printf("error.");
		getch();
		exit(0);
	}
	fseek(fp,0,SEEK_END);
	offset=ftell(fp);
	count=offset/LEN2;
	rewind(fp);
	fread(&Order,LEN2,1,fp);
	if(count>12)
		count=12;
	if(count==0)
		{
			Putbmp64k(253,176,"img\\bqb.bmp");         //δ��ѯ����ʷ����
		}
	if(count!=0)
	{
		for(i=0;i<count;i++)
		{
			itoa(i+1,str2,10);
			change(str1,str2);
			Putbmp64k(0,123+50*i,str1);
			printASC(Order.order_time,35,135+50*i,1,1,1);
			printASC(Order.account,181,135+50*i,1,1,1);
			printASC(Order.name,298,135+50*i,1,1,1);
			printASC(Order.number,447,135+50*i,1,1,1);
			if(Order.address[0]=='0')  //��Է
			{
				printhz16(604,132+50*i,"��Է",1);
				printASC(Order.building,642,135+50*i,1,1,1);
				printhz16(664,132+50*i,"��",1);
			}
			if(Order.address[0]=='1')  //��Է
			{
				printhz16(604,132+50*i,"��Է",1);
				printASC(Order.building,642,135+50*i,1,1,1);
				printhz16(664,132+50*i,"��",1);
			}
			if(Order.address[0]=='2')  //��ݿ
			{
				printhz16(604,132+50*i,"��ݿ",1);
				printASC(Order.building,642,135+50*i,1,1,1);
				printhz16(664,132+50*i,"��",1);
			}
			for(j=0;j<55;j++)
			{
				if(Order.cai[j].count[0]!='0')
					sum+=(atoi(Order.cai[j].price)*atoi(Order.cai[j].count));
			}
			sum=sum+6;
			itoa(sum,str2,10);
			printASC(str2,780,135+50*i,1,1,1);
			sum=0;
			Putbmp64k(904,128+50*i,"img\\xxxx.bmp");
			Putbmp64k(977,128+50*i,"img\\sc.bmp");
			if(i!=(count-1))
			{
				fread(&Order,LEN2,1,fp);
			}
		}
	}
	fclose(fp);
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
	    MouseDraw(M);
		delay(20);
	    MousePutBk(M.x, M.y);
        if(MouseBarLeft(922,15,1009,62)==1)            //�˳�
		{
			exit(0);           
		}	
        if(MouseBarLeft(0,0,144,62)==1)                //��һ��    
		{
			Putbmp64k(0,0,"img\\glyxx.bmp");
			*aflag=2;                //��ֹ�ظ����룬ɾ����Ϣ��1
			break;
		}	
        if(MouseBarLeft(904,128,964,158)==1)           //��һ����ϸ��Ϣ
		{
			detail(1,count,aflag);
			break;
		}	
        if(MouseBarLeft(904,178,964,208)==1)           //�ڶ�����ϸ��Ϣ
		{
			detail(2,count,aflag);
			break;
		}	
        if(MouseBarLeft(904,228,964,258)==1)            //3
		{
			detail(3,count,aflag);
			break;
		}
        if(MouseBarLeft(904,258,964,308)==1)            //4
		{
			detail(4,count,aflag);
			break;
		}	
        if(MouseBarLeft(904,308,964,358)==1)            //5
		{
			detail(5,count,aflag);
			break;
		}
        if(MouseBarLeft(904,358,964,408)==1)            //6		
		{
			detail(6,count,aflag);
			break;
		}
		if(MouseBarLeft(904,408,964,458)==1)            //7
		{
			detail(7,count,aflag);
			break;
		}	
        if(MouseBarLeft(904,458,964,508)==1)            //8
		{
			detail(8,count,aflag);
			break;
		}	
        if(MouseBarLeft(904,508,964,558)==1)            //9
		{
			detail(9,count,aflag);
			break;
		}
        if(MouseBarLeft(904,558,964,608)==1)            //10
		{
			detail(10,count,aflag);
			break;
		}	
        if(MouseBarLeft(904,608,964,658)==1)            //11
		{
			detail(11,count,aflag);
			break;
		}
        if(MouseBarLeft(904,658,964,708)==1)            //12	
		{
			detail(12,count,aflag);
			break;
		}
		if(MouseBarLeft(977,128,1007,158)==1)           //��1��ɾ��
		{
			Delete(1,count,aflag);
			break;
		}
		if(MouseBarLeft(977,178,1007,208)==1)           //��2��ɾ��
		{
			Delete(2,count,aflag);
			break;
		}
		if(MouseBarLeft(977,228,1007,258)==1)           //��3��ɾ��
		{
			Delete(3,count,aflag);
			break;
		}
		if(MouseBarLeft(977,278,1007,308)==1)           //��4��ɾ��
		{
			Delete(4,count,aflag);
			break;
		}
		if(MouseBarLeft(977,328,1007,358)==1)           //��5��ɾ��
		{
			Delete(5,count,aflag);
			break;
		}
		if(MouseBarLeft(977,378,1007,408)==1)           //��6��ɾ��
		{
			Delete(6,count,aflag);
			break;
		}
		if(MouseBarLeft(977,428,1007,458)==1)           //��7��ɾ��
		{
			Delete(7,count,aflag);
			break;
		}
		if(MouseBarLeft(977,478,1007,508)==1)           //��8��ɾ��
		{
			Delete(8,count,aflag);
			break;
		}
		if(MouseBarLeft(977,528,1007,558)==1)           //��9��ɾ��
		{
			Delete(9,count,aflag);
			break;
		}
		if(MouseBarLeft(977,578,1007,608)==1)           //��10��ɾ��
		{
			Delete(10,count,aflag);
			break;
		}
		if(MouseBarLeft(977,628,1007,658)==1)           //��11��ɾ��
		{
			Delete(11,count,aflag);
			break;
		}
		if(MouseBarLeft(977,678,1007,708)==1)           //��12��ɾ��
		{
			Delete(12,count,aflag);
			break;
		}
	}
}
/*��ʾ������ϸ��Ϣ*/
void detail(int flag,int count,int *aflag)
{
	FILE *fp;
	struct order Order;
	if(count>=flag)
	{
		if((fp=fopen("ord.txt","r"))==NULL)
		{
			printf("error");
			getch();
			exit(0);
		}
		fseek(fp,(flag-1)*LEN2,0);
		fread(&Order,LEN2,1,fp);
		fclose(fp);
        List(Order.cai,aflag);		
	}
}
/*ɾ��������Ϣ*/
void Delete(int flag,int count,int *aflag)
{
	MOUSE M;
	FILE *fp;
	int offset;
	int i=0;
	struct order *Order;
	if(count>=flag)
	{
		Putbmp64k(217,172,"img\\delete.bmp");    //�Ƿ�ɾ������
		while(1)
		{
			MouseXYB(&M);
			MouseStoreBk(M.x, M.y);
			MouseDraw(M);
			delay(20);
			MousePutBk(M.x, M.y);
			if(MouseBarLeft(410,501,547,570)==1)    //ȷ��
			{
			    if((fp=fopen("ord.txt","r+"))==NULL)
				{
					printf("error.");
					getch();
					exit(0);
				}
				fseek(fp,0,2);
				offset=ftell(fp);
				i=offset/LEN2;
				rewind(fp);
                fseek(fp,flag*LEN2,0);
                fread(Order,LEN2,i-flag,fp);
                rewind(fp);
                fseek(fp,(flag-1)*LEN2,0);
                fwrite(Order,LEN2,i-flag,fp);
				rewind(fp);
				fread(Order,LEN2,i-1,fp);
                fclose(fp); 
                if((fp=fopen("ord.txt","w+"))==NULL)
				{
					printf("error.");
					getch();
					exit(0);
				}
				fclose(fp);
				if((fp=fopen("ord.txt","r+"))==NULL)
				{
					printf("error.");
					getch();
					exit(0);
				}
				fwrite(Order,LEN2,i-1,fp);
				fclose(fp);
				*aflag=1;
                break;				
			}
			if(MouseBarLeft(662,198,710,240)==1)    //��
			{
				*aflag=1;
				break;
			}
		}
	}
}
/*��Ʒ��Ϣ����*/
void manager_revise(void)
{
	FILE *fp;
	struct caipin wjcf[55]={"","",""};
	if((fp=fopen("caipin.txt","r+"))==NULL)
	{
		printf("cannot open the file.(caipin.txt)");
		getch();
		exit(0);
	}
	fread(wjcf,LEN,55,fp);                   //��caipin.txt�ļ��е����ݶ�ȡ��wjcf[55]
	fclose(fp);
	Putbmp64k(0,0,"img\\store2.bmp");         //������һ�Ž���
	show_price1(wjcf);                             //��ʼ����һ�Ž���
	show_list(wjcf);
}

/*����Ա�޸Ĳ�Ʒ�۸���ʾ��Ʒ*/
void show_list(struct caipin *wjcf)
{
	struct caipin *list=wjcf;
	MOUSE M;
	int fen[7]={1};
	int i;
	int flag=0;
	char c='-';   	//�ж���'+'���ǡ�����
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(0,72,117,130)==1)                 //�Ȳ�
     	{		
		    Recai1(&flag,fen,list);
		}
		if(MouseBarLeft(0,132,117,190)==1)                //�ǽ���
     	{		
		    Gaijiaofan(&flag,fen,list);
		}
		if(MouseBarLeft(0,192,117,250)==1)                //�ɹ���
     	{	
            Ganguo(&flag,fen,list);
		}
		if(MouseBarLeft(0,252,117,310)==1)                //����
     	{	
            Liangcai(&flag,fen,list);
		}
		if(MouseBarLeft(0,312,117,370)==1)                //�ҳ�С��
     	{		
		    Jiachang(&flag,fen,list);
		}
		if(MouseBarLeft(0,372,117,430)==1)                //��ʳ
     	{	
            Zhushi(&flag,fen,list);
		}
		if(MouseBarLeft(0,432,117,490)==1)                //����
     	{		
		    Yinliao(&flag,fen,list);
		}
		if(MouseBarLeft(995,417,1019,443)==1)             //��һҳ
		{
            Next_Page(&flag,fen,list);
		}
		if(MouseBarLeft(123,403,151,435)==1)              //��һҳ
        {
			Last_Page(&flag,fen,list);
		}
		if(MouseBarLeft(294,375,328,406)==1)     //1(-)
		{
			c='-';
			price1(&flag,fen,list,c);
		}
		if(MouseBarLeft(357,374,390,407)==1)     //1(+)
		{
			c='+';
			price1(&flag,fen,list,c);
		}
		if(MouseBarLeft(596,375,627,406)==1)     //2(-)
		{
			c='-';
			price2(&flag,fen,list,c);
		}
		if(MouseBarLeft(662,374,696,407)==1)     //2(+)
		{
			c='+';
			price2(&flag,fen,list,c);
		}
		if(MouseBarLeft(896,375,930,406)==1)     //3(-)
		{
			c='-';
			price3(&flag,fen,list,c);
		}
		if(MouseBarLeft(966,374,1000,407)==1)    //3(+)
		{
			c='+';
			price3(&flag,fen,list,c);
		}
		if(MouseBarLeft(294,722,328,755)==1)     //4(-)
		{
			c='-';
			price4(&flag,fen,list,c);
		}
		if(MouseBarLeft(357,722,390,755)==1)     //4(+)
		{
			c='+';
			price4(&flag,fen,list,c);
		}
		if(MouseBarLeft(596,722,627,755)==1)     //5(-)
		{
			c='-';
			price5(&flag,fen,list,c);
		}
		if(MouseBarLeft(662,722,696,755)==1)     //5(+)
		{
			c='+';
			price5(&flag,fen,list,c);
		}
		if(MouseBarLeft(896,722,930,755)==1)     //6(-)
		{
			c='-';
			price6(&flag,fen,list,c);
		}
		if(MouseBarLeft(966,722,1000,755)==1)    //6(+)
		{
			c='+';
			price6(&flag,fen,list,c);
		}
		if(MouseBarLeft(139,373,206,409)==1)          //��һ����
		{
			Putbmp64k(347,285,"img\\qr2.bmp");
			price_revise(fen,list,flag,1);
		}
		if(MouseBarLeft(442,373,509,409)==1)          //�ڶ�����
		{
			//count=2;
			Putbmp64k(347,285,"img\\qr2.bmp");
			price_revise(fen,list,flag,2);
		}
		if(MouseBarLeft(751,373,818,409)==1)          //��������
		{
			//count=3;
			Putbmp64k(347,285,"img\\qr2.bmp");
			price_revise(fen,list,flag,3);
		}
		if(MouseBarLeft(139,724,206,760)==1)          //���ĸ���
		{
			//count=4;
			Putbmp64k(347,285,"img\\qr2.bmp");
			price_revise(fen,list,flag,4);
		}
		if(MouseBarLeft(442,724,509,760)==1)          //�������
		{
			//count=5;
			Putbmp64k(347,285,"img\\qr2.bmp");
			price_revise(fen,list,flag,5);
		}
		if(MouseBarLeft(751,724,818,760)==1)          //��������
		{
			//count=6;
			Putbmp64k(347,285,"img\\qr2.bmp");
			price_revise(fen,list,flag,6);
		}
		if(MouseBarLeft(933,24,995,57)==1)                //�˳�
		{
			exit(0);
		}		
		if(MouseBarLeft(17,24,135,51)==1)                //��һ��
		{
			Putbmp64k(0,0,"img\\glyxx.bmp");
			break;
		}
		if(MouseBarLeft(0,707,117,768)==1)              //ȷ��
		{
			recaipin(list);
			qr();
            break;			
		}
	}
}

/*���޸ĺ���������´���caipin.txt*/
void recaipin(struct caipin *list)
{
	FILE *fp=NULL;
	if((fp=fopen("caipin.txt","r+"))==NULL)
	{
		printf("cannot open the file.(caipin.txt)");
		getch();
		exit(0);
	}
	fwrite(list,LEN,55,fp);
	fclose(fp);
}
/*���ȷ�Ϸ��ؽ���*/
void qr(void)
{
	MOUSE M;
	Putbmp64k(315,173,"img\\qr.bmp");
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
		MouseDraw(M);
	    delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(491,446,632,495)==1)
		{
			break;
		} 
	}
	Putbmp64k(0,0,"img\\glyxx.bmp");
}
/*�б�*/
void List(struct caipin *wjcf,int *aflag)
{
	MOUSE M;
	int i,j,sum=0;
	int count=0;
	char str[5];
	char Sum1[6];
	char Sum2[6];
	char str1[]="cai\\\\cmxx.bmp";
	char str2[]="price\\\\xx.bmp";
	char str3[]="numb\\\\nxx.bmp";
	Putbmp64k(0,0,"numb\\_js.bmp");
	for(i=0;i<55;i++)
	{
		if(wjcf[i].count[0]!='0')
		{
			sum+=atoi(wjcf[i].price)*atoi(wjcf[i].count);
		}
	}
	if(sum>99&&sum<200)
	{
		count=sum-10+6;
		Putbmp64k(899,713,"img\\100.bmp");
	}
	if(sum>199&&sum<500)
	{
	    count=sum-25+6;
		Putbmp64k(899,713,"img\\200.bmp");
	}
	if(sum>500)
	{
		count=sum-70+6;
		Putbmp64k(899,713,"img\\500.bmp");
	}
	itoa(sum,Sum1,10);
	itoa(count,Sum2,10);
	printASC32_16(Sum1,592,711,0);
	printASC32_16(Sum2,796,711,0);
	
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
			Putbmp64k(873,153+30*(j-1),str3);
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
			Putbmp64k(0,0,"numb\\_js2.bmp");
			if(sum>99&&sum<200)
			{
				Putbmp64k(899,713,"img\\100.bmp");
			}
			if(sum>199&&sum<500)
			{
				Putbmp64k(899,713,"img\\200.bmp");
			}
			if(sum>500)
			{
				Putbmp64k(899,713,"img\\500.bmp");
			}
			printASC32_16(Sum1,592,711,0);
	        printASC32_16(Sum2,796,711,0);
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
				Putbmp64k(873,153+30*(j-20),str3);
			  }
			}
		}
		if(MouseBarLeft(17,24,135,51)==1)                //��һ��
		{
			*aflag=1;
			break;
		}
		if(MouseBarLeft(17,381,47,411)==1)               //��һҳ
		{
			Putbmp64k(0,0,"numb\\_js.bmp");
			if(sum>99&&sum<200)
			{
				Putbmp64k(899,713,"img\\100.bmp");
			}
			if(sum>199&&sum<500)
			{
				Putbmp64k(899,713,"img\\200.bmp");
			}
			if(sum>500)
			{
				Putbmp64k(899,713,"img\\500.bmp");
			}
			printASC32_16(Sum1,592,711,0);
			printASC32_16(Sum2,796,711,0);
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
					Putbmp64k(873,153+30*(j-1),str3);
				}
			}
		}
		if(MouseBarLeft(929,18,1001,57)==1)                        //�˳�
		{
			exit(0);
		}			
	}
}
/*ֱ���޸Ĳ�Ʒ�۸�*/
void price_revise(int *fen,struct caipin *list,const int flag,const int count)   //flag�ڶ�ҳ������fen��¼��һҳ�棬count����Ĳ�Ʒλ��
{
	MOUSE M;
	int i;
	int price_count=0;    //��¼�ǵڼ������޸�
	int posx=335;
	int posx_count=0;
	char *s="";           //�洢����ļ۸�
	for(i=0;i<7;i++)
	{
	  if(fen[i]==1)
	  {
		break;
	  }
	}     //�õ�iֵ
	if(i==0&&flag==0)          //��һ���һ��
	{
		price_count=count-1;
	}
	if(flag==1)          //��һ��ڶ���
	{
		price_count=5+count;
	}
	if(i==1&&flag==0)          //�ڶ����һ��
	{
		price_count=7+count;
	}
	if(flag==2)          //�ڶ���ڶ���
	{
		price_count=13+count;
	}
	if(i==2)                     //������
	{
		price_count=19+count;
	}
	if(i==3)                     //������
	{
		price_count=25+count;
	}
	if(i==4&&flag==0)          //�������һ��
	{
		price_count=31+count;
	}
	if(flag==3)          //������ڶ���
	{
		price_count=37+count;
	}
	if(i==5)                   //������
	{
		price_count=43+count;
	}
	if(i==6)                   //������
	{
		price_count=49+count;
	}
	while(1)
	{
		MouseXYB(&M);
		MouseStoreBk(M.x, M.y);
		MouseDraw(M);
		delay(20);
		MousePutBk(M.x, M.y);
		if(MouseBarLeft(365,303,779,361)==1)     //��������
		{
			input_revise(&posx,s,&posx_count);
		}
		if(MouseBarLeft(367,375,557,417)==1)     //���ȷ��
		{
			if(posx_count!=0)
			{
				recaipin1(price_count,s,list);
				recaipin2(flag,i,list);   //ˢ�½���
				delay(50);
				break;
			}
		}
		if(MouseBarLeft(589,373,781,417)==1)     //���ȡ��
		{
			recaipin2(flag,i,list);
			delay(10);
			break;
		}
	}
}
/*ֱ���޸Ĳ�Ʒ��Ϣ�����ȷ�ϣ�д���ļ�*/
void recaipin1(int price_count,char *s,struct caipin *list)
{
	int i;
	if(s[1]=='\0')
	{
		list[price_count].price[0]=s[0];
		list[price_count].price[1]=s[1];
	}
	else
	{
		for(i=0;i<3;i++)
		{
			list[price_count].price[i]=s[i];
		}
	}	
}
/*�޸Ĳ˼�ȷ�Ϻ󷵻�ԭҳ��*/
void recaipin2(const int flag,const int i,struct caipin *list)
{
	if(i==0&&flag==0)          //��һ���һ��
	{
		Putbmp64k(117,72,"img\\s10.bmp");
		Putbmp64k(117,72,"img\\s10.bmp");
		show_price1(list);
	}
	if(flag==1)                //��һ��ڶ���
	{
		Putbmp64k(117,72,"img\\s101.bmp");
		show_price2(list);
	}
	if(i==1&&flag==0)          //�ڶ����һ��
	{
		Putbmp64k(117,72,"img\\s11.bmp");
		show_price3(list);
	}
	if(flag==2)          //�ڶ���ڶ���
	{
		Putbmp64k(117,72,"img\\s111.bmp");
		show_price4(list);
	}
	if(i==2)                     //������
	{
		Putbmp64k(117,72,"img\\s12.bmp");
		show_price5(list);
	}
	if(i==3)                     //������
	{
		Putbmp64k(117,72,"img\\s13.bmp");
		show_price6(list);
	}		
	if(i==4&&flag==0)          //�������һ��
	{
		Putbmp64k(117,72,"img\\s14.bmp");
		show_price7(list);
	}
	if(flag==3)          //������ڶ���
	{
		Putbmp64k(117,72,"img\\s141.bmp");
		show_price8(list);
	}			
	if(i==5)                   //������
	{
		Putbmp64k(117,72,"img\\s15.bmp");
		show_price9(list);
	}
	if(i==6)                   //������
	{
		Putbmp64k(117,72,"img\\s16.bmp");
		show_price10(list);
	}
}

/*��ʾ�û���Ϣ*/
void manager_user(void)
{
	FILE *fp,*fq;
	MOUSE M;
	struct Customer Cus;
	struct time_config Time;
	struct order Ord;
	int offset=0;
	int i,j;
	int count=0;
	int count1=0;
	char str1[]="numb\\\\nxx.bmp";
	char *str2;
	Putbmp64k(0,0,"img\\yhxx2.bmp");
	if((fp=fopen("user.txt","r"))==NULL)
	{
		printf("error");
		getch();
		exit(0);
	}
	fseek(fp,0,SEEK_END);
	offset=ftell(fp);
	count=offset/LEN1;
	rewind(fp);
	for(i=0;i<count;i++)
	{
		fread(&Cus,LEN1,1,fp);
		itoa(i+1,str2,10);
		change(str1,str2);
		Putbmp64k(0,125+50*i,str1);
		printASC(Cus.Account,35,135+50*i,1,1,1);
		if((fq=fopen("ord.txt","r"))==NULL)
		{
			printf("error");
			getch();
			exit(0);
		}
		fseek(fq,0,2);
		offset=ftell(fq);
		count1=offset/LEN2;
		for(j=count1-1;j>=0;j--)
		{
			rewind(fq);
			fseek(fq,LEN2*j,0);
			fread(&Ord,LEN2,1,fq);
			if(strcmp(Ord.account,Cus.Account)==0)
			{
				printASC(Ord.name,596,135+50*i,1,1,1);
				printASC(Ord.number,759,135+50*i,1,1,1);
				if(Ord.address[0]=='0')  //��Է
				{
					printhz16(891,132+50*i,"��Է",1);
					printASC(Ord.building,929,135+50*i,1,1,1);
					printhz16(951,132+50*i,"��",1);
				}
				if(Ord.address[0]=='1')  //��Է
				{
					printhz16(891,132+50*i,"��Է",1);
					printASC(Ord.building,929,135+50*i,1,1,1);
					printhz16(951,132+50*i,"��",1);
				}
				if(Ord.address[0]=='2')  //��ݿ
				{
					printhz16(891,132+50*i,"��ݿ",1);
					printASC(Ord.building,929,135+50*i,1,1,1);
					printhz16(951,132+50*i,"��",1);
				}
				break;
			}
		}
		if(j<0)
		{
			printhz16(596,132+50*i,"δ��ѯ��",1);
			printhz16(759,132+50*i,"δ��ѯ��",1);
			printhz16(891,132+50*i,"δ��ѯ��",1);
		}
		fclose(fq);
		if(i==count-1)
		{
			fclose(fp);
		}
	}
	
	if((fp=fopen("time.txt","r"))==NULL)
	{
		printf("error");
		getch();
		exit(0);
	}
	for(i=0;i<count;i++)
	{
		fread(&Time,LEN3,1,fp);
		printASC(Time.time1,183,135+50*i,1,1,1);
		printASC(Time.time2,376,135+50*i,1,1,1);
		if(i==count-1)
		{
			fclose(fp);
		}
	}
	
	while(1)
	{
		MouseXYB(&M);
	    MouseStoreBk(M.x, M.y);
	    MouseDraw(M);
		delay(20);
	    MousePutBk(M.x, M.y);
		if(MouseBarLeft(922,15,1009,62)==1)            //�˳�
		{
			exit(0);           
		}	
        if(MouseBarLeft(0,0,144,62)==1)                //��һ��    
		{
			Putbmp64k(0,0,"img\\glyxx.bmp");
			break;
		}
	}
}
