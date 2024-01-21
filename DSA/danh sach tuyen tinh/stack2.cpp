#include<stdio.h>
#include<stdlib.h>
// Khởi tạo stack: Init (S)
// Tạo mới 1 nút: CreateNode (x)
// Kiểm tra stack rỗng: IsEmpty (S)
// Đưa phần tử vào Stack: Push (S,x)
// Lấy phần tử ra khỏi Stack: Pop (S, x)
struct node{
	int data;
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
NODE*x CreateNode(int x){
	NODE *p=new NODE;
	if(p==NULL){
		printf("khong du bo nho");
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}
int IsEmpty(STACK s){
	if(s.top==NULL) return 1;
	return 0;
}
// (s.top) node moi-node cu, them vao dau
void Push(STACK &s,int x){
	NODE * NewNode=CreateNode(x);
	if(NewNode!=NULL){
		if(IsEmpty(s)){
			s.top=NewNode;
		}
		else{
			NewNode->next=s.top;
			s.top=NewNode;
		}
	}
}
int Pop(STACK&s){
	NODE*p;
	int x;
	if(!IsEmpty(s)){
		p=s.top;
		s.top=p->next;
		x=p->data;
		delete p;
		return x;
	}
}
// Nhap n phan tu vao stack
void Input(STACK&s,int n){
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		Push(s,x);
	}
}
//xuat n phan tu trong stack
void Output(STACK s){
	NODE *p;
	for(p=s.top;p!=NULL;p=p->next){
		printf("%d",p->data);
	}
}
int main()
{
STACK s;
Init(s);
int n;
scanf("%d",&n);
Input(s,n);
Output(s);;
int x=17;
Push(s,x);
Output(s);
int p=Pop(s);
Output(s);
}