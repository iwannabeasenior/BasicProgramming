#include<stdio.h>
void merge(int a[],int l,int m,int r){
	int ta[r-l+1];
	int i=l;int j=m+1;
	for(int k=l;k<=r;k++)
	{
		if(i>m){
			ta[k]=a[j];j++;
		}
		else if(j>r){
			ta[k]=a[i];
			i++;
		}
		else {
			if(a[i]<a[j]){
				ta[k]=a[i];
				i++;
			}
			else{
				ta[k]=a[j];
				j++;
			}
		}
	}
	for(int k=l;k<=r;k++)
	{
		a[k]=ta[k];
	}
}

void mergeSort(int a[],int l,int r){
	if(l<r){
		int m=(l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}


int main()
{
int n;scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++) scanf("%d",&a[i]);
mergeSort(a,0,n-1);
for(int i=0;i<n;i++)
{
	printf("%d ",a[i]);
}
}