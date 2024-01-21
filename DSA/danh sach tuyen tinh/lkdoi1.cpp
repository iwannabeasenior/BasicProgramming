#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *next;
	Node* prev;
}NODE;
typedef struct doulist{
	NODE*pHead;
	NODE*pTail;
} DLIST;
void KhoiTao(DLIST &ds){
	ds.pHead=NULL;
	ds.pTail=NULL;
}
int kiemtrarong(DLIST ds){
	if(ds.pHead==NULL){
		return 1;
	}
	return 0;
}
NODE* nodemoi(int x){
	NODE*p;
p=new NODE;
if(p==NULL){
	printf("khong du bo nho");
	return NULL;
}
p->data=x;
p->next=NULL;
p->prev=NULL;
return p;

}


int main()
{
DLIST ds;
KhoiTao(ds);
kiemtrarong(ds);
}