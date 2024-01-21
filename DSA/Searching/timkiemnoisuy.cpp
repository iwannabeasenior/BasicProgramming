#include<stdio.h>
#include<stdlib.h>

int timkiem(int a[],int n,int x){
	int left=0;
	int right=n-1;
	while(a[left]<=x && a[right]>=x && left<=right){
		double val1=(double)(x-a[left])/(a[right]-a[left]);
		int val2=right-left;
		int  search=left+val1*val2;
		if(a[search]==x) return search;
		else if(a[search]>x) right=search-1;
		else left=search+1;
	}
	return -1;

}
int main()
{
int n;
int a[n];
for(int i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
int x;scanf("%d",&x);
int t=timkiem(a,n,x);

printf("%d",t);
// else printf("khong ton tai x");
}