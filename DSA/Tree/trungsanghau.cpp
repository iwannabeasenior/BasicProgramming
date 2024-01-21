#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "ctype.h"
/** 
 * use QUEUE
*/
struct node
{
	char info;
	node *next;
};

struct list
{
	node *dau;
};

void list_null(list &l)
{
	l.dau=NULL;
}

node* tao(char a)
{
	node *p=new node;
	if(p==NULL)return NULL;
	p->info=a;
	p->next=NULL;
	return p;
}

void add_dau(list &l,node *p)
{
	if(l.dau==NULL)
		l.dau=p;
	else
	{
		p->next=l.dau;
		l.dau=p;
	}
}

int uu_tien(char c)
{
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/'||c=='%')
		return 2;
	return 0;
}

void trung_hau(list &l,char *chuoi)
{
	int n=strlen(chuoi);
	char hauto[50];int j=0;

	for(int i=0;i<n;i++)
	{
		char c=chuoi[i];

		if(isalnum(c)!=0)
		{
			hauto[j++]=c;
		}
		else
		{
			//nếu c là '(' thì push vào stack
			if(c=='(')
			{
				node *p=tao(c);
				add_dau(l,p);
			}
			else
			{	
				//nếu c là ')' thì pop tất cả các phẩn tử cho đến khi gặp '('
				if(c==')')
				{
					while(l.dau->info!='(')
					{
						node *p=l.dau;
						hauto[j++]=l.dau->info;
						l.dau=l.dau->next;
						delete p;
					}
					// xóa '('
					node *p=l.dau;
					l.dau=l.dau->next;
					delete p;
				}
				else
				{
					// nếu là toán tử thì pop từ trên xuống với điều kiện ưu tiên lớn hơn c
					while(uu_tien(l.dau->info)>=uu_tien(c)&&l.dau!=NULL)///lỗi
					{
						node *p=l.dau;
						hauto[j++]=l.dau->info;
						l.dau=l.dau->next;
						delete p;
					}
					// push c vào stack
					node *p=tao(c);
					add_dau(l,p);	
				}
			}
		}
	}



// pop tất cả còn lại trong stack ra
	while(l.dau!=NULL)
	{
		node *p=l.dau;
		hauto[j++]=l.dau->info;
		l.dau=l.dau->next;
		delete p;
	}
	for(int i=0;i<j;i++)
	{
		printf("%c",hauto[i]);
	}
}
int main()
{
	list l;
	list_null(l);

	char bt[50];
	printf("nhap bieu thuc doi sang hau to ");
	gets(bt);

	trung_hau(l,bt);
	getch();
}