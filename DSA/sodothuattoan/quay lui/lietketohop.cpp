#include<stdio.h>
int k,n;
int a[1000];
void solution(){
	for(int i=1;i<=k;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
void try1(int t){
	for(int i=a[t-1]+1;i<=n-k+t;i++){
		a[t]=i;
		if(t==k) solution();
		else try1(t+1);
	}
}

int main()
{
	scanf("%d %d",&k,&n);
	a[0]=0;
	try1(1);
}