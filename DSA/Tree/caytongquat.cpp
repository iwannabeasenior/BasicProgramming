#include<stdio.h>
#include<stdlib.h>
//duyet tien thu tu ->NLR
//duyet trung thu tu ->LNR
//duyet hau thu tu->LRN
struct Node{
	int id;
	Node*leftMostChild;
	// trai nhat
	Node*rightSibling;
	// anh em ben phai 
};
typedef struct Node NODE;
NODE*root;
typedef NODE* tree;
void Init(Node* &root){
	root=NULL;
}
NODE* CreateNode(int x){
	NODE*p=new NODE;
	if(p==NULL) return NULL;
	p->leftMostChild=NULL;
	p->rightSibling=NULL;
	p->id=x;
	return p;
}
//XEM LAI HAM INSERTNODE NAY
void insertNode(tree&root,NODE*p){
	if(root!=NULL){
		if(root->leftMostChild!=NULL)  return insertNode(root->leftMostChild,p);
		else if(root->rightSibling!=NULL) return insertNode(root->rightSibling,p); 
	}
	else root=p;
}
//find(r,id) : tim mot cay co nhan truoc tren cay co goc r
Node*find(NODE*r,int v){
	if(r==NULL) return NULL;
	if(r->id==v) return r;
	NODE*p=r->leftMostChild;
	while(p!=NULL){
		NODE*h=find(p,v);
		if(h!=NULL) return h;
		p=p->rightSibling;
	}
	return NULL;
}
// NLR
void preOrder(NODE*r){
	if(r==NULL) return ;
	printf("%d",r->id);
	Node *p=r->leftMostChild;
	while(p!=NULL){
		preOrder(p);
		p=p->rightSibling;
	}
}
//LNR
void inOrder(NODE*r){
	if(r==NULL) return ;
	NODE*p=r->leftMostChild;
	inOrder(p);
	printf("%d",r->id);
	if(p!=NULL){
		inOrder(p);
		p=p->rightSibling;
	}
}
//LRN
void postOrder(NODE*r){
	if(r==NULL ) return ;
	NODE*p=r->leftMostChild;
	while(p!=NULL){
		postOrder(p);
		p=p->rightSibling;
	}
	printf("%d",r->id);
}
//dem so nut tren cay
int count(NODE*r){
	if(r==NULL) return 0;
	int s=1;
	NODE*p=r->leftMostChild;
	while(p!=NULL){
		s+=count(p);
		p=p->rightSibling;
	}
	return s;
}
//dem so nut la tren cay
int countLeaves(NODE*r){
	if(r==NULL) return 0;
	int s=0;
	NODE*p=r->leftMostChild;
	if(p==NULL ) s=1;
	while(p!=NULL){
		s+=countLeaves(p);
		p=p->rightSibling;
	}
	return s;
}
//do cao cua 1 nut
int height(NODE*p){
	if(p==NULL) return 0;
	int maxh=0;
	NODE*q=p->leftMostChild;
	while(q!=NULL){
		int h=height(q);
		if(h>maxh) maxh=h;
		q=q->rightSibling;
		}
		return maxh+1;
}
//do sau cua 1 nut
int depth(NODE*r,int v, int d){
	//d la do sau cua 1 nut
	if(r==NULL) return -1;
	if(r->id==v) return d;
	NODE*p=r->leftMostChild;
	while(p!=NULL){
		if(p->id==v) return d+1;
		int dv=depth(p,v,d+1);
		if(dv>0) return dv;
		p=p->rightSibling;
	}
	return -1;
}
int depth(NODE*r ,int v){
	return depth(r,v,1);
}
//tim nut cha cua 1 nut
NODE*parent(NODE*p, NODE*r){
	if(r==NULL) return NULL;
	NODE*q=r->leftMostChild;
	while(q!=NULL){
		if(p==q) return r;
		NODE*pp=parent(p,q);
		if(pp!=NULL) return pp;
		q=q->rightSibling;
	}
	return NULL;
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		NODE*p=CreateNode(x);
		insertNode(root,p);
	}

	postOrder(root);
}