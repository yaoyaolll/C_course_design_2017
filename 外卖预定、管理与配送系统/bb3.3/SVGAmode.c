#include "SVGAmode.h"

/**********************************************************
Function��		SetSVGA256

Description��	SVGA��ʾģʽ���ú�������Ϊ0x105

Calls��			int86
				delay
				printf
				exit

Called By��		AutoSimulate
				HandOperate
				
Input��			None

Output��		������Ϣ

Return��		None				
Others��		None
**********************************************************/
void SetSVGA256(void)
{
	/*****************************************************
	��dos.h��REGS�Ķ������£�
	struct WORDREGS
	{
		unsigned int ax, bx, cx, dx, si, di, cflag, flags;
	};
	
	struct BYTEREGS
	{
		unsigned char al, ah, bl, bh, cl, ch, dl, dh;
	};
	
	union REGS
	{
		struct WORDREGS x;
		struct BYTEREGS h;
	};
	����al��Ӧax�ĵͰ�λ��ah��Ӧax�ĸ߰�λ���Դ����ơ�
	����ʱ��Ҫ����������ڲ���ȡֵ,��ȡ����ֵ��ʾ����Ϣ��
	*****************************************************/
	union REGS graph_regs;
	
	/*����VESA VBEģʽ�Ĺ��ܺ�*/
	graph_regs.x.ax = 0x4f02;
	graph_regs.x.bx = 0x105;
	int86(0x10, &graph_regs, &graph_regs);
	
	/*ax != 0x004f��ζ�ų�ʼ��ʧ�ܣ����������Ϣ����,��ͬ*/
	if (graph_regs.x.ax != 0x004f)
	{
		printf("Error in setting SVGA mode!\nError code:0x%x\n", graph_regs.x.ax);
		delay(5000);
		exit(1);
	}
}

/**********************************************************
Function��		SetSVGA64k

Description��	SVGA��ʾģʽ���ú�������Ϊ0x117

Calls��			int86
				delay
				printf
				exit

Called By��		AutoSimulate
				HandOperate
				
Input��			None

Output��		������Ϣ

Return��		None				
Others��		None
**********************************************************/
void SetSVGA64k(void)
{
	/*REGS���������*/
	union REGS graph_regs;
	
	/*����VESA VBEģʽ�Ĺ��ܺ�*/
	graph_regs.x.ax = 0x4f02;
	graph_regs.x.bx = 0x117;
	int86(0x10, &graph_regs, &graph_regs);
	
	/*ax != 0x004f��ζ�ų�ʼ��ʧ�ܣ����������Ϣ����,��ͬ*/
	if (graph_regs.x.ax != 0x004f)
	{
		printf("Error in setting SVGA mode!\nError code:0x%x\n", graph_regs.x.ax);
		delay(5000);
		exit(1);
	}
}

/**********************************************************
Function��		GetSVGA

Description��	��ȡSVGA��ʾģʽ��bx��ժ¼���õ�ģʽ�����£�
				ģʽ��		�ֱ���		��ɫ��		��ɫλ����
				0x101		640*480		256				-
				0x103		800*600		256				-
				0x104		1024*768	16				-
				0x105		1024*768	256				-
				0x110		640*480		32K			1:5:5:5
				0x111		640*480		64K			5:6:5
				0x112		640*480		16.8M		8:8:8
				0x113		800*600		32K			1:5:5:5
				0x114		800*600		64K			5:6:5
				0x115		800*600		16.8M		8:8:8
				0x116		1024*768	32K			1:5:5:5
				0x117		1024*768	64K			5:6:5
				0x118		1024*768	16.8M		8:8:8

Calls��			int86
				delay
				printf
				exit

Called By��		Unknown
Input��			None

Output��		��ʼ��ʧ��ʱ����Ļ�������š�

Return��		unsigned int graph_regs.x.bx	��ʾģʽ��

Others��		None
**********************************************************/
unsigned int GetSVGA(void)
{
	/*REGS���������*/
	union REGS graph_regs;
	
	/*��ȡ��ǰVESA VBEģʽ�Ĺ��ܺ�*/
	graph_regs.x.ax = 0x4f03;
	int86(0x10, &graph_regs, &graph_regs);
	
	/*��ʾ������Ϣ*/
	if (graph_regs.x.ax != 0x004f)
	{
		printf("Error in getting SVGA mode!\nError code:0x%x\n", graph_regs.x.ax);
		delay(5000);
		exit(1);
	}
	
	return graph_regs.x.bx;
}

