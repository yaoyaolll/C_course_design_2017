#include "head.h"
#include "SVGAmode.h"
#include "input.h"

/*在框中输入账户*/
void inputzh(int x1,int x2,int y,User *users)     //x1直接在结构体赋值给posx,*b传递输入数组,x2为框的右边界,y为纵坐标。flag=0时，为账户；flag为1时，为密码
{
	char ka;                             //读取输入字符
	while((ka=getch())!=13)              //按Enter退出
	{
		if(((ka>='a'&&ka<='z')||(ka>='A'&&ka<='Z')||(ka>='0'&&ka<='9'))&&(users->posx1<=x2-14))
		{
		    printasc(ka,users->posx1,y,1,1,2);      //输出一个字符
			users->Account[users->count1]=ka;
			users->posx1+=16;
			(users->count1)++;
		}
		if(ka==0x8&&(users->posx1>x1))               //按下backspace键
		{
			users->posx1-=16;
			Putbmp64k(users->posx1,y,"img\\bk0.bmp");
			(users->count1)--;
		}
		users->Account[users->count1]='\0';
	}
}

/*在框中输入密码*/
void inputmm(int x1,int x2,int y,User *users)
{
	char ka;                             //读取输入字符
	while((ka=getch())!=13)              //按Enter退出
	{
		if(((ka>='a'&&ka<='z')||(ka>='A'&&ka<='Z')||(ka>='0'&&ka<='9'))&&(users->posx2<=x2-14))
		{  
			printasc('*',users->posx2,y,1,1,2);     //密码用‘*’隐式输出
			users->Password[users->count2]=ka;
			users->posx2+=16;
			(users->count2)++;
		}
		if(ka==0x8&&(users->posx2>x1))               //按下backspace键
		{
			users->posx2-=16;
			Putbmp64k(users->posx2,y,"img\\bk1.bmp");
			(users->count2)--;
		}
		users->Password[users->count2]='\0';
	}
}


/*输入电话号码或用户名*/
void inputinfo(struct information *info,int flag)    //pox1,pox2在函数体外初始化为700
{
	int y=0;
	char ka;
	if(flag==0)         //用户姓名框
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
	if(flag==1)              //电话框
	{
		y=205;
		while((ka=getch())!=13)    //当按下enter键且电话号码个数正好为11时退出循环
		{
			if((ka>='0'&&ka<='9')&&(info->count2<11))     //电话号码个数不能多于11个
			{
				if((info->count2==0)&&ka!='1');         //第一位当为1
				else
				{
				    printasc(ka,info->posx2,y,1,1,2);
					info->number[info->count2]=ka;
				    info->posx2+=16;
				    (info->count2)++;                       //count2在函数体外必须初始化为0
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
	if(flag==2)             //楼栋框
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
/*输入菜品价格*/
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
/*连续输入一行字符，大小为16*16*/
void printASC(char *s,int x,int y,int dx,int dy,unsigned char color)
{
	char *s1;
	unsigned long offset;
	FILE *fp;
	char buffer[16]; //buffer用来存储一个字符
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
		offset=(*s)*16+1; //计算该字符在字库中偏移量
		fseek(fp,offset,SEEK_SET);
		fread(buffer,16,1,fp); //取出字符16字节的点阵字模存入buffer中

		for(n=0;n<dx;n++) //将16位字节的点阵按位在屏幕上打印出来(1:打印,0:不打印),显示字符
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
		s++; //一个字符内码占用一个字节
		x+=8*dx;//字符间间隔
	}
	s=s1;
	fclose(fp);

}

/*输出单个字符16*16*/
void printasc(char c,int x,int y,int dx,int dy,unsigned char color)
{
	unsigned long offset;
	FILE *fp;
	char buffer[16]; //buffer用来存储一个字符
	int m,n,i,j;
	if ((fp=fopen("ziku\\asc16","rb"))==NULL)
	{
		printf("Can't open asc16,Please add it");
		getch();
		exit(1);
	}
	offset=c*16+1; //计算该字符在字库中偏移量
	fseek(fp,offset,SEEK_SET);
	fread(buffer,16,1,fp); //取出字符16字节的点阵字模存入buffer中

	for(n=0;n<dx;n++) //将16位字节的点阵按位在屏幕上打印出来(1:打印,0:不打印),显示字符
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
/*输出一行字符，大小为32*16*/
void printASC32_16(char *s,int x,int y,unsigned char color)
{
	char *s1;
	unsigned long offset;
	FILE *fp;
	int index;
	char bytes[64]; //buffer用来存储一个字符
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
		offset=(*s-32)*64; //计算该字符在字库中偏移量
		fseek(fp,offset,SEEK_SET);
		fread(bytes,64,1,fp); //取出字符64字节的点阵字模存入buffer中

			for(i=0;i<32;i++)
			{
				for(j=0;j<16;j++)
				{
					index=j*32+i;
					if((mask[index%8]&bytes[index/8])!=NULL)//屏蔽出汉字模的一个点,j/8只有0和1
							Putpixel64k(x+j,y+i,color);                  //是1则显示该点
				}
			}
		
		s++; //一个字符内码占用一个字节
		x+=16;//字符间间隔
	}
	s=s1;
	fclose(fp);

}

/*输入汉字*/
void printhz16(int x,int y,char *s,int color) //*s为输入的汉字，以ANSI编码
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
			    wm=s[1]-0xa0;                  //求出区码和位码
			    offset=(94*(qm-1)+wm-1)*32L;   //求出偏移量
			    fseek(fp,offset,SEEK_SET);     //定位到汉字处
			    fread(bytes,32L,1,fp);         //将字模提取至bytes数组
				for(i=0;i<16;i++)       //16行
			    {
				    pos=2*i;            //pos转到下一行
					for(j=0;j<16;j++)   //两个字节一共十六位
					{
						if((mask[j%8]&bytes[pos+j/8])!=NULL)//屏蔽出汉字模的一个点,j/8只有0和1
							Putpixel64k(x+j,y+i,color);                  //是1则显示该点
					}
			    }
				x+=20;                     //列增加20
				s+=2;                      //汉字为两个字节，地址指向下一个汉字	
			}
            x=20;
            y+=20;             //若一行显示完，显示下一行				
		}
	}
	fclose(fp);
}
/*****************************************
(mask[j%8]&bytes[pos+j/8])!=NULL         *
mask数组存八个十六进制数，转换为二进制为:*
1 0 0 0 0 0 0 0                          * 
0 1 0 0 0 0 0 0                          *
0 0 1 0 0 0 0 0                          *
0 0 0 1 0 0 0 0    分别跟一个字节相与    *
0 0 0 0 1 0 0 0                          *
0 0 0 0 0 1 0 0                          *   
0 0 0 0 0 0 1 0                          * 
0 0 0 0 0 0 0 1                          *
然后分别与一行每个字节相与，当某位mask   *
与bytes都为1时，在x,y所在的点显示。      *
*****************************************/
