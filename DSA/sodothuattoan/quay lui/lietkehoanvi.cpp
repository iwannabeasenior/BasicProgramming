#include<stdio.h>
int a[1001],m[1001];
int n;
void solution(){
	for(int i=1;i<=n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
void try1 (int t){
	for(int i=1;i<=n;i++){
		if(!m[i]){
			a[t]=i;
			m[i]=1;
		if(t==n) {
			solution();
		}
		else try1 (t+1);
		m[i]=0;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=1000;i++)
	{
	
		m[i]=0;
	}
	try1(1);
}