/**********************************************************
Function��		Selectpage

Description��	���жϹ��ܵĻ�ҳ�����������д�Դ�ʱ���Ѱַ����

Calls��			int86

Called By��		Putpixel256
				Putpixel64k
				Xorpixel
				Horizline
				Getpixel64k
				
Input��			register char page		��Ҫ������ҳ���

Output��		None
Return��		None
Others��		None
**********************************************************/
void Selectpage(register char page)
{
	/*REGS����ͬ��*/
	union REGS graph_regs;
	
	/*��һ�ε�ҳ���,���ڼ����л�����,��ʹ�ô����ܶ����Ҫ����*/
	static unsigned char old_page = 0;
	
	/*��־���������ж��Ƿ��ǵ�һ�λ�ҳ*/
	static int flag = 0;
	
	/*����ҳ����ƹ��ܺ�*/
	graph_regs.x.ax = 0x4f05;
	graph_regs.x.bx = 0;
	
	/*����ǵ�һ�λ�ҳ*/
	if (flag == 0)
	{
		old_page = page;
		graph_regs.x.dx = page;
		int86(0x10, &graph_regs, &graph_regs);
		flag++;
	}
	
	/*������ϴ�ҳ��Ų�ͬ������л�ҳ*/
	else if (page != old_page)
	{
		old_page = page;
		graph_regs.x.dx = page;
		int86(0x10, &graph_regs, &graph_regs);
	}
}

/**********************************************************
Function��		Putpixel256

Description��	���㺯����������ͼ�����Ļ�������������0x105ģʽ��

Calls��			Selectpage

Called By��		Putbmp256
				Line
				Circle
				
Input��			int x					���غ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y					���������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				unsigned char color		��ɫ��������256��

Output��		����Ļ�ϻ�ָ����ɫ�ĵ�

Return��		None
Others��		None
**********************************************************/
void Putpixel256(int x, int y, unsigned char color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾�������޸�*/
	unsigned char far * const video_buffer = (unsigned char far *)0xa0000000L;
	
	/*Ҫ�л���ҳ���*/
	unsigned char new_page;
	
	/*��Ӧ�Դ��ַƫ����*/
	unsigned long int page;
	
	/*�жϵ��Ƿ�����Ļ��Χ�ڣ����ھ��˳�*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return;
	}
	
	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 16;	/*64k����һ��ҳ������64k������㷨*/
	Selectpage(new_page);
	
	/*���Դ�д����ɫ����Ӧ�㻭��*/
	video_buffer[page] = color;	
}

/**********************************************************
Function��		Putpixel64k

Description��	���㺯����������ͼ�����Ļ�������������0x117ģʽ��

Calls��			Selectpage

Called By��		Putbmp64k
				MousePutBk
				MouseDraw
				
Input��			int x					���غ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y					���������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				unsigned int color		��ɫ��������64k��

Output��		����Ļ�ϻ�ָ����ɫ�ĵ�

Return��		None
Others��		None
**********************************************************/
void Putpixel64k(int x, int y, unsigned int color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾�������޸�*/
	unsigned int far * const video_buffer = (unsigned char far *)0xa0000000L;
	
	/*Ҫ�л���ҳ���*/
	unsigned char new_page;
	
	/*��Ӧ�Դ��ַƫ����*/
	unsigned long int page;
	
	/*�жϵ��Ƿ�����Ļ��Χ�ڣ����ھ��˳�*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return;
	}
	
	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 15;	/*32k����һ��ҳ������32k������㷨*/
	Selectpage(new_page);
	
	/*���Դ�д����ɫ����Ӧ�㻭��*/
	video_buffer[page] = color;	
}

