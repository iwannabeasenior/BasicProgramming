#include<stdio.h>
void swap(int *a,int *b){
	int c=*a;
	*a=*b;
	*b=c;
}
void bublesort(int a[],int n){
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1]) swap(&a[j],&a[j+1]);
		}
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
	bublesort(a,n);
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
}