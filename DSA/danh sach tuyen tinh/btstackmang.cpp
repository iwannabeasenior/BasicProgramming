#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct date{
	int ngay,thang,nam;
};
typedef struct date date;
struct Maytinh{
	char ID[6];
	char ten[256];
	date ngay_xuat;
	float gia_xuat;
};

typedef struct Maytinh mt;
void nhap(mt &t){
	scanf("%s",t.ID);
	scanf("%s",t.ten);
	scanf("%f",&t.gia_xuat);
	scanf("%d %d %d",&t.ngay_xuat.ngay,&t.ngay_xuat.thang,&t.ngay_xuat.nam);
	
}
//
struct node{
	mt x;
	node* next;
};
typedef struct node NODE;
struct stack{
	NODE* top;
};
typedef struct stack STACK;
void Init(STACK &s){
	s.top=NULL;
}
NODE* CreateNode(mt t){
	NODE*u=new NODE;
	if(u==NULL){
		printf("khong du bo nho");
		return NULL;
	}
	u->x=t;
	u->next=NULL;
	return u;
}
void Push(STACK&s,mt t){
	NODE* NewNode=CreateNode(t);
	if(NewNode!=NULL){
		if(s.top==NULL){
			s.top=NewNode;
		}
		else{
			NewNode->next=s.top;
			s.top=NewNode;
		}
		
	}
}
mt Pop(STACK &s){
	NODE* p;
	mt t;
	if(s.top!=NULL){
		p=s.top;
		s.top=p->next;
		t=p->x;
		delete p;
		return t;
	}
}
void Nhap(STACK&s,int n){
	for(int i=0;i<n;i++)
	{
		mt t;
		nhap(t);
		Push(s,t);
	}
}
void Xuat(STACK s){
	NODE *p;
	for(p=s.top;p!=NULL;p=p->next){
		printf("%f",p->x.ID);
	}
}
int main(){
STACK s;
int n;
scanf("%d",&n);
Nhap(s,n);
Xuat(s);
}