/**********************************************************
Function��		Putbmp256

Description��	8λ��ѹ��bmpͼ��λ��ʾ������
				ֻ֧��8λ��ѹ��bmpͼ����������������Ϊ1024��
				����bmp���;���֧�֣�
				����0x105ģʽ��ʹ�ã�
				Ϊ�˼򻯣�û�������ļ����ͼ�⹦�ܼ�⹦�ܣ�������벻��Ҫ����ļ���
				�˺����ʺ��ڲ���λ�������¶�ȡ����ͼƬ��
				��Ȼ�������˶�ȡ��ɫ���ܣ����ܼ���ʵ��ʹ����ɫ���������������ͼƬ��
				��ͳһҪ��ʹ��WindowsĬ����ɫ������Ӱ������ͼƬ��ʾ��

Calls��			Putpixel256

				fseek
				fread
				fclose
				outportb
				malloc
				free

Called By��		AutoSimulate
				HandOperate
				
Input��			int x		ͼƬ���Ͻǵĺ����꣨��Ļ�ο�ϵ��
				int y		ͼƬ���Ͻǵ������꣨��Ļ�ο�ϵ��
				const char * path	bmpͼƬ·��

Output��		��Ļ����ʾͼƬ

Return��		0	��ʾ�ɹ�
				-1	��ʾʧ��
				
Others��		None
**********************************************************/
int Putbmp256(int x, int y, const char * path)
{
	/*ָ��ͼƬ�ļ����ļ�ָ��*/
	FILE * fpbmp;
	
	/*bmp��ɫ��ṹָ��*/
	RGBQUAD * pclr, *clr;
	
	/*�����ػ���ָ��*/
	unsigned char * buffer;
	
	/*ʵ��ʹ�õ���ɫ���е���ɫ��*/
	unsigned long int clr_used;
	
	/*ͼƬ�Ŀ�ȡ��߶ȡ�һ��������ռ�ֽ�������������ֽڣ�*/
	long int width, height, linebytes;
	
	/*ѭ������*/
	int i, j;
	
	/*ͼƬλ��*/
	unsigned int bit;
	
	/*ѹ��������*/
	unsigned long int compression;
	
	/*���ļ�*/
	if ((fpbmp = fopen(path, "rb")) == NULL)
	{
		return -1;
	}
	
	/*��ȡλ��*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);
	
	/*��8λͼ���˳�*/
	if (bit != 8U)
	{
		return -1;
	}
	
	/*��ȡѹ������*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);
	
	/*����ѹ���㷨���˳�*/
	if (compression != 0UL)
	{
		return -1;
	}
	
	/*��ȡ��ȡ��߶�*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	
	/*��ȳ������˳�*/
	if (width > SCR_WIDTH)
	{
		return -1;
	}

	/*����һ������ռ�ֽ�������������Ŀ��ֽ�*/
	linebytes = width % 4;
	
	if(!linebytes)
	{
		linebytes = width;
	}
	else
	{
		linebytes = width + 4 - linebytes;
	}
	
	/*��ȡʵ��ʹ�õ���ɫ���е���ɫ��*/
	fseek(fpbmp, 46L, 0);
	fread(&clr_used, 4, 1, fpbmp);
	
	/*����ɫ��Ϊ0����ʹ����2��bit�η�����ɫ*/
	if (clr_used == 0L)
	{
		clr_used = 1U << bit;
	}
	
	/*������ɫ��̬����ռ�*/
	if ((clr = (RGBQUAD *)malloc(4L * clr_used)) == 0)
	{
		return -1;
	}
	
	/*��ɫ����ָ���ʼ��*/
	pclr = clr;
	
	/*��ȡ��ɫ��*/
	fseek(fpbmp, 54L, 0);
	
	if ((fread((unsigned char *)pclr, 4L * clr_used, 1, fpbmp)) != 1)
	{
		return -1;
	}
	
	/*������ɫ��������ɫ�Ĵ���ֵ*/
	for (i = 0; i < clr_used; i++, pclr++) 
	{
		outportb(0x3c8, i);				/*����Ҫ�ı����ɫ��*/
		outportb(0x3c9, pclr->r >> 2);
		outportb(0x3c9, pclr->g >> 2);
		outportb(0x3c9, pclr->b >> 2);
	}
	
	free(clr);
	
	/*�������������ݶ�̬����ռ�*/
	if ((buffer = (unsigned char *)malloc(linebytes)) == 0)
	{
		return -1;
	}
	
	/*��ɨ����ʽ��ȡͼƬ���ݲ���ʾ*/
	fseek(fpbmp, 54L + 4L * clr_used, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*��ȡһ����������*/
		
		for (j = 0; j < width; j++)
		{
			Putpixel256(j + x, i + y, buffer[j]);
		}
	}
	
	free(buffer);	
	fclose(fpbmp);
	
	return 0;	
}

