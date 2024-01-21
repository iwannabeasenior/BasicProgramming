#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	Node * next;
};
typedef struct Node NODE;
struct List {
	NODE*pHead;
	NODE*pTail;
};
typedef struct List LIST;
void khoitao(LIST &ds){
	ds.pHead=NULL;
	ds.pTail=NULL;
}
int kiemtrarong(LIST &ds){
	if(ds.pHead==NULL) return 1;
	return 0;
}
NODE* Taonode(int x){
	NODE*p;
	p=new(NODE);
	if(p==NULL){
		printf("het bo nho");
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}
void chendau(LIST& ds,NODE*p){
	if(ds.pHead==NULL){
		ds.pHead=p;
		ds.pTail=p;
	}
	else{
		p->next=ds.pHead;
		ds.pHead=p;
	}
}
int main()
{
	LIST ds;
	printf("%p",ds);
	printf("%p",ds.pHead);



	int x=10;
	NODE*p=Taonode(x);
	chendau(ds,p);
}