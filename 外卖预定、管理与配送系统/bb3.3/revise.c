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
void customer_revise(char *account)
{
	FILE *fp;
	int aflag=1;                                   //参数，判定进入哪个函数
	struct caipin wjcf[55]={"","",""};
	if((fp=fopen("caipin.txt","r+"))==NULL)
	{
		printf("cannot open the file.(caipin.txt)");
		getch();
		exit(0);
	}
	fread(wjcf,LEN,55,fp);                   //将caipin.txt文件中的数据读取至wjcf[55]
	fclose(fp);
	while(1)
	{
	    if(aflag==1)
	    {
			Putbmp64k(0,0,"img\\store.bmp");         //贴出第一张界面
		    show_init1(wjcf);                       
	        store(wjcf,&aflag);                      
	       
	    }
	    if(aflag==2)
	    {
			 list1(wjcf,&aflag);
	    }
		if(aflag==3)
		{
			break;
		}
		if(aflag==4)
		{
			Putbmp64k(0,0,"img\\fk.bmp");
			distribution(wjcf,&aflag,account);
		}
	}
}
/*贴出第一张图相应的价格*/
void show_init1(struct caipin *wjcf)        //s10.bmp
{
	char letter[]="price\\\\xx.bmp"; 	    //替换letter[9],letter[10],可以输出图片
	char string1[]="numb\\\\nxx.bmp";
	change(letter,wjcf[0].price);
	change(string1,wjcf[0].count);
	Putbmp64k(139,373,letter);
	Putbmp64k(327,373,string1);
	change(letter,wjcf[1].price);
	change(string1,wjcf[1].count);
	Putbmp64k(442,373,letter);
	Putbmp64k(628,373,string1);
	change(letter,wjcf[2].price);
	change(string1,wjcf[2].count);
	Putbmp64k(751,373,letter);
	Putbmp64k(932,373,string1);
	change(letter,wjcf[3].price);
	change(string1,wjcf[3].count);
	Putbmp64k(139,724,letter);
	Putbmp64k(327,724,string1);
	change(letter,wjcf[4].price);
	change(string1,wjcf[4].count);
	Putbmp64k(442,724,letter);
	Putbmp64k(628,724,string1);
	change(letter,wjcf[5].price);
	change(string1,wjcf[5].count);
	Putbmp64k(751,724,letter);
	Putbmp64k(932,724,string1);
}
/*贴出第二张图相应的价格*/
void show_init2(struct caipin *wjcf)        //s101.bmp
{
	char letter[]="price\\\\xx.bmp"; 	    //替换letter[9],letter[10],可以输出图片
	char string1[]="numb\\\\nxx.bmp";
	change(letter,wjcf[6].price);
	change(string1,wjcf[6].count);
	Putbmp64k(139,373,letter);
	Putbmp64k(327,373,string1);
	change(letter,wjcf[7].price);
	change(string1,wjcf[7].count);
	Putbmp64k(442,373,letter);
	Putbmp64k(628,373,string1);
}
/*贴出第三张图相应的价格*/
void show_init3(struct caipin *wjcf)        //s11.bmp
{
	char letter[]="price\\\\xx.bmp"; 	//替换letter[9],letter[10],可以输出图片
	char string1[]="numb\\\\nxx.bmp";
	change(letter,wjcf[8].price);
	change(string1,wjcf[8].count);
	Putbmp64k(139,373,letter);
	Putbmp64k(327,373,string1);
	change(letter,wjcf[9].price);
	change(string1,wjcf[9].count);
	Putbmp64k(442,373,letter);
	Putbmp64k(628,373,string1);
	change(letter,wjcf[10].price);
	change(string1,wjcf[10].count);
	Putbmp64k(751,373,letter);
	Putbmp64k(932,373,string1);
	change(letter,wjcf[11].price);
	change(string1,wjcf[11].count);
	Putbmp64k(139,724,letter);
	Putbmp64k(327,724,string1);
	change(letter,wjcf[12].price);
	change(string1,wjcf[12].count);
	Putbmp64k(442,724,letter);
	Putbmp64k(628,724,string1);
	change(letter,wjcf[13].price);
	change(string1,wjcf[13].count);
	Putbmp64k(751,724,letter);
	Putbmp64k(932,724,string1);
}
/*贴出第四张图相应的价格*/
void show_init4(struct caipin *wjcf)        //s111.bmp
{
	char letter[]="price\\\\xx.bmp"; 	//替换letter[9],letter[10],可以输出图片
	char string1[]="numb\\\\nxx.bmp";
	change(letter,wjcf[14].price);
	change(string1,wjcf[14].count);
	Putbmp64k(139,373,letter);
	Putbmp64k(327,373,string1);
	change(letter,wjcf[15].price);
	change(string1,wjcf[15].count);
	Putbmp64k(442,373,letter);
	Putbmp64k(628,373,string1);
	change(letter,wjcf[16].price);
	change(string1,wjcf[16].count);
	Putbmp64k(751,373,letter);
	Putbmp64k(932,373,string1);
	change(letter,wjcf[17].price);
	change(string1,wjcf[17].count);
	Putbmp64k(139,724,letter);
	Putbmp64k(327,724,string1);
	change(letter,wjcf[18].price);
	change(string1,wjcf[18].count);
	Putbmp64k(442,724,letter);
	Putbmp64k(628,724,string1);
	change(letter,wjcf[19].price);
	change(string1,wjcf[19].count);
	Putbmp64k(751,724,letter);
	Putbmp64k(932,724,string1);
}
/*贴出第五张图相应的价格*/
void show_init5(struct caipin *wjcf)        //s10.bmp
{
	char letter[]="price\\\\xx.bmp"; 	//替换letter[9],letter[10],可以输出图片
	char string1[]="numb\\\\nxx.bmp";
	change(letter,wjcf[20].price);
	change(string1,wjcf[20].count);
	Putbmp64k(139,373,letter);
	Putbmp64k(327,373,string1);
	change(letter,wjcf[21].price);
	change(string1,wjcf[21].count);
	Putbmp64k(442,373,letter);
	Putbmp64k(628,373,string1);
	change(letter,wjcf[22].price);
	change(string1,wjcf[22].count);
	Putbmp64k(751,373,letter);
	Putbmp64k(932,373,string1);
	change(letter,wjcf[23].price);
	change(string1,wjcf[23].count);
	Putbmp64k(139,724,letter);
	Putbmp64k(327,724,string1);
	change(letter,wjcf[24].price);
	change(string1,wjcf[24].count);
	Putbmp64k(442,724,letter);
	Putbmp64k(628,724,string1);
	change(letter,wjcf[25].price);
	change(string1,wjcf[25].count);
	Putbmp64k(751,724,letter);
	Putbmp64k(932,724,string1);
}
/*贴出第六张图相应的价格*/
void show_init6(struct caipin *wjcf)        //s13.bmp
{
	char letter[]="price\\\\xx.bmp"; 	//替换letter[9],letter[10],可以输出图片
	char string1[]="numb\\\\nxx.bmp";
	change(letter,wjcf[26].price);
	change(string1,wjcf[26].count);
	Putbmp64k(139,373,letter);
	Putbmp64k(327,373,string1);
	change(letter,wjcf[27].price);
	change(string1,wjcf[27].count);
	Putbmp64k(442,373,letter);
	Putbmp64k(628,373,string1);
	change(letter,wjcf[28].price);
	change(string1,wjcf[28].count);
	Putbmp64k(751,373,letter);
	Putbmp64k(932,373,string1);
	change(letter,wjcf[29].price);
	change(string1,wjcf[29].count);
	Putbmp64k(139,724,letter);
	Putbmp64k(327,724,string1);
	change(letter,wjcf[30].price);
	change(string1,wjcf[30].count);
	Putbmp64k(442,724,letter);
	Putbmp64k(628,724,string1);
	change(letter,wjcf[31].price);
	change(string1,wjcf[31].count);
	Putbmp64k(751,724,letter);
	Putbmp64k(932,724,string1);
}
/*贴出第七张图相应的价格*/
void show_init7(struct caipin *wjcf)        //s14.bmp
{
	char letter[]="price\\\\xx.bmp"; 	//替换letter[9],letter[10],可以输出图片
	char string1[]="numb\\\\nxx.bmp";
	change(letter,wjcf[32].price);
	change(string1,wjcf[32].count);
	Putbmp64k(139,373,letter);
	Putbmp64k(327,373,string1);
	change(letter,wjcf[33].price);
	change(string1,wjcf[33].count);
	Putbmp64k(442,373,letter);
	Putbmp64k(628,373,string1);
	change(letter,wjcf[34].price);
	change(string1,wjcf[34].count);
	Putbmp64k(751,373,letter);
	Putbmp64k(932,373,string1);
	change(letter,wjcf[35].price);
	change(string1,wjcf[35].count);
	Putbmp64k(139,724,letter);
	Putbmp64k(327,724,string1);
	change(letter,wjcf[36].price);
	change(string1,wjcf[36].count);
	Putbmp64k(442,724,letter);
	Putbmp64k(628,724,string1);
	change(letter,wjcf[37].price);
	change(string1,wjcf[37].count);
	Putbmp64k(751,724,letter);
	Putbmp64k(932,724,string1);
}
/*贴出第八张图相应的价格*/
void show_init8(struct caipin *wjcf)        //s141.bmp
{
	char letter[]="price\\\\xx.bmp"; 	//替换letter[9],letter[10],可以输出图片
	char string1[]="numb\\\\nxx.bmp";
	change(letter,wjcf[38].price);
	change(string1,wjcf[38].count);
	Putbmp64k(139,373,letter);
	Putbmp64k(327,373,string1);
	change(letter,wjcf[39].price);
	change(string1,wjcf[39].count);
	Putbmp64k(442,373,letter);
	Putbmp64k(628,373,string1);
	change(letter,wjcf[40].price);
	change(string1,wjcf[40].count);
	Putbmp64k(751,373,letter);
	Putbmp64k(932,373,string1);
	change(letter,wjcf[41].price);
	change(string1,wjcf[41].count);
	Putbmp64k(139,724,letter);
	Putbmp64k(327,724,string1);
	change(letter,wjcf[42].price);
	change(string1,wjcf[42].count);
	Putbmp64k(442,724,letter);
	Putbmp64k(628,724,string1);
	change(letter,wjcf[43].price);
	change(string1,wjcf[43].count);
	Putbmp64k(751,724,letter);
	Putbmp64k(932,724,string1);
}
/*贴出第九张图相应的价格*/
void show_init9(struct caipin *wjcf)        //s15.bmp
{
	char letter[]="price\\\\xx.bmp"; 	//替换letter[9],letter[10],可以输出图片
	char string1[]="numb\\\\nxx.bmp";
	change(letter,wjcf[44].price);
	change(string1,wjcf[44].count);
	Putbmp64k(139,373,letter);
	Putbmp64k(327,373,string1);
	change(letter,wjcf[45].price);
	change(string1,wjcf[45].count);
	Putbmp64k(442,373,letter);
	Putbmp64k(628,373,string1);
	change(letter,wjcf[46].price);
	change(string1,wjcf[46].count);
	Putbmp64k(751,373,letter);
	Putbmp64k(932,373,string1);
	change(letter,wjcf[47].price);
	change(string1,wjcf[47].count);
	Putbmp64k(139,724,letter);
	Putbmp64k(327,724,string1);
	change(letter,wjcf[48].price);
	change(string1,wjcf[48].count);
	Putbmp64k(442,724,letter);
	Putbmp64k(628,724,string1);
	change(letter,wjcf[49].price);
	change(string1,wjcf[49].count);
	Putbmp64k(751,724,letter);
	Putbmp64k(932,724,string1);
}
/*贴出第十张图相应的价格*/
void show_init10(struct caipin *wjcf)        //s10.bmp
{
	char letter[]="price\\\\xx.bmp"; 	//替换letter[9],letter[10],可以输出图片
	char string1[]="numb\\\\nxx.bmp";
	change(letter,wjcf[50].price);
	change(string1,wjcf[50].count);
	Putbmp64k(139,373,letter);
	Putbmp64k(327,373,string1);
	change(letter,wjcf[51].price);
	change(string1,wjcf[51].count);
	Putbmp64k(442,373,letter);
	Putbmp64k(628,373,string1);
	change(letter,wjcf[52].price);
	change(string1,wjcf[52].count);
	Putbmp64k(751,373,letter);
	Putbmp64k(932,373,string1);
	change(letter,wjcf[53].price);
	change(string1,wjcf[53].count);
	Putbmp64k(139,724,letter);
	Putbmp64k(327,724,string1);
	change(letter,wjcf[54].price);
	change(string1,wjcf[54].count);
	Putbmp64k(442,724,letter);
	Putbmp64k(628,724,string1);
}