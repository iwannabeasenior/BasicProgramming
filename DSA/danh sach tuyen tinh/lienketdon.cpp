#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	Node *next;
};
typedef struct Node NODE;
struct list{
	NODE* pHead;;
	NODE* pTail;
};
typedef struct list LIST;
void Khoitao(LIST &ds){
	ds.pHead=NULL;
	ds.pTail=NULL;
}
//khoi tao danh sach lk don
int Kiemtrarong(LIST ds){
	if(ds.pHead==NULL){
		return 1;
	}
	return 0;
}
//kiem tra xem danh sach rong hay khong
NODE* TaoNode(int x){
	NODE*p;
	p=new NODE;
	if(p==NULL){
		printf("Khong du bo nho");
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}
int main()
{
LIST ds;
Khoitao(ds);
Kiemtrarong(ds);
TaoNode(2);
}