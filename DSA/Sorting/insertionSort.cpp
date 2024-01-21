//sap xep chen
#include<stdio.h>
void insertionSort(int a[],int n){
	for(int k=1;k<n;k++){
		int index=a[k];
		int j=k;

		while(index<a[j-1]){
			a[j]=a[j-1];
			j--;
			if(j==0) break;
		}
	    a[j++]=index;
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
	insertionSort(a,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}