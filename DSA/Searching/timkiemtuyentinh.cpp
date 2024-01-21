#include<stdio.h>
int LinearSearch(int a[],int n,int x){
    for(int i=0;i<n;i++){
        if(a[i]==x){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    printf("nhap so phan tu:");
    scanf("%d",&n);
    int a[n];
    int x;
    getchar();
    printf("nhap phan tu x:");
    scanf("%d",&x);
    getchar();
    printf("nhap n phan tu vao:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
   int t= LinearSearch(a,n,x);
    if(t==-1){
        printf("khong ton tai x trong mang a");
    }
    else printf("phan tu %d nam o vi tri :%d",x,t);

}