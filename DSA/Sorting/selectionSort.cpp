#include<stdio.h>
void swap(int *a,int *b){
	int c=*a;
	*a=*b;
	*b=c;
}
void selectionSort(int a[],int n){
	for(int i=0;i<n-1;i++)
	{	int min=i;
		for(int j=i+1;j<n;j++ ){
			if(a[min]>a[j]) {min=j;}
		}
		if(a[i]>a[min])
		swap(&a[i],&a[min]);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selectionSort(a,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}