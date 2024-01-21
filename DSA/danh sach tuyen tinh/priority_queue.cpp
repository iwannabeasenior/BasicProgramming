#include<stdio.h>
int n;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insert (int a[],int val){
    n=n+1;
    int i=n;
    a[i]=val;
    while (i>1 && a[i/2]<a[i])
    {
        swap(&a[i/2],&a[i]);
        i=i/2;
    }
}
void maxheap(int a[],int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n&& a[left]>a[i]){
        largest=left;
    }
   
    if(right<=n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&a[i],&a[largest]);
        maxheap(a,largest);
    }
}
int max_element(int a[]){
    return a[1];
}
int pop_max_element(int a[]){
    if(n==0){
        printf("khong the xoa phan tu vi hang doi rong");
        return -1;
    }
    int max=a[1];
    a[1]=a[n];
    n=n-1;
    maxheap(a,1);
    return max;
}
void print_element(int a[]){
    if(n<=0) return ;
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
}
int main(){
    n=0;
    int a[10];
  
    insert(a,5);
    insert(a,8);
    insert(a,1);
    insert(a,7);
    insert(a,3);
    insert(a,2);
    insert(a,7);
    insert(a,4);
    insert(a,9);
    pop_max_element(a);print_element(a);
    printf("\n");
    pop_max_element(a);print_element(a);
    
}