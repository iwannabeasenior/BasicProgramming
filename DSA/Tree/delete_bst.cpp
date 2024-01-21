#include <stdio.h>
#include <stdlib.h>
 struct Node{
    //khai bao du lieu cua node co kieu du lieu int
    int data;
    //khai bao con tro den cay con trai
    Node* left;
    //khai bao con tro den cay con phai
    Node* right;
};
typedef struct Node* Tree;
Tree root;
void Init (Tree &root){   
    //gan node goc ve NULL
    root = NULL;
}
Node* CreateNode (int x){
    //tao node moi
    Node* p = new Node;
    //neu cay nhi phan khong rong
    if (p != NULL){
        //gan cay con trai va cay con phai mac dinh bang NULL
        p->left = NULL;
        p->right = NULL;
        //gan data bang x
        p->data = x;
    }
    //tra ve node p
    return p;
}
int InsertNode(Tree &root, Node*p){
    //neu node root khac rong thi thuc hien them vao cay
    if (root != NULL){
        //neu 2 data cua 2 node bang nhau thi ket thuc
        if (root->data==p->data){
            return 0;
        }
        //neu khoa cua root lon hon khoa cua p thi goi de quy trai 
        if (root->data > p->data){
            return InsertNode(root->left, p);
        }
        else{//neu khoa cua root nho hon khoa cua p thi goi de quy phai 
            return InsertNode(root->right,p);
        }
    }else { //truong hop neu node root la rong thi them node p vao node root
        root = p;
    }
}
void Input(Tree &root){
    int n;
    printf ("NHAP SO LUONG NODE CAN THEM: "); 
    scanf("%d",&n);
    for(int i=1; i<=n;i++){
        int x;
        printf ("NHAP DATA CUA NODE %d: ",i); 
        scanf("%d",&x);
        //tao node p co data = x
        Node* p = CreateNode(x);
        //them node p co data x vao trong cay
        InsertNode(root, p);
    }
}
void NLR(Tree root){
    if (root!=NULL){
        //hien thi du lieu cua tung node sau khi duyet
        printf("%d \t",root->data);
        //su dung de quy de duyet tiep cay con trai
        NLR(root->left);
        //su dung de quy de duyet tiep cay con phai
        NLR(root->right);
    }
}
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
void RemoveTree(Tree &root){
    //neu van ton tai node goc
    if(root){
        //de quy sang nhanh trai
        RemoveTree(root->left);
        //de quy sang nhanh phai
        RemoveTree(root->right);
        //xoa node goc
        delete(root);
    }
}
int main(){
    //tao cay voi node goc la root
    Tree root;
    //khoi tao cay
    Init(root);
    //nhap n phan tu vao cay
    Input(root);
    //duyet cay theo NLR
    printf("Duyet cay theo NLR\n");
    NLR(root);
    //tao khoa X = 5
    int X = 5;
    //goi ham xoa node theo khoa X
    DeleteNode(root,X);
    //duyet cay theo NLR
    printf("\nCay sau khi xoa node co khoa X = 5\n");
    NLR(root);
    //goi ham huy toan bo cay
    RemoveTree(root);
}