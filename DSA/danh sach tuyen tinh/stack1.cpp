#include<stdio.h>
#define MAX 100
struct stack
{
	int top;
	int A[MAX];
};
typedef struct stack STACK;
#include<stdlib.h>
void Init(STACK &s){
	s.top=-1;
}
int Empty(STACK s){
	if(s.top==-1){
		return 1;
	}
	return 0;
}
int IsFull(STACK s){
	if(s.top==MAX-1){
		return 1;
	}
	return 0;
}
void Push(STACK &s,int x){
	if(IsFull(s)==0){
		s.top++;
		s.A[s.top]=x;
	}
}
int Pop(STACK &s){
	int x;
	if(!Empty(s)){
		x=s.A[s.top];
		s.top--;
	}
	return x;
}
int Top(STACK &s){
	int x;
	if(!Empty(s)){
		x=s.A[s.top];
		return x;
	}else {
		return NULL;
	}
}
//nhap n phan tu vao stack
void Input(STACK&s,int n){
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		Push(s,x);
	}
}
//xuat cac phan tu trong stack
void Output(STACK s){
	for(int i=s.top;i>-1;i--){
		printf("%d n",s.A[i]);
	}
}
int main()
{
	STACK s;
	Init(s);
}