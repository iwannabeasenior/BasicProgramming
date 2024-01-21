#include<stdio.h>
typedef struct Node{
	Node* left;
	Node* right;
	int data;
}NODE;
typedef NODE* tree;
tree root;
NODE*CreateNode(int x){
	NODE*p=new NODE;
	if(p==NULL) return NULL;
	p->left=NULL;
	p->right=NULL;
	p->data=x;
	return p;
}
int cal(int k, NODE* r, int d){

    if (r == NULL) return 0;

    if(k == d) return r->data;

    return cal(k, r->left, d+1) + cal(k, r->right, d+1);

}
int main()
{	
	NODE* a=CreateNode(6);
	NODE* b=CreateNode(1);
	NODE* c=CreateNode(9);
	NODE* d=CreateNode(4);
	NODE* e=CreateNode(7);
	NODE* g=CreateNode(8);
	NODE* h=CreateNode(2);
	NODE* i=CreateNode(5);
	NODE* k=CreateNode(3);
	NODE* l=CreateNode(10);
	a->left=b;
	a->right=c;
	b->right=d;
	c->left=e;
	c->right=g;
	d->left=h;
	d->right=i;
	g->left=k;
	g->right=l;
	printf("%d",cal(4,a,1));
}