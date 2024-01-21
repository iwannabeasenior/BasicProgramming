#include<stdio.h>
void swap(int *a,int *b){
	int c=*a;
	*a=*b;
	*b=c;
}
int partition(int a[],int l,int r){
	int p=a[r];
	int i=l-1;
	for(int j=l;j<r;j++)
	{
		if(a[j]<p){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return i+1;
}
void quicksort(int a[],int l,int r){
	if(l<r){
		int pi=partition(a,l,r);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,r);
	}
	
}
int main()
{
	int n;scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}