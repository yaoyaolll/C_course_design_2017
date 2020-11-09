/*
Function List��
	1.unsigned int Getpixel64k(int x, int y);
		ȡ����ɫ��������������0x117ģʽ��
		
	2.int MouseInit(void);
		��긴λ
	
	3.void MouseRange(int x1, int y1, int x2, int y2);
		��������ƶ���Χ
		
	4.int MouseXYB(MOUSE * mouse);
		��ȡ��ǰ���״̬������ָ���ṹ��
		
	5.int MouseBarLeft(int x1, int y1, int x2, int y2);
		�ж��������Ƿ���ָ�������ڰ���
		
	6.void MouseStoreBk(int x, int y);
		���汻��긲��������Դ�����
		
	7.void MousePutBk(int x, int y);
		�ָ�����긲��������Դ�����
		
	8.void MouseReset(void);
		�������״̬����ΧΪȫ��
		
	9.void MouseDraw(MOUSE mouse);
		������꺯��		

History��		�Ա��ļ����޸��뼰ʱ�����¸�ʽ��¼�����棨ÿ���޸ĵ����г�����
	Example��	Date��
				Author��
				Version��
				Modification��
**********************************************************/
#ifndef	MOUSE_H
#define	MOUSE_H

#include"SVGAmode.h"

/*���ṹ�壬�������״̬*/
typedef struct mouse_
{
	int x;			/*��������*/
	int y;			/*���������*/
	int but;		/*��ť��״̬��0,1λ�ֱ��ʾ���Ҽ�����λΪ1��ʾ���£�0��ʾ�ɿ�*/
}	MOUSE;

/**********************************************************
Function��		Getpixel64k

Description��	ȡ����ɫ��������������0x117ģʽ��

Calls��			Selectpage
				
Called By��		MouseStoreBk

Input��			int x	���غ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y	���������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��

Output��		None

Return��		unsigned int	��Ӧ��������Դ��������ɫ
				
Others��		None
**********************************************************/
extern unsigned int Getpixel64k(int x, int y);

/**********************************************************
Function��		 MouseInit

Description��	��긴λ

Calls��			int86
				
Called By��		MouseReset

Input��			None

Output��		��긴λ

Return��		unsigned int	����ִ�н����
								0x0000	��֧��
								0xffff	֧��
				
Others��		None
**********************************************************/
extern int MouseInit(void);

/**********************************************************
Function��		 MouseRange

Description��	��������ƶ���Χ

Calls��			int86
				
Called By��		MouseReset

Input��			int x1		�ƶ���Χ���ϽǺ�����
				int y1		�ƶ���Χ���Ͻ�������
				int x2		�ƶ���Χ���½Ǻ�����
				int y2		�ƶ���Χ���½�������

Output��		None
Return��		None
				
Others��		None
**********************************************************/
extern void MouseRange(int x1, int y1, int x2, int y2);

/**********************************************************
Function��		 MouseXYB

Description��	��ȡ��ǰ���״̬������ָ���ṹ��

Calls��			int86

Called By��		MouseBarLeft
				MouseBarRight
				Menu

Input��			MOUSE * mouse	������״̬�ṹ��ĵ�ַ

Output��		MOUSE * mouse	������״̬�ṹ�屻����

Return��		mouse->but		��갴ť״̬

Others��		None
**********************************************************/
extern int MouseXYB(MOUSE * mouse);

/**********************************************************
Function��		 MouseBarLeft

Description��	�ж��������Ƿ���ָ�������ڰ���

Calls��			MouseXYB

Called By��		Menu

Input��			int x1		�ƶ���Χ���ϽǺ�����
				int y1		�ƶ���Χ���Ͻ�������
				int x2		�ƶ���Χ���½Ǻ�����
				int y2		�ƶ���Χ���½�������

Output��		None

Return��		1		��������ָ�������ڰ���
				0		������û��ָ�������ڰ���

Others��		None
**********************************************************/
extern int MouseBarLeft(int x1, int y1, int x2, int y2);

/**********************************************************
Function��		 MouseStoreBk

Description��	���汻��긲��������Դ�����
				Bk��background����д

Calls��			Getpixel64k

Called By��		MouseReset
				Menu

Input��			int x		����������
				int y		�����������

Output��		int mouse_bk[10][10]			ȫ�ֱ������汻��긲��������Դ�����
				int const mouse_shape[10][10]	�����״ȫ�ֱ�������

Return��		None
Others��		None
**********************************************************/
extern void MouseStoreBk(int x, int y);

/**********************************************************
Function��		 MousePutBk

Description��	�ָ�����긲��������Դ�����
				Bk��background����д

Calls��			Putpixel64k

Called By��		Menu

Input��			int x							����������
				int y							�����������
				int mouse_bk[10][10]			ȫ�ֱ������汻��긲��������Դ�����
				int const mouse_shape[10][10]	�����״ȫ�ֱ�������
				
Output��		����Ļ�ϻָ�����긲��������Դ�����

Return��		None
Others��		None
**********************************************************/
extern void MousePutBk(int x, int y);

/**********************************************************
Function��		 MouseReset

Description��	�������״̬����ΧΪȫ��

Calls��			MouseInit
				MouseRange
				MouseStoreBk
				
				printf
				getch
				exit

Called By��		Menu

Input��			None
				
Output��		�������״̬

Return��		None
Others��		None
**********************************************************/
extern void MouseReset(void);

/**********************************************************
Function		MouseDraw

Description��	������꺯��

Calls��			Putpixel64k

Called By��		Menu

Input��			MOUSE mouse						������״̬�Ľṹ��
				int const mouse_shape[10][10]	�����״ȫ�ֱ�������
				
Output��		��ָ�����괦�������

Return��		None
Others��		None
**********************************************************/
extern void MouseDraw(MOUSE mouse);
int Ispress(void);

#endif