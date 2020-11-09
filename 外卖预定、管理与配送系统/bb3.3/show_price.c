#include "head.h"
#include "SVGAmode.h"
#include "input.h"
#include "mouse.h"
#include "manager.h"
#include "show_price.h"
#include "Cai_Config.h"
#include "reprice.h"

/*贴出第一张图相应的价格*/              
void show_price1(struct caipin *wjcf)        //s10.bmp
{
	char letter[]="price\\\\xx.bmp";         //替换letter[9],letter[10],可以输出图片
	change(letter,wjcf[0].price);
	Putbmp64k(139,373,letter);
	change(letter,wjcf[1].price);
	Putbmp64k(442,373,letter);
	change(letter,wjcf[2].price);
	Putbmp64k(751,373,letter);
	change(letter,wjcf[3].price);
	Putbmp64k(139,724,letter);
	change(letter,wjcf[4].price);
	Putbmp64k(442,724,letter);
	change(letter,wjcf[5].price);
	Putbmp64k(751,724,letter);
}
/*贴出第二张图相应的价格*/
void show_price2(struct caipin *wjcf)        //s101.bmp
{
	char letter[]="price\\\\xx.bmp";         //替换letter[9],letter[10],可以输出图片
	change(letter,wjcf[6].price);
	Putbmp64k(139,373,letter);
	change(letter,wjcf[7].price);
	Putbmp64k(442,373,letter);
}
/*贴出第三张图相应的价格*/
void show_price3(struct caipin *wjcf)        //s11.bmp
{
	char letter[]="price\\\\xx.bmp";         //替换letter[9],letter[10],可以输出图片
	change(letter,wjcf[8].price);
	Putbmp64k(139,373,letter);
	change(letter,wjcf[9].price);
	Putbmp64k(442,373,letter);
	change(letter,wjcf[10].price);
	Putbmp64k(751,373,letter);
	change(letter,wjcf[11].price);
	Putbmp64k(139,724,letter);
	change(letter,wjcf[12].price);
	Putbmp64k(442,724,letter);
	change(letter,wjcf[13].price);
	Putbmp64k(751,724,letter);
}
/*贴出第四张图相应的价格*/
void show_price4(struct caipin *wjcf)        //s111.bmp
{
	char letter[]="price\\\\xx.bmp";         //替换letter[9],letter[10],可以输出图片
	change(letter,wjcf[14].price);
	Putbmp64k(139,373,letter);
	change(letter,wjcf[15].price);
	Putbmp64k(442,373,letter);
	change(letter,wjcf[16].price);
	Putbmp64k(751,373,letter);
	change(letter,wjcf[17].price);
	Putbmp64k(139,724,letter);
	change(letter,wjcf[18].price);
	Putbmp64k(442,724,letter);
	change(letter,wjcf[19].price);
	Putbmp64k(751,724,letter);
}
/*贴出第五张图相应的价格*/
void show_price5(struct caipin *wjcf)        //s12.bmp
{
	char letter[]="price\\\\xx.bmp";         //替换letter[9],letter[10],可以输出图片
	change(letter,wjcf[20].price);
	Putbmp64k(139,373,letter);
	change(letter,wjcf[21].price);
	Putbmp64k(442,373,letter);
	change(letter,wjcf[22].price);
	Putbmp64k(751,373,letter);
	change(letter,wjcf[23].price);
	Putbmp64k(139,724,letter);
	change(letter,wjcf[24].price);
	Putbmp64k(442,724,letter);
	change(letter,wjcf[25].price);
	Putbmp64k(751,724,letter);
}
/*贴出第六张图相应的价格*/
void show_price6(struct caipin *wjcf)        //s13.bmp
{
	char letter[]="price\\\\xx.bmp";         //替换letter[9],letter[10],可以输出图片
	change(letter,wjcf[26].price);
	Putbmp64k(139,373,letter);
	change(letter,wjcf[27].price);
	Putbmp64k(442,373,letter);
	change(letter,wjcf[28].price);
	Putbmp64k(751,373,letter);
	change(letter,wjcf[29].price);
	Putbmp64k(139,724,letter);
	change(letter,wjcf[30].price);
	Putbmp64k(442,724,letter);
	change(letter,wjcf[31].price);
	Putbmp64k(751,724,letter);
}
/*贴出第七张图相应的价格*/                   
void show_price7(struct caipin *wjcf)        //s14.bmp
{
	char letter[]="price\\\\xx.bmp";         //替换letter[9],letter[10],可以输出图片
	change(letter,wjcf[32].price);
	Putbmp64k(139,373,letter);
	change(letter,wjcf[33].price);
	Putbmp64k(442,373,letter);
	change(letter,wjcf[34].price);
	Putbmp64k(751,373,letter);
	change(letter,wjcf[35].price);
	Putbmp64k(139,724,letter);
	change(letter,wjcf[36].price);
	Putbmp64k(442,724,letter);
	change(letter,wjcf[37].price);
	Putbmp64k(751,724,letter);
}
/*贴出第八张图相应的价格*/
void show_price8(struct caipin *wjcf)        //s141.bmp
{
	char letter[]="price\\\\xx.bmp";         //替换letter[9],letter[10],可以输出图片
	change(letter,wjcf[38].price);
	Putbmp64k(139,373,letter);
	change(letter,wjcf[39].price);
	Putbmp64k(442,373,letter);
	change(letter,wjcf[40].price);
	Putbmp64k(751,373,letter);
	change(letter,wjcf[41].price);
	Putbmp64k(139,724,letter);
	change(letter,wjcf[42].price);
	Putbmp64k(442,724,letter);
	change(letter,wjcf[43].price);
	Putbmp64k(751,724,letter);
}
/*贴出第九张图相应的价格*/
void show_price9(struct caipin *wjcf)        //s15.bmp
{ 
	char letter[]="price\\\\xx.bmp";         //替换letter[9],letter[10],可以输出图片
	change(letter,wjcf[44].price);
	Putbmp64k(139,373,letter);
	change(letter,wjcf[45].price);
	Putbmp64k(442,373,letter);
	change(letter,wjcf[46].price);
	Putbmp64k(751,373,letter);
	change(letter,wjcf[47].price);
	Putbmp64k(139,724,letter);
	change(letter,wjcf[48].price);
	Putbmp64k(442,724,letter);
	change(letter,wjcf[49].price);
	Putbmp64k(751,724,letter);
}
/*贴出第十张图相应的价格*/
void show_price10(struct caipin *wjcf)        //s16.bmp
{
	char letter[]="price\\\\xx.bmp";         //替换letter[9],letter[10],可以输出图片
	change(letter,wjcf[50].price);
	Putbmp64k(139,373,letter);
	change(letter,wjcf[51].price);
	Putbmp64k(442,373,letter);
	change(letter,wjcf[52].price);
	Putbmp64k(751,373,letter);
	change(letter,wjcf[53].price);
	Putbmp64k(139,724,letter);
	change(letter,wjcf[54].price);
	Putbmp64k(442,724,letter);
}
/*调出正确的小图片*/
void change(char *s,char *m)                 //s指代letter[],m指代wjcf[].price
{
	if(m[1]=='\0')
	{
		s[7]='0';
		s[8]=m[0];
	}
	else
	{
		s[7]=m[0];
		s[8]=m[1];
	}
}