/**********************************************************
Function��		Putbmp64k

Description��	24λ��ѹ��bmpͼ��λ��ʾ������
				ֻ֧��24λ��ѹ��bmpͼ����������������Ϊ1024��
				����bmp���;���֧�֣�
				����0x117ģʽ��ʹ�ã�
				Ϊ�˼򻯣�û�������ļ����ͼ�⹦�ܼ�⹦�ܣ�������벻��Ҫ����ļ���

Calls��			Putpixel64k

				fseek
				fread
				fclose
				outportb
				malloc
				free

Called By��		AutoSimulate
				HandOperate
				Menu
				
Input��			int x		ͼƬ���Ͻǵĺ����꣨��Ļ�ο�ϵ��
				int y		ͼƬ���Ͻǵ������꣨��Ļ�ο�ϵ��
				const char * path	bmpͼƬ·��

Output��		��Ļ����ʾͼƬ

Return��		0	��ʾ�ɹ�
				-1	��ʾʧ��
				
Others��		None
**********************************************************/
int Putbmp64k(int x, int y, const char * path)
{
	/*ָ��ͼƬ�ļ����ļ�ָ��*/
	FILE * fpbmp;
	
	/*�����ػ���ָ��*/
	COLORS24 * buffer;
	
	/*ͼƬ�Ŀ�ȡ��߶ȡ�һ��������ռ�ֽ�������������ֽڣ�*/
	long int width, height, linebytes;
	
	/*ѭ������*/
	int i, j;
	
	/*ͼƬλ��*/
	unsigned int bit;
	
	/*ѹ��������*/
	unsigned long int compression;
	
	/*���ļ�*/
	if ((fpbmp = fopen(path, "rb")) == NULL)
	{
		printf("cannot open the file.");
		return -1;
	}
	
	/*��ȡλ��*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);
	
	/*��24λͼ���˳�*/
	if (bit != 24U)
	{
		return -1;
	}
	
	/*��ȡѹ������*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);
	
	/*����ѹ���㷨���˳�*/
	if (compression != 0UL)
	{
		return -1;
	}
	
	/*��ȡ��ȡ��߶�*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	
	/*��ȳ������˳�*/
	if (width > SCR_WIDTH)
	{
		return -1;
	}

	/*����һ������ռ�ֽ�������������Ŀ��ֽ�*/
	linebytes = (3 * width) % 4;
	
	if(!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}

	/*�������������ݶ�̬����ռ�*/
	if ((buffer = (COLORS24 *)malloc(linebytes)) == 0)
	{
		return -1;
	}
	
	/*��ɨ����ʽ��ȡͼƬ���ݲ���ʾ*/
	fseek(fpbmp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*��ȡһ����������*/
		
		/*һ�����ص����ݴ���ͻ���*/
		for (j = 0; j < width; j++)
		{
			/*0x117ģʽ�£�ԭͼ��������8λ�ֱ����Ϊ5λ��6λ��5λ*/
			buffer[j].R >>= 3;
			buffer[j].G >>= 2;
			buffer[j].B >>= 3;
			Putpixel64k(j + x, i + y,
			((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B)));	/*����������ɫ���������Ӹ�λ����λ����*/
		}
	}
	
	free(buffer);	
	fclose(fpbmp);
	
	return 0;	
}

/**********************************************************
Function��		Xorpixel

Description��	��λ��򻭵㺯��

Calls��			Selectpage

Called By��		XorCarBmp
				
Input��			int x					���غ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y					���������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				unsigned char color		��ɫ��������256��

Output��		����Ļ�ϻ�����

Return��		None
Others��		None
**********************************************************/
void Xorpixel(int x, int y, unsigned char color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾�������޸�*/
	unsigned char far * const video_buffer = (unsigned char far *)0xa0000000L;
	
	/*Ҫ�л���ҳ���*/
	unsigned char new_page;
	
	/*��Ӧ�Դ��ַƫ����*/
	unsigned long int page;
	
	/*�жϵ��Ƿ�����Ļ��Χ�ڣ����ھ��˳�*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return;
	}
	
	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 16;
	Selectpage(new_page);
	
	/*��λ���ʽ���Դ�д����ɫ����Ӧ�㻭��*/
	video_buffer[page] ^= color;	
}

