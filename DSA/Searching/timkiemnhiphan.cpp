#include<stdio.h>
int search(int a[],int n,int x){
    int left,mid,right;
    left=0;
    right=n-1;
    do{
        mid=(left+right)/2;
        if(a[mid]==x) return mid;
        else if(a[mid]<x){
            left=mid+1;
        }
        else {
            right=mid-1;
        }
    }
    while(left<=right);
    return -1;
}
int main(){
    int n;
    scanf("%d",&n);
    int x;
    getchar();
    scanf("%d",&x);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
   int t= search(a,n,x);
   if(t==-1) printf("khong tim thay phan tu ");
   else printf("phan tu %d o vi tri %d",x,t);
}