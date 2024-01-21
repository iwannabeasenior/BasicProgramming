#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int x;
	node *next;
}NODE;
typedef struct queue{
	NODE* front;
	NODE* rear;
}QUEUE;
void Init(QUEUE&q){
	q.front=NULL;
	q.rear=NULL;
}
NODE* CreateNode(int x){
	NODE* p;
	p=new NODE;
	if(p==NULL){
		printf("khong du bo nho");
		return NULL;
	}
	p->x=x;
	p->next=NULL;
	return p;
}
int IsEmpty(QUEUE q){
	if(q.front==NULL){
		return 1;
	}
	return 0;
}
// node cu -node moi(q.rear), them vao cuoi
void Add(QUEUE&q,NODE*NewNode){
	if(q.front==NULL){
		q.front=NewNode;
		q.rear=NewNode;
	}
	else{
		q.rear->next=NewNode;
		q.rear=NewNode;
	}
}
int Remove(QUEUE&q){
	int x;
	NODE*p=NULL;
	if(!IsEmpty(q)){
		p=q.front;
		x=p->x;
		q.front=p->next;
		delete p;
		if(q.front==NULL){
			q.rear=NULL;
		}
	}
	return x;
}
//nhap xuat node vao trong queue
void Input(QUEUE&q,int n){
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		NODE*p;
		p=CreateNode(x);
		Add(q,p);
	}
}
void Output(QUEUE q){
	 NODE*p;
	 for(p=q.front;p!=NULL;p=p->next){
	 	printf("%d\n",p->x);
	 }
}
int main()
{

}