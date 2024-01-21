// Permutations of a given string
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void swap(char *a,char *b){
	char c=*a;
	*a=*b;
	*b=c;

}
void daonguoc(char*str,int t,int n){
	int i=t+1,j=n-1;
	while(i<j){
		swap(&str[i],&str[j]);
		i++;
		j--;
	}
}
int test(char*str){
	for(int i=strlen(str)-1;i>0;i--)
	{
		if(str[i]>str[i-1]) return i-1;
	}
	return -1;
}
int dictionary(char*str){
	int n=strlen(str);
	int t=test(str);
	if(t!=-1){
		for(int i=n-1;i>t;i--){
			if(str[i]>str[t]){
				swap(&str[i],&str[t]);
				break;
			}
		}
		daonguoc(str,t,n);
		printf("%s",str);
		printf("\n");
		dictionary(str);
	}
	else return 1;
}
int main()
{
	char str[100];
	scanf("%s",str);
	printf("%s\n",str);
	dictionary(str);
}	