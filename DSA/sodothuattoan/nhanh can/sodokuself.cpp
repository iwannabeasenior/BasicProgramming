#include<stdio.h>
int a[10][10];
void solution(int a[10][10]){
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<10;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
		 
}
bool check(int l,int c,int r){
	if(l!=1){
		for(int i=1;i<l;i++)
	{
		if(a[i][r]==c) return false;
	}
	}
	if(r!=1){
	for(int i=1;i<r;i++)
	{
		if(a[l][i]==c) return false;
	}	
	}
	
	
	int I=l/3,J=r/3;
	if(l%3==0){
		I--;
	}
	if(r%3==0){
		J--;
	}
	int i=l-I*3,j=r-J*3;
	for(int i1=I*3+1;i1<I*3+i;i1++ ){
		for(int j1=J*3+1;j1<=J*3+3;j1+1){
			if(a[i1][j1]==c) return false;
		}
	}
	for(int j1=J*3+1;j1<J*3+j;j1++){
		if(a[I*3+i][j1]==c) return false;
	}
	return true;
}
void try1(int l, int r){
	for(int v=1;v<10;v++)
	{
		if(check(l,v,r)){
			a[l][r]=v;
		if(l==9&&r==9) solution(a);
		else if(r==9) try1(l+1,1);
		 else try1(l,r+1);
	}
}
}
int main()
{
	
	try1(1,1);
}