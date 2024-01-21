#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct queue{
	int A[MAX];
	int front,rear;
};
typedef struct queue QUEUE;
void Init(QUEUE&q){
	q.front=0;
	q.rear=-1;
}
int IsEmpty(QUEUE q){
	if(q.front>q.rear){
		return 1;
	}
	return 0;
}
int IsFull(QUEUE q){
	if(q.rear==MAX-1){
		return 1;
	}
	return 0;
}
void Add(QUEUE&q,int x){
	if(IsFull(q)==0){
		q.rear++;
		q.A[q.rear]=x;
	}
}
int Remove(QUEUE&q){
	int x;
	if(!IsEmpty(q)){
		x=q.A[q.front];
		q.front++;
		return x;
	}
	else{
		q.front=0;q.rear=-1;
	}
}
void Input(QUEUE&q,int n){
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		Add(q,x);
	}
}
void Output(QUEUE q){
	for(int i=q.front;i<=q.rear;i++){
		printf("%d",q.A[i]);
	}
}
int main()
{
	
}