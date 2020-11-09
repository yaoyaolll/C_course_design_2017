#ifndef _manager_h_
#define _manager_h_

void manager(void);
void manager_revise(void);
void show_list(struct caipin *wjcf);
void change(char *s,char *m);
void transform(int x,int y,char *s,char c);
void recaipin(struct caipin *list);
void qr(void);
void manager_order(int *aflag);
void manager_init(void);
void detail(int flag,int count,int *aflag);
void Delete(int flag,int count,int *aflag);
void List(struct caipin *wjcf,int *aflag);
void price_revise(int *fen,struct caipin *list,const int flag,const int count);
void recaipin1(int price_count,char *s,struct caipin *list);
void recaipin2(const int flag,const int i,struct caipin *list);
void manager_user(void);

#endif