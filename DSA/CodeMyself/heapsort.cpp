#include<stdio.h>
//
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
// build heap
void heapify(int a[],int n,int i){
    int left=2*i;
    int right=2*i+1;
    int largest=i;
    if(left<=n && a[left]>a[i]){
        largest=left;
    }
    if(right<=n && a[right]>a[i]){
        largest=right;
    }
    if(largest!=i){
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
}
// sort 
void heapsort(int a[],int n){
    for(int i=n/2;i>0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(&a[1],&a[i]);
        heapify(a,i-1,a[1]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n+1];
   
    for (size_t i = 1; i <= n; i++)
    {
        /* code */
        scanf("%d",&a[i]);
    }
     heapsort(a,n);
     for(int i=1;i<=n;i++){
        printf("%d",a[i]);
     }
}