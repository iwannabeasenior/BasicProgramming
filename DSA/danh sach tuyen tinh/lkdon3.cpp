#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node*next;
}NODE;
typedef struct List{
	Node*pHead;
	Node*pTail;
}LIST;
void khoitao1(LIST &ds){
	ds.pHead=NULL;
	ds.pTail=NULL;
}
int kiemtrarong(LIST ds){
	if(ds.pHead==NULL) return 1;
	return 0;
}
void khoitao(int x){
	NODE*p;
	p=new(NODE);
	if(p==NULL){
		printf("thieu bo nho");
	}
	p->data=x;
	p->next=NULL;
	return p;
}
//chen dau
void chendau(LIST &ds,NODE*p){
	if(ds.pHead==NULL){
		ds.pHead=p;
		ds.pTail=p;
	}
	else{
		p->next=ds.pHead;
		ds.pHead=p;
	}
}
//chen cuoi
void chencuoi(){
	if(ds.pHead==NULL){
		ds.pHead=p;
		ds.pTail=p;
	}
	else{
		ds.pTail->next=p;
		ds.pTail=p;
	}
}
//chèn giữa
void chengiua(LIST &ds,NODE*q,NODE*p){
	if(q==NULL){
		chendau(ds,p);
	}
	else{
		p->next=q->next;
		q->next=p;
		if(q==ds.pTail){
			ds.pTail=p;
		}
	}
}	
int main()
{	int x=10,y=20;
	NODE*p=new NODE;//ton bo nho hon 
	NODE*q=new NODE;
	p=khoitao(x);
	q=khoitao(y);
	LIST ds;

	chengiua(LIST &ds,q,p);
}