#include "head.h"
#include "SVGAmode.h"
#include "input.h"

/*�ڿ��������˻�*/
void inputzh(int x1,int x2,int y,User *users)     //x1ֱ���ڽṹ�帳ֵ��posx,*b������������,x2Ϊ����ұ߽�,yΪ�����ꡣflag=0ʱ��Ϊ�˻���flagΪ1ʱ��Ϊ����
{
	char ka;                             //��ȡ�����ַ�
	while((ka=getch())!=13)              //��Enter�˳�
	{
		if(((ka>='a'&&ka<='z')||(ka>='A'&&ka<='Z')||(ka>='0'&&ka<='9'))&&(users->posx1<=x2-14))
		{
		    printasc(ka,users->posx1,y,1,1,2);      //���һ���ַ�
			users->Account[users->count1]=ka;
			users->posx1+=16;
			(users->count1)++;
		}
		if(ka==0x8&&(users->posx1>x1))               //����backspace��
		{
			users->posx1-=16;
			Putbmp64k(users->posx1,y,"img\\bk0.bmp");
			(users->count1)--;
		}
		users->Account[users->count1]='\0';
	}
}

/*�ڿ�����������*/
void inputmm(int x1,int x2,int y,User *users)
{
	char ka;                             //��ȡ�����ַ�
	while((ka=getch())!=13)              //��Enter�˳�
	{
		if(((ka>='a'&&ka<='z')||(ka>='A'&&ka<='Z')||(ka>='0'&&ka<='9'))&&(users->posx2<=x2-14))
		{  
			printasc('*',users->posx2,y,1,1,2);     //�����á�*����ʽ���
			users->Password[users->count2]=ka;
			users->posx2+=16;
			(users->count2)++;
		}
		if(ka==0x8&&(users->posx2>x1))               //����backspace��
		{
			users->posx2-=16;
			Putbmp64k(users->posx2,y,"img\\bk1.bmp");
			(users->count2)--;
		}
		users->Password[users->count2]='\0';
	}
}


/*����绰������û���*/
void inputinfo(struct information *info,int flag)    //pox1,pox2�ں��������ʼ��Ϊ700
{
	int y=0;
	char ka;
	if(flag==0)         //�û�������
	{
		y=149;
		while((ka=getch())!=13)
		{
			if(((ka>='a'&&ka<='z')||(ka>='A'&&ka<='Z'))&&(info->posx1<=890))
			{
				printasc(ka,info->posx1,y,1,1,2);
				info->name[info->count1]=ka;
				info->posx1+=16;
				(info->count1)++;
			}
			if(ka==0x8&&(info->posx1>700))
			{
				info->posx1-=16;
				Putbmp64k(info->posx1,y,"img\\bk8.bmp");
				(info->posx1)--;
			}
			info->name[info->count1]='\0';
		}
	}
	if(flag==1)              //�绰��
	{
		y=205;
		while((ka=getch())!=13)    //������enter���ҵ绰�����������Ϊ11ʱ�˳�ѭ��
		{
			if((ka>='0'&&ka<='9')&&(info->count2<11))     //�绰����������ܶ���11��
			{
				if((info->count2==0)&&ka!='1');         //��һλ��Ϊ1
				else
				{
				    printasc(ka,info->posx2,y,1,1,2);
					info->number[info->count2]=ka;
				    info->posx2+=16;
				    (info->count2)++;                       //count2�ں�����������ʼ��Ϊ0
				}		
			}
			if(ka==0x8&&(info->posx2>700))
			{
				info->posx2-=16;
				Putbmp64k(info->posx2,y,"img\\bk8.bmp");
				(info->count2)--;
			}
			info->number[info->count2]='\0';
		}
	}
	if(flag==2)             //¥����
	{
		y=400;
		while((ka=getch())!=13)
		{
			if((ka>='0'&&ka<='9')&&(info->posx3<736))
			{
				printasc(ka,info->posx3,y,1,1,2);
				info->posx3+=16;
				info->building[info->count3]=ka;
				(info->count3)++;
			}
			if(ka==0x8&&(info->posx3>710))
			{
				info->posx3-=16;
				Putbmp64k(info->posx3,y,"img\\bk8.bmp");
				(info->count3)--;
			}
			info->building[info->count3]='\0';
		}
	}
}
/*�����Ʒ�۸�*/
void input_revise(int *posx,char *s,int *count)
{
	char ka;
	char letter[]="numa\\\\x.bmp";
	while((ka=getch())!=13)
	{
		if((ka>='0'&&ka<='9')&&(*count<2))
		{
			if(ka=='0'&&((*count)==0));
			else
			{
				(*posx)+=48;
				s[*count]=ka;
				letter[6]=ka;
				Putbmp64k(*posx,311,letter);
				(*count)++;
			}
		}
		if(ka==0x8&&(*posx>336))
		{
			Putbmp64k(*posx,311,"numa\\bk.bmp");
			(*posx)-=48;
			(*count)--;
		}
		s[*count]='\0';
	}
}
/*��������һ���ַ�����СΪ16*16*/
void printASC(char *s,int x,int y,int dx,int dy,unsigned char color)
{
	char *s1;
	unsigned long offset;
	FILE *fp;
	char buffer[16]; //buffer�����洢һ���ַ�
	int m,n,i,j;
	if ((fp=fopen("ziku\\asc16","rb"))==NULL)
	{
		printf("Can't open asc16,Please add it");
		getch();
		exit(1);
	}
	s1=s;
	while(*s)
	{
		offset=(*s)*16+1; //������ַ����ֿ���ƫ����
		fseek(fp,offset,SEEK_SET);
		fread(buffer,16,1,fp); //ȡ���ַ�16�ֽڵĵ�����ģ����buffer��

		for(n=0;n<dx;n++) //��16λ�ֽڵĵ���λ����Ļ�ϴ�ӡ����(1:��ӡ,0:����ӡ),��ʾ�ַ�
		{
			for(i=0;i<16;i++)
			{
						for(j=0;j<8;j++)
						{
							for(m=0;m<dy;m++)
							{
								if(((buffer[i]>>(7-j))&0x1)!=NULL)
								{
									Putpixel64k(x+j+n,y+i+m,color);
								}
							}
						}

			}
		}
		s++; //һ���ַ�����ռ��һ���ֽ�
		x+=8*dx;//�ַ�����
	}
	s=s1;
	fclose(fp);

}

