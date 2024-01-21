#include<stdio.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int a[],int i,int n){
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	if(l<n&& a[l]>a[largest]){
		largest=l;
	}
	if(r<n&& a[r]>a[largest]){
		largest=r;
	}
	if(largest!=i){
		swap(&a[i],&a[largest]);
		heapify(a,largest,n);
	}

}
void heapsort(int a[],int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(a,i,n);
	}
	for(int i=n-1;i>=0;i--){
		swap(&a[i],&a[0]);
		heapify(a,0,i);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}