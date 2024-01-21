#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node*left;
	Node*right;
} NODE;
typedef  NODE* Tree;
Tree root;
void Init(Tree &root){
	root=NULL;
}
NODE*CreateNode(int x){
	Node*p=new NODE;
	if(p==NULL)
	{
		return NULL;
	}
	p->left=NULL;
	p->right=NULL;
	p->data=x;
	return p;
}
int InsertNode(Tree &root,NODE*p){
	if(root!=NULL){
		if(root->data==p->data){
			return 0;
		}
		if(root->data>p->data){
			return InsertNode(root->left,p);
		}
		else return InsertNode(root->right,p);
	}
	else{
		root=p;
	}
}
void Input(Tree&root,int n){
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		NODE*p=CreateNode(x);
		InsertNode(root,p);
	}
}

int main()
{

}