/**********************************************************
Function��		Horizline

Description��	��ˮƽ�ߺ���
				���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
				��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ����ʱӦ��ֹ�����ش�����

Calls��			Selectpage

Called By��		Line
				Bar
				Circlefill

Input��			int x					��ʼ������꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y					��ʼ�������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int width				ˮƽ���ȣ�Ϊ���������죬Ϊ����������
				unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ���ˮƽ��

Return��		None
Others��		None
**********************************************************/
void Horizline(int x, int y, int width, unsigned char color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾�������޸�*/
	unsigned char far * const video_buffer = (unsigned char far *)0xa0000000L;
	
	/*Ҫ�л���ҳ���*/
	unsigned char new_page;
	
	/*��Ӧ�Դ��ַƫ����*/
	unsigned long int page;
	
	/*i��x����ʱ����������ѭ������*/
	int i;
	
	/*�ж����췽������ʼ�㿿��*/
	if (width < 0)
	{
		x = x + width;
		width = -width;
	}
	
	i = x;
	
	/*ʡ�Գ�����Ļ��߲���*/
	if (x < 0)
	{
		x = 0;
		width += i;
	}
	
	/*����������Ļ��ʱ�˳�*/
	if (x >= SCR_WIDTH)
	{
		return;
	}
	
	/*����������Ļ��ʱ�˳�*/
	if (y < 0 || y >= SCR_HEIGHT)
	{
		return;
	}
	
	/*ʡ�Գ�����Ļ�ұ߲���*/
	if (x + width > SCR_WIDTH)
	{
		width = SCR_WIDTH - x;
	}
	
	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 16;
	Selectpage(new_page);
	
	/*���Դ�д����ɫ��ˮƽ�߻���*/
	for (i = 0; i < width; i++)
	{
		*(video_buffer + page + i) = color;
	}
}

/**********************************************************
Function��		Line

Description��	��һ��ֱ�ߺ���
				���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
				��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ����ʱӦ��ֹ�����ش�����

Calls��			Putpixel256
				
				abs

Called By��		LightSW
				LightNE
				LightNW
				LightSE

Input��			int x1					��ʼ������꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y1					��ʼ�������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int x2					��ֹ������꣨��Ļ�ο�ϵ��
				int y2					��ֹ�������꣨��Ļ�ο�ϵ��
				unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ���ֱ��

Return��		None
Others��		None
**********************************************************/
void Line(int x1, int y1, int x2, int y2, unsigned char color)
{
	int	dx, dy;			/*ֱ��x��y�����ֵ*/
	int dx2, dy2;		/*�ӿ������ٶȵ��м�ֵ*/
	int xinc, yinc;		/*�ж��롢y���ӷ���ķ���ֵ*/
	int d, dxy;			/*���߱���*/
	
	/*���������ֵ���м����*/
	dx = abs(x2 - x1);
	dx2 = dx << 1;
	dy = abs(y2 - y1);
	dy2 = dy << 1;
	
	/*�ж�ֱ��x�������ӷ���*/
	if (x2 > x1)
	{
		xinc = 1;
	}
	
	/*�������ֱ��*/
	else if (x2 == x1)
	{
		/*y��������*/
		if (y1 > y2)
		{
			dx = y1;
			y1 = y2;
			y2 = dx;
		}
		
		/*����ֱ��*/
		for (dx = y1; dx <= y2; dx++)
		{
			Putpixel256(x1, dx, color);
		}
		
		return;
	}
	
	else
	{
		xinc = -1;
	}
	
	/*�ж�ֱ��y�������ӷ���*/
	if (y2 > y1)
	{
		yinc = 1;
	}
	
	/*�����ˮƽ��*/
	else if (y2 == y1)
	{
		Horizline(x1, y1, x2 - x1, color);		
		return;
	}
	
	else
	{
		yinc = -1;
	}
	
	/*******************************
	��������Bresenham�㷨����ֱ�ߡ�
	���㷨�ǵõ����ϵĳ���Ŀ����㷨��
	����ϸ����ȥ��
	*******************************/
	Putpixel256(x1, y1, color);
	
	if (dx >= dy)
	{
		d = dy2 - dx;
		dxy = dy2 - dx2;
		
		while (dx--)
		{
			if (d <= 0)
			{
				d += dy2;
			}
			
			else
			{
				d += dxy;
				y1 += yinc;
			}
			
			x1 += xinc;
			Putpixel256(x1, y1, color);
		}
	}
	
	else
	{
		d = dx2 - dy;
		dxy = dx2 - dy2;
		
		while (dy--)
		{
			if (d <= 0)
			{
				d += dx2;
			}
			
			else
			{
				d += dxy;
				x1 += xinc;
			}
			
			y1 += yinc;
			Putpixel256(x1, y1, color);
		}
	}
}

