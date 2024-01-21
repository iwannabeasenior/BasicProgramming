#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int L[n];
    for(int i=0;i<n;i++)
    {
        L[i]=0;
    }
	L[0]=a[0];
	int max=L[0];
	for(int i=1;i<n;i++)
	{
		if(L[i-1]<0) L[i]=a[i];
		else L[i]=a[i]+L[i-1];
		if(max<L[i]) max=L[i];
	}
	printf("%d",max);

}
