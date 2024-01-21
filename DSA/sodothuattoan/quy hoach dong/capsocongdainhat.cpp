#include<stdio.h>
int max(int a,int b){
	return a>b?a:b;
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
	int L[n]={0};
	L[0]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]-1==a[j]) L[i]=max(L[j]+1,L[i]);
		}
	}
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(max<L[i]) max=L[i];
	}
	printf("%d",max);

}