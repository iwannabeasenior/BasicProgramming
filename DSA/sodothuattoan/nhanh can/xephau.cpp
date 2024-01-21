#include<stdio.h>
int n;
int a[1001];

void solution(){
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}
void xephau(int t){
	for(int i=1;i<=n;i++){
		a[t]=i;
		for(int j=0;j<=t-1;j++){
			if(a[t]==a[j]|| (a[t]+t)==(a[j]+j)||(a[t]-t)==(a[j]-j)){
				1;
				goto x;
			}
		}
		if(t==n) solution();
				xephau(t+1);		
x: 1;
	}
}
int main()
{
scanf("%d",&n);
a[0]=-1000;
xephau(1);
}