/**********************************************************
Function��		Bar
Description��	�����ο麯��
				���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
				��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ�Ĳ���ʱӦ��ֹ�����ش�����

Calls��			Horizline

Called By��		LightSW
				LightNE
				LightNW
				LightSE

Input��			int x1					�Խǵ�1�ĺ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y1					�Խǵ�1�������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int x2					�Խǵ�2�ĺ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y2					�Խǵ�2�������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ������ο�

Return��		None
Others��		None
**********************************************************/
void Bar(int x1, int y1, int x2, int y2, unsigned char color)
{
	/*tempΪ��ʱ������ѭ������*/
	/*widthΪ���γ�*/
	int temp, width;
	
	/*x��������*/
	if (x1 > x2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	
	/*y��������*/
	if (y1 > y2)
	{
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	
	/*������γ�*/
	width = x2 - x1;
	
	/*����ɨ�軭������*/
	for (temp = y1; temp <= y2; temp++)
	{
		Horizline(x1, temp, width, color);
	}
}

/**********************************************************
Function��		Circle
Description��	��ԲȦ����
				���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
				��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ�Ĳ���ʱӦ��ֹ�����ش�����

Calls��			Putpixel256

Called By��		LightSW
				LightNE
				LightNW
				LightSE

Input��			int xc					x_center����д��Բ�ĺ����꣨��Ļ�ο�ϵ��
				int yc					y_center����д��Բ�������꣨��Ļ�ο�ϵ��
				int radius				�뾶������Ϊ��
				unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ���ԲȦ

Return��		None
Others��		None
**********************************************************/
void Circle(int xc, int yc, int radius, unsigned char color)
{
	/*��ԲȦ�Ķ�λ�����;��߱���*/
	int x, y, d;
	
	/*�뾶����Ϊ���������˳�*/
	if (radius <= 0)
	{
		return;
	}
	
	/************************************
	��������Bresenham�㷨����ԲȦ��
	���㷨�ǵõ����ϵĳ���Ŀ����㷨��
	����ϸ����ȥ��
	************************************/
	y = radius;
	d = 3 - radius << 1;
	
	for (x = 0; x <= y; x++)
	{
		Putpixel256(xc + x, yc + y, color);
		Putpixel256(xc + x, yc - y, color);
		Putpixel256(xc - x, yc - y, color);
		Putpixel256(xc - x, yc + y, color);
		Putpixel256(xc + y, yc + x, color);
		Putpixel256(xc + y, yc - x, color);
		Putpixel256(xc - y, yc - x, color);
		Putpixel256(xc - y, yc + x, color);
		
		if (d < 0)
		{
			d += x * 4 + 6;
		}
		
		else
		{
			d += (x - y) * 4 + 10;
			y--;
		}
	}
}

/**********************************************************
Function��		Circlefill
Description��	��ʵ��Բ����
				���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
				��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ�Ĳ���ʱӦ��ֹ�����ش�����

Calls��			Horizline

Called By��		LightColorR
				LightColorY
				LightColorG
				LightColor1
				LightColor2
				LightColor3
				LightColor4
				LightColorD1
				LightColorD2
				LightColorD3
				TrafficLight

Input��			int xc					x_center����д��Բ�ĺ����꣨��Ļ�ο�ϵ��
				int yc					y_center����д��Բ�������꣨��Ļ�ο�ϵ��
				int radius				�뾶������Ϊ��
				unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ���ԲȦ

Return��		None
Others��		None
**********************************************************/
void Circlefill(int xc, int yc, int radius, unsigned char color)
{
	/*��ԲȦ�Ķ�λ�����;��߱���*/
	int x = 0,
		y = radius,
		dx = 3,
		dy = 2 - radius - radius,
		d = 1 - radius;
	
	/*�뾶����Ϊ���������˳�*/
	if (radius <= 0)
	{
		return;
	}
	
	/************************************
	��������Bresenham�㷨����ʵ��Բ��
	���㷨�ǵõ����ϵĳ���Ŀ����㷨��
	����ϸ����ȥ��
	************************************/
	while (x <= y)
	{
		Horizline(xc - x, yc - y, x + x, color);
        Horizline(xc - y, yc - x, y + y, color);
        Horizline(xc - y, yc + x, y + y, color);
        Horizline(xc - x, yc + y, x + x, color);
        
        if (d < 0)
        {
            d += dx;
            dx += 2;
        }
        
        else
        {
            d += (dx + dy);
            dx += 2;
            dy += 2;
            y--;
		}

        x++;
	}
}