#include<stdio.h>
void move(int n,char a,char b, char c){
	if(n==1)
	{
		printf("Move 1 disk from %c to %c\n",a,b);
	}
	else{
		move (n-1,a,c,b);
		move(1,a,b,c);
		move(n-1,c,b,a);
	}
}
int main()
{
int n;
printf("nhap gia tri cua n:");
scanf("%d",&n);
move(n,'a','b','c');
return 0;
}