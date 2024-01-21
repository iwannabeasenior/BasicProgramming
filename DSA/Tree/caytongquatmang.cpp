/* Chuong trinh cai dat cay tong quat bang mang*/
#include<stdio.h>
#define MAXLENGTH 100   //chi so toi da cua mang
#define NIL -1
typedef char DataType;
typedef int Node;
typedef struct {
   DataType Data[MAXLENGTH];   //Luu gia tri cua nut
   Node Parent[MAXLENGTH];      //Cha cua nut i se luu o vi tri i trong mang
   int MaxNode;// so luong node hien co 
}Tree;

//Khoi tao cay rong
void MakeNull_Tree (Tree *T)
{
   (*T).MaxNode=0;
}
//Kiem tra cay rong
int EmptyTree(Tree T)
{
   return T.MaxNode == 0;
}
//Xac dinh nut cha cua nut tren cay
Node Parent(Node n,Tree T)
{
   if (EmptyTree(T) || (n>T.MaxNode-1))
      return NIL;
   else
      return T.Parent[n];
}
//Xac dinh gia tri cua nut tren cay
DataType Label_Node(Node n,Tree T)
{
   if (!EmptyTree(T) && (n<=T.MaxNode-1))
      return T.Data[n];
}
//Xac dinh nut goc trong cay
Node Root(Tree T)
{
   if (!EmptyTree(T))
      return 0;
   else
      return NIL;
}
//Ham xac dinh con trai nhat cua mot nut
Node LeftMostChild(Node n,Tree T)
{
   Node i;
   int found;
   if (n<0)
      return NIL;
   i=n+1;      
   found=0;
   while ((i<=T.MaxNode-1) && !found)
      if (T.Parent[i]==n)
         found=1;
      else i=i+1;
   if (found)
      return i;
   else
      return NIL;
}
//Ham xac dinh anh em ruot phai cua mot nut
Node RightSibling(Node n,Tree T)
{
   Node i,parent;
   int found;
   if (n<0)
      return NIL;
   parent=T.Parent[n];
   i=n+1;
   found=0;
   while ((i<=T.MaxNode-1) && !found)
      if (T.Parent[i]==parent)
         found=1;
      else i=i+1;
   if (found)
      return i;
   else
      return NIL;
}
//Duyet tien tu
void PreOrder(Node n,Tree T)
{
   Node i;
   printf("%c ",Label_Node(n,T));
   i=LeftMostChild(n,T);
   while (i!=NIL) {
      PreOrder(i,T);
      i=RightSibling(i,T);
   }
}
//Duyet trung tu
void InOrder(Node n,Tree T)
{
   Node i;
   i=LeftMostChild(n,T);
   if (i!=NIL)
      InOrder(i,T);
   printf("%c ",Label_Node(n,T));
   i=RightSibling(i,T);
   while (i!=NIL){
      InOrder(i,T);
      i=RightSibling(i,T);
   }
}
//Duyet hau tu
void PostOrder(Node n,Tree T)
{
   Node i;
   i=LeftMostChild(n,T);
   while (i!=NIL){
      PostOrder(i,T);
      i=RightSibling(i,T);
   }
   printf("%c ",Label_Node(n,T));
}
//Doc cay
void ReadTree(Tree *T){
   int i;
   MakeNull_Tree(&*T);
   do {
      printf("Cay co bao nhieu nut? ");
      scanf("%d",&(*T).MaxNode);
   } while (((*T).MaxNode<1) || ((*T).MaxNode>MAXLENGTH));
   printf("Nhap nhan cua nut goc: ");
   fflush(stdin);
   scanf("%c",&(*T).Data[0]);
   (*T).Parent[0]=NIL; /* nut goc khong co cha */
   for (i=1;i<=(*T).MaxNode-1;i++){
      printf("Nhap cha cua nut %d: ",i);
      scanf("%d",&(*T).Parent[i]);
      printf("Nhap nhan cua nut %d: ",i);
      fflush(stdin);
      scanf("%c",&(*T).Data[i]);
   }
}
//Chuong trinh chinh
void main(){
   
   Tree T;   
   printf("Nhap du lieu cho cay tong quat\n");
   ReadTree(&T);
   printf("\nDanh sach duyet tien tu cua cay vua nhap la\n");
   PreOrder(Root(T),T);
   printf("\nDanh sach duyet trung tu cua cay vua nhap la\n");
   InOrder(Root(T),T);
   printf("\nDanh sach duyet hau tu cua cay vua nhap la\n");
   PostOrder(Root(T),T);
   

}