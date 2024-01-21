#include<stdio.h>
int max(int a,int b){
	return a>b?a:b;
}
int main()
{
	int rs=0;
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n+1],b[m+1];
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=0;j<=m;j++)
	{
		scanf("%d",&b[j]);
	}
	int c[n+1][m+1];
	for(int i=0;i<=n;i++) c[i][0]=0;
	for(int i=0;i<=m;i++) c[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
			else c[i][j]=max(c[i-1][j],c[i][j-1]);
			rs=max(c[i][j],rs);
		}
	}

	printf("%d",rs);
}	