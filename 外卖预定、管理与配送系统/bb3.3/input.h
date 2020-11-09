#ifndef _input_h_
#define _input_h_


void inputzh(int x1,int x2,int y,User *users);
void inputmm(int x1,int x2,int y,User *users);
void input_revise(int *posx,char *s,int *count);
void printASC(char *s,int x,int y,int dx,int dy,unsigned char color);
void printasc(char c,int x,int y,int dx,int dy,unsigned char color);
void printhz16(int x,int y,char *s,int color);
void printASC32_16(char *s,int x,int y,unsigned char color);
void inputinfo(struct information *info,int flag);

#endif 