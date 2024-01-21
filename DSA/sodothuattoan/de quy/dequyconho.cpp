#include<stdio.h>

int c[1000][1000];

int dequyconho(int a,int b){

	if(a==b||a==0){
		c[a][b]=1;
	}	
	else {
		if(c[a][b]<0)
			c[a][b]=dequyconho(a-1,b-1)+dequyconho(a,b-1);
	}
	return c[a][b];
	}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			c[i][j]=-1;
		}
	}
	int x=dequyconho(a,b);
	printf("%d",x);
}