#include<stdio.h>
#include<stdlib.h>
struct Node{
	Node* left;
	Node* right;
	int data;
};
typedef struct Node NODE;
typedef NODE* Tree;
NODE* CreateNode(int x){
	NODE* p;
	p=new NODE;
	if(p==NULL) return NULL;
	else {
		p->left=NULL;
		p->right=NULL;
		p->data=x;
	}
	return p;
}
int InsertNode(Tree &root,NODE*p){
	if(root!=NULL){
		if(root->data==p->data) return 0;
		else if(root->data>p->data)  InsertNode(root->left,p);
		else  InsertNode(root->right,p);
		}
	else root=p;
}
void Init (Tree&root){
	root=NULL;
}
void NLR(Tree root){
    if (root!=NULL){
        //xu ly node goc
        printf("%d \t",root->data);
        //su dung de quy de duyet tiep cay con trai
        NLR(root->left);
        //su dung de quy de duyet tiep cay con phai
        NLR(root->right);
    }
}
void LNR(Tree root){
	if(root!=NULL){
		LNR(root->left);
		printf("%d",root->data);
		LNR(root->right);
	}
}
void LRN(Tree root){
	if(root!=NULL){
		LRN(root->left);
		LRN(root->right);
		printf("%d",root->data);
	}
}
//find with recursion
NODE* SearchNodeRecursion(Tree root,int n){
	if(root!=NULL){
		if(root->data==n) return root;
		if(root->data>n) SearchNodeRecursion(root->right,n);
		else SearchNodeRecursion(root->left,n);
	}
	return NULL;

}
//find without recursion
NODE* SearchNode(Tree root,int n){
	NODE*p=root;
	while(p!=NULL){
		if(p->data==n) return p;
		else if(p->data>n) p=p->right;
		else p=p->left;
	}
	return NULL;
}
// ham tim phan tu the mang 
void FindReplNode(Tree &p, Tree &q){
    if(q->left){
        FindReplNode(p, q->left);
    }else{
        p->data = q->data;
        p = q;
        q = q->right;
    }
}
void DeleteNode(Tree &root, int X){
    //neu cay rong thi ket thuc ham xoa
    if(root== NULL){
        return;
    }
    //neu khoa X nho hon data cua node dang xet
    if(root->data > X){
        //de quy ham xoa theo nhanh trai
        return DeleteNode(root->left, X);
    }
    //neu khoa X lon hon data cua node dang xet
    if (root->data < X){
        //de quy ham xoa theo nhanh phai
        return DeleteNode(root->right, X);
    }
    //tao node p lam node the mang
    Node* p = root;
    //neu cay con trai la rong
    if(root->left == NULL){
        //gan lai node goc theo nhanh phai
        root = root->right;
    }else if(root->right == NULL){//neu cay con phai la rong
        //gan lai node goc theo nhanh trai
        root = root->left;
    }else{ // nguoc lai, neu cay co du 2 con
        //su dung node the mang
        FindReplNode (p, root->right);
    }
    //xoa di node p
    delete p;
}
int main()
{
	Tree root;
	Init(root);
	for(int i=1;i<=8;i++)
	{
		int x;
		scanf("%d",&x);
		NODE*p=CreateNode(x);
		InsertNode(root,p);
	}
	// NLR(root);
	DeleteNode(root,3);
	// RemoveTree(root);
	NLR(root);
}