/*��������ַ�16*16*/
void printasc(char c,int x,int y,int dx,int dy,unsigned char color)
{
	unsigned long offset;
	FILE *fp;
	char buffer[16]; //buffer�����洢һ���ַ�
	int m,n,i,j;
	if ((fp=fopen("ziku\\asc16","rb"))==NULL)
	{
		printf("Can't open asc16,Please add it");
		getch();
		exit(1);
	}
	offset=c*16+1; //������ַ����ֿ���ƫ����
	fseek(fp,offset,SEEK_SET);
	fread(buffer,16,1,fp); //ȡ���ַ�16�ֽڵĵ�����ģ����buffer��

	for(n=0;n<dx;n++) //��16λ�ֽڵĵ���λ����Ļ�ϴ�ӡ����(1:��ӡ,0:����ӡ),��ʾ�ַ�
	{
		for(i=0;i<16;i++)
		{
				for(j=0;j<8;j++)
				{
					for(m=0;m<dy;m++)
					{
						if(((buffer[i]>>(7-j))&0x1)!=NULL)
						{
							Putpixel64k(x+j+n,y+i+m,color);
						}
					}
				}

		}
	}
	fclose(fp);
}
/*���һ���ַ�����СΪ32*16*/
void printASC32_16(char *s,int x,int y,unsigned char color)
{
	char *s1;
	unsigned long offset;
	FILE *fp;
	int index;
	char bytes[64]; //buffer�����洢һ���ַ�
	int i,j;
	unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};    
	if ((fp=fopen("ziku\\ASC32_16","rb"))==NULL)
	{
		printf("Can't open asc,Please add it");
		getch();
		exit(1);
	}
	s1=s;
	while(*s)
	{
		offset=(*s-32)*64; //������ַ����ֿ���ƫ����
		fseek(fp,offset,SEEK_SET);
		fread(bytes,64,1,fp); //ȡ���ַ�64�ֽڵĵ�����ģ����buffer��

			for(i=0;i<32;i++)
			{
				for(j=0;j<16;j++)
				{
					index=j*32+i;
					if((mask[index%8]&bytes[index/8])!=NULL)//���γ�����ģ��һ����,j/8ֻ��0��1
							Putpixel64k(x+j,y+i,color);                  //��1����ʾ�õ�
				}
			}
		
		s++; //һ���ַ�����ռ��һ���ֽ�
		x+=16;//�ַ�����
	}
	s=s1;
	fclose(fp);

}

/*���뺺��*/
void printhz16(int x,int y,char *s,int color) //*sΪ����ĺ��֣���ANSI����
{
	FILE *fp=NULL;
	unsigned char qm;                       
	unsigned char wm;                       
	unsigned long offset;                  
	char bytes[32];                         
	unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};     
	                                                                       
	int i;
    int j; 
    int pos;	                     
	if((fp=fopen("ziku\\hzk16","rb"))==NULL)
	{
		printf("can not open the file.");
		getch();
		closegraph();
		exit(1);
	}
	else
	{
		while(*s!=NULL)
		{
			while(x<1024&&(*s!=NULL))
			{
				qm=s[0]-0xa0;
			    wm=s[1]-0xa0;                  //��������λ��
			    offset=(94*(qm-1)+wm-1)*32L;   //���ƫ����
			    fseek(fp,offset,SEEK_SET);     //��λ�����ִ�
			    fread(bytes,32L,1,fp);         //����ģ��ȡ��bytes����
				for(i=0;i<16;i++)       //16��
			    {
				    pos=2*i;            //posת����һ��
					for(j=0;j<16;j++)   //�����ֽ�һ��ʮ��λ
					{
						if((mask[j%8]&bytes[pos+j/8])!=NULL)//���γ�����ģ��һ����,j/8ֻ��0��1
							Putpixel64k(x+j,y+i,color);                  //��1����ʾ�õ�
					}
			    }
				x+=20;                     //������20
				s+=2;                      //����Ϊ�����ֽڣ���ַָ����һ������	
			}
            x=20;
            y+=20;             //��һ����ʾ�꣬��ʾ��һ��				
		}
	}
	fclose(fp);
}
/*****************************************
(mask[j%8]&bytes[pos+j/8])!=NULL         *
mask�����˸�ʮ����������ת��Ϊ������Ϊ:*
1 0 0 0 0 0 0 0                          * 
0 1 0 0 0 0 0 0                          *
0 0 1 0 0 0 0 0                          *
0 0 0 1 0 0 0 0    �ֱ��һ���ֽ�����    *
0 0 0 0 1 0 0 0                          *
0 0 0 0 0 1 0 0                          *   
0 0 0 0 0 0 1 0                          * 
0 0 0 0 0 0 0 1                          *
Ȼ��ֱ���һ��ÿ���ֽ����룬��ĳλmask   *
��bytes��Ϊ1ʱ����x,y���ڵĵ���ʾ��      *
*****************************************/
