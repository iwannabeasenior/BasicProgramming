#include<stdio.h>
int x[11];
void solution()
{
	for(int i=1;i<=10;i++)
	{
		printf("%d",x[i]);
		
	}printf("\n");
}

void try1(int n){
	for(int i=0;i<=1;i++)
	{
		x[n]=i;
		if(n==10) solution();
		else try1(n+1);
	}
}
int main()
{
 try1(